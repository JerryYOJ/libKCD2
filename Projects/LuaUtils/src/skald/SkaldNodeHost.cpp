#include "skald/SkaldNodeHost.h"

#include <algorithm>
#include <cstdint>
#include <utility>

#include "REL.h"
#include "conceptmodule/C_ConstantPort.h"
#include "conceptmodule/C_ModuleBase.h"
#include "conceptmodule/C_TemplatedNode.h"
#include "conceptmodule/E_PortDirection.h"
#include "conceptmodule/I_Port.h"
#include "crysystem/SSystemGlobalEnvironment.h"
#include "rttr/instance.h"
#include "rttr/type.h"

namespace luautils::skald {
namespace {

// Builds a private single-tag XML document and hands it to the factory --
// the same construction path the real deserializer uses per node/module,
// just with a synthetic one-element document instead of an authored graph.
bool CreateXmlTaggedNode(
    wh::conceptmodule::C_ConceptNodeFactory* factory,
    std::string_view tag,
    rttr::variant& value,
    std::string& error)
{
    const std::string tagText(tag);
    const std::string xmlText = "<" + tagText + "/>";
    SSystemGlobalEnvironment* environment =
        SSystemGlobalEnvironment::GetInstance();
    if (!environment || !environment->pSystem) {
        error = "CrySystem is not available for SKALD construction";
        return false;
    }

    XmlNodeRef xml;
    environment->pSystem->LoadXmlFromBuffer(
        &xml.m_ptr, xmlText.data(),
        static_cast<std::uint64_t>(xmlText.size()), 0, 1);
    if (!xml) {
        error = "failed to parse private SKALD XML for '" + tagText + "'";
        return false;
    }

    wh::conceptmodule::S_NodeCreationCtx context{};
    context.typeName = tagText.c_str();
    bool ok = false;
    bool skipped = false;
    value = factory->Create(context, nullptr, ok, xml, skipped, false);
    if (skipped) {
        error = "native SKALD factory skipped '" + tagText + "'";
        return false;
    }
    if (!ok || !value.is_valid()) {
        error = "native SKALD factory failed to create '" + tagText + "'";
        return false;
    }
    return true;
}

}  // namespace

SkaldNodeHost::~SkaldNodeHost()
{
    Clear();
}

bool SkaldNodeHost::CreateNode(
    std::string_view className,
    std::string_view typeParameter,
    const SkaldPropertyApplier& applier,
    const SkaldPortResolver& resolver,
    const std::vector<SkaldExtraPort>& extraPorts,
    SkaldCreatedNode& result,
    std::string& error)
{
    result.value = rttr::variant{};
    result.node = nullptr;

    if (!EnsureHost(error))
        return false;

    rttr::variant value;
    wh::conceptmodule::C_Node* node = nullptr;
    if (!CreateFactoryNode(className, value, node, error))
        return false;

    // NOTE: do NOT try to tear the node down on the failure paths below by
    // resetting `value`. Releasing a factory-built node here faults instantly
    // (measured): something else still references it at this point. Failed
    // creations are left for the existing scope-exit release.
    if (!ApplyTypeParameter(node, typeParameter, error))
        return false;
    // Config properties must land before port enumeration: they drive the
    // dynamic pin synthesis InstallConstants then walks (GetPortDefinitions
    // reads them live every call, no snapshot).
    if (applier && !applier(node, value, error))
        return false;
    if (!InstallConstants(node, resolver, error))
        return false;
    if (!InstallExtraPorts(node, extraPorts, error))
        return false;

    // NOTE: pre-materializing all definition-listed ports here (so
    // ActivateNode's Reset registration walk sees the synthesized Set<X>
    // companions) was tried 2026-08-08 and did NOT make commit pulses reach
    // the C_Effect latch -- source-mapped auto-trigger fires evidently need
    // real graph wiring, not just port existence at registration time.
    // Effect activation goes through SetActivation (OnEffectActivate) only.

    _smart_ptr<wh::conceptmodule::C_Node> child(node);
    wh::conceptmodule::AttachChild(child, m_module);

    const auto attached = std::find_if(
        m_module->m_nodes.begin(), m_module->m_nodes.end(),
        [node](const _smart_ptr<wh::conceptmodule::C_Node>& entry) {
            return entry.get() == node;
        });
    if (attached == m_module->m_nodes.end()) {
        error = "native SKALD host did not retain the created node";
        return false;
    }

    ActivateAttachedNode(node, error);

    result.value = std::move(value);
    result.node = node;
    return true;
}

bool SkaldNodeHost::DescribeNode(
    std::string_view className,
    std::string_view typeParameter,
    std::vector<SkaldPortInfo>& ports,
    std::string& error)
{
    ports.clear();

    if (!EnsureHost(error))
        return false;

    rttr::variant value;
    wh::conceptmodule::C_Node* node = nullptr;
    if (!CreateFactoryNode(className, value, node, error))
        return false;
    if (!ApplyTypeParameter(node, typeParameter, error))
        return false;

    node->GetPortDefinitions(
        [&](const std::shared_ptr<wh::conceptmodule::definition::I_PortDefinition>&
                definition) {
            if (!definition)
                return;

            SkaldPortInfo info;
            const CryStringT<char> nativeName = definition->GetName();
            info.name = nativeName.c_str();
            info.direction = definition->GetDirection();

            const rttr::type valueType = definition->GetValueType();
            if (valueType.is_valid())
                info.valueType = std::string(valueType.get_name());
            // The registered trigger type is named "trigger" -- NOT
            // "wh::conceptmodule::S_Trigger", which resolves to nothing.
            info.isTrigger = info.valueType == "trigger";

            ports.push_back(std::move(info));
        });

    return true;
}

void SkaldNodeHost::DestroyNode(wh::conceptmodule::C_Node* node) noexcept
{
    RemoveAttachedNode(node);
}

void SkaldNodeHost::Clear() noexcept
{
    if (m_project) {
        if (m_projectActivated) {
            // Manager's own per-project unload order (0x1813F7428):
            // Hibernate before Detach; both are recursive for
            // C_ModuleBase, so this cascades through the module and every
            // node it holds in one pair of calls.
            wh::conceptmodule::HibernateGraph(
                m_project.get(),
                wh::conceptmodule::E_NodeHibernateReason::GraphUnload);
            m_project->DetachOrDeactivate();
        }
        m_project.reset();
    }
    m_module.reset();
    m_projectActivated = false;
    DestroyFactory();
}

bool SkaldNodeHost::EnsureHost(std::string& error)
{
    if (!m_factory) {
        m_factory = wh::conceptmodule::C_ConceptNodeFactory::Ctor(nullptr);
        if (!m_factory) {
            error = "native SKALD node factory construction failed";
            return false;
        }
    }

    if (!m_project) {
        m_project = wh::conceptmodule::CreateProject("LuaUtils");
        if (!m_project) {
            error = "native SKALD project construction failed";
            return false;
        }
    }

    return CreateModule(error);
}

bool SkaldNodeHost::CreateModule(std::string& error)
{
    if (m_module)
        return true;

    // A generic grouping container (rttr name "wh::conceptmodule::Module",
    // strong registration-site evidence) built through the SAME factory
    // path authored content uses -- this guarantees a non-root parent,
    // which the auto-trigger wiring walk (0x18069467C) requires to wire a
    // node's "OnExec" pin instead of stopping immediately at a root
    // project.
    rttr::variant value;
    if (!CreateXmlTaggedNode(m_factory, "Module", value, error))
        return false;

    const rttr::instance object(value);
    if (!object.m_rawPtr) {
        error = "native SKALD factory returned a null module";
        return false;
    }
    rttr::type rawType = object.m_rawType;
    if (rawType.is_pointer())
        rawType = rawType.get_raw_type();
    const rttr::type moduleType =
        rttr::type::get_by_name("wh::conceptmodule::ModuleBase");
    if (!moduleType.is_valid() ||
        (rawType != moduleType && !rawType.is_derived_from(moduleType))) {
        error = "native SKALD factory result is not a C_ModuleBase";
        return false;
    }

    auto* module =
        static_cast<wh::conceptmodule::C_ModuleBase*>(object.m_rawPtr);
    _smart_ptr<wh::conceptmodule::C_Node> child(module);
    _smart_ptr<wh::conceptmodule::C_ModuleBase> projectAsParent(m_project);
    wh::conceptmodule::AttachChild(child, projectAsParent);

    const auto attached = std::find_if(
        m_project->m_nodes.begin(), m_project->m_nodes.end(),
        [module](const _smart_ptr<wh::conceptmodule::C_Node>& entry) {
            return entry.get() == module;
        });
    if (attached == m_project->m_nodes.end()) {
        error = "native SKALD host did not retain the created module";
        return false;
    }

    m_module = _smart_ptr<wh::conceptmodule::C_ModuleBase>(module);

    // Activate is flag-guarded per object (0x180ACFDB0) and never cascades
    // to a freshly attached child, so project and module each activate
    // themselves explicitly. Reason RuntimeConditionPassed (not GameStart,
    // which the real bootstrap uses and which is numerically 0) is what
    // makes WakeGraph's post-Wake pass actually run PropagateToPorts on the
    // module -- harmless here (a plain C_Module has no C_Effect override),
    // but kept uniform with node activation below.
    m_project->Activate();
    m_project->ActivateNode();
    wh::conceptmodule::WakeGraph(
        m_project.get(),
        wh::conceptmodule::E_NodeWakeReason::RuntimeConditionPassed);
    wh::conceptmodule::StartGraph(m_project.get());
    m_projectActivated = true;

    m_module->Activate();
    m_module->ActivateNode();
    wh::conceptmodule::WakeGraph(
        m_module.get(),
        wh::conceptmodule::E_NodeWakeReason::RuntimeConditionPassed);
    return true;
}

bool SkaldNodeHost::CreateFactoryNode(
    std::string_view className,
    rttr::variant& value,
    wh::conceptmodule::C_Node*& node,
    std::string& error)
{
    node = nullptr;
    if (className.empty()) {
        error = "SKALD node class name is empty";
        return false;
    }

    if (!CreateXmlTaggedNode(m_factory, className, value, error))
        return false;

    const rttr::instance object(value);
    if (!object.m_rawPtr) {
        error = "native SKALD factory returned a null node";
        return false;
    }

    rttr::type rawType = object.m_rawType;
    if (rawType.is_pointer())
        rawType = rawType.get_raw_type();

    const rttr::type nodeType =
        rttr::type::get_by_name("wh::conceptmodule::Node");
    if (!nodeType.is_valid() ||
        (rawType != nodeType && !rawType.is_derived_from(nodeType))) {
        error = "native SKALD factory result for '" + std::string(className) +
                "' is not a C_Node";
        return false;
    }

    node = static_cast<wh::conceptmodule::C_Node*>(object.m_rawPtr);
    return true;
}

bool SkaldNodeHost::ApplyTypeParameter(
    wh::conceptmodule::C_Node* node,
    std::string_view typeParameter,
    std::string& error)
{
    const rttr::type templatedType =
        rttr::type::get_by_name("wh::conceptmodule::TemplatedNode");
    const rttr::type nodeType = node->get_type();
    const bool isTemplated = templatedType.is_valid() &&
        (nodeType == templatedType || nodeType.is_derived_from(templatedType));

    if (!isTemplated) {
        if (!typeParameter.empty()) {
            error = "this SKALD node has no type parameter";
            return false;
        }
        return true;
    }
    if (typeParameter.empty()) {
        error = "missing required SKALD type parameter 'TypeT'";
        return false;
    }

    // The setter resolves the registered type name, stores m_typeT and
    // dispatches OnTypeTSet so dynamic pin definitions exist before the
    // constant-input enumeration below.
    auto* templated = static_cast<wh::conceptmodule::C_TemplatedNode*>(node);
    templated->SetTypeT(std::string(typeParameter));

    const rttr::type applied = templated->m_typeT;
    const rttr::string_view appliedName = applied.get_name();
    if (!applied.is_valid() ||
        std::string_view(appliedName.data(), appliedName.size()) !=
            typeParameter) {
        error = "native SKALD node rejected type parameter '" +
                std::string(typeParameter) + "'";
        return false;
    }
    return true;
}

bool SkaldNodeHost::InstallConstants(
    wh::conceptmodule::C_Node* node,
    const SkaldPortResolver& resolver,
    std::string& error)
{
    const rttr::type triggerType =
        rttr::type::get_by_name("wh::conceptmodule::S_Trigger");

    bool failed = false;
    std::string failureMessage;
    node->GetPortDefinitions(
        [&](const std::shared_ptr<wh::conceptmodule::definition::I_PortDefinition>&
                definition) {
            if (failed || !definition)
                return;

            using wh::conceptmodule::E_PortDirection;
            if (definition->GetDirection() != E_PortDirection::In)
                return;
            const rttr::type valueType = definition->GetValueType();
            if (triggerType.is_valid() && valueType == triggerType)
                return;

            const CryStringT<char> nativeName = definition->GetName();
            const std::string name(nativeName.c_str());

            bool install = false;
            std::string literal;
            rttr::variant object;
            bool isObject = false;
            std::string resolverError;
            if (!resolver(*definition, name, install, literal, object,
                          isObject, resolverError)) {
                failed = true;
                failureMessage = resolverError.empty()
                    ? "SKALD input '" + name + "' was rejected"
                    : resolverError;
                return;
            }
            if (!install)
                return;

            _smart_ptr<wh::conceptmodule::C_ConstantPort> constant =
                wh::conceptmodule::CreateConstantPort(nativeName, literal);
            if (!constant) {
                failed = true;
                failureMessage =
                    "failed to create constant port '" + name + "'";
                return;
            }
            if (isObject) {
                // Handle-backed constants: the literal machinery only
                // carries raw text, so overwrite m_value with the
                // already-typed registry variant. Consumers convert lazily
                // on read exactly as they do for string literals.
                constant->m_value = std::move(object);
            }

            _smart_ptr<wh::conceptmodule::I_Port> port(constant);
            const bool added = node->AddPort(port);
            if (!added) {
                failed = true;
                failureMessage =
                    "failed to install constant port '" + name + "'";
            }
        });

    if (failed) {
        error = failureMessage;
        return false;
    }
    return true;
}

// Variadic pins: installed by name with no matching port definition, the way
// authored XML declares MakeArray's <Constant Name="A"/><Constant Name="B"/>
// value list. Callers pass them pre-sorted -- MakeArray builds its Array output
// by walking C_Node::m_ports positionally (GetPortValue 0x1806A98B8 + append
// 0x181E327E0), so insertion order IS element order.
bool SkaldNodeHost::InstallExtraPorts(
    wh::conceptmodule::C_Node* node,
    const std::vector<SkaldExtraPort>& extraPorts,
    std::string& error)
{
    for (const SkaldExtraPort& extra : extraPorts) {
        const CryStringT<char> nativeName(extra.name.c_str());
        _smart_ptr<wh::conceptmodule::C_ConstantPort> constant =
            wh::conceptmodule::CreateConstantPort(nativeName, extra.literal);
        if (!constant) {
            error = "failed to create variadic port '" + extra.name + "'";
            return false;
        }
        if (extra.isObject)
            constant->m_value = extra.object;

        _smart_ptr<wh::conceptmodule::I_Port> port(constant);
        // AddPort only fails on a duplicate name (0x180697390); an undeclared
        // name binds to a null definition and installs.
        if (!node->AddPort(port)) {
            error = "failed to install variadic port '" + extra.name +
                    "' (duplicate name?)";
            return false;
        }
    }
    return true;
}

void SkaldNodeHost::ActivateAttachedNode(
    wh::conceptmodule::C_Node* node,
    std::string& error)
{
    (void)error;
    node->Activate();

    // Deserialization-complete init: the loader delivers lifecycle event 5
    // before waking the graph ([36] never suppresses it while Hibernating),
    // and node types apply their DefaultValue pins there (C_StateVariable
    // OnLifecycleEvent [34] 0x1806B0CA8). Pairing the event with the node's
    // own MapEventToPhase result reproduces the loader's phase match
    // (DispatchLifecycleEvent's own gate, 0x1806B0AFC, requires exactly
    // this pairing to deliver).
    node->DispatchLifecycleEvent(5, node->MapEventToPhase(5));

    node->ActivateNode();

    // WakeGraph's post-Wake pass calls PropagateToPorts(reason) [40] on
    // every node that transitions Hibernating->Awake; GameStart(0) is
    // reason 0, so PropagateToPorts never runs for it (matches the real
    // bootstrap: authored initial-load content arms via StartGraph/OnWake
    // instead). RuntimeConditionPassed is nonzero, so C_Effect's override
    // (0x1813E804C) runs its Trigger-sweep and arms the node -- for
    // non-effect leaves PropagateToPorts stays the base nullsub, so this is
    // uniformly safe.
    wh::conceptmodule::WakeGraph(
        node, wh::conceptmodule::E_NodeWakeReason::RuntimeConditionPassed);
}

void SkaldNodeHost::RemoveAttachedNode(
    wh::conceptmodule::C_Node* node) noexcept
{
    if (!node || !m_module)
        return;

    const auto found = std::find_if(
        m_module->m_nodes.begin(), m_module->m_nodes.end(),
        [node](const _smart_ptr<wh::conceptmodule::C_Node>& entry) {
            return entry.get() == node;
        });
    if (found == m_module->m_nodes.end())
        return;

    _smart_ptr<wh::conceptmodule::C_Node> child(node);
    if (m_projectActivated) {
        // Manager's own per-object unload order (0x1813F7428): Hibernate
        // before Detach.
        wh::conceptmodule::HibernateGraph(
            node, wh::conceptmodule::E_NodeHibernateReason::GraphUnload);
        node->DetachOrDeactivate();
    }
    wh::conceptmodule::EraseChild(m_module->m_nodes, child);

    _smart_ptr<wh::conceptmodule::C_ModuleBase> noParent;
    wh::conceptmodule::SetParent(node, noParent);
}

void SkaldNodeHost::DestroyFactory() noexcept
{
    wh::conceptmodule::C_ConceptNodeFactory::Dtor(m_factory);
    m_factory = nullptr;
}

}  // namespace luautils::skald
