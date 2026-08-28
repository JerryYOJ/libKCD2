#pragma once

#include <cstddef>
#include <cstdint>

namespace wh::entitymodule {

// Source name unresolved; scheduler 0x180666AF8 proves the complete field map.
struct S_ClothingSystemCursor {
    void* m_owner;                                          // +0x00
    void* m_position;                                       // +0x08
    std::uint32_t m_processed;                              // +0x10
    std::uint32_t m_limit;                                  // +0x14
    double m_time;                                          // +0x18
};

static_assert(offsetof(S_ClothingSystemCursor, m_processed) == 0x10,
              "S_ClothingSystemCursor::m_processed offset mismatch");
static_assert(offsetof(S_ClothingSystemCursor, m_time) == 0x18,
              "S_ClothingSystemCursor::m_time offset mismatch");
static_assert(sizeof(S_ClothingSystemCursor) == 0x20,
              "S_ClothingSystemCursor size mismatch");

}  // namespace wh::entitymodule
