#pragma once
#include <cstddef>
#include <cstdint>
#include "E_TableDataType.h"
#include "S_ColumnDefaultValue.h"

// wh::databasemodule::I_ColumnDescriptor -- table-column descriptor interface.
// sizeof 0x08; vtable 0x183E192F8, exactly 17 slots.

namespace wh::databasemodule {

class I_ColumnDescriptor {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_ColumnDescriptor;

    virtual ~I_ColumnDescriptor() = 0;  // [0] 0x1825BCADC
    virtual E_TableDataType GetType() const = 0;  // [1]
    virtual uint32_t GetOffset() const = 0;  // [2]
    virtual uint32_t GetSize() const = 0;  // [3]
    virtual uint32_t GetAlignment() const = 0;  // [4]
    virtual bool IsPrimaryKey() const = 0;  // [5]
    virtual const char* GetName() const = 0;  // [6]
    virtual bool HasDefaultValue() const = 0;  // [7]
    virtual const char* GetDefaultString() const = 0;  // [8]
    virtual const S_ColumnDefaultValue& GetDefaultValue() const = 0;  // [9]
    virtual bool OmitWhenDefault() const = 0;  // [10] [SYNTHETIC NAME]
    virtual bool ApplyDefault(void* field) const = 0;  // [11]
    virtual bool IsDefaultValue(const void* field) const = 0;  // [12]
    virtual bool IsTransient() const = 0;  // [13] [SYNTHETIC NAME]
    virtual bool IsNotPatched() const = 0;  // [14]
    virtual bool unk_15() const = 0;  // [15] reads descriptor +0x24
    virtual const char* GetFloatSerializationFormat() const = 0;  // [16]
};
static_assert(sizeof(I_ColumnDescriptor) == 0x08,
              "I_ColumnDescriptor must be 0x08");

}  // namespace wh::databasemodule
