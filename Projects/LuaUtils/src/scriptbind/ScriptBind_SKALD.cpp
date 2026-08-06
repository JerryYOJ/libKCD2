#include "scriptbind/ScriptBind_SKALD.h"

#include <exception>
#include <string>
#include <utility>
#include <vector>

#include "LuaHelpers.h"
#include "Offsets/vtables/IFunctionHandler.h"
#include "Offsets/vtables/IScriptSystem.h"
#include "Offsets/vtables/IScriptTable.h"

namespace luautils {
namespace {

ScriptAnyValue NilValue()
{
    ScriptAnyValue value;
    value.type = ANY_TNIL;
    value.nHandle = 0;
    return value;
}

int ReturnError(Offsets::IFunctionHandler* handler,
                const std::string& error)
{
    const char* message = error.empty()
        ? "SKALD operation failed"
        : error.c_str();
    return handler->EndFunctionAny2(
        NilValue(), ScriptAnyValue(message));
}

int ReturnTrue(Offsets::IFunctionHandler* handler)
{
    return handler->EndFunctionAny(ScriptAnyValue(true));
}

const char* DirectionName(wh::conceptmodule::E_PortDirection direction)
{
    switch (direction) {
    case wh::conceptmodule::E_PortDirection::In:  return "In";
    case wh::conceptmodule::E_PortDirection::Out: return "Out";
    case wh::conceptmodule::E_PortDirection::Bi:  return "Bi";
    default:                                     return "None";
    }
}

template <class Callback>
int Safely(Offsets::IFunctionHandler* handler, Callback&& callback)
{
    try {
        return callback();
    } catch (const std::exception& exception) {
        return ReturnError(handler, exception.what());
    } catch (...) {
        return ReturnError(
            handler, "unknown native exception during SKALD operation");
    }
}

bool RequireParamCount(Offsets::IFunctionHandler* handler,
                       int expected, std::string& error)
{
    const int count = handler->GetParamCount();
    if (count < expected) {
        error = "missing required argument";
        return false;
    }
    if (count > expected) {
        error = "too many arguments";
        return false;
    }
    return true;
}

bool ReadStringParam(Offsets::IFunctionHandler* handler, int index,
                     std::string& value, std::string& error)
{
    ScriptAnyValue any;
    any.type = ANY_TSTRING;
    any.str = nullptr;
    if (!handler->GetParamAny(index, any)) {
        error = "could not read string argument";
        return false;
    }
    if (!any.str) {
        error = "string argument must not be null";
        return false;
    }
    value = any.str;
    return true;
}

bool ReadHandleParam(Offsets::IFunctionHandler* handler, int index,
                     skald::SkaldRuntime::Handle& value,
                     std::string& error)
{
    ScriptAnyValue any;
    any.type = ANY_THANDLE;
    any.nHandle = 0;
    if (!handler->GetParamAny(index, any)) {
        error = "could not read SKALD handle argument";
        return false;
    }
    if (!any.nHandle) {
        error = "SKALD handle must be nonzero";
        return false;
    }
    value = static_cast<skald::SkaldRuntime::Handle>(any.nHandle);
    return true;
}

bool ReadBoolParam(Offsets::IFunctionHandler* handler, int index,
                   bool& value, std::string& error)
{
    ScriptAnyValue any;
    any.type = ANY_TBOOLEAN;
    any.b = false;
    if (!handler->GetParamAny(index, any)) {
        error = "argument must be a boolean";
        return false;
    }
    value = any.b;
    return true;
}

bool ReadTableParam(Offsets::IFunctionHandler* handler, int index,
                    ScriptAnyValue& value, std::string& error)
{
    value.type = ANY_TTABLE;
    value.table = nullptr;
    if (!handler->GetParamAny(index, value) || !value.table) {
        error = "argument must be a table";
        return false;
    }
    return true;
}

bool ReadFunctionParam(Offsets::IFunctionHandler* handler, int index,
                       HSCRIPTFUNCTION& value, std::string& error)
{
    ScriptAnyValue any;
    any.type = ANY_TFUNCTION;
    any.function = nullptr;
    if (!handler->GetParamAny(index, any) || !any.function) {
        error = "argument must be a function";
        return false;
    }
    value = any.function;
    return true;
}

class ScriptAnyRefGuard
{
public:
    ScriptAnyRefGuard(Offsets::IScriptSystem* scriptSystem,
                      const ScriptAnyValue& value) noexcept
        : m_scriptSystem(scriptSystem), m_value(value)
    {}

