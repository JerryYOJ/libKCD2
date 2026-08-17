#include "rttr/method.h"

#include "rttr/detail/method_wrapper_base.h"

namespace rttr {

bool method::is_valid() const
{
    return m_wrapper && m_wrapper->is_valid();
}

string_view method::get_name() const
{
    return m_wrapper ? m_wrapper->m_name : string_view{};
}

type method::get_return_type() const
{
    return m_wrapper ? m_wrapper->get_return_type() : type{};
}

type method::get_declaring_type() const
{
    return m_wrapper ? m_wrapper->m_declaringType : type{};
}

bool method::is_static() const
{
    return m_wrapper && m_wrapper->is_static();
}

parameter_info_range method::get_parameter_infos() const
{
    if(m_wrapper) return m_wrapper->get_parameter_infos();
    return parameter_info_range{};
}

variant method::get_metadata(const variant& key) const
{
    return m_wrapper ? m_wrapper->get_metadata(key) : variant{};
}

variant method::invoke_variadic(instance object,
                                const std::vector<argument>& arguments) const
{
    return m_wrapper
        ? m_wrapper->invoke_variadic(object, arguments)
        : variant{};
}

}  // namespace rttr
