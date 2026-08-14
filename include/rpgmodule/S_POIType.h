#pragma once
#include <cstdint>
#include <cstddef>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "E_DiscoveryMsgMode.h"

// -----------------------------------------------
// wh::rpgmodule::S_POIType -- parsed poi_type row (KCD2 WHGame.dll 1.5.6, sjw7).
// -----------------------------------------------
// C_POITypeDatabase::m_objects element. sizeof 0x38 PROVEN: ParseRows [10]
// sub_181342680 walks xmmword_18532DC80 with += 0x38. Converter sub_18134277C.
// This is the row I_RPGLocationManager::FindPOIType / FindPOITypeByMarkType return.

namespace wh::rpgmodule {

struct S_POIType {
    CryGUID             m_id;                        // +0x00  poi_type_id
    CryStringT<char>    m_name;                      // +0x10  poi_type_name
    int32_t             m_markType;                  // +0x18  mark_type; -1 = none
    uint32_t            _pad1C;                      // +0x1C
    CryStringT<char>    m_label;                     // +0x20  ui label key
    float               m_discoveryDist;             // +0x28  type-default radius (m)
    E_DiscoveryMsgMode  m_discoveryMsgMode;          // +0x2C  decoded from the raw string
    bool                m_discoverableByLocation;    // +0x2D  I_POI[24] reads this byte
    uint8_t             _pad2E[2];                   // +0x2E
    int32_t             m_uiOrder;                   // +0x30  I_POI[37] GetDefPriority
    uint32_t            _pad34;                      // +0x34
};
static_assert(sizeof(S_POIType) == 0x38, "S_POIType must be 0x38 (ParseRows stride)");
static_assert(offsetof(S_POIType, m_discoveryDist) == 0x28, "discoveryDist at 0x28");
static_assert(offsetof(S_POIType, m_discoverableByLocation) == 0x2D, "discoverableByLocation at 0x2D");
static_assert(offsetof(S_POIType, m_uiOrder) == 0x30, "uiOrder at 0x30");

}  // namespace wh::rpgmodule
