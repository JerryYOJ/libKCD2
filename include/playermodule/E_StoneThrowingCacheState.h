#pragma once
#include <cstdint>

namespace wh::playermodule {

// Source-reconstructed type/enumerator names; all four dword states and transitions are proved.
enum class E_StoneThrowingCacheState : std::uint32_t {
    Free = 0,
    AssignedToPile = 1,
    Active = 2,
    PendingReset = 3,
};
static_assert(sizeof(E_StoneThrowingCacheState) == 0x04,
              "stone-throwing cache state must be four bytes");

}  // namespace wh::playermodule
