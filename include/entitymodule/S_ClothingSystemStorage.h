#pragma once

#include <cstddef>
#include <cstdint>

namespace wh::entitymodule {

// Source name unresolved; constructor 0x180EE88C0 and teardown helpers prove 0x68.
struct S_ClothingSystemStorage {
    std::uint64_t m_config00;                               // +0x00
    std::uint64_t m_config08;                               // +0x08
    std::uint8_t m_unknown10[0x28];                         // +0x10
    std::uint64_t m_stride;                                 // +0x38, initialized 0x18
    std::uint64_t m_alignment;                              // +0x40, initialized 0x08
    std::uint64_t m_unknown48;                              // +0x48
    std::uint64_t m_unknown50;                              // +0x50
    void* m_self;                                           // +0x58
    std::uint64_t m_unknown60;                              // +0x60
};

static_assert(offsetof(S_ClothingSystemStorage, m_stride) == 0x38,
              "S_ClothingSystemStorage::m_stride offset mismatch");
static_assert(offsetof(S_ClothingSystemStorage, m_self) == 0x58,
              "S_ClothingSystemStorage::m_self offset mismatch");
static_assert(sizeof(S_ClothingSystemStorage) == 0x68,
              "S_ClothingSystemStorage size mismatch");

}  // namespace wh::entitymodule
