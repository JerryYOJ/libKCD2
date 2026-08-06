#pragma once

#include <string>
#include <vector>

#include "crysystem/ScriptAnyValue.h"
#include "rttr/argument.h"
#include "rttr/method.h"
#include "rttr/type.h"
#include "rttr/variant.h"
#include "rttr/RttrHandleRegistry.h"

namespace Offsets {
struct IFunctionHandler;
}

namespace luautils {

class RttrLuaConverter
{
public:
    explicit RttrLuaConverter(RttrHandleRegistry& registry) noexcept;

    bool GetHandleParam(Offsets::IFunctionHandler* pH, int index,
                        RttrHandleRegistry::Handle& handle,
                        std::string& error) const;
    const rttr::variant* ResolveObject(RttrHandleRegistry::Handle handle,
                                       rttr::type declaringType,
                                       std::string& error) const;
    bool BuildArguments(Offsets::IFunctionHandler* pH, int firstIndex,
                        const rttr::method& method,
                        std::vector<rttr::variant>& values,
                        std::vector<rttr::argument>& arguments,
                        std::string& error) const;
    bool ConvertValue(const ScriptAnyValue& value, rttr::type expectedType,
                      rttr::variant& result, std::string& error) const;
    // Wraps a raw, natively-owned object pointer (e.g. a C_Soul* resolved
    // from a WUID) as an rttr::variant of the given type. Non-owning: the
    // variant never deletes the pointee, only stores/compares it -- for
    // handles produced this way, not by a native rttr call.
    static rttr::variant MakeObjectPointerVariant(void* pointer,
                                                  rttr::type valueType);
    // One captured array element: a raw, natively-owned object pointer
    // (resolved from an RTTR handle) or literal text from a Lua string.
    struct ArrayElement
    {
        void* pointer = nullptr;
        std::string text;
        bool isText = false;
    };
    // Builds a game-owned container variant of containerType (constructed
    // through the type's own registered default constructor) and fills it
    // through the container's own sequential-view insert ops, per element:
    // object pointers are inserted carrying the view's exact element type
    // (pointer containers only), text rides the registered string->element
    // converters (e.g. CryStringT for 'Strings'). On any failure returns an
    // invalid variant with `error` naming the element and the types involved;
    // a partially-filled container is never returned.
    static rttr::variant MakeArrayVariant(std::vector<ArrayElement>&& elements,
                                          rttr::type containerType,
                                          std::string& error);
    bool ConvertResult(rttr::variant&& value, rttr::type declaredType,
                       ScriptAnyValue& result, std::string& stringStorage,
                       std::string& error);

    // True for std::basic_string_view targets, whose values are NON-OWNING and
    // therefore unsafe to hand the game from a temporary buffer.
    static bool IsStringViewType(rttr::type valueType);

    static std::string GetTypeName(rttr::type valueType);

private:
    bool ConvertArgument(const ScriptAnyValue& value, rttr::type expectedType,
                         rttr::variant& result, std::string& error) const;
    bool IsObjectCompatible(rttr::type actualType,
                            rttr::type expectedType) const;

    RttrHandleRegistry& m_registry;
};

}  // namespace luautils
