#pragma once
#include <cstddef>
#include <cstdint>

// -----------------------------------------------
// wh::environmentmodule::S_PickableAreaRespawnRecord -- consumed-plant wake-up record
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x20. [SYNTHETIC NAME]
// -----------------------------------------------
// sub_182ADDCF0 builds this exact 0x20 value before inserting it into the manager's
// respawn hash. Equality helper sub_182ADBDFC compares position/radius/area ID; the
// final qword is the absolute world-time wake-up value.

namespace wh::environmentmodule {

struct S_PickableAreaRespawnRecord {
    Vec3     position;         // +0x00
    float    radius;           // +0x0C
    uint8_t  pickable_area_id; // +0x10
    uint8_t  _pad11[7];        // +0x11
    uint64_t wake_time;        // +0x18  absolute world time
};
static_assert(sizeof(S_PickableAreaRespawnRecord) == 0x20,
              "S_PickableAreaRespawnRecord must be 0x20");
static_assert(offsetof(S_PickableAreaRespawnRecord, wake_time) == 0x18,
              "wake_time must be at +0x18");

}  // namespace wh::environmentmodule
