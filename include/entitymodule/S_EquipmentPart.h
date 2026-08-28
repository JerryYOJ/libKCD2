#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::entitymodule::S_EquipmentPart
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x10. No vtable.
// -----------------------------------------------

namespace wh::entitymodule {

struct S_EquipmentPart {
    std::uint32_t m_id;                                   // +0x00 RTTR "Id"
    std::uint8_t _pad04[4];                               // +0x04
    CryStringT<char> m_name;                              // +0x08 RTTR "Name"
};

static_assert(offsetof(S_EquipmentPart, m_id) == 0x00,
              "S_EquipmentPart::m_id offset mismatch");
static_assert(sizeof(S_EquipmentPart) == 0x10,
              "S_EquipmentPart size mismatch");

}  // namespace wh::entitymodule
