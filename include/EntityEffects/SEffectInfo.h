#pragma once
#include <cstddef>
#include <cstdint>
#include "TAttachedEffectId.h"

namespace EntityEffects {

struct SEffectInfo {
    TAttachedEffectId id;             // +0x00
    int entityEffectSlot;             // +0x04
    int characterEffectSlot;          // +0x08
    std::uint32_t _pad0C;             // +0x0C
    CryStringT<char> helperName;       // +0x10
};
static_assert(sizeof(SEffectInfo) == 0x18, "SEffectInfo must be 0x18");
static_assert(offsetof(SEffectInfo, helperName) == 0x10,
              "effect helper name must be at 0x10");

}  // namespace EntityEffects
