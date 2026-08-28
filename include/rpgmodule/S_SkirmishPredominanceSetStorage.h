#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::rpgmodule {

// Layout shell for an MSVC tree container whose node-entry type is not yet
// recoverable. Constructor/destructor and traversal prove the 0x10 tree object.
struct alignas(8) S_SkirmishPredominanceSetStorage {
    std::uint8_t m_tree[0x10];
};

static_assert(sizeof(S_SkirmishPredominanceSetStorage) == 0x10,
              "S_SkirmishPredominanceSetStorage size mismatch");

} // namespace wh::rpgmodule
