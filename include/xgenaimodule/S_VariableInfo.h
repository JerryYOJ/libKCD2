#pragma once
#include <cstddef>
#include <cstdint>
#include "E_VariableForm.h"

namespace wh::xgenaimodule {
struct S_VariableInfo {
    CryStringT<char> m_name;  // +0x0 RTTR "name"
    CryStringT<char> m_type;  // +0x8 RTTR "type"
    E_VariableForm::Type m_form;  // +0x10 RTTR "form"
    std::uint8_t m_unknown14[0x4];                  // +0x14
    CryStringT<char> m_values;  // +0x18 RTTR "values"
    bool m_isPersistent;  // +0x20 RTTR "isPersistent"
    std::uint8_t m_unknown21[0x1];                  // +0x21
    bool m_isOptional;  // +0x22 RTTR "isOptional"
    std::uint8_t m_unknown23[0x5];                  // +0x23
};

static_assert(offsetof(S_VariableInfo, m_values) == 0x18, "S_VariableInfo::m_values offset mismatch");
static_assert(offsetof(S_VariableInfo, m_form) == 0x10, "S_VariableInfo::m_form offset mismatch");
static_assert(offsetof(S_VariableInfo, m_type) == 0x8, "S_VariableInfo::m_type offset mismatch");
static_assert(offsetof(S_VariableInfo, m_name) == 0x0, "S_VariableInfo::m_name offset mismatch");
static_assert(sizeof(S_VariableInfo) == 0x28, "S_VariableInfo size mismatch");

}  // namespace wh::xgenaimodule
