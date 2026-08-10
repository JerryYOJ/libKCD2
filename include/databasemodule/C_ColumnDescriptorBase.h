#pragma once
#include <cstddef>
#include <cstdint>
#include "I_ColumnDescriptor.h"

// wh::databasemodule::C_ColumnDescriptorBase -- shared descriptor implementation.
// Abstract, sizeof 0x38; no standalone complete-object vtable is emitted.

namespace wh::databasemodule {

class C_ColumnDescriptorBase : public I_ColumnDescriptor {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ColumnDescriptorBase;

    E_TableDataType GetType() const override;  // [1] reads +0x08
    uint32_t GetOffset() const override;  // [2] reads +0x0C
    uint32_t GetSize() const override;  // [3] reads +0x10
    uint32_t GetAlignment() const override;  // [4] reads +0x14
    bool IsPrimaryKey() const override = 0;  // [5]
    const char* GetName() const override;  // [6] reads +0x18
    bool HasDefaultValue() const override;  // [7] reads +0x20
    const char* GetDefaultString() const override;  // [8]
    const S_ColumnDefaultValue& GetDefaultValue() const override;  // [9]
    bool OmitWhenDefault() const override;  // [10] reads +0x21
    bool ApplyDefault(void* field) const override;  // [11]
    bool IsDefaultValue(const void* field) const override;  // [12]
    bool IsTransient() const override;  // [13] reads +0x22
    bool IsNotPatched() const override;  // [14] reads +0x23
    bool unk_15() const override;  // [15] reads +0x24
    const char* GetFloatSerializationFormat() const override;  // [16] null

    E_TableDataType m_type;                  // +0x08
    uint32_t m_offset;                       // +0x0C
    uint32_t m_size;                         // +0x10
    uint32_t m_alignment;                    // +0x14
    const char* m_name;                      // +0x18, borrowed
    bool m_hasDefaultValue;                  // +0x20
    bool m_omitWhenDefault;                  // +0x21 [SYNTHETIC NAME]
    bool m_transient;                        // +0x22 [SYNTHETIC NAME]
    bool m_notPatched;                       // +0x23
    bool m_unk24;                            // +0x24
    uint8_t _pad25[3];                       // +0x25
    S_ColumnDefaultValue m_defaultValue;     // +0x28
};
static_assert(sizeof(C_ColumnDescriptorBase) == 0x38,
              "C_ColumnDescriptorBase must be 0x38");
static_assert(offsetof(C_ColumnDescriptorBase, m_name) == 0x18,
              "column name at 0x18");
static_assert(offsetof(C_ColumnDescriptorBase, m_defaultValue) == 0x28,
              "column default store at 0x28");

}  // namespace wh::databasemodule
