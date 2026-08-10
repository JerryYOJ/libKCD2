#pragma once
#include <cstddef>
#include <cstdint>

// Fixed retail TBL header read before the native row and string blocks. [SYNTHETIC NAME]

namespace wh::databasemodule {

struct S_TBLTableHeader {
    int32_t m_formatVersion;       // +0x00, required value 3
    uint32_t m_nameTypeHash;       // +0x04
    uint32_t m_layoutHash;         // +0x08
    int32_t m_tableVersion;        // +0x0C
    int32_t m_rowCount;            // +0x10
    int32_t m_stringDataSize;      // +0x14
    int32_t m_stringCount;         // +0x18
};
static_assert(sizeof(S_TBLTableHeader) == 0x1C,
              "S_TBLTableHeader must be 0x1C");

}  // namespace wh::databasemodule
