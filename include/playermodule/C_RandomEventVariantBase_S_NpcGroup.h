#pragma once
#include <cstddef>
#include <cstdint>

#include "C_RandomEventVariantBase.h"

namespace wh::playermodule {

struct C_RandomEventVariantBase::S_NpcGroup {
    CryStringT<char> m_soulPool;                             // +0x00
    CryStringT<char> m_soulName;                             // +0x08
    CryStringT<char> m_tagPoints;                            // +0x10
    CryStringT<char> m_npcAssetName;                         // +0x18
    CryStringT<char> m_schedulerProxy;                       // +0x20
    C_RandomEventNonNegativeValue m_count;                        // +0x28
    C_RandomEventNonNegativeValue m_countStandardDeviation;       // +0x2C
    float m_countDifficultyAddPerNpc;                        // +0x30
    std::uint8_t m_padding34[4];
};

static_assert(sizeof(C_RandomEventVariantBase::S_NpcGroup) == 0x38,
              "C_RandomEventVariantBase::S_NpcGroup size mismatch");
static_assert(offsetof(C_RandomEventVariantBase::S_NpcGroup, m_soulPool) == 0x00,
              "S_NpcGroup soul pool offset mismatch");
static_assert(offsetof(C_RandomEventVariantBase::S_NpcGroup, m_count) == 0x28,
              "S_NpcGroup count offset mismatch");
static_assert(offsetof(C_RandomEventVariantBase::S_NpcGroup,
                       m_countDifficultyAddPerNpc) == 0x30,
              "S_NpcGroup difficulty offset mismatch");

} // namespace wh::playermodule
