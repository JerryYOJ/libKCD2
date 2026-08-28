#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"
#include "E_ConstraintType.h"

namespace wh::conceptmodule {
class S_TypeConstraint {
public:
    RTTR_ENABLE()  // [0..2]
    E_ConstraintType m_type;  // +0x8 RTTR "Type"
    std::uint8_t m_unknown0C[0x4];                  // +0xC
    CryStringT<char> m_target;  // +0x10 RTTR "Target"
    CryStringT<char> m_keyProperty;  // +0x18 RTTR "KeyProperty"
    CryStringT<char> m_valueProperty;  // +0x20 RTTR "ValueProperty"
};

static_assert(offsetof(S_TypeConstraint, m_valueProperty) == 0x20, "S_TypeConstraint::m_valueProperty offset mismatch");
static_assert(offsetof(S_TypeConstraint, m_keyProperty) == 0x18, "S_TypeConstraint::m_keyProperty offset mismatch");
static_assert(offsetof(S_TypeConstraint, m_target) == 0x10, "S_TypeConstraint::m_target offset mismatch");
static_assert(offsetof(S_TypeConstraint, m_type) == 0x8, "S_TypeConstraint::m_type offset mismatch");
static_assert(sizeof(S_TypeConstraint) == 0x28, "S_TypeConstraint size mismatch");

}  // namespace wh::conceptmodule
