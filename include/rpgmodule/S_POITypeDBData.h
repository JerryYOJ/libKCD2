#pragma once
#include <cstdint>
#include <cstddef>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

// -----------------------------------------------
// wh::rpgmodule::S_POITypeDBData -- raw poi_type table row (KCD2 WHGame.dll 1.5.6, sjw7).
// -----------------------------------------------
// Register [7] descriptors in sub_1801AE1D0 (globals qword_1854B7610..7648). Stride 0x40
// from the last column (ui_order @+0x3C, size 4). Strings point into the table pool.

namespace wh::rpgmodule {

struct S_POITypeDBData {
    CryGUID      m_poiTypeId;                // +0x00  column "poi_type_id"
    const char*  m_poiTypeName;              // +0x10  column "poi_type_name"
    int32_t      m_markType;                 // +0x18  column "mark_type" (default -1)
    uint8_t      _pad1C[4];                  // +0x1C
    const char*  m_label;                    // +0x20  column "label"
    float        m_discoveryDist;            // +0x28  column "discovery_dist"
    uint8_t      _pad2C[4];                  // +0x2C
    const char*  m_discoveryMsgMode;         // +0x30  column "discovery_msg_mode"
    bool         m_discoverableByLocation;   // +0x38  column "discoverable_by_location"
    uint8_t      _pad39[3];                  // +0x39
    int32_t      m_uiOrder;                  // +0x3C  column "ui_order"
};
static_assert(sizeof(S_POITypeDBData) == 0x40, "S_POITypeDBData must be 0x40 (column stride)");
static_assert(offsetof(S_POITypeDBData, m_discoveryDist) == 0x28, "discovery_dist at 0x28");
static_assert(offsetof(S_POITypeDBData, m_discoverableByLocation) == 0x38, "discoverable_by_location at 0x38");

}  // namespace wh::rpgmodule
