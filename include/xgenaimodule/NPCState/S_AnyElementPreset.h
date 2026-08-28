#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../../CryEngine/CryCommon/CryString.h"
#include "E_ElementType.h"

namespace wh::xgenaimodule::NPCState {

struct S_AnyElementPreset {
    CryStringT<char> m_name;                              // +0x00 RTTR "Name"
    bool m_dropHomeSlotAutoReturnLeft;                    // +0x08 RTTR "DropHomeSlotAutoReturnLeft"
    bool m_dropHomeSlotAutoReturnRight;                   // +0x09 RTTR "DropHomeSlotAutoReturnRight"
    std::uint8_t _pad0A[6];                               // +0x0A
    std::vector<E_ElementType::Type> m_elements;          // +0x10 RTTR "Elements"
    std::uint8_t _pad28[8];                               // +0x28
};

static_assert(offsetof(S_AnyElementPreset, m_elements) == 0x10,
              "S_AnyElementPreset::m_elements offset mismatch");
static_assert(sizeof(S_AnyElementPreset) == 0x30,
              "S_AnyElementPreset size mismatch");

}  // namespace wh::xgenaimodule::NPCState
