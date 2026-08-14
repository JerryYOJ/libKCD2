#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::rpgmodule::E_DiscoveryMsgMode -- KCD2 WHGame.dll 1.5.6 (sjw7).
// -----------------------------------------------
// poi_type.discovery_msg_mode. Names from the ParseRows string decoder
// sub_1823DA1A8 (Normal / ShowOnlyFirst / DoNotShow). Stored as one byte on
// S_POIType (+0x2C). Wrapper name is [SYNTHETIC] -- no RTTR enum type found.

namespace wh::rpgmodule {

enum class E_DiscoveryMsgMode : uint8_t {
    Normal         = 0,
    ShowOnlyFirst  = 1,
    DoNotShow      = 2,
};

}  // namespace wh::rpgmodule
