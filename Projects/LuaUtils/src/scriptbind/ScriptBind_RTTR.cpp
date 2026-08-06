#include "scriptbind/ScriptBind_RTTR.h"

#include <cmath>
#include <exception>
#include <string>
#include <utility>
#include <vector>

#include "LuaHelpers.h"
#include "Offsets/vtables/IFunctionHandler.h"
#include "Offsets/vtables/IScriptSystem.h"
#include "Offsets/vtables/IScriptTable.h"
#include "ResolveHelpers.h"
#include "rpgmodule/C_Soul.h"
#include "rpgmodule/I_Soul.h"
#include "rttr/detail/class_data.h"
#include "rttr/enumeration.h"
#include "rttr/instance.h"
#include "rttr/method.h"
#include "rttr/property.h"
#include "rttr/type.h"
#include "rttr/variant.h"

namespace luautils {
namespace {

// The game's type::get_property/get_method (0x1806A55FC/0x1806A76A0) search
// the DECLARED member list only; inherited members live on their declaring
// type's class_data. class_data keeps every transitive base pre-flattened
// (m_base_types, base-depth sorted), so resolving a member the way callers
// expect is the exact type first, then one linear pass over that list.
rttr::property FindPropertyInHierarchy(const rttr::type& type,
                                       rttr::string_view name)
{
    rttr::property found = type.get_property(name);
    if (found.is_valid() || !type.is_class())
        return found;
    if (!type.m_type_data || !type.m_type_data->get_class_data)
        return found;
    for (const rttr::type& base :
         type.m_type_data->get_class_data().m_base_types) {
        rttr::property inherited = base.get_property(name);
        if (inherited.is_valid())
            return inherited;
    }
    return found;
}

rttr::method FindMethodInHierarchy(const rttr::type& type,
                                   rttr::string_view name)
{
    rttr::method found = type.get_method(name);
    if (found.is_valid() || !type.is_class())
        return found;
    if (!type.m_type_data || !type.m_type_data->get_class_data)
        return found;
    for (const rttr::type& base :
         type.m_type_data->get_class_data().m_base_types) {
        rttr::method inherited = base.get_method(name);
        if (inherited.is_valid())
            return inherited;
    }
    return found;
}

ScriptAnyValue NilValue()
{
    ScriptAnyValue value;
    value.type = ANY_TNIL;
    value.nHandle = 0;
    return value;
}

int ReturnError(Offsets::IFunctionHandler* pH, const std::string& error)
{
    const char* message = error.empty()
        ? "RTTR operation failed"
        : error.c_str();
    return pH->EndFunctionAny2(NilValue(), ScriptAnyValue(message));
}

int ReturnTrue(Offsets::IFunctionHandler* pH)
{
    return pH->EndFunctionAny(ScriptAnyValue(true));
}

template <class Callback>
int Safely(Offsets::IFunctionHandler* pH, Callback&& callback)
{
    try {
        return callback();
    } catch (const std::exception& exception) {
        return ReturnError(pH, exception.what());
    } catch (...) {
        return ReturnError(pH, "unknown native exception during RTTR operation");
    }
}

bool ReadStringParam(Offsets::IFunctionHandler* pH, int index,
                     std::string& value, std::string& error)
{
    if (index < 1 || index > pH->GetParamCount()) {
        error = "missing required argument";
        return false;
    }
    ScriptAnyValue any;
    any.type = ANY_ANY;
    any.table = nullptr;
    if (!pH->GetParamAny(index, any)) {
        error = "could not read argument";
        return false;
    }
    if (any.type != ANY_TSTRING || !any.str) {
        error = "argument must be a string";
        return false;
    }
    value = any.str;
    return true;
}

bool RequireParamCount(Offsets::IFunctionHandler* pH, int minimum,
                       int maximum, std::string& error)
{
    const int count = pH->GetParamCount();
    if (count < minimum) {
        error = "missing required argument";
        return false;
    }
    if (maximum >= 0 && count > maximum) {
        error = "too many arguments";
        return false;
    }
    return true;
}

int ReturnConverted(Offsets::IFunctionHandler* pH,
                    RttrLuaConverter& converter,
                    rttr::variant&& value,
                    rttr::type declaredType)
{
    ScriptAnyValue result;
    std::string stringStorage;
    std::string error;
    if (!converter.ConvertResult(std::move(value), declaredType, result,
                                 stringStorage, error))
        return ReturnError(pH, error);
    return pH->EndFunctionAny(result);
}

}  // namespace

CScriptBind_RTTR::CScriptBind_RTTR(RttrRuntime& runtime) noexcept
    : m_runtime(runtime)
{}

void CScriptBind_RTTR::Init(Offsets::IScriptSystem* pSS)
{
    if (!pSS || m_pMethodsTable)
        return;

    m_pSS = pSS;
    m_pMethodsTable = pSS->CreateTable(0, 0);
    if (!m_pMethodsTable)
        return;
    m_pMethodsTable->AddRef();

    RegisterFunction("CallGlobal", "methodName, ...",
                     functor(*this, &CScriptBind_RTTR::CallGlobal));
    RegisterFunction("CallMethod",
                     "objectHandle, declaringType, methodName, ...",
                     functor(*this, &CScriptBind_RTTR::CallMethod));
    RegisterFunction("GetProperty",
                     "objectHandle, declaringType, propertyName",
                     functor(*this, &CScriptBind_RTTR::GetProperty));
    RegisterFunction("GetEnum", "enumType, valueName",
                     functor(*this, &CScriptBind_RTTR::GetEnum));
    RegisterFunction("GetTypeName", "handle",
                     functor(*this, &CScriptBind_RTTR::GetTypeName));
    RegisterFunction("Release", "handle",
                     functor(*this, &CScriptBind_RTTR::Release));
    RegisterFunction("Clear", "",
                     functor(*this, &CScriptBind_RTTR::Clear));
    RegisterFunction("GetSoulByWuid", "soulWuid",
                     functor(*this, &CScriptBind_RTTR::GetSoulByWuid));

    m_pSS->SetGlobalAny("RTTR", ScriptAnyValue(m_pMethodsTable));
}

void CScriptBind_RTTR::RegisterFunction(const char* name, const char* params,
                                        const FunctionFunctor& function)
{
    SUserFunctionDesc descriptor;
    descriptor.sGlobalName = "RTTR";
    descriptor.sFunctionName = name;
    descriptor.sFunctionParams = params;
    descriptor.pFunctor = function;
    m_pMethodsTable->AddFunction(descriptor);
}

int CScriptBind_RTTR::CallGlobal(Offsets::IFunctionHandler* pH)
{
    return Safely(pH, [&]() {
        std::string error;
        std::string methodName;
        if (!RequireParamCount(pH, 1, -1, error) ||
            !ReadStringParam(pH, 1, methodName, error))
            return ReturnError(pH, error);

        const rttr::method method = rttr::type::get_global_method(methodName);
        if (!method.is_valid())
            return ReturnError(pH, "unknown reflected global method '" +
                                      methodName + "'");

        std::vector<rttr::variant> values;
        std::vector<rttr::argument> arguments;
        if (!m_runtime.Converter().BuildArguments(pH, 2, method, values, arguments,
                                        error))
            return ReturnError(pH, error);

        rttr::instance object;
        rttr::variant result = method.invoke_variadic(object, arguments);
        return ReturnConverted(pH, m_runtime.Converter(), std::move(result),
                               method.get_return_type());
    });
}

int CScriptBind_RTTR::CallMethod(Offsets::IFunctionHandler* pH)
{
    return Safely(pH, [&]() {
        std::string error;
        if (!RequireParamCount(pH, 3, -1, error))
            return ReturnError(pH, error);

        RttrHandleRegistry::Handle handle = 0;
        std::string declaringTypeName;
        std::string methodName;
        if (!m_runtime.Converter().GetHandleParam(pH, 1, handle, error) ||
            !ReadStringParam(pH, 2, declaringTypeName, error) ||
            !ReadStringParam(pH, 3, methodName, error))
            return ReturnError(pH, error);

        const rttr::type declaringType =
            rttr::type::get_by_name(declaringTypeName);
        if (!declaringType.is_valid())
            return ReturnError(pH, "unknown reflected type '" +
                                      declaringTypeName + "'");

        const rttr::variant* objectValue =
            m_runtime.Converter().ResolveObject(handle, declaringType, error);
        if (!objectValue)
            return ReturnError(pH, error);

        const rttr::method method =
            FindMethodInHierarchy(declaringType, methodName);
        if (!method.is_valid())
            return ReturnError(pH, "unknown reflected method '" + methodName +
                                      "' on type '" + declaringTypeName + "'");

        std::vector<rttr::variant> values;
        std::vector<rttr::argument> arguments;
        if (!m_runtime.Converter().BuildArguments(pH, 4, method, values, arguments,
                                        error))
            return ReturnError(pH, error);

        rttr::instance object(*objectValue);
        rttr::variant result = method.invoke_variadic(object, arguments);
        return ReturnConverted(pH, m_runtime.Converter(), std::move(result),
                               method.get_return_type());
    });
}

int CScriptBind_RTTR::GetProperty(Offsets::IFunctionHandler* pH)
{
    return Safely(pH, [&]() {
        std::string error;
        if (!RequireParamCount(pH, 3, 3, error))
            return ReturnError(pH, error);

        RttrHandleRegistry::Handle handle = 0;
        std::string declaringTypeName;
        std::string propertyName;
        if (!m_runtime.Converter().GetHandleParam(pH, 1, handle, error) ||
            !ReadStringParam(pH, 2, declaringTypeName, error) ||
            !ReadStringParam(pH, 3, propertyName, error))
            return ReturnError(pH, error);

        const rttr::type declaringType =
            rttr::type::get_by_name(declaringTypeName);
        if (!declaringType.is_valid())
            return ReturnError(pH, "unknown reflected type '" +
                                      declaringTypeName + "'");

        const rttr::variant* objectValue =
            m_runtime.Converter().ResolveObject(handle, declaringType, error);
        if (!objectValue)
            return ReturnError(pH, error);

        const rttr::property property =
            FindPropertyInHierarchy(declaringType, propertyName);
        if (!property.is_valid())
            return ReturnError(pH, "unknown reflected property '" +
                                      propertyName + "' on type '" +
                                      declaringTypeName + "'");

        rttr::instance object(*objectValue);
        rttr::variant result = property.get_value(object);
        return ReturnConverted(pH, m_runtime.Converter(), std::move(result),
                               property.get_type());
    });
}

int CScriptBind_RTTR::GetEnum(Offsets::IFunctionHandler* pH)
{
    return Safely(pH, [&]() {
        std::string error;
        if (!RequireParamCount(pH, 2, 2, error))
            return ReturnError(pH, error);

        std::string enumTypeName;
        std::string valueName;
        if (!ReadStringParam(pH, 1, enumTypeName, error) ||
            !ReadStringParam(pH, 2, valueName, error))
            return ReturnError(pH, error);

        const rttr::type enumType = rttr::type::get_by_name(enumTypeName);
        if (!enumType.is_valid())
            return ReturnError(pH, "unknown reflected type '" +
                                      enumTypeName + "'");
        if (!enumType.is_enumeration())
            return ReturnError(pH, "reflected type '" + enumTypeName +
                                      "' is not an enumeration");

        const rttr::enumeration enumeration = enumType.get_enumeration();
        if (!enumeration.is_valid())
            return ReturnError(pH, "reflected enumeration '" + enumTypeName +
                                      "' has no registered values");

        rttr::variant result = enumeration.name_to_value(valueName);
        if (!result.is_valid())
            return ReturnError(pH, "unknown value '" + valueName +
                                      "' for reflected enumeration '" +
                                      enumTypeName + "'");
        return ReturnConverted(pH, m_runtime.Converter(), std::move(result), enumType);
    });
}

int CScriptBind_RTTR::GetTypeName(Offsets::IFunctionHandler* pH)
{
    return Safely(pH, [&]() {
        std::string error;
        if (!RequireParamCount(pH, 1, 1, error))
            return ReturnError(pH, error);

        RttrHandleRegistry::Handle handle = 0;
        if (!m_runtime.Converter().GetHandleParam(pH, 1, handle, error))
            return ReturnError(pH, error);
        const rttr::variant* value = m_runtime.Registry().Lookup(handle);
        if (!value)
            return ReturnError(pH, "unknown or stale RTTR handle");

        const std::string typeName =
            RttrLuaConverter::GetTypeName(value->get_type());
        return pH->EndFunctionAny(ScriptAnyValue(typeName.c_str()));
    });
}

int CScriptBind_RTTR::Release(Offsets::IFunctionHandler* pH)
{
    return Safely(pH, [&]() {
        std::string error;
        if (!RequireParamCount(pH, 1, 1, error))
            return ReturnError(pH, error);

        RttrHandleRegistry::Handle handle = 0;
        if (!m_runtime.Converter().GetHandleParam(pH, 1, handle, error))
            return ReturnError(pH, error);
        if (!m_runtime.Registry().Release(handle))
            return ReturnError(pH, "unknown or stale RTTR handle");
        return ReturnTrue(pH);
    });
}

int CScriptBind_RTTR::Clear(Offsets::IFunctionHandler* pH)
{
    return Safely(pH, [&]() {
        std::string error;
        if (!RequireParamCount(pH, 0, 0, error))
            return ReturnError(pH, error);
        m_runtime.ClearHandles();
        return ReturnTrue(pH);
    });
}

int CScriptBind_RTTR::GetSoulByWuid(Offsets::IFunctionHandler* pH)
{
    return Safely(pH, [&]() {
        std::string error;
        if (!RequireParamCount(pH, 1, 1, error))
            return ReturnError(pH, error);

        ScriptAnyValue argument;
        argument.type = ANY_ANY;
        argument.table = nullptr;
        if (!pH->GetParamAny(1, argument))
            return ReturnError(pH, "could not read soulWuid argument");

        // A live WUID (e.g. player.soul) is {__ThisWUID = <lightuserdata>}:
        // the game encodes it as a raw pointer-sized value, not a Lua number
        // -- this VM's Lua numbers are 32-bit floats (24-bit mantissa), which
        // cannot round-trip a real WUID's full bit pattern (the tag alone
        // occupies the top byte). Unwrap one level of table before reading.
        if (argument.type == ANY_TTABLE && argument.table) {
            ScriptAnyValue wuidField;
            wuidField.type = ANY_ANY;
            wuidField.table = nullptr;
            if (argument.table->GetValueAny("__ThisWUID", wuidField))
                argument = wuidField;
        }

        uint64_t wuidValue = 0;
        if (argument.type == ANY_TUSERDATA) {
            wuidValue = static_cast<uint64_t>(
                reinterpret_cast<std::uintptr_t>(argument.ud.ptr));
        } else if (argument.type == ANY_THANDLE && argument.nHandle != 0) {
            wuidValue = static_cast<uint64_t>(argument.nHandle);
        } else if (argument.type == ANY_TNUMBER &&
                   std::isfinite(argument.number) && argument.number >= 0.0 &&
                   std::trunc(argument.number) == argument.number) {
            wuidValue = static_cast<uint64_t>(argument.number);
        } else {
            return ReturnError(pH,
                "soulWuid must be a WUID lightuserdata (e.g. player.soul), "
                "a {__ThisWUID=...} table, or a nonnegative integer/handle");
        }

        wh::rpgmodule::C_Soul* soul = ResolveSoulByWuid(wuidValue);
        if (!soul)
            return ReturnError(pH, "no soul found for the given WUID");

        const rttr::type soulType =
            rttr::type::get_by_name("wh::rpgmodule::I_Soul");
        if (!soulType.is_valid())
            return ReturnError(pH, "wh::rpgmodule::I_Soul is not reflected");

        // C_Soul : public I_Soul at +0x00 (primary base) -- identity cast,
        // no pointer adjustment, but written explicitly rather than relying
        // on that not changing.
        auto* asSoul = static_cast<wh::rpgmodule::I_Soul*>(soul);
        rttr::variant value =
            RttrLuaConverter::MakeObjectPointerVariant(asSoul, soulType);

        const RttrHandleRegistry::DedupKey dedupKey{ soulType, asSoul };
        const RttrHandleRegistry::Handle handle =
            m_runtime.Registry().Store(std::move(value), &dedupKey);
        return pH->EndFunctionAny(HandleValue(handle));
    });
}

}  // namespace luautils
