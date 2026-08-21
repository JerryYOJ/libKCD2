#pragma once
#include <cstddef>
#include "S_SpatialGridKey.h"

namespace wh::combatmodule {

// Reconstructed declaration placement; the binary hash algorithm remains open.
struct S_SpatialGridKeyHash {
    std::size_t operator()(const S_SpatialGridKey& key) const noexcept;
};
static_assert(sizeof(S_SpatialGridKeyHash) == 0x01);

}  // namespace wh::combatmodule
