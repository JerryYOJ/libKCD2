#pragma once
#include <vector>
#include "../xgenaimodule/I_Area.h"
#include "I_TagPoint.h"

// -----------------------------------------------
// Mapped value of C_SniffableItemManager (KCD2 WHGame.dll 1.5.6).
// sizeof 0x30. No RTTI — [SYNTHETIC NAME].
// -----------------------------------------------
// Insert copies two MSVC std::vector (begin/end/cap) onto the hash node at +0x20/+0x38.
// Field names are the C_SniffableItem RTTR ports that produce them.

namespace wh::entitymodule {

struct S_SniffableItemData {
    std::vector<wh::xgenaimodule::I_Area*> m_areas;          // +0x00
    std::vector<I_TagPoint*>               m_targetPoints;   // +0x18
};
static_assert(sizeof(S_SniffableItemData) == 0x30,
              "S_SniffableItemData is two std::vector (0x18+0x18)");

}  // namespace wh::entitymodule
