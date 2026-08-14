#pragma once
#include <cstddef>
#include <cstdint>
#include "../Offsets/vtables/IRenderNode.h"

// -----------------------------------------------
// wh::environmentmodule::S_PickableAreaInstance -- tracked vegetation/merged-mesh
// plant record (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x30. [SYNTHETIC NAME]
// -----------------------------------------------
// Instance scans sub_1809F2F7C/sub_182ADDA1C advance by 0x30. Writers prove the
// render-node pointer, Vec3 position, byte area ID, byte availability flag, and AABB.

namespace wh::environmentmodule {

struct S_PickableAreaInstance {
    Offsets::IRenderNode* render_node;      // +0x00  vegetation node or owning merged-mesh node
    Vec3                  position;         // +0x08  interaction point
    uint8_t               pickable_area_id; // +0x14
    bool                  available;        // +0x15  cleared when consumed
    uint8_t               _pad16[2];        // +0x16
    AABB                  bounds;           // +0x18  selection/intersection bounds
};
static_assert(sizeof(S_PickableAreaInstance) == 0x30,
              "S_PickableAreaInstance must match the 0x30 instance stride");
static_assert(offsetof(S_PickableAreaInstance, pickable_area_id) == 0x14,
              "pickable_area_id must be at +0x14");
static_assert(offsetof(S_PickableAreaInstance, bounds) == 0x18,
              "bounds must be at +0x18");

}  // namespace wh::environmentmodule
