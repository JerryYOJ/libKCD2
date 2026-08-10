#pragma once
#include "C_FileTableSerializer.h"

namespace wh::databasemodule {

class C_TBLTableSerializer : public C_FileTableSerializer {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_TBLTableSerializer;

    bool IsBinary() const override;                    // [1] true
    const char* GetName() const override;              // [2] "TBL"
    bool Load(S_DatabaseTableRecord& table) override;  // [6] 0x182749088
    const char* GetFileExtension() const override;     // [9] "tbl"
};
static_assert(sizeof(C_TBLTableSerializer) == 0x18,
              "C_TBLTableSerializer must be 0x18");

}  // namespace wh::databasemodule
