#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"
#include "I_NodeDefinition.h"

namespace wh::conceptmodule::definition {

struct I_NodeDefinition::S_PropertyDef {
    RTTR_ENABLE()                                             // [0..2]

    CryStringT<char> m_name;                                  // +0x08 RTTR "Name"
    rttr::variant m_value;                                    // +0x10 RTTR "Value"
    bool m_userDefined;                                       // +0x28 RTTR "UserDefined"
    std::uint8_t m_unknown29[7];                              // +0x29
};

static_assert(offsetof(I_NodeDefinition::S_PropertyDef, m_name) == 0x08,
              "I_NodeDefinition::S_PropertyDef::m_name offset mismatch");
static_assert(offsetof(I_NodeDefinition::S_PropertyDef, m_value) == 0x10,
              "I_NodeDefinition::S_PropertyDef::m_value offset mismatch");
static_assert(offsetof(I_NodeDefinition::S_PropertyDef, m_userDefined) == 0x28,
              "I_NodeDefinition::S_PropertyDef::m_userDefined offset mismatch");
static_assert(sizeof(I_NodeDefinition::S_PropertyDef) == 0x30,
              "I_NodeDefinition::S_PropertyDef size mismatch");

}  // namespace wh::conceptmodule::definition
