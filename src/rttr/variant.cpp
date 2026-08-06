#include "rttr/variant.h"

#include <utility>

#include "REL.h"
#include "rttr/type.h"

namespace rttr {
namespace {

variant::policy_func GetEmptyPolicy()
{
    static REL::Relocation<variant::policy_func> policy{ REL::ID(29775) };  // 0x1804FBC18
    return policy.get();
}

}  // namespace

variant::variant() noexcept
    : m_data{}, m_policy(GetEmptyPolicy())
{}

variant::variant(detail::variant_data data, policy_func policy) noexcept
    : m_data(data), m_policy(policy ? policy : GetEmptyPolicy())
{}

variant::variant(const variant& other)
{
    using Fn = variant*(__fastcall*)(variant*, const variant*);
    static REL::Relocation<Fn> fn{ REL::ID(29719) };  // 0x1804F8710
    fn(this, &other);
}

variant::variant(variant&& other) noexcept
{
    using Fn = variant*(__fastcall*)(variant*, variant*);
    static REL::Relocation<Fn> fn{ REL::ID(36450) };  // 0x1806926A8
    fn(this, &other);
}

variant& variant::operator=(const variant& other)
{
    if (this != &other) {
        variant copy(other);
        *this = std::move(copy);
    }
    return *this;
}

variant& variant::operator=(variant&& other) noexcept
{
    if (this != &other) {
        using Fn = variant*(__fastcall*)(variant*, variant*);
        static REL::Relocation<Fn> fn{ REL::ID(29720) };  // 0x1804F8734
        fn(this, &other);
    }
    return *this;
}

variant::~variant()
{
    using Fn = void(__fastcall*)(variant*);
    static REL::Relocation<Fn> fn{ REL::ID(29772) };  // 0x1804FB9D0
    fn(this);
}

bool variant::is_valid() const
{
    using Fn = bool(__fastcall*)(const variant*);
    static REL::Relocation<Fn> fn{ REL::ID(29731) };  // 0x1804F9CDC
    return fn(this);
}

bool variant::is_nullptr() const
{
    return m_policy && m_policy(
        static_cast<std::uint8_t>(detail::variant_policy_operation::is_nullptr),
        const_cast<detail::variant_data*>(&m_data), nullptr);
}

type variant::get_type() const
{
    // Member return is this-first then hidden result: RCX=this, RDX=out.
    using Fn = type*(__fastcall*)(const variant*, type*);
    static REL::Relocation<Fn> fn{ REL::ID(29732) };  // 0x1804F9CEC
    type result;
    fn(this, &result);
    return result;
}

bool variant::convert_to(const type& target, variant& out) const
{
    // The full untyped conversion: same-type copy, wrapper (un)wrap,
    // arithmetic/string fast paths, pointer upcasts, enums, and the
    // registered-converter registry (lookup 0x1804F9FB0) -- the same
    // machinery that types authored SKALD constants.
    using Fn = bool(__fastcall*)(const variant*, const type*, variant*);
    static REL::Relocation<Fn> fn{ REL::ID(29730) };  // 0x1804F9640
    return fn(this, &target, &out);
}

void* variant::get_policy_pointer(detail::variant_policy_operation operation) const
{
    void* result = nullptr;
    if (!m_policy || !m_policy(static_cast<std::uint8_t>(operation),
                              const_cast<detail::variant_data*>(&m_data), &result))
        return nullptr;
    return result;
}

void* variant::get_value() const
{
    return get_policy_pointer(detail::variant_policy_operation::get_value);
}

void* variant::get_ptr() const
{
    return get_policy_pointer(detail::variant_policy_operation::get_ptr);
}

void* variant::get_raw_ptr() const
{
    return get_policy_pointer(detail::variant_policy_operation::get_raw_ptr);
}

variant variant::from_policy(detail::variant_data data, policy_func policy) noexcept
{
    return variant(data, policy);
}

}  // namespace rttr
