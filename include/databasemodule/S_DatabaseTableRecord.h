#pragma once
#include <cstddef>
#include <cstdint>
#include "E_DatabaseTableFlags.h"
#include "S_TableLayout.h"

// wh::databasemodule::S_DatabaseTableRecord -- module-owned registered table state.
// sizeof 0x58; constructor 0x180D17F20. [SYNTHETIC NAME]

namespace wh::databasemodule {

class I_TableSerializer;

struct S_DatabaseTableRecord {
    std::byte*        m_pRows;                         // +0x00, owned while loaded
    uint32_t          m_rowCount;                      // +0x08
    uint32_t          m_rowAllocationCount;            // +0x0C
    char*             m_pStringPool;                   // +0x10, owned while loaded
    uint32_t          m_stringPoolBytes;               // +0x18
    uint32_t          m_stringPoolAllocationBytes;     // +0x1C
    uint32_t          m_relocatedStringReferenceCount; // +0x20
    uint32_t          m_uniqueStringCount;             // +0x24
    CryStringT<char>  m_tableName;                     // +0x28
    CryStringT<char>  m_pathPrefix;                    // +0x30
    int32_t           m_versionNumber;                 // +0x38
    uint32_t          _pad3C;                          // +0x3C
    S_TableLayout*    m_pLayout;                       // +0x40, borrowed
    I_TableSerializer* m_pSerializer;                  // +0x48, borrowed
    E_DatabaseTableFlags m_flags;                      // +0x50
    bool              m_loaded;                        // +0x54
    uint8_t           _pad55[3];                       // +0x55
};
static_assert(sizeof(S_DatabaseTableRecord) == 0x58, "S_DatabaseTableRecord must be 0x58");
static_assert(offsetof(S_DatabaseTableRecord, m_tableName) == 0x28, "table name at 0x28");
static_assert(offsetof(S_DatabaseTableRecord, m_pLayout) == 0x40, "layout at 0x40");
static_assert(offsetof(S_DatabaseTableRecord, m_loaded) == 0x54, "loaded flag at 0x54");

}  // namespace wh::databasemodule
