#include "rttr/type.h"

#include "REL.h"
#include "rttr/argument.h"
#include "rttr/enumeration.h"
#include "rttr/method.h"
#include "rttr/property.h"
#include "rttr/variant.h"

namespace rttr {

bool type::is_derived_from(const type& other) const
{
    if (!is_valid() || !other.is_valid())
        return false;
    using Fn = bool(__fastcall*)(const type*, const type*);
    static REL::Relocation<Fn> fn{ REL::ID(29665) };  // 0x1804F6364
    return fn(this, &other);
}

type type::get_pointer_type() const
{
    if (!is_valid())
        return {};
    using Fn = type(__fastcall*)(const type&);
    static REL::Relocation<Fn> fn{ REL::ID(36954) };  // 0x1806A4F08
    return fn(*this);
}

void* type::apply_offset(void* pointer, const type& source, const type& target)
{
    if (!pointer || !source.is_valid() || !target.is_valid())
        return nullptr;
    using Fn = void*(__fastcall*)(void*, const type*, const type*);
    static REL::Relocation<Fn> fn{ REL::ID(36690) };  // 0x18069A498
    return fn(pointer, &source, &target);
}

property type::get_property(string_view name) const
{
    if (!is_valid())
        return {};
    using Fn = property(__fastcall*)(const type&, string_view);
    static REL::Relocation<Fn> fn{ REL::ID(36971) };  // 0x1806A55FC
    return fn(*this, name);
}

method type::get_method(string_view name) const
{
    if (!is_valid())
        return {};
    // Member return is this-first then hidden result: RCX=this, RDX=out, R8=name.
    using Fn = method*(__fastcall*)(const type*, method*, const string_view*);
    static REL::Relocation<Fn> fn{ REL::ID(37024) };  // 0x1806A76A0
    method result;
    fn(this, &result, &name);
    return result;
}

enumeration type::get_enumeration() const
{
    return enumeration(is_valid() ? m_type_data->enum_wrapper : nullptr);
}

variant type::create_variant(const argument& value) const
{
    return is_valid() && m_type_data->create_variant
        ? m_type_data->create_variant(value)
        : variant{};
}

type type::get_by_name(string_view name)
{
    using Fn = type(__fastcall*)(string_view);
    static REL::Relocation<Fn> fn{ REL::ID(36975) };  // 0x1806A589C
    return fn(name);
}

method type::get_global_method(string_view name)
{
    using Fn = method(__fastcall*)(string_view);
    static REL::Relocation<Fn> fn{ REL::ID(37000) };  // 0x1806A6DF0
    return fn(name);
}

}  // namespace rttr
