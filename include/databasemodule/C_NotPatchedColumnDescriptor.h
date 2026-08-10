#pragma once
#include "C_ColumnDescriptor.h"

namespace wh::databasemodule {

class C_NotPatchedColumnDescriptor : public C_ColumnDescriptor {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_NotPatchedColumnDescriptor;
};
static_assert(sizeof(C_NotPatchedColumnDescriptor) == 0x38,
              "C_NotPatchedColumnDescriptor must be 0x38");

}  // namespace wh::databasemodule
