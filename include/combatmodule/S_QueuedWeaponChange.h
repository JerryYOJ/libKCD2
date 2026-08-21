#pragma once
#include <cstddef>
#include <cstdint>
#include "../entitymodule/E_HandSlot.h"
#include "../framework/WUID.h"

namespace wh::combatmodule {

struct S_QueuedWeaponChange {
    wh::entitymodule::E_HandSlot m_hand;     // +0x00
    std::uint32_t                _pad04;     // +0x04
    wh::framework::WUID          m_itemWuid; // +0x08
};
static_assert(sizeof(S_QueuedWeaponChange) == 0x10);
static_assert(offsetof(S_QueuedWeaponChange, m_hand) == 0x00);
static_assert(offsetof(S_QueuedWeaponChange, m_itemWuid) == 0x08);

}  // namespace wh::combatmodule
