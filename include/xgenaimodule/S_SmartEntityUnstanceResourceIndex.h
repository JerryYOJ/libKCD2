#pragma once
#include <cstddef>
#include <cstdint>

// Sorted internal unstance-resource lookup entry. [SYNTHETIC NAME]

namespace wh::xgenaimodule {

struct S_SmartEntityUnstanceResourceIndex {
    int32_t m_resourceId;       // +0x00
    uint16_t m_resourceIndex;   // +0x04
    uint16_t _pad06;            // +0x06
};
static_assert(sizeof(S_SmartEntityUnstanceResourceIndex) == 0x08,
              "S_SmartEntityUnstanceResourceIndex must be 0x08");

}  // namespace wh::xgenaimodule
