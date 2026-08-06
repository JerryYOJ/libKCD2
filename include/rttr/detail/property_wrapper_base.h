#pragma once

#include <cstddef>

#include "rttr/argument.h"
#include "rttr/instance.h"
#include "rttr/string_view.h"
#include "rttr/type.h"
#include "rttr/variant.h"

namespace rttr::detail {

class property_wrapper_base
{
public:
    virtual ~property_wrapper_base() = default;  // [0]
    virtual void unk_01() const {}               // [1]
    virtual bool is_valid() const = 0;           // [2]
    virtual void unk_03() const {}               // [3]
    virtual void unk_04() const {}               // [4]
    virtual void unk_05() const {}               // [5]
    virtual type get_type() const = 0;            // [6]
    virtual variant get_metadata(const variant& key) const = 0;  // [7]
    // [8] this rttr fork orders the wrapper set as (argument, instance), not
    // the public (instance, argument): override 0x1812FC488 converts arg first
    // (rdx) then validates instance (r8); base stub 0x180838AE0 = read-only,
    // returns false. Invoke through rttr::property::set_value.
    virtual bool set_value(argument arg, instance object) const { return false; }
    virtual variant get_value(instance object) const = 0;        // [9]

    string_view m_name;       // +0x08
    type m_declaringType;     // +0x18
};
static_assert(offsetof(property_wrapper_base, m_name) == 0x08,
              "property_wrapper_base name at 0x08");
static_assert(offsetof(property_wrapper_base, m_declaringType) == 0x18,
              "property_wrapper_base declaring type at 0x18");
static_assert(sizeof(property_wrapper_base) == 0x20,
              "property_wrapper_base must be 0x20");

}  // namespace rttr::detail
