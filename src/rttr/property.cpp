#include "rttr/property.h"

#include "rttr/detail/property_wrapper_base.h"

namespace rttr {

bool property::is_valid() const
{
    return m_wrapper && m_wrapper->is_valid();
}

string_view property::get_name() const
{
    return m_wrapper ? m_wrapper->m_name : string_view{};
}

type property::get_type() const
{
    return m_wrapper ? m_wrapper->get_type() : type{};
}

type property::get_declaring_type() const
{
    return m_wrapper ? m_wrapper->m_declaringType : type{};
}

variant property::get_value(instance object) const
{
    return m_wrapper ? m_wrapper->get_value(object) : variant{};
}

bool property::set_value(instance object, argument arg) const
{
    // The wrapper virtual takes (argument, instance) in this fork; the public
    // API keeps the conventional (instance, argument) order and swaps here.
    return m_wrapper ? m_wrapper->set_value(arg, object) : false;
}

}  // namespace rttr
