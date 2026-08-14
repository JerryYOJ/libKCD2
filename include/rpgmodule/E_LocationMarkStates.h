#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::rpgmodule::E_LocationMarkStates -- KCD2 WHGame.dll 1.5.6 (sjw7).
// -----------------------------------------------
// POI / location mark discovery state. RTTR name "wh::rpgmodule::E_LocationMarkStates"
// (enumeration_wrapper<...,3,0> registrar sub_1801C0780). Also the return type of
// GetPOIDiscoveryStatus / argument of SetPOIDiscoveryStatus.
// Values are the same 0/1/2 machine C_POI::m_state and C_RPGLocation::m_state use.

namespace wh::rpgmodule {

enum class E_LocationMarkStates : int32_t {
    Unknown            = 0,
    KnownUndiscovered  = 1,
    Discovered         = 2,
};

}  // namespace wh::rpgmodule
