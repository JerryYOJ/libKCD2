#pragma once
#include <cstddef>
#include <cstdint>
#include "E_StoneThrowingCacheState.h"
#include "../CryEngine/CryAction/GameObjectTypes.h"
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/TimeValue.h"
#include "../EntityEffects/TAttachedEffectId.h"

namespace wh::playermodule {

// Source-reconstructed name; exact shared Cache/pile record layout.
struct S_StoneThrowingCacheEntry {
    EntityId m_entityId;                                      // +0x00
    EntityId m_ownerPileEntityId;                             // +0x04, zero when unassigned
    QuatT m_transform08;                                      // +0x08, captured on cache insertion
    QuatT m_transform24;                                      // +0x24, refreshed during launch
    E_StoneThrowingCacheState m_state;                        // +0x40
    std::uint32_t _pad44;                                     // +0x44
    CTimeValue m_time48;                                      // +0x48, role OPEN; init -100000
    std::uint32_t m_referenceCount;                           // +0x50
    std::uint32_t _pad54;                                     // +0x54
    CTimeValue m_rollingEffectUntil;                          // +0x58
    EntityEffects::TAttachedEffectId m_rollingEffectId;       // +0x60, f_stone_rolling
    std::uint32_t _pad64;                                     // +0x64
};

static_assert(sizeof(S_StoneThrowingCacheEntry) == 0x68,
              "S_StoneThrowingCacheEntry must be 0x68");
static_assert(offsetof(S_StoneThrowingCacheEntry, m_transform08) == 0x08,
              "first stone transform must be at 0x08");
static_assert(offsetof(S_StoneThrowingCacheEntry, m_transform24) == 0x24,
              "second stone transform must be at 0x24");
static_assert(offsetof(S_StoneThrowingCacheEntry, m_state) == 0x40,
              "stone cache state must be at 0x40");
static_assert(offsetof(S_StoneThrowingCacheEntry, m_time48) == 0x48,
              "first stone time must be at 0x48");
static_assert(offsetof(S_StoneThrowingCacheEntry, m_referenceCount) == 0x50,
              "stone reference count must be at 0x50");
static_assert(offsetof(S_StoneThrowingCacheEntry, m_rollingEffectUntil) == 0x58,
              "rolling effect timer must be at 0x58");
static_assert(offsetof(S_StoneThrowingCacheEntry, m_rollingEffectId) == 0x60,
              "rolling effect id must be at 0x60");

}  // namespace wh::playermodule
