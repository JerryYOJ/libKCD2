#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::environmentmodule::S_PickableAreaMaterialDBData -- raw
// "pickable_area_material" table row (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x10.
// -----------------------------------------------
// Register descriptor builder sub_180164EB0 defines the int32 ID at +0x00 and
// string column at +0x08. ParseRows sub_1814F31F0 walks raw rows at a 0x10 stride.

namespace wh::environmentmodule {

struct S_PickableAreaMaterialDBData {
    int32_t     pickable_area_id; // +0x00
    uint8_t     _pad04[4];        // +0x04
    const char* material_name;    // +0x08  CGF asset path, PK
};
static_assert(sizeof(S_PickableAreaMaterialDBData) == 0x10,
              "S_PickableAreaMaterialDBData must match the 0x10 raw-row stride");

}  // namespace wh::environmentmodule
