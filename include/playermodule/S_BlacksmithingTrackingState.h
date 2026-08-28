#pragma once
#include <cstddef>
#include <cstdint>
#include <set>

namespace wh::playermodule {

class C_Blacksmithing;

struct S_BlacksmithingTrackingState {
    C_Blacksmithing* m_owner;                 // +0x00
    std::int64_t m_timestamp;                 // +0x08, ctor -100000
    std::set<std::uint64_t> m_primary;        // +0x10, element semantics unresolved
    std::set<std::uint64_t> m_secondary;      // +0x20, element semantics unresolved
};

static_assert(sizeof(S_BlacksmithingTrackingState) == 0x30,
              "S_BlacksmithingTrackingState size mismatch");
static_assert(offsetof(S_BlacksmithingTrackingState, m_primary) == 0x10,
              "S_BlacksmithingTrackingState primary offset mismatch");

} // namespace wh::playermodule
