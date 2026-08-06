#pragma once

#include "rttr/argument.h"
#include "rttr/instance.h"
#include "rttr/string_view.h"
#include "rttr/type.h"
#include "rttr/variant.h"

namespace rttr {

namespace detail {
class property_wrapper_base;
}

class property
{
public:
    property() noexcept : m_wrapper(nullptr) {}
    explicit property(const detail::property_wrapper_base* wrapper) noexcept : m_wrapper(wrapper) {}
    property(const property& other) noexcept : m_wrapper(other.m_wrapper) {}
    property& operator=(const property& other) noexcept
    {
        m_wrapper = other.m_wrapper;
        return *this;
    }

    bool is_valid() const;
    string_view get_name() const;
    type get_type() const;
    type get_declaring_type() const;
    variant get_value(instance object) const;
    bool set_value(instance object, argument arg) const;

    const detail::property_wrapper_base* m_wrapper;  // +0x00
};
static_assert(sizeof(property) == 0x8, "rttr::property is one wrapper pointer");

}  // namespace rttr
