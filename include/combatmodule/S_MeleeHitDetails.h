#pragma once
#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace wh::combatmodule {

struct S_MeleeHitDetails {
    bool         targetParryInPlace; // +0x00
    bool         wasBlocked;         // +0x01
    bool         staminaSourceTag6;  // +0x02
    bool         wasPerfectBlocked;  // +0x03
    bool         comboActive;        // +0x04
    bool         comboResult;        // +0x05
    bool         isFreeAttack;       // +0x06
    bool         isMasterStrike;     // +0x07
    std::int32_t requestValue;       // +0x08
    bool         hasDestroyedItem;   // +0x0C
    std::byte    _pad0D[3];          // +0x0D
};
static_assert(sizeof(S_MeleeHitDetails) == 0x10);
static_assert(offsetof(S_MeleeHitDetails, requestValue) == 0x08);
static_assert(offsetof(S_MeleeHitDetails, hasDestroyedItem) == 0x0C);
static_assert(std::is_trivially_copyable_v<S_MeleeHitDetails>);

}  // namespace wh::combatmodule
