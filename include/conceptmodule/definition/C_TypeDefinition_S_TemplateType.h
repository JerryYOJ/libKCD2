#pragma once
#include <cstddef>
#include <cstdint>
#include "../../CryEngine/CryCommon/CryString.h"
#include "../../rttr/rttr_enable.h"
#include "C_TypeDefinition.h"

namespace wh::conceptmodule::definition {

struct C_TypeDefinition::S_TemplateType {
    RTTR_ENABLE()                                             // [0..2]

    CryStringT<char> m_name;                                  // +0x08 RTTR "Name"
    int m_id;                                                 // +0x10 RTTR "Id"
    std::uint8_t m_unknown14[4];                              // +0x14
};

static_assert(offsetof(C_TypeDefinition::S_TemplateType, m_name) == 0x08,
              "C_TypeDefinition::S_TemplateType::m_name offset mismatch");
static_assert(offsetof(C_TypeDefinition::S_TemplateType, m_id) == 0x10,
              "C_TypeDefinition::S_TemplateType::m_id offset mismatch");
static_assert(sizeof(C_TypeDefinition::S_TemplateType) == 0x18,
              "C_TypeDefinition::S_TemplateType size mismatch");

}  // namespace wh::conceptmodule::definition
