#pragma once
#include <cstddef>
#include <cstdint>

// Owned built-in dynamic-enum adapter entry. [SYNTHETIC NAME]

namespace wh::databasemodule {

class C_DatabaseDynamicEnum;

struct S_OwnedDynamicEnumEntry {
    uint32_t m_nameHash;                    // +0x00, lowercase ASCII CRC32
    C_DatabaseDynamicEnum* m_adapter;       // +0x08, owned
};
static_assert(sizeof(S_OwnedDynamicEnumEntry) == 0x10,
              "S_OwnedDynamicEnumEntry must be 0x10");
static_assert(offsetof(S_OwnedDynamicEnumEntry, m_adapter) == 0x08,
              "owned dynamic-enum adapter at 0x08");

}  // namespace wh::databasemodule
