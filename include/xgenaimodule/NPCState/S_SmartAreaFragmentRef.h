#pragma once
#include <cstddef>
#include <cstdint>

// -----------------------------------------------
// wh::xgenaimodule::NPCState::S_SmartAreaFragmentRef -- sret payload of
// C_AnimActionBase::GetSmartAreaFragmentRef (KCD2 WHGame.dll Steam 1.5.6).
// sizeof 0x10. [INFERRED name; ABI proven]
// -----------------------------------------------
// Slot-44 default 0x1816E94F0 writes {0xFFFF, null}; concrete writers
// 0x18162A4DC / 0x181523924 / 0x180399304 pair a C_SmartArea* with a 16-bit
// fragment id (WUID resolver 0x1807E3738, tag 7 = SmartArea registry).

namespace wh::xgenaimodule {
class C_SmartArea;
}

namespace wh::xgenaimodule::NPCState {

struct S_SmartAreaFragmentRef {
    std::uint16_t fragmentId;      // +0x00  0xFFFF = none
    std::uint8_t  _pad02[6];       // +0x02
    C_SmartArea*  smartArea;       // +0x08
};
static_assert(sizeof(S_SmartAreaFragmentRef) == 0x10, "S_SmartAreaFragmentRef size mismatch");

}  // namespace wh::xgenaimodule::NPCState
