#pragma once
#include <cstddef>
#include <cstdint>

// -----------------------------------------------
// wh::environmentmodule::S_PickableAreaMaterial -- parsed material-to-area mapping
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x10.
// -----------------------------------------------
// ParseRows sub_1814F31F0 copies the int32 ID and constructs an owned CryStringT<char>
// at +0x08, advancing the destination vector by 0x10 per object.

namespace wh::environmentmodule {

struct S_PickableAreaMaterial {
    int32_t          pickable_area_id; // +0x00
    uint8_t          _pad04[4];        // +0x04
    CryStringT<char> material_name;    // +0x08  CGF asset path
};
static_assert(sizeof(S_PickableAreaMaterial) == 0x10,
              "S_PickableAreaMaterial must match the 0x10 parsed-object stride");
static_assert(offsetof(S_PickableAreaMaterial, material_name) == 0x08,
              "material_name must be at +0x08");

}  // namespace wh::environmentmodule
