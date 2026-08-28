#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

namespace wh::playermodule {

class C_Blacksmithing;

struct S_BlacksmithingStrokeState {
    C_Blacksmithing* m_owner;                 // +0x00
    std::uint8_t m_unknown08[0x18];           // +0x08
    std::vector<std::uint64_t> m_entries;     // +0x20, 8-byte elements
    std::uint8_t m_unknown38[0x48];           // +0x38
};

static_assert(sizeof(S_BlacksmithingStrokeState) == 0x80,
              "S_BlacksmithingStrokeState size mismatch");
static_assert(offsetof(S_BlacksmithingStrokeState, m_entries) == 0x20,
              "S_BlacksmithingStrokeState entries offset mismatch");

} // namespace wh::playermodule
