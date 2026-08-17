#pragma once
#include <array>
#include <cstdint>

// -----------------------------------------------
// wh::animationmodule::S_AnimatedActionTagState -- KCD2 WHGame.dll 1.5.6. sizeof 0x14.
// -----------------------------------------------
// Source-reconstructed name for the 20-byte Mannequin tag bitfield embedded twice by
// C_AnimatedActionData. CTagDefinition setter sub_1804AC88C addresses it bytewise.

namespace wh::animationmodule {

struct S_AnimatedActionTagState {
    std::array<std::uint8_t, 0x14> m_bits;
};
static_assert(sizeof(S_AnimatedActionTagState) == 0x14);

}  // namespace wh::animationmodule
