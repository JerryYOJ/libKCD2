#pragma once
#include "C_ColumnDescriptorBase.h"

namespace wh::databasemodule {

class C_ColumnDescriptor : public C_ColumnDescriptorBase {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ColumnDescriptor;

    bool IsPrimaryKey() const override;  // [5] 0x180838AE0
};
static_assert(sizeof(C_ColumnDescriptor) == 0x38,
              "C_ColumnDescriptor must be 0x38");

}  // namespace wh::databasemodule
