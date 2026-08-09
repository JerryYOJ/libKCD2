#pragma once

#include <cstddef>

#include "rttr/detail/type_data.h"
#include "rttr/string_view.h"

namespace rttr {

class argument;
class enumeration;
class method;
class property;
class variant;

class type
{
public:
    type() noexcept : m_type_data(nullptr) {}
    explicit type(detail::type_data* data) noexcept : m_type_data(data) {}
    type(const type& other) noexcept : m_type_data(other.m_type_data) {}
    type& operator=(const type& other) noexcept
    {
        m_type_data = other.m_type_data;
        return *this;
    }

    bool operator==(const type& other) const noexcept { return m_type_data == other.m_type_data; }
    bool operator!=(const type& other) const noexcept { return m_type_data != other.m_type_data; }
    bool operator<(const type& other) const noexcept { return m_type_data < other.m_type_data; }

    bool is_valid() const noexcept { return m_type_data && m_type_data->is_valid; }
    string_view get_name() const noexcept
    {
        return m_type_data
            ? string_view(m_type_data->name.data(), m_type_data->name.size())
            : string_view{};
    }
    std::size_t get_sizeof() const noexcept
    {
        return m_type_data ? m_type_data->get_sizeof : 0;
    }
    std::size_t get_pointer_dimension() const noexcept
    {
        return m_type_data ? m_type_data->get_pointer_dimension : 0;
    }
    type get_raw_type() const noexcept
    {
        return type(m_type_data ? m_type_data->raw_type_data : nullptr);
    }
    type get_wrapped_type() const noexcept
    {
        return type(m_type_data ? m_type_data->wrapped_type : nullptr);
    }

    bool is_class() const noexcept { return test_trait(detail::type_trait_infos::is_class); }
    bool is_enumeration() const noexcept { return test_trait(detail::type_trait_infos::is_enum); }
    bool is_array() const noexcept { return test_trait(detail::type_trait_infos::is_array); }
    bool is_pointer() const noexcept { return test_trait(detail::type_trait_infos::is_pointer); }
    bool is_arithmetic() const noexcept { return test_trait(detail::type_trait_infos::is_arithmetic); }
    bool is_template_instantiation() const noexcept
    {
        return test_trait(detail::type_trait_infos::is_template_instantiation);
    }

    bool is_derived_from(const type& other) const;
    type get_pointer_type() const;
    property get_property(string_view name) const;
    method get_method(string_view name) const;
    enumeration get_enumeration() const;
    variant create_variant(const argument& value) const;

    static type get_by_name(string_view name);
    static method get_global_method(string_view name);
    // Adjusts `pointer` -- an instance of `source` -- to `target`, applying
    // the base-cast thunk for the matching base, so multiple inheritance is
    // handled rather than assumed away. Null when `target` is not a base of
    // the object's most-derived type. Compares RAW types, so `T` and `T*`
    // are interchangeable as either argument.
    static void* apply_offset(void* pointer, const type& source,
                              const type& target);

    detail::type_data* m_type_data;  // +0x00

private:
    bool test_trait(detail::type_trait_infos trait) const noexcept
    {
        return m_type_data &&
               m_type_data->m_type_traits.test(static_cast<std::size_t>(trait));
    }
};
static_assert(sizeof(type) == 0x8, "rttr::type is one type_data pointer");

}  // namespace rttr
