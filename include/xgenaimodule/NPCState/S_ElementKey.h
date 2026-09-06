#pragma once
#include <cstddef>
#include <cstdint>
#include "../../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::xgenaimodule::NPCState::S_ElementKey -- sret payload of I_Element::GetKey
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x10. [SYNTHETIC name; ABI proven]
// -----------------------------------------------
// Base GetKey 0x181AA9C40 returns {empty qword_18533A588, 0}.
// C_HandContentElement 0x1808F973C writes {this+0x18 CryString, int32(hand==1)};
// C_ItemSetAsideElement 0x1816E5F80 writes {this+0x28 CryString, int32 this+0x38}.

namespace wh::xgenaimodule::NPCState {

struct S_ElementKey {
    CryStringT<char> name;       // +0x00 interned
    std::int32_t     qualifier;  // +0x08
    std::uint8_t     _pad0C[4];  // +0x0C
};
static_assert(sizeof(S_ElementKey) == 0x10, "S_ElementKey size mismatch");

}  // namespace wh::xgenaimodule::NPCState
