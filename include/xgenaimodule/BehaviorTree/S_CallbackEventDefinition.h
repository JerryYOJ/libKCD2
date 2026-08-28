#pragma once
#include <cstddef>
#include <cstdint>
#include "../../CryEngine/CryCommon/CryString.h"

namespace wh::xgenaimodule::BehaviorTree {

struct S_CallbackEventDefinition {
    std::uint8_t m_unknown00[0x10];                       // +0x00 Signature accessor
    CryStringT<char> m_name;                              // +0x10 RTTR "Name"
    bool m_atomic;                                        // +0x18 RTTR "Atomic"
    std::uint8_t _pad19[7];                               // +0x19
};

static_assert(offsetof(S_CallbackEventDefinition, m_name) == 0x10,
              "S_CallbackEventDefinition::m_name offset mismatch");
static_assert(sizeof(S_CallbackEventDefinition) == 0x20,
              "S_CallbackEventDefinition size mismatch");

}  // namespace wh::xgenaimodule::BehaviorTree
