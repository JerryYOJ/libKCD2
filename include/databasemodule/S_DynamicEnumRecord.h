#pragma once
#include <cstddef>
#include <cstdint>

// Borrowed dynamic-enum provider registration. [SYNTHETIC NAME]

namespace wh::databasemodule {

class I_DynamicEnum;

struct S_DynamicEnumRecord {
    uint32_t m_nameHash;              // +0x00, lowercase ASCII CRC32
    I_DynamicEnum* m_provider;        // +0x08, borrowed
    CryStringT<char> m_tableName;     // +0x10
};
static_assert(sizeof(S_DynamicEnumRecord) == 0x18,
              "S_DynamicEnumRecord must be 0x18");
static_assert(offsetof(S_DynamicEnumRecord, m_provider) == 0x08,
              "dynamic-enum provider at 0x08");
static_assert(offsetof(S_DynamicEnumRecord, m_tableName) == 0x10,
              "dynamic-enum table name at 0x10");

}  // namespace wh::databasemodule
