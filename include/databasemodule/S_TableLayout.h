#pragma once
#include <cstdint>

// wh::databasemodule::S_TableLayout -- registered column layout. [SYNTHETIC NAME]
// sizeof 0x20; allocated by generated-layout builder 0x180D17458.

namespace wh::databasemodule {

class I_ColumnDescriptor;

struct S_TableLayout {
    int32_t              m_columnCount;      // +0x00
    uint32_t             _pad04;             // +0x04
    I_ColumnDescriptor** m_ppColumns;        // +0x08
    int32_t              m_rowStride;        // +0x10
    int32_t              m_versionNumber;    // +0x14
    uint32_t             m_nameTypeHash;     // +0x18
    uint32_t             m_memoryLayoutHash; // +0x1C
};
static_assert(sizeof(S_TableLayout) == 0x20, "S_TableLayout must be 0x20");

}  // namespace wh::databasemodule
