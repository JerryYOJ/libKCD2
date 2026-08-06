#include "skald/SkaldRuntime.h"

#include <algorithm>
#include <cmath>
#include <cstdarg>
#include <cstring>
#include <exception>
#include <iomanip>
#include <limits>
#include <map>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "LuaHelpers.h"
#include "Offsets/RTTI.h"
#include "Offsets/vtables/ILog.h"
#include "Offsets/vtables/IScriptSystem.h"
#include "Offsets/vtables/IScriptTable.h"
#include "conceptmodule/C_Effect.h"
#include "conceptmodule/C_ObjectProperties.h"
#include "conceptmodule/E_PortDirection.h"
#include "conceptmodule/E_PortSpecification.h"
#include "crysystem/SSystemGlobalEnvironment.h"
#include "rttr/argument.h"
#include "rttr/instance.h"
#include "rttr/property.h"
#include "rttr/type.h"

namespace luautils::skald {
namespace {

ScriptAnyValue NilValue()
{
    ScriptAnyValue value;
    value.type = ANY_TNIL;
    value.nHandle = 0;
    return value;
}

template <class T>
void EraseValue(std::vector<T>& values, const T& value)
{
    values.erase(std::remove(values.begin(), values.end(), value), values.end());
}

bool CreatesRegistryHandle(rttr::type declaredType,
                           const ScriptAnyValue& value)
{
    return value.type == ANY_THANDLE && value.nHandle != 0 &&
           (declaredType.is_enumeration() || declaredType.is_class() ||
            declaredType.is_pointer());
}

// Certified port names use registered rttr spellings; when a spelling still
// misses the registry, classify from the value the port actually produced.
rttr::type EffectiveResultType(rttr::type declaredType,
                               const rttr::variant& value)
{
    if (declaredType.is_valid() || !value.is_valid())
        return declaredType;
    return value.get_type();
}

}  // namespace

SkaldRuntime::SkaldRuntime(RttrRuntime& rttrRuntime) noexcept
    : m_rttrRuntime(rttrRuntime)
{}

SkaldRuntime::~SkaldRuntime()
{
    Shutdown();
}

void SkaldRuntime::SetScriptSystem(
    Offsets::IScriptSystem* scriptSystem) noexcept
{
    Offsets::IScriptSystem* previousSystem = nullptr;
    HSCRIPTFUNCTION previousDispatcher = nullptr;
    {
        std::lock_guard lock(m_mutex);
        if (m_scriptSystem == scriptSystem)
            return;
    }

    InvalidateLuaOutputs();
    Clear();
    {
        std::lock_guard lock(m_mutex);
        previousSystem = m_scriptSystem;
        previousDispatcher = m_updateDispatcher;
        m_scriptSystem = scriptSystem;
        m_updateDispatcher = nullptr;
    }
    if (previousSystem && previousDispatcher)
        previousSystem->ReleaseFunc(previousDispatcher);
}

bool SkaldRuntime::SetUpdateDispatcher(
    HSCRIPTFUNCTION dispatcher, std::string& error)
{
    if (!dispatcher) {
        error = "SKALD update dispatcher must be a function";
        return false;
    }

    Offsets::IScriptSystem* scriptSystem = nullptr;
    HSCRIPTFUNCTION previous = nullptr;
    {
        std::lock_guard lock(m_mutex);
        if (!m_scriptSystem) {
            error = "SKALD script system is not initialized";
            return false;
        }
        scriptSystem = m_scriptSystem;
        previous = m_updateDispatcher;
        m_updateDispatcher = dispatcher;
    }
    if (previous)
        scriptSystem->ReleaseFunc(previous);
    return true;
}

bool SkaldRuntime::CreateNode(
    std::string_view cppType,
    Offsets::IScriptTable* arguments,
    Handle& nodeHandle,
    RttrHandleRegistry::Handle& rttrHandle,
    std::string& error)
{
    nodeHandle = 0;
    rttrHandle = 0;

    if (!arguments) {
        error = "SKALD node creation arguments must be a table";
        return false;
    }

    // Node shape is not known until the native factory constructs it (and,
    // for C_TemplatedNode leaves, until TypeT is applied), so the raw Lua
    // arguments are captured here and matched against live port
    // definitions inside the resolver the host invokes during creation.
    // "TypeT" is consumed directly, never treated as a port name.
    std::string typeParameter;
    std::unordered_map<std::string, ScriptAnyValue> rawInputs;
    std::unordered_map<std::string, ScriptAnyValue> configProperties;
    std::map<std::string, ScriptAnyValue> extraInputs;   // ordered: name IS position
    // A nested Lua table is only valid INSIDE the iteration that produced it:
    // the iterator hands out a temporary IScriptTable wrapper, and this RE
    // ScriptAnyValue is a plain POD that (unlike the SDK type) does not
    // AddRef it. Array inputs are therefore drained to plain C++ here and the
    // table pointer is never stored -- dump-verified 2026-08-07: keeping one
    // until the port resolver ran vcalled a recycled heap block
    // (0xC0000005 execute, rip in the heap, rcx = the dead wrapper).
    struct ArrayInput
    {
        struct Element
        {
            RttrHandleRegistry::Handle handle = 0;
            std::string text;
            bool isText = false;
        };
        std::string alias;
        std::vector<Element> elements;
    };
    std::unordered_map<std::string, ArrayInput> arrayInputs;
    {
        Offsets::IScriptTable::Iterator iterator =
            arguments->BeginIteration(false);
        while (arguments->MoveNext(iterator)) {
            if (!iterator.sKey) {
                arguments->EndIteration(iterator);
                error = "SKALD node creation arguments require string keys";
                return false;
            }
            const std::string name(iterator.sKey);
            if (name == "TypeT") {
                if (iterator.value.type != ANY_TSTRING || !iterator.value.str) {
                    arguments->EndIteration(iterator);
                    error = "SKALD type parameter 'TypeT' must be a string";
                    return false;
                }
                typeParameter = iterator.value.str;
                continue;
            }
            // Reserved channel: config value properties applied via RTTR
            // set_value before port enumeration (drives dynamic pin synthesis).
            if (name == "__properties") {
                if (iterator.value.type != ANY_TTABLE || !iterator.value.table) {
                    arguments->EndIteration(iterator);
                    error = "SKALD '__properties' must be a table";
                    return false;
                }
                Offsets::IScriptTable* propsTable = iterator.value.table;
                bool propsOk = true;
                Offsets::IScriptTable::Iterator inner =
                    propsTable->BeginIteration(false);
                while (propsTable->MoveNext(inner)) {
                    if (!inner.sKey) {
                        propsOk = false;
                        break;
                    }
                    configProperties.emplace(std::string(inner.sKey), inner.value);
                }
                propsTable->EndIteration(inner);
                if (!propsOk) {
                    arguments->EndIteration(iterator);
                    error = "SKALD '__properties' requires string keys";
                    return false;
                }
                continue;
            }
            // Reserved channel: variadic pins installed by name with no port
            // definition (MakeArray's A/B/C value list). Sorted by name below,
            // because the node reads them positionally out of m_ports.
            if (name == "__ports") {
                if (iterator.value.type != ANY_TTABLE || !iterator.value.table) {
                    arguments->EndIteration(iterator);
                    error = "SKALD '__ports' must be a table";
                    return false;
                }
                Offsets::IScriptTable* portsTable = iterator.value.table;
                bool portsOk = true;
                Offsets::IScriptTable::Iterator inner =
                    portsTable->BeginIteration(false);
                while (portsTable->MoveNext(inner)) {
                    if (!inner.sKey) {
                        portsOk = false;
                        break;
                    }
                    extraInputs.emplace(std::string(inner.sKey), inner.value);
                }
                portsTable->EndIteration(inner);
                if (!portsOk) {
                    arguments->EndIteration(iterator);
                    error = "SKALD '__ports' requires string keys";
                    return false;
                }
                continue;
            }
            // Array creation input: {__array_type="<container>", h1, h2, ...}.
            // Drained NOW, while the wrapper is guaranteed alive (see the
            // ArrayInput note above). __array_type is caller-supplied
            // (certification-cited), not introspected from
            // definition.GetValueType() -- that call's container-vs-element
            // shape for array-kind ports is not certified.
            if (iterator.value.type == ANY_TTABLE && iterator.value.table) {
                Offsets::IScriptTable* arrayTable = iterator.value.table;
                ScriptAnyValue typeNameAny;
                typeNameAny.type = ANY_ANY;
                typeNameAny.table = nullptr;
                if (!arrayTable->GetValueAny("__array_type", typeNameAny) ||
                    typeNameAny.type != ANY_TSTRING || !typeNameAny.str) {
                    arguments->EndIteration(iterator);
                    error = "SKALD array input '" + name +
                        "' requires a table with __array_type set to the "
                        "certified container type name";
                    return false;
                }

                ArrayInput entry;
                entry.alias = typeNameAny.str;
                const int count = arrayTable->Count();
                if (count > 0)
                    entry.elements.reserve(static_cast<std::size_t>(count));
                bool elementsOk = true;
                for (int index = 1; index <= count; ++index) {
                    ScriptAnyValue elementAny;
                    elementAny.type = ANY_ANY;
                    elementAny.table = nullptr;
                    arrayTable->GetAtAny(index, elementAny);
                    ArrayInput::Element element;
                    if (elementAny.type == ANY_THANDLE &&
                        elementAny.nHandle != 0) {
                        element.handle =
                            static_cast<RttrHandleRegistry::Handle>(
                                elementAny.nHandle);
                    } else if (elementAny.type == ANY_TSTRING &&
                               elementAny.str) {
                        element.text = elementAny.str;
                        element.isText = true;
                    } else {
                        error = "SKALD array input '" + name + "' element " +
                            std::to_string(index) +
                            " must be a nonzero handle or a string";
                        elementsOk = false;
                        break;
                    }
                    entry.elements.push_back(std::move(element));
                }
                if (!elementsOk) {
                    arguments->EndIteration(iterator);
                    return false;
                }
                arrayInputs.emplace(name, std::move(entry));
                continue;
            }
            rawInputs.emplace(name, iterator.value);
        }
        arguments->EndIteration(iterator);
    }

    std::unordered_set<std::string> consumed;
    const SkaldPortResolver resolver =
        [&](wh::conceptmodule::definition::I_PortDefinition& definition,
            std::string_view portName, bool& install, std::string& literal,
            rttr::variant& object, bool& isObject, std::string& innerError) {
            install = false;
            const std::string name(portName);

            // Array inputs were drained during argument capture; nothing
            // Lua-side is touched here.
            if (const auto arrayFound = arrayInputs.find(name);
                arrayFound != arrayInputs.end()) {
                consumed.insert(name);
                const ArrayInput& arrayInput = arrayFound->second;
                const rttr::type containerType =
                    rttr::type::get_by_name(arrayInput.alias.c_str());
                if (!containerType.is_valid()) {
                    innerError = "SKALD array input '" + name +
                        "' has an unreflected container type '" +
                        arrayInput.alias + "'";
                    return false;
                }

                std::vector<RttrLuaConverter::ArrayElement> elements;
                elements.reserve(arrayInput.elements.size());
                for (std::size_t index = 0;
                     index < arrayInput.elements.size(); ++index) {
                    const ArrayInput::Element& captured =
                        arrayInput.elements[index];
                    RttrLuaConverter::ArrayElement element;
                    if (captured.isText) {
                        element.text = captured.text;
                        element.isText = true;
                    } else {
                        const rttr::variant* elementValue =
                            m_rttrRuntime.Registry().Lookup(captured.handle);
                        if (!elementValue || !elementValue->is_valid()) {
                            innerError = "SKALD array input '" + name +
                                "' element " + std::to_string(index + 1) +
                                " references an unknown or stale RTTR handle";
                            return false;
                        }
                        element.pointer = elementValue->get_raw_ptr();
                    }
                    elements.push_back(std::move(element));
                }

                std::string arrayError;
                object = RttrLuaConverter::MakeArrayVariant(
                    std::move(elements), containerType, arrayError);
                if (!object.is_valid()) {
                    innerError = "SKALD array input '" + name + "': " +
                        arrayError;
                    return false;
                }
                isObject = true;
                install = true;
                return true;
            }

            const auto found = rawInputs.find(name);
            if (found == rawInputs.end())
                return true;
            consumed.insert(name);

            const ScriptAnyValue& value = found->second;
            if (value.type == ANY_THANDLE && value.nHandle != 0) {
                const rttr::variant* stored = m_rttrRuntime.Registry().Lookup(
                    static_cast<RttrHandleRegistry::Handle>(value.nHandle));
                if (!stored || !stored->is_valid()) {
                    innerError = "SKALD input '" + name +
                        "' references an unknown or stale RTTR handle";
                    return false;
                }
                const rttr::type declaredType = definition.GetValueType();
                rttr::variant converted;
                if (declaredType.is_valid() &&
                    stored->convert_to(declaredType, converted) &&
                    converted.is_valid()) {
                    object = std::move(converted);
                } else {
                    object = *stored;
                }
                isObject = true;
                install = true;
                return true;
            }

            // Tables never reach rawInputs (drained during capture), so a
            // table here would be a stale pointer -- refuse instead of
            // dereferencing it.
            if (value.type == ANY_TTABLE) {
                innerError = "SKALD input '" + name +
                    "' is a table that was not captured as an array input";
                return false;
            }

            const rttr::type expectedType = definition.GetValueType();
            if (!expectedType.is_valid()) {
                // Templated ports (e.g. ContainsElement.Value under a TypeT)
                // report no reflected value type from their shared authoring
                // definition -- the resolved type lives on the live port, not
                // the schema. A Lua string still installs fine as a raw
                // LITERAL: the same lazy-convert transport authored XML rides,
                // with the consumer converting on read. Handles already take
                // the tolerant branch above; everything else keeps failing
                // loudly.
                if (value.type == ANY_TSTRING && value.str) {
                    literal = value.str;
                    install = true;
                    return true;
                }
                innerError = "SKALD input '" + name +
                    "' has an unreflected native value type";
                return false;
            }
            rttr::variant converted;
            if (!m_rttrRuntime.Converter().ConvertValue(
                    value, expectedType, converted, innerError)) {
                innerError = "invalid value for SKALD input '" + name +
                    "': " + innerError;
                return false;
            }
            const rttr::string_view convertedName =
                converted.get_type().get_name();
            const std::string_view convertedTypeName(
                convertedName.data(), convertedName.size());
            if (convertedTypeName == "bool" || convertedTypeName == "int") {
                if (!SerializeConstant(expectedType, converted, literal,
                                       innerError))
                    return false;
                install = true;
                return true;
            }
            // ConvertValue also succeeds for non-bool/int results reached via
            // the registered string->type converter (variant convert_to
            // 0x1804F9640, e.g. a plain Lua string into a GUID/ID struct like
            // S_BuffDefinitionId) or enum name-to-value lookup.
            // SerializeConstant only understands bool/int text, so these
            // install directly as objects instead, same as a handle input.
            object = std::move(converted);
            isObject = true;
            install = true;
            return true;
        };

    // Applied after TypeT, before port enumeration: each entry is a reflected
    // value property (std::string / int) whose contents drive dynamic pin
    // synthesis. set_value converts the argument to the property's declared
    // type and silently rejects on mismatch, so a genuine std::string/int
    // variant (what ConvertValue builds) is required.
    const SkaldPropertyApplier applier =
        [&](wh::conceptmodule::C_Node* node, const rttr::variant& nodeValue,
            std::string& innerError) -> bool {
            if (configProperties.empty())
                return true;
            rttr::instance object(nodeValue);
            rttr::type nodeType = object.m_rawType;
            if (nodeType.is_pointer())
                nodeType = nodeType.get_raw_type();
            if (!nodeType.is_valid()) {
                innerError = "SKALD node has no reflected type for properties";
                return false;
            }
            for (const auto& [name, value] : configProperties) {
                const rttr::property prop = nodeType.get_property(name);
                if (!prop.is_valid()) {
                    innerError = "unknown SKALD property '" + name + "'";
                    return false;
                }
                // "DeclaringType" never goes through rttr::property::set_value:
                // set_value rejects every variant we can build for it, and a
                // rejected write leaves state behind that kills the NEXT node
                // construction. The game registers a plain native setter for it
                // -- void C_ObjectProperties::SetDeclaringType(std::string),
                // 0x18106FFF4 -- so call that directly, exactly as
                // ApplyTypeParameter calls C_TemplatedNode::SetTypeT.
                if (name == "DeclaringType") {
                    const rttr::type objectProperties =
                        rttr::type::get_by_name(
                            "wh::conceptmodule::ObjectProperties");
                    if (!node || !objectProperties.is_valid() ||
                        (nodeType != objectProperties &&
                         !nodeType.is_derived_from(objectProperties))) {
                        innerError = "SKALD property 'DeclaringType' is only "
                            "settable on ObjectProperties nodes";
                        return false;
                    }
                    if (value.type != ANY_TSTRING || !value.str) {
                        innerError =
                            "SKALD property 'DeclaringType' must be a string";
                        return false;
                    }
                    static_cast<wh::conceptmodule::C_ObjectProperties*>(node)
                        ->SetDeclaringType(value.str);
                    continue;
                }
                const rttr::type propType = prop.get_type();
                if (!propType.is_valid()) {
                    innerError = "SKALD property '" + name +
                        "' has an unreflected type";
                    return false;
                }
                if (RttrLuaConverter::IsStringViewType(propType)) {
                    innerError = "SKALD property '" + name +
                        "' is a std::string_view and cannot be set safely";
                    return false;
                }
                rttr::variant converted;
                if (!m_rttrRuntime.Converter().ConvertValue(
                        value, propType, converted, innerError)) {
                    innerError = "invalid value for SKALD property '" + name +
                        "': " + innerError;
                    return false;
                }
                const rttr::argument arg(converted);
                if (!prop.set_value(object, arg)) {
                    innerError = "native SKALD rejected property '" + name +
                        "' (type mismatch)";
                    return false;
                }
            }
            return true;
        };

    // Variadic pins carry raw text exactly like authored XML constants -- the
    // node converts per element on read, so no declared type is needed here.
    // std::map iteration is name-ordered, which is the element order.
    std::vector<SkaldExtraPort> extraPorts;
    extraPorts.reserve(extraInputs.size());
    for (const auto& [name, value] : extraInputs) {
        SkaldExtraPort extra;
        extra.name = name;
        if (value.type == ANY_THANDLE && value.nHandle != 0) {
            const rttr::variant* stored = m_rttrRuntime.Registry().Lookup(
                static_cast<RttrHandleRegistry::Handle>(value.nHandle));
            if (!stored || !stored->is_valid()) {
                error = "SKALD variadic port '" + name +
                    "' references an unknown or stale RTTR handle";
                return false;
            }
            extra.object = *stored;
            extra.isObject = true;
        } else if (value.type == ANY_TSTRING && value.str) {
            extra.literal = value.str;
        } else if (value.type == ANY_TNUMBER) {
            // Integral values must not pick up a ".000000" tail: authored XML
            // writes plain integers and the element parser is text-driven.
            const float n = value.number;
            if (n == std::floor(n) && std::fabs(n) < 1e9f) {
                extra.literal = std::to_string(static_cast<long long>(n));
            } else {
                std::ostringstream out;
                out << std::setprecision(9) << n;
                extra.literal = out.str();
            }
        } else if (value.type == ANY_TBOOLEAN) {
            extra.literal = value.b ? "true" : "false";
        } else {
            error = "SKALD variadic port '" + name +
                "' must be a string, number, boolean or RTTR handle";
            return false;
        }
        extraPorts.push_back(std::move(extra));
    }

    SkaldCreatedNode created;
    if (!m_host.CreateNode(cppType, typeParameter, applier, resolver,
                           extraPorts, created, error))
        return false;

    if (consumed.size() != rawInputs.size() + arrayInputs.size()) {
        for (const auto& [name, value] : rawInputs) {
            (void)value;
            if (consumed.find(name) == consumed.end()) {
                error = "unknown SKALD creation input '" + name + "'";
                break;
            }
        }
        if (error.empty()) {
            for (const auto& [name, value] : arrayInputs) {
                (void)value;
                if (consumed.find(name) == consumed.end()) {
                    error = "unknown SKALD creation input '" + name + "'";
                    break;
                }
            }
        }
        if (error.empty())
            error = "unknown SKALD creation input";
        m_host.DestroyNode(created.node);
        return false;
    }

    RttrHandleRegistry::Handle storedHandle = 0;
    try {
        storedHandle =
            m_rttrRuntime.Registry().Store(std::move(created.value));
    } catch (const std::exception& exception) {
        m_host.DestroyNode(created.node);
        error = exception.what();
        return false;
    }

    Handle storedNodeHandle = 0;
    bool inserted = false;
    try {
        std::lock_guard lock(m_mutex);
        if (AllocateHandle(storedNodeHandle, error)) {
            inserted = m_nodes.emplace(
                storedNodeHandle,
                NodeRecord{ storedHandle,
                            _smart_ptr<wh::conceptmodule::C_Node>(created.node),
                            {}, {} }).second;
        }
    } catch (const std::exception& exception) {
        {
            std::lock_guard lock(m_mutex);
            m_nodes.erase(storedNodeHandle);
        }
        m_rttrRuntime.Registry().Release(storedHandle);
        m_host.DestroyNode(created.node);
        error = exception.what();
        return false;
    } catch (...) {
        {
            std::lock_guard lock(m_mutex);
            m_nodes.erase(storedNodeHandle);
        }
        m_rttrRuntime.Registry().Release(storedHandle);
        m_host.DestroyNode(created.node);
        error = "unknown native exception while retaining SKALD node";
        return false;
    }
    if (!storedNodeHandle || !inserted) {
        m_rttrRuntime.Registry().Release(storedHandle);
        m_host.DestroyNode(created.node);
        if (error.empty())
            error = "SKALD node token collision";
        return false;
    }

    nodeHandle = storedNodeHandle;
    rttrHandle = storedHandle;
    return true;
}

bool SkaldRuntime::DescribeNode(std::string_view cppType,
                                std::string_view typeParameter,
                                std::vector<SkaldPortInfo>& ports,
                                std::string& error)
{
    std::lock_guard lock(m_mutex);
    return m_host.DescribeNode(cppType, typeParameter, ports, error);
}

bool SkaldRuntime::DestroyNode(Handle nodeHandle, std::string& error)
{
    NodeRecord record;
    std::vector<HSCRIPTFUNCTION> callbacks;
    Offsets::IScriptSystem* scriptSystem = nullptr;
    {
        std::lock_guard lock(m_mutex);
        const auto entry = m_nodes.find(nodeHandle);
        if (entry == m_nodes.end()) {
            error = "unknown or stale SKALD node handle";
            return false;
        }
        callbacks.reserve(entry->second.triggerConnections.size());
        record = entry->second;
        scriptSystem = m_scriptSystem;
        RemoveNodeRecordsLocked(nodeHandle, callbacks);
    }

    if (scriptSystem) {
        for (HSCRIPTFUNCTION callback : callbacks)
            if (callback)
                scriptSystem->ReleaseFunc(callback);
    }
    m_rttrRuntime.Registry().Release(record.rttrHandle);
    m_host.DestroyNode(record.node.get());
    return true;
}

bool SkaldRuntime::BindTriggerOutput(
    Handle nodeHandle, std::string_view outputName,
    HSCRIPTFUNCTION callback, Handle& connectionHandle,
    std::string& error)
{
    connectionHandle = 0;
    if (!callback) {
        error = "SKALD trigger output callback must be a function";
        return false;
    }

    _smart_ptr<wh::conceptmodule::I_Port> port;
    rttr::type declaredType;
    if (!FindOutputPort(nodeHandle, outputName, /*expectTrigger=*/true,
                        port, declaredType, error))
        return false;

    Handle handle = 0;
    {
        std::lock_guard lock(m_mutex);
        const auto nodeEntry = m_nodes.find(nodeHandle);
        if (nodeEntry == m_nodes.end()) {
            error = "unknown or stale SKALD node handle";
            return false;
        }
        if (!m_scriptSystem || !m_updateDispatcher) {
            error = "SKALD generated update dispatcher is not initialized";
            return false;
        }
        if (nodeEntry->second.triggerConnections.size() >=
            kMaxTriggerConnectionsPerNode) {
            error = "SKALD node trigger-output connection limit reached";
            return false;
        }
        if (!AllocateHandle(handle, error))
            return false;

        auto* activePort = static_cast<wh::conceptmodule::C_ActiveTriggerPort*>(
            port.get());
        auto& nodeConnections = nodeEntry->second.triggerConnections;
        nodeConnections.reserve(nodeConnections.size() + 1);

        const auto [route, routeInserted] =
            m_triggerRoutes.try_emplace(activePort);
        try {
            route->second.reserve(route->second.size() + 1);
            const auto [entry, inserted] = m_triggerConnections.emplace(
                handle,
                TriggerConnectionRecord{ nodeHandle, port, callback });
            if (!inserted) {
                if (routeInserted && route->second.empty())
                    m_triggerRoutes.erase(route);
                error = "SKALD trigger-output token collision";
                return false;
            }

            nodeConnections.push_back(handle);
            route->second.push_back(handle);
        } catch (...) {
            m_triggerConnections.erase(handle);
            EraseValue(nodeConnections, handle);
            if (const auto currentRoute = m_triggerRoutes.find(activePort);
                currentRoute != m_triggerRoutes.end()) {
                EraseValue(currentRoute->second, handle);
                if (routeInserted && currentRoute->second.empty())
                    m_triggerRoutes.erase(currentRoute);
            }
            throw;
        }
    }

    connectionHandle = handle;
    return true;
}

bool SkaldRuntime::BindDataOutput(
    Handle nodeHandle, std::string_view outputName,
    Handle& bindingHandle, OutputUpdate& initialValue,
    std::string& error)
{
    bindingHandle = 0;
    initialValue = OutputUpdate{};

    _smart_ptr<wh::conceptmodule::I_Port> port;
    // Best-effort declared type, read live from the port's own definition;
    // if it comes back invalid, EffectiveResultType classifies from the
    // runtime value's own type instead.
    rttr::type declaredType;
    if (!FindOutputPort(nodeHandle, outputName, /*expectTrigger=*/false,
                        port, declaredType, error))
        return false;

    Handle handle = 0;
    {
        std::lock_guard lock(m_mutex);
        const auto nodeEntry = m_nodes.find(nodeHandle);
        if (nodeEntry == m_nodes.end()) {
            error = "unknown or stale SKALD node handle";
            return false;
        }
        if (nodeEntry->second.dataBindings.size() >=
            kMaxDataBindingsPerNode) {
            error = "SKALD node data-output binding limit reached";
            return false;
        }
        if (!AllocateHandle(handle, error))
            return false;

        auto& nodeBindings = nodeEntry->second.dataBindings;
        nodeBindings.reserve(nodeBindings.size() + 1);
        if (!m_dataBindings.emplace(
                handle, DataBindingRecord{ nodeHandle, port,
                                           declaredType }).second) {
            error = "SKALD data-output token collision";
            return false;
        }
        nodeBindings.push_back(handle);
    }

    try {
        initialValue.binding = handle;
        initialValue.declaredType = declaredType;
        initialValue.value = port->GetValue();
    } catch (const std::exception& exception) {
        std::string ignored;
        UnbindDataOutput(handle, ignored);
        error = std::string("failed to read SKALD data output '") +
                std::string(outputName) + "': " + exception.what();
        return false;
    } catch (...) {
        std::string ignored;
        UnbindDataOutput(handle, ignored);
        error = "unknown native exception while reading SKALD data output '" +
                std::string(outputName) + "'";
        return false;
    }

    bindingHandle = handle;
    return true;
}

bool SkaldRuntime::UnbindDataOutput(
    Handle bindingHandle, std::string& error)
{
    std::lock_guard lock(m_mutex);
    const auto entry = m_dataBindings.find(bindingHandle);
    if (entry == m_dataBindings.end()) {
        error = "unknown or stale SKALD data-output binding";
        return false;
    }

    if (const auto nodeEntry = m_nodes.find(entry->second.node);
        nodeEntry != m_nodes.end()) {
        EraseValue(nodeEntry->second.dataBindings, bindingHandle);
    }
    m_dataBindings.erase(entry);

    for (TriggerCapture& event : m_eventQueue) {
        event.updates.erase(
            std::remove_if(event.updates.begin(), event.updates.end(),
                           [bindingHandle](const OutputUpdate& update) {
                               return update.binding == bindingHandle;
                           }),
            event.updates.end());
    }
    return true;
}

bool SkaldRuntime::Disconnect(
    Handle connectionHandle, std::string& error)
{
    HSCRIPTFUNCTION callback = nullptr;
    Offsets::IScriptSystem* scriptSystem = nullptr;
    {
        std::lock_guard lock(m_mutex);
        const auto entry = m_triggerConnections.find(connectionHandle);
        if (entry == m_triggerConnections.end()) {
            error = "unknown or stale SKALD trigger-output connection";
            return false;
        }

        const TriggerConnectionRecord record = entry->second;
        callback = record.callback;
        scriptSystem = m_scriptSystem;
        if (const auto nodeEntry = m_nodes.find(record.node);
            nodeEntry != m_nodes.end()) {
            EraseValue(nodeEntry->second.triggerConnections,
                       connectionHandle);
        }

        auto* activePort = static_cast<wh::conceptmodule::C_ActiveTriggerPort*>(
            record.port.get());
        if (const auto route = m_triggerRoutes.find(activePort);
            route != m_triggerRoutes.end()) {
            EraseValue(route->second, connectionHandle);
            if (route->second.empty())
                m_triggerRoutes.erase(route);
        }
        m_triggerConnections.erase(entry);

        for (TriggerCapture& event : m_eventQueue)
            EraseValue(event.connections, connectionHandle);
        m_eventQueue.erase(
            std::remove_if(m_eventQueue.begin(), m_eventQueue.end(),
                           [](const TriggerCapture& event) {
                               return event.connections.empty();
                           }),
            m_eventQueue.end());
    }

    if (scriptSystem && callback)
        scriptSystem->ReleaseFunc(callback);
    return true;
}

bool SkaldRuntime::TriggerInput(
    Handle nodeHandle, std::string_view triggerName,
    std::vector<OutputUpdate>& updates, std::string& error)
{
    updates.clear();

    _smart_ptr<wh::conceptmodule::C_Node> node;
    {
        std::lock_guard lock(m_mutex);
        const auto entry = m_nodes.find(nodeHandle);
        if (entry == m_nodes.end()) {
            error = "unknown or stale SKALD node handle";
            return false;
        }
        node = entry->second.node;
    }

    const std::string triggerNameText(triggerName);
    const CryStringT<char> name(triggerNameText.c_str());
    // GetOrCreatePort (0x180699630): materializes from I_PortDefinition if the pin was never wired.
    _smart_ptr<wh::conceptmodule::I_Port> port =
        node->GetOrCreatePort(name);
    if (!port ||
        port->GetDirection() != wh::conceptmodule::E_PortDirection::In ||
        port->GetSpecification() !=
            wh::conceptmodule::E_PortSpecification::InputTriggerPort) {
        error = "native SKALD input trigger '" +
                std::string(triggerName) + "' is unavailable";
        return false;
    }

    try {
        port->Trigger();
        updates = SnapshotBindings(CollectBindingSources(nodeHandle));
    } catch (const std::exception& exception) {
        error = std::string("native SKALD trigger failed: ") +
                exception.what();
        return false;
    } catch (...) {
        error = "unknown native exception during SKALD trigger";
        return false;
    }

    // The trigger hook only ENQUEUES output events: it runs while the native
    // fan-out is still on the stack, where a Lua callback could Destroy() the
    // very node whose OnExecute frame is executing beneath it. Here that
    // cascade has fully unwound, so deliver this pulse's events before
    // returning to the caller's chunk instead of leaving them for the next
    // frame's tick (which also made a same-chunk Destroy() silently drop
    // them). Externally-originated fires still deliver via the tick.
    DeliverQueuedEvents();
    return true;
}

void SkaldRuntime::QueueDestroy(Handle nodeHandle) noexcept
{
    // Called from Lua __gc finalizers, which fire at arbitrary allocation
    // points inside the VM -- teardown here would reenter the runtime
    // mid-operation (the non-recursive mutex deadlocks, and node teardown
    // mid-port-walk is the measured UAF class). Only enqueue; the actual
    // DestroyNode runs at the next DeliverQueuedEvents drain point.
    // Handles are monotonic (Clear never resets m_nextHandle), so a stale
    // entry can only fail lookup, never hit a recycled node.
    if (!nodeHandle)
        return;
    try {
        std::lock_guard lock(m_mutex);
        m_destroyQueue.push_back(nodeHandle);
    } catch (...) {
    }
}

bool SkaldRuntime::SetActivation(
    Handle nodeHandle, bool active,
    std::vector<OutputUpdate>& updates, std::string& error)
{
    updates.clear();

    _smart_ptr<wh::conceptmodule::C_Node> node;
    {
        std::lock_guard lock(m_mutex);
        const auto entry = m_nodes.find(nodeHandle);
        if (entry == m_nodes.end()) {
            error = "unknown or stale SKALD node handle";
            return false;
        }
        node = entry->second.node;
    }

    // wake_pulse nodes are certified C_Effect-derived and the Lua generator
    // only ever emits Activate/Deactivate for them, but SKALD is a global Lua
    // table -- nothing stops a script calling raw_skald.SetActivation on any
    // node handle directly, so the cast is verified against the game's own
    // RTTI rather than trusted blindly.
    auto* effect = kcd_cast<wh::conceptmodule::C_Effect*>(node.get());
    if (!effect) {
        error = "native SKALD node is not a C_Effect and cannot be activated";
        return false;
    }

    // m_lastActiveState is the same edge-detect cache C_Effect::OnExecute
    // itself uses, kept consistent with it rather than tracked separately.
    try {
        if (active != effect->m_lastActiveState) {
            effect->m_lastActiveState = active;
            if (active)
                effect->OnEffectActivate();
            else
                effect->OnEffectDeactivate();
        }
        updates = SnapshotBindings(CollectBindingSources(nodeHandle));
    } catch (const std::exception& exception) {
        error = std::string("native SKALD activation failed: ") +
                exception.what();
        return false;
    } catch (...) {
        error = "unknown native exception during SKALD activation";
        return false;
    }

    DeliverQueuedEvents();
    return true;
}

Offsets::IScriptTable* SkaldRuntime::CreateUpdateTable(
    std::vector<OutputUpdate>& updates, std::string& error)
{
    Offsets::IScriptTable* table = nullptr;
    std::vector<RttrHandleRegistry::Handle> createdHandles;
    try {
        if (BuildUpdateTable(updates, table, createdHandles, error))
            return table;
    } catch (const std::exception& exception) {
        error = exception.what();
    } catch (...) {
        error = "unknown native exception while converting SKALD outputs";
    }
    if (table)
        table->Release();
    ReleaseHandles(createdHandles);
    return nullptr;
}

SkaldRuntime::TriggerCapture SkaldRuntime::CaptureOutputTrigger(
    wh::conceptmodule::C_ActiveTriggerPort* port) noexcept
{
    TriggerCapture capture;
    if (!port)
        return capture;

    try {
        std::vector<BindingSource> sources;
        {
            std::lock_guard lock(m_mutex);
            const auto route = m_triggerRoutes.find(port);
            if (route == m_triggerRoutes.end())
                return capture;

            Handle nodeHandle = 0;
            for (Handle connectionHandle : route->second) {
                const auto connection =
                    m_triggerConnections.find(connectionHandle);
                if (connection == m_triggerConnections.end() ||
                    connection->second.port.get() != port)
                    continue;
                if (!nodeHandle)
                    nodeHandle = connection->second.node;
                if (connection->second.node == nodeHandle)
                    capture.connections.push_back(connectionHandle);
            }
            if (!nodeHandle || capture.connections.empty() ||
                m_nodes.find(nodeHandle) == m_nodes.end()) {
                capture.connections.clear();
                return capture;
            }

            capture.generation = m_generation;
            capture.sequence = m_nextEventSequence++;
            if (!capture.sequence) {
                m_nextEventSequence = 0;
                capture = TriggerCapture{};
                ++m_droppedEvents;
                return capture;
            }
            capture.node = nodeHandle;

            const NodeRecord& node = m_nodes.at(nodeHandle);
            sources.reserve(node.dataBindings.size());
            for (Handle bindingHandle : node.dataBindings) {
                const auto binding = m_dataBindings.find(bindingHandle);
                if (binding == m_dataBindings.end() ||
                    binding->second.node != nodeHandle)
                    continue;
                sources.push_back(BindingSource{
                    bindingHandle, binding->second.port,
                    binding->second.declaredType });
            }
        }
        capture.updates = SnapshotBindings(sources);
    } catch (...) {
        Log("[LuaUtils] failed to snapshot a native SKALD output event");
        return TriggerCapture{};
    }
    return capture;
}

void SkaldRuntime::EnqueueOutputTrigger(
    TriggerCapture&& capture) noexcept
{
    if (!capture)
        return;

    try {
        std::lock_guard lock(m_mutex);
        if (capture.generation != m_generation ||
            m_nodes.find(capture.node) == m_nodes.end())
            return;

        capture.connections.erase(
            std::remove_if(
                capture.connections.begin(), capture.connections.end(),
                [this, &capture](Handle connectionHandle) {
                    const auto entry =
                        m_triggerConnections.find(connectionHandle);
                    return entry == m_triggerConnections.end() ||
                           entry->second.node != capture.node;
                }),
            capture.connections.end());
        if (capture.connections.empty())
            return;

        if (m_eventQueue.size() >= kMaxQueuedEvents) {
            ++m_droppedEvents;
            return;
        }
        m_eventQueue.push_back(std::move(capture));
    } catch (...) {
        std::lock_guard lock(m_mutex);
        ++m_droppedEvents;
    }
}

void SkaldRuntime::DeliverQueuedEvents() noexcept
{
    std::deque<TriggerCapture> events;
    std::vector<Handle> destroys;
    std::size_t dropped = 0;
    {
        std::lock_guard lock(m_mutex);
        events.swap(m_eventQueue);
        destroys.swap(m_destroyQueue);
        dropped = std::exchange(m_droppedEvents, 0);
    }

    // GC-queued node destroys drain first: a collected wrapper's node dies
    // before its (now unreachable) events would deliver, and DestroyNode's
    // own record removal makes those events drop naturally below.
    for (const Handle nodeHandle : destroys) {
        std::string ignored;
        try {
            DestroyNode(nodeHandle, ignored);
        } catch (...) {
        }
    }

    if (dropped) {
        Log("[LuaUtils] dropped %zu SKALD output event(s); queue capacity is %zu",
            dropped, kMaxQueuedEvents);
    }
    if (events.empty())
        return;

    std::sort(events.begin(), events.end(),
              [](const TriggerCapture& left,
                 const TriggerCapture& right) {
                  return left.sequence < right.sequence;
              });

    for (TriggerCapture& event : events) {
        Offsets::IScriptSystem* scriptSystem = nullptr;
        HSCRIPTFUNCTION dispatcher = nullptr;
        {
            std::lock_guard lock(m_mutex);
            if (event.generation != m_generation ||
                m_nodes.find(event.node) == m_nodes.end())
                continue;

            event.updates.erase(
                std::remove_if(
                    event.updates.begin(), event.updates.end(),
                    [this, &event](const OutputUpdate& update) {
                        const auto binding =
                            m_dataBindings.find(update.binding);
                        return binding == m_dataBindings.end() ||
                               binding->second.node != event.node;
                    }),
                event.updates.end());
            event.connections.erase(
                std::remove_if(
                    event.connections.begin(), event.connections.end(),
                    [this, &event](Handle connectionHandle) {
                        const auto connection =
                            m_triggerConnections.find(connectionHandle);
                        return connection == m_triggerConnections.end() ||
                               connection->second.node != event.node;
                    }),
                event.connections.end());
            if (event.connections.empty())
                continue;

            scriptSystem = m_scriptSystem;
            dispatcher = m_updateDispatcher;
        }
        if (!scriptSystem)
            continue;

        if (!event.updates.empty()) {
            if (!dispatcher) {
                Log("[LuaUtils] discarded a SKALD output event because the update dispatcher is unavailable");
                continue;
            }

            Offsets::IScriptTable* table = nullptr;
            std::vector<RttrHandleRegistry::Handle> createdHandles;
            std::string error;
            bool converted = false;
            try {
                converted = BuildUpdateTable(event.updates, table,
                                             createdHandles, error);
            } catch (const std::exception& exception) {
                error = exception.what();
            } catch (...) {
                error = "unknown native exception";
            }
            if (!converted || !table) {
                if (table)
                    table->Release();
                ReleaseHandles(createdHandles);
                Log("[LuaUtils] failed to convert SKALD output updates: %s",
                    error.empty() ? "unknown error" : error.c_str());
                continue;
            }

            bool delivered = false;
            if (scriptSystem->BeginCall(dispatcher)) {
                scriptSystem->PushFuncParamAny(ScriptAnyValue(table));
                delivered = scriptSystem->EndCall();
            }
            table->Release();
            if (!delivered) {
                ReleaseHandles(createdHandles);
                Log("[LuaUtils] generated SKALD update dispatcher failed");
                continue;
            }
        }

        for (Handle connectionHandle : event.connections) {
            HSCRIPTFUNCTION callback = nullptr;
            {
                std::lock_guard lock(m_mutex);
                if (event.generation != m_generation)
                    break;
                const auto connection =
                    m_triggerConnections.find(connectionHandle);
                if (connection == m_triggerConnections.end() ||
                    connection->second.node != event.node)
                    continue;
                callback = connection->second.callback;
            }
            if (callback && scriptSystem->BeginCall(callback))
                scriptSystem->EndCall();
        }
    }
}

void SkaldRuntime::InvalidateLuaOutputs() noexcept
{
    Offsets::IScriptSystem* scriptSystem = nullptr;
    HSCRIPTFUNCTION dispatcher = nullptr;
    bool delivered = false;
    try {
        {
            std::lock_guard lock(m_mutex);
            if (!m_scriptSystem || !m_updateDispatcher)
                return;
            scriptSystem = m_scriptSystem;
            dispatcher = scriptSystem->AddFuncRef(m_updateDispatcher);
        }

        if (dispatcher && scriptSystem->BeginCall(dispatcher)) {
            scriptSystem->PushFuncParamAny(ScriptAnyValue(false));
            delivered = scriptSystem->EndCall();
        }
    } catch (...) {
        delivered = false;
    }

    if (scriptSystem && dispatcher)
        scriptSystem->ReleaseFunc(dispatcher);
    if (!delivered)
        Log("[LuaUtils] generated SKALD lifecycle invalidator failed");
}

void SkaldRuntime::Clear() noexcept
{
    std::vector<NodeRecord> records;
    std::vector<HSCRIPTFUNCTION> callbacks;
    Offsets::IScriptSystem* scriptSystem = nullptr;
    {
        std::lock_guard lock(m_mutex);
        records.reserve(m_nodes.size());
        for (auto& [handle, record] : m_nodes) {
            (void)handle;
            records.push_back(std::move(record));
        }
        callbacks.reserve(m_triggerConnections.size());
        for (const auto& [handle, connection] : m_triggerConnections) {
            (void)handle;
            if (connection.callback)
                callbacks.push_back(connection.callback);
        }
        scriptSystem = m_scriptSystem;

        m_nodes.clear();
        m_dataBindings.clear();
        m_triggerConnections.clear();
        m_triggerRoutes.clear();
        m_eventQueue.clear();
        m_destroyQueue.clear();
        m_droppedEvents = 0;
        ++m_generation;
        if (!m_generation)
            m_generation = 1;
    }

    if (scriptSystem) {
        for (HSCRIPTFUNCTION callback : callbacks)
            scriptSystem->ReleaseFunc(callback);
    }
    for (const NodeRecord& record : records)
        m_rttrRuntime.Registry().Release(record.rttrHandle);
    m_host.Clear();
}

wh::conceptmodule::C_Node* SkaldRuntime::GetNode(
    Handle nodeHandle) const noexcept
{
    std::lock_guard lock(m_mutex);
    const auto entry = m_nodes.find(nodeHandle);
    return entry == m_nodes.end() ? nullptr : entry->second.node.get();
}

bool SkaldRuntime::SerializeConstant(
    const rttr::type& valueType,
    const rttr::variant& value,
    std::string& literal,
    std::string& error)
{
    const rttr::string_view name = valueType.get_name();
    const std::string_view typeName(name.data(), name.size());

    if (typeName == "bool") {
        bool result = false;
        void* source = value.get_value();
        if (!source) {
            error = "converted SKALD bool input has no value";
            return false;
        }
        std::memcpy(&result, source, sizeof(result));
        literal = result ? "true" : "false";
        return true;
    }
    if (typeName == "int") {
        int result = 0;
        void* source = value.get_value();
        if (!source) {
            error = "converted SKALD int input has no value";
            return false;
        }
        std::memcpy(&result, source, sizeof(result));
        literal = std::to_string(result);
        return true;
    }

    error = "SKALD constant serialization is not certified for type '" +
            std::string(typeName) + "'";
    return false;
}

bool SkaldRuntime::AllocateHandle(
    Handle& handle, std::string& error) noexcept
{
    if (!m_nextHandle) {
        error = "SKALD handle space exhausted";
        handle = 0;
        return false;
    }
    handle = m_nextHandle;
    m_nextHandle = handle == std::numeric_limits<Handle>::max()
        ? 0
        : handle + 1;
    return true;
}

bool SkaldRuntime::FindOutputPort(
    Handle nodeHandle, std::string_view outputName,
    bool expectTrigger,
    _smart_ptr<wh::conceptmodule::I_Port>& port,
    rttr::type& declaredType,
    std::string& error) const
{
    port.reset();
    declaredType = rttr::type();

    _smart_ptr<wh::conceptmodule::C_Node> node;
    {
        std::lock_guard lock(m_mutex);
        const auto entry = m_nodes.find(nodeHandle);
        if (entry == m_nodes.end()) {
            error = "unknown or stale SKALD node handle";
            return false;
        }
        node = entry->second.node;
    }

    const std::string outputNameText(outputName);
    const CryStringT<char> name(outputNameText.c_str());
    port = node->GetOrCreatePort(name);
    if (!port ||
        port->GetDirection() != wh::conceptmodule::E_PortDirection::Out) {
        error = "unknown SKALD output '" + outputNameText + "'";
        port.reset();
        return false;
    }

    const wh::conceptmodule::E_PortSpecification expectedSpecification =
        expectTrigger
            ? wh::conceptmodule::E_PortSpecification::OutputTriggerPort
            : wh::conceptmodule::E_PortSpecification::OutputDataPort;
    if (port->GetSpecification() != expectedSpecification) {
        error = "SKALD output '" + outputNameText +
                "' has the wrong port kind";
        port.reset();
        return false;
    }

    if (auto definition = port->m_definition.lock())
        declaredType = definition->GetValueType();
    return true;
}

std::vector<SkaldRuntime::BindingSource>
SkaldRuntime::CollectBindingSources(Handle nodeHandle) const
{
    std::vector<BindingSource> sources;
    std::lock_guard lock(m_mutex);
    const auto nodeEntry = m_nodes.find(nodeHandle);
    if (nodeEntry == m_nodes.end())
        return sources;

    sources.reserve(nodeEntry->second.dataBindings.size());
    for (Handle bindingHandle : nodeEntry->second.dataBindings) {
        const auto binding = m_dataBindings.find(bindingHandle);
        if (binding == m_dataBindings.end() ||
            binding->second.node != nodeHandle)
            continue;
        sources.push_back(BindingSource{
            bindingHandle, binding->second.port,
            binding->second.declaredType });
    }
    return sources;
}

std::vector<SkaldRuntime::OutputUpdate>
SkaldRuntime::SnapshotBindings(
    const std::vector<BindingSource>& sources)
{
    std::vector<OutputUpdate> updates;
    updates.reserve(sources.size());
    for (const BindingSource& source : sources) {
        OutputUpdate update;
        update.binding = source.binding;
        update.declaredType = source.declaredType;
        try {
            update.value = source.port->GetValue();
        } catch (...) {
            update.value = rttr::variant{};
        }
        updates.push_back(std::move(update));
    }
    return updates;
}

bool SkaldRuntime::BuildUpdateTable(
    std::vector<OutputUpdate>& updates,
    Offsets::IScriptTable*& table,
    std::vector<RttrHandleRegistry::Handle>& createdHandles,
    std::string& error)
{
    Offsets::IScriptSystem* scriptSystem = nullptr;
    {
        std::lock_guard lock(m_mutex);
        scriptSystem = m_scriptSystem;
    }
    if (!scriptSystem) {
        error = "SKALD script system is not initialized";
        return false;
    }

    createdHandles.reserve(createdHandles.size() + updates.size());
    table = scriptSystem->CreateTable(0, 0);
    if (!table) {
        error = "could not create SKALD output update table";
        return false;
    }

    int index = 1;
    for (OutputUpdate& update : updates) {
        Offsets::IScriptTable* entry = scriptSystem->CreateTable(0, 0);
        if (!entry) {
            error = "could not create SKALD output update entry";
            return false;
        }
        entry->SetValueAny("binding", HandleValue(update.binding));

        ScriptAnyValue value = NilValue();
        std::string stringStorage;
        const rttr::type effectiveType =
            EffectiveResultType(update.declaredType, update.value);
        if (update.value.is_valid() &&
            !m_rttrRuntime.Converter().ConvertResult(
                std::move(update.value), effectiveType, value,
                stringStorage, error)) {
            entry->Release();
            return false;
        }
        if (CreatesRegistryHandle(effectiveType, value)) {
            createdHandles.push_back(
                static_cast<RttrHandleRegistry::Handle>(value.nHandle));
        }
        entry->SetValueAny("value", value);
        table->SetAtAny(index++, ScriptAnyValue(entry));
        entry->Release();
    }
    return true;
}

void SkaldRuntime::ReleaseHandles(
    const std::vector<RttrHandleRegistry::Handle>& handles) noexcept
{
    for (RttrHandleRegistry::Handle handle : handles)
        m_rttrRuntime.Registry().Release(handle);
}

void SkaldRuntime::RemoveNodeRecordsLocked(
    Handle nodeHandle, std::vector<HSCRIPTFUNCTION>& callbacks)
{
    const auto nodeEntry = m_nodes.find(nodeHandle);
    if (nodeEntry == m_nodes.end())
        return;

    for (Handle connectionHandle : nodeEntry->second.triggerConnections) {
        const auto connection =
            m_triggerConnections.find(connectionHandle);
        if (connection == m_triggerConnections.end())
            continue;
        if (connection->second.callback)
            callbacks.push_back(connection->second.callback);
        auto* activePort = static_cast<wh::conceptmodule::C_ActiveTriggerPort*>(
            connection->second.port.get());
        if (const auto route = m_triggerRoutes.find(activePort);
            route != m_triggerRoutes.end()) {
            EraseValue(route->second, connectionHandle);
            if (route->second.empty())
                m_triggerRoutes.erase(route);
        }
        m_triggerConnections.erase(connection);
    }
    for (Handle bindingHandle : nodeEntry->second.dataBindings)
        m_dataBindings.erase(bindingHandle);

    m_eventQueue.erase(
        std::remove_if(m_eventQueue.begin(), m_eventQueue.end(),
                       [nodeHandle](const TriggerCapture& event) {
                           return event.node == nodeHandle;
                       }),
        m_eventQueue.end());
    m_nodes.erase(nodeEntry);
}

void SkaldRuntime::Log(const char* format, ...) const noexcept
{
    auto* environment = SSystemGlobalEnvironment::GetInstance();
    if (!environment || !environment->pLog)
        return;

    va_list arguments;
    va_start(arguments, format);
    environment->pLog->LogV(
        Offsets::ELogType::eAlways, format, arguments);
    va_end(arguments);
}

void SkaldRuntime::Shutdown() noexcept
{
    Clear();

    Offsets::IScriptSystem* scriptSystem = nullptr;
    HSCRIPTFUNCTION dispatcher = nullptr;
    {
        std::lock_guard lock(m_mutex);
        scriptSystem = m_scriptSystem;
        dispatcher = m_updateDispatcher;
        m_scriptSystem = nullptr;
        m_updateDispatcher = nullptr;
    }
    if (scriptSystem && dispatcher)
        scriptSystem->ReleaseFunc(dispatcher);
}

}  // namespace luautils::skald
