#pragma once
#include "C_ColumnDescriptor.h"

namespace wh::databasemodule {

class C_PKColumnDescriptor : public C_ColumnDescriptor {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PKColumnDescriptor;

    bool IsPrimaryKey() const override;  // [5] 0x18041A6A0
};
static_assert(sizeof(C_PKColumnDescriptor) == 0x38,
              "C_PKColumnDescriptor must be 0x38");

}  // namespace wh::databasemodule
