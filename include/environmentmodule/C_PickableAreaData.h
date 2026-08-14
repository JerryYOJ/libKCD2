#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

// -----------------------------------------------
// wh::environmentmodule::C_PickableAreaData -- parsed pickable-area definition
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x58.
// -----------------------------------------------
// Converter sub_1813D278C copies the serialized fields and folds every matching
// pickable_area_material path into the uint32 CRC vector at +0x40. ParseRows
// sub_1813D25F8 advances the destination vector by 0x58 per object.

namespace wh::environmentmodule {

class C_PickableAreaData {
public:
    uint8_t               id;                 // +0x00  byte-width proven by converter/rebuild stores
    uint8_t               _pad01[7];          // +0x01
    CryStringT<char>       name;               // +0x08
    int32_t                amount;             // +0x10
    float                  respawn_time;       // +0x14  game-world hours
    CryGUID                guid_item_picked;   // +0x18
    float                  anim_speed;         // +0x28
    uint8_t                _pad2C[4];          // +0x2C
    CryStringT<char>       anim_fragment;      // +0x30
    CryStringT<char>       anim_tags;          // +0x38
    std::vector<uint32_t>  material_path_crcs; // +0x40  case-folded CGF-path CRCs
};
static_assert(sizeof(C_PickableAreaData) == 0x58,
              "C_PickableAreaData must match the 0x58 parsed-object stride");
static_assert(offsetof(C_PickableAreaData, guid_item_picked) == 0x18,
              "guid_item_picked must be at +0x18");
static_assert(offsetof(C_PickableAreaData, material_path_crcs) == 0x40,
              "material_path_crcs must be at +0x40");

}  // namespace wh::environmentmodule
