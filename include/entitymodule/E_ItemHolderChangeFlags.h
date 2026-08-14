#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::E_ItemHolderChangeFlags -- holder mutation mask.
// -----------------------------------------------
// [SOURCE-RECONSTRUCTED TYPE NAME] The five bits are consumed independently by
// C_ItemHolder implementations; the original enumerator spellings are not emitted.

namespace wh::entitymodule {

enum class E_ItemHolderChangeFlags : std::uint32_t {
    None   = 0x00,
    Flag01 = 0x01, // controls the primary item relation
    Flag02 = 0x02,
    Flag04 = 0x04, // controls the secondary holder relation
    Flag08 = 0x08,
    Flag10 = 0x10, // suppresses vector mutation on split-item transitions
};
static_assert(sizeof(E_ItemHolderChangeFlags) == 0x04,
              "item-holder change flags must remain four bytes");

}  // namespace wh::entitymodule
