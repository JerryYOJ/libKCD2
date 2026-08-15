#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"

namespace wh::playermodule {

// Source-reconstructed name; exact trivial element stored by C_StoneThrowingPile.
struct S_StoneThrowingNodePair {
    Vec3 m_from;                     // +0x00
    Vec3 m_to;                       // +0x0C
    bool m_alternateSide;            // +0x18, assigned alternately after rebuild
    std::uint8_t _pad19[3];          // +0x19
};

static_assert(sizeof(S_StoneThrowingNodePair) == 0x1C,
              "S_StoneThrowingNodePair must be 0x1C");
static_assert(offsetof(S_StoneThrowingNodePair, m_to) == 0x0C,
              "second node position must be at 0x0C");
static_assert(offsetof(S_StoneThrowingNodePair, m_alternateSide) == 0x18,
              "node side byte must be at 0x18");

}  // namespace wh::playermodule
