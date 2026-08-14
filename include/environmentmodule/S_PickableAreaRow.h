#pragma once
#include <cstdint>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

// -----------------------------------------------
// wh::environmentmodule::S_PickableAreaRow -- raw "pickable_area_desc" table row
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x40.
// -----------------------------------------------
// Register descriptor builder sub_180164B60 defines eight columns at offsets
// 0x00/0x08/0x10/0x14/0x18/0x28/0x30/0x38. ParseRows sub_1813D25F8 walks
// the raw table with a 0x40 stride and converts each row through sub_1813D278C.

namespace wh::environmentmodule {

struct S_PickableAreaRow {
    int32_t     id;                // +0x00  PK; converted to uint8_t in C_PickableAreaData
    uint8_t     _pad04[4];         // +0x04
    const char* name;              // +0x08
    int32_t     amount;            // +0x10
    float       respawn_time;      // +0x14  game-world hours
    CryGUID     guid_item_picked;  // +0x18
    float       anim_speed;        // +0x28
    uint8_t     _pad2C[4];         // +0x2C
    const char* anim_fragment;     // +0x30
    const char* anim_tags;         // +0x38
};
static_assert(sizeof(S_PickableAreaRow) == 0x40,
              "S_PickableAreaRow must match the 0x40 raw-row stride");

}  // namespace wh::environmentmodule
