#pragma once
#include <cstdint>
#include <cstddef>
#include "../framework/C_OverrideConflictManager.h"
#include "../framework/WUID.h"

// -----------------------------------------------
// wh::entitymodule::C_HorseUsageManager -- KCD2 WHGame.dll.  sizeof 0x80.
// -----------------------------------------------
// RTTI : C_OverrideConflictManager<WUID,WUID>. Alloc 0x80, ctor sub_181064934.
// Owner C_EntityModule+0x1B8. +0x18 is a 0x10-stride WUID pair array.

namespace wh::entitymodule {

class C_HorseUsageManager
    : public wh::framework::C_OverrideConflictManager<wh::framework::WUID, wh::framework::WUID> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_HorseUsageManager;
    void OcmVf1() override {}   // [1] Find  0x18124DA28
    void OcmVf2() override {}   // [2] Set   0x18124DC3C

    wh::framework::WUID* m_pPairs;        // +0x18
    uint64_t             m_pairCount;     // +0x20
    uint64_t             m_pairCapacity;  // +0x28
    uint32_t             m_zero30;        // +0x30  ctor 2
    uint32_t             _pad34;          // +0x34
    uint64_t             m_q38;           // +0x38
    uint64_t             m_q40;           // +0x40
    uint8_t              m_block48[0x30]; // +0x48
    int32_t              m_neg78;         // +0x78  -1
    uint32_t             m_zero7C;        // +0x7C
};
static_assert(sizeof(C_HorseUsageManager) == 0x80, "C_HorseUsageManager must be 0x80");
static_assert(offsetof(C_HorseUsageManager, m_pPairs) == 0x18, "pairs");
static_assert(offsetof(C_HorseUsageManager, m_neg78) == 0x78, "sentinel");

}  // namespace wh::entitymodule
