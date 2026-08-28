#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::rpgmodule {

struct S_DocumentRarity {
    CryStringT<char> m_name;                              // +0x00
    float m_xpMultiplier;                                 // +0x08 RTTR "XPMultiplier"
    std::uint8_t _pad0C[4];                               // +0x0C
};

static_assert(offsetof(S_DocumentRarity, m_xpMultiplier) == 0x08,
              "S_DocumentRarity::m_xpMultiplier offset mismatch");
static_assert(sizeof(S_DocumentRarity) == 0x10,
              "S_DocumentRarity size mismatch");

}  // namespace wh::rpgmodule
