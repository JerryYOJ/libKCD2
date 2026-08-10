#pragma once
#include <cstddef>
#include <cstdint>
#include "I_DynamicEnum.h"

// wh::databasemodule::C_DatabaseDynamicEnum -- owned table-backed enum adapter.
// sizeof 0x18; vtable 0x183A94E38, exactly five slots and no virtual destructor.

namespace wh::databasemodule {

struct S_DatabaseTableRecord;

class C_DatabaseDynamicEnum : public I_DynamicEnum {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_DatabaseDynamicEnum;

    uint32_t GetCount() const override;                         // [0] 0x1819E09C0
    uint32_t GetValue(uint32_t index) const override;           // [1] 0x181531D20
    const char* GetName(uint32_t index) const override;         // [2] 0x181531D3C
    uint32_t GetValueByName(const char* name) const override;   // [3] 0x1808B2B98
    const char* GetNameByValue(uint32_t value) const override;  // [4] 0x1806F8DF8

    S_DatabaseTableRecord* m_table;  // +0x08, borrowed
    CryStringT<char> m_tableName;    // +0x10
};
static_assert(sizeof(C_DatabaseDynamicEnum) == 0x18,
              "C_DatabaseDynamicEnum must be 0x18");
static_assert(offsetof(C_DatabaseDynamicEnum, m_table) == 0x08,
              "dynamic-enum table record at 0x08");
static_assert(offsetof(C_DatabaseDynamicEnum, m_tableName) == 0x10,
              "dynamic-enum table name at 0x10");

}  // namespace wh::databasemodule