    ~ScriptAnyRefGuard()
    {
        if (m_scriptSystem)
            m_scriptSystem->ReleaseAny(m_value);
    }

private:
    Offsets::IScriptSystem* m_scriptSystem;
    const ScriptAnyValue& m_value;
};

class FunctionRefGuard
{
public:
    FunctionRefGuard(Offsets::IScriptSystem* scriptSystem,
                     HSCRIPTFUNCTION function) noexcept
        : m_scriptSystem(scriptSystem), m_function(function)
    {}

    ~FunctionRefGuard()
    {
        if (m_scriptSystem && m_function)
            m_scriptSystem->ReleaseFunc(m_function);
    }

    void Release() noexcept { m_function = nullptr; }

private:
    Offsets::IScriptSystem* m_scriptSystem;
    HSCRIPTFUNCTION m_function;
};

}  // namespace

CScriptBind_SKALD::CScriptBind_SKALD(
    skald::SkaldRuntime& runtime) noexcept
    : m_runtime(runtime)
{}

void CScriptBind_SKALD::Init(Offsets::IScriptSystem* scriptSystem)
{
    if (!scriptSystem || m_pMethodsTable)
        return;

    m_pSS = scriptSystem;
    m_runtime.SetScriptSystem(scriptSystem);
    m_pMethodsTable = scriptSystem->CreateTable(0, 0);
    if (!m_pMethodsTable)
        return;
    m_pMethodsTable->AddRef();

    RegisterFunction("CreateNode", "cppType, arguments",
                     functor(*this, &CScriptBind_SKALD::CreateNode));
    RegisterFunction("GetPortDefinitions", "cppType, typeParameter",
                     functor(*this, &CScriptBind_SKALD::GetPortDefinitions));
    RegisterFunction("DestroyNode", "nodeHandle",
                     functor(*this, &CScriptBind_SKALD::DestroyNode));
    RegisterFunction("BindTriggerOutput", "nodeHandle, outputName, callback",
                     functor(*this, &CScriptBind_SKALD::BindTriggerOutput));
    RegisterFunction("BindDataOutput", "nodeHandle, outputName",
                     functor(*this, &CScriptBind_SKALD::BindDataOutput));
    RegisterFunction("UnbindDataOutput", "bindingHandle",
                     functor(*this, &CScriptBind_SKALD::UnbindDataOutput));
    RegisterFunction("Disconnect", "connectionHandle",
                     functor(*this, &CScriptBind_SKALD::Disconnect));
    RegisterFunction("TriggerInput", "nodeHandle, triggerName",
                     functor(*this, &CScriptBind_SKALD::TriggerInput));
    RegisterFunction("QueueDestroy", "nodeHandle",
                     functor(*this, &CScriptBind_SKALD::QueueDestroy));
    RegisterFunction("SetActivation", "nodeHandle, active",
                     functor(*this, &CScriptBind_SKALD::SetActivation));
    RegisterFunction("SetUpdateDispatcher", "dispatcher",
                     functor(*this, &CScriptBind_SKALD::SetUpdateDispatcher));

    scriptSystem->SetGlobalAny("SKALD", ScriptAnyValue(m_pMethodsTable));
}

void CScriptBind_SKALD::RegisterFunction(
    const char* name, const char* params,
    const FunctionFunctor& function)
{
    SUserFunctionDesc descriptor;
    descriptor.sGlobalName = "SKALD";
    descriptor.sFunctionName = name;
    descriptor.sFunctionParams = params;
    descriptor.pFunctor = function;
    m_pMethodsTable->AddFunction(descriptor);
}

int CScriptBind_SKALD::CreateNode(
    Offsets::IFunctionHandler* handler)
{
    return Safely(handler, [&]() {
        std::string error;
        std::string cppType;
        if (!RequireParamCount(handler, 2, error) ||
            !ReadStringParam(handler, 1, cppType, error))
            return ReturnError(handler, error);

        ScriptAnyValue arguments;
        if (!ReadTableParam(handler, 2, arguments, error))
            return ReturnError(handler, error);
        ScriptAnyRefGuard argumentsGuard(m_pSS, arguments);

        skald::SkaldRuntime::Handle nodeHandle = 0;
        RttrHandleRegistry::Handle rttrHandle = 0;
        if (!m_runtime.CreateNode(cppType, arguments.table,
                                  nodeHandle, rttrHandle, error))
            return ReturnError(handler, error);
        return handler->EndFunctionAny2(
            HandleValue(nodeHandle), HandleValue(rttrHandle));
    });
}

int CScriptBind_SKALD::GetPortDefinitions(
    Offsets::IFunctionHandler* handler)
{
    return Safely(handler, [&]() {
        std::string error;
        const int count = handler->GetParamCount();
        if (count < 1 || count > 2)
            return ReturnError(handler,
                "expected (cppType) or (cppType, typeParameter)");

        std::string cppType;
        if (!ReadStringParam(handler, 1, cppType, error))
            return ReturnError(handler, error);

        std::string typeParameter;
        if (count == 2 && !ReadStringParam(handler, 2, typeParameter, error))
            return ReturnError(handler, error);

        std::vector<skald::SkaldPortInfo> ports;
        if (!m_runtime.DescribeNode(cppType, typeParameter, ports, error))
            return ReturnError(handler, error);

        Offsets::IScriptTable* table = m_pSS->CreateTable(0, 0);
        if (!table)
            return ReturnError(handler, "could not create port result table");

        int index = 1;
        for (const skald::SkaldPortInfo& port : ports) {
            Offsets::IScriptTable* entry = m_pSS->CreateTable(0, 0);
            if (!entry)
                continue;
            entry->SetValueAny("name", ScriptAnyValue(port.name.c_str()));
            entry->SetValueAny("valueType",
                               ScriptAnyValue(port.valueType.c_str()));
            entry->SetValueAny("direction",
                               ScriptAnyValue(DirectionName(port.direction)));
            entry->SetValueAny("isTrigger", ScriptAnyValue(port.isTrigger));
            table->SetAtAny(index++, ScriptAnyValue(entry));
            entry->Release();
        }

        const int results = handler->EndFunctionAny(ScriptAnyValue(table));
        table->Release();
        return results;
    });
}

int CScriptBind_SKALD::DestroyNode(
    Offsets::IFunctionHandler* handler)
{
    return Safely(handler, [&]() {
        std::string error;
        skald::SkaldRuntime::Handle nodeHandle = 0;
        if (!RequireParamCount(handler, 1, error) ||
            !ReadHandleParam(handler, 1, nodeHandle, error) ||
            !m_runtime.DestroyNode(nodeHandle, error))
            return ReturnError(handler, error);
        return ReturnTrue(handler);
    });
}

int CScriptBind_SKALD::BindTriggerOutput(
    Offsets::IFunctionHandler* handler)
{
    return Safely(handler, [&]() {
        std::string error;
        skald::SkaldRuntime::Handle nodeHandle = 0;
        std::string outputName;
        HSCRIPTFUNCTION callback = nullptr;
        if (!RequireParamCount(handler, 3, error) ||
            !ReadHandleParam(handler, 1, nodeHandle, error) ||
            !ReadStringParam(handler, 2, outputName, error) ||
            !ReadFunctionParam(handler, 3, callback, error))
            return ReturnError(handler, error);

        FunctionRefGuard callbackGuard(m_pSS, callback);
        skald::SkaldRuntime::Handle connectionHandle = 0;
        if (!m_runtime.BindTriggerOutput(
                nodeHandle, outputName, callback,
                connectionHandle, error))
            return ReturnError(handler, error);
        callbackGuard.Release();
        return handler->EndFunctionAny(HandleValue(connectionHandle));
    });
}

int CScriptBind_SKALD::BindDataOutput(
    Offsets::IFunctionHandler* handler)
{
    return Safely(handler, [&]() {
        std::string error;
        skald::SkaldRuntime::Handle nodeHandle = 0;
        std::string outputName;
        if (!RequireParamCount(handler, 2, error) ||
            !ReadHandleParam(handler, 1, nodeHandle, error) ||
            !ReadStringParam(handler, 2, outputName, error))
            return ReturnError(handler, error);

        skald::SkaldRuntime::Handle bindingHandle = 0;
        skald::SkaldRuntime::OutputUpdate initialValue;
        if (!m_runtime.BindDataOutput(
                nodeHandle, outputName, bindingHandle,
                initialValue, error))
            return ReturnError(handler, error);

        ScriptAnyValue value = NilValue();
        std::string stringStorage;
        rttr::type effectiveType = initialValue.declaredType;
        if (!effectiveType.is_valid() && initialValue.value.is_valid())
            effectiveType = initialValue.value.get_type();
        try {
            if (initialValue.value.is_valid() &&
                !g_rttrRuntime.Converter().ConvertResult(
                    std::move(initialValue.value),
                    effectiveType, value,
                    stringStorage, error)) {
                std::string ignored;
                m_runtime.UnbindDataOutput(bindingHandle, ignored);
                return ReturnError(handler, error);
            }
        } catch (...) {
            std::string ignored;
            m_runtime.UnbindDataOutput(bindingHandle, ignored);
            throw;
        }

        return handler->EndFunctionAny2(
            HandleValue(bindingHandle), value);
    });
}

int CScriptBind_SKALD::UnbindDataOutput(
    Offsets::IFunctionHandler* handler)
{
    return Safely(handler, [&]() {
        std::string error;
        skald::SkaldRuntime::Handle bindingHandle = 0;
        if (!RequireParamCount(handler, 1, error) ||
            !ReadHandleParam(handler, 1, bindingHandle, error) ||
            !m_runtime.UnbindDataOutput(bindingHandle, error))
            return ReturnError(handler, error);
        return ReturnTrue(handler);
    });
}

int CScriptBind_SKALD::Disconnect(
    Offsets::IFunctionHandler* handler)
{
    return Safely(handler, [&]() {
        std::string error;
        skald::SkaldRuntime::Handle connectionHandle = 0;
        if (!RequireParamCount(handler, 1, error) ||
            !ReadHandleParam(handler, 1, connectionHandle, error) ||
            !m_runtime.Disconnect(connectionHandle, error))
            return ReturnError(handler, error);
        return ReturnTrue(handler);
    });
}

int CScriptBind_SKALD::TriggerInput(
    Offsets::IFunctionHandler* handler)
{
    return Safely(handler, [&]() {
        std::string error;
        skald::SkaldRuntime::Handle nodeHandle = 0;
        std::string triggerName;
        if (!RequireParamCount(handler, 2, error) ||
            !ReadHandleParam(handler, 1, nodeHandle, error) ||
            !ReadStringParam(handler, 2, triggerName, error))
            return ReturnError(handler, error);

        std::vector<skald::SkaldRuntime::OutputUpdate> updates;
        if (!m_runtime.TriggerInput(
                nodeHandle, triggerName, updates, error))
            return ReturnError(handler, error);

        Offsets::IScriptTable* table =
            m_runtime.CreateUpdateTable(updates, error);
        if (!table)
            return ReturnError(handler, error);
        const int result =
            handler->EndFunctionAny(ScriptAnyValue(table));
        table->Release();
        return result;
    });
}

int CScriptBind_SKALD::QueueDestroy(
    Offsets::IFunctionHandler* handler)
{
    return Safely(handler, [&]() {
        std::string error;
        skald::SkaldRuntime::Handle nodeHandle = 0;
        if (!RequireParamCount(handler, 1, error) ||
            !ReadHandleParam(handler, 1, nodeHandle, error))
            return ReturnError(handler, error);

        m_runtime.QueueDestroy(nodeHandle);
        return ReturnTrue(handler);
    });
}

int CScriptBind_SKALD::SetActivation(
    Offsets::IFunctionHandler* handler)
{
    return Safely(handler, [&]() {
        std::string error;
        skald::SkaldRuntime::Handle nodeHandle = 0;
        bool active = false;
        if (!RequireParamCount(handler, 2, error) ||
            !ReadHandleParam(handler, 1, nodeHandle, error) ||
            !ReadBoolParam(handler, 2, active, error))
            return ReturnError(handler, error);

        std::vector<skald::SkaldRuntime::OutputUpdate> updates;
        if (!m_runtime.SetActivation(nodeHandle, active, updates, error))
            return ReturnError(handler, error);

        Offsets::IScriptTable* table =
            m_runtime.CreateUpdateTable(updates, error);
        if (!table)
            return ReturnError(handler, error);
        const int result =
            handler->EndFunctionAny(ScriptAnyValue(table));
        table->Release();
        return result;
    });
}

int CScriptBind_SKALD::SetUpdateDispatcher(
    Offsets::IFunctionHandler* handler)
{
    return Safely(handler, [&]() {
        std::string error;
        HSCRIPTFUNCTION dispatcher = nullptr;
        if (!RequireParamCount(handler, 1, error) ||
            !ReadFunctionParam(handler, 1, dispatcher, error))
            return ReturnError(handler, error);

        FunctionRefGuard dispatcherGuard(m_pSS, dispatcher);
        if (!m_runtime.SetUpdateDispatcher(dispatcher, error))
            return ReturnError(handler, error);
        dispatcherGuard.Release();
        return ReturnTrue(handler);
    });
}

}  // namespace luautils
