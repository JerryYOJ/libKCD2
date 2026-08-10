#pragma once
#include <cstddef>
#include <cstdint>
#include "C_ColumnDescriptorBase.h"

namespace wh::databasemodule {

class C_RenamedColumnDescriptor : public C_ColumnDescriptorBase {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_RenamedColumnDescriptor;

    bool IsPrimaryKey() const override;  // [5] reads +0x38

    bool m_isPrimaryKey;  // +0x38
    uint8_t _pad39[7];    // +0x39
};
static_assert(sizeof(C_RenamedColumnDescriptor) == 0x40,
              "C_RenamedColumnDescriptor must be 0x40");
static_assert(offsetof(C_RenamedColumnDescriptor, m_isPrimaryKey) == 0x38,
              "renamed primary-key state at 0x38");

}  // namespace wh::databasemodule
