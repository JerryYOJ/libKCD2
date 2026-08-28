#pragma once
#include <cstddef>
#include "E_ForgeAssetSlot.h"

// -----------------------------------------------
// wh::playermodule::S_ForgeSlotPrerequisite
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x02. No vtable.
// -----------------------------------------------

namespace wh::playermodule {

struct S_ForgeSlotPrerequisite {
    E_ForgeAssetSlot::Type m_slot;                        // +0x00 RTTR "slot"
    E_ForgeAssetSlot::Type m_prerequisite;                // +0x01 RTTR "prerequisite"
};

static_assert(offsetof(S_ForgeSlotPrerequisite, m_slot) == 0x00,
              "S_ForgeSlotPrerequisite::m_slot offset mismatch");
static_assert(sizeof(S_ForgeSlotPrerequisite) == 0x02,
              "S_ForgeSlotPrerequisite size mismatch");

}  // namespace wh::playermodule
