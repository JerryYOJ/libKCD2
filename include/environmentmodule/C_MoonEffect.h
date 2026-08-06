#pragma once
#include <cstdint>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"

// -----------------------------------------------
// wh::environmentmodule::C_MoonEffect -- concept-graph moon/celestial effect node
// (KCD2 1.5.6, kd7u).  modeled sizeof 0x198 [alloc UNPROVEN -- rttr-factory created].
// -----------------------------------------------
// Own vtable 0x18471ED68 (late section -- normal); ctor sub_182AD6A0C. BYTE-IDENTICAL layout
// to C_SunEffect (same base chain and the same four ports at +0x88/+0xC8/+0x108/+0x148);
// only the vtable differs. Kept as a sibling (RTTI: both derive conceptmodule::C_Effect
// directly). Port roles RESOLVED 2026-08-05 (RTTR registration 0x180E23730): UseLongitude/
// Longitude/UseLatitude/Latitude, each gating the corresponding celestial param write in
// OnEffectActivate 0x182AD7080. See C_SunEffect.h for the field caveats.

namespace wh::environmentmodule {

class C_MoonEffect : public conceptmodule::C_Effect {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_MoonEffect;
    conceptmodule::C_TypedPortRef<bool>  m_useLongitudePort;  // +0x88   In -- UseLongitude
    conceptmodule::C_TypedPortRef<float> m_longitudePort;     // +0xC8   In -- Longitude
    conceptmodule::C_TypedPortRef<bool>  m_useLatitudePort;   // +0x108  In -- UseLatitude
    conceptmodule::C_TypedPortRef<float> m_latitudePort;      // +0x148  In -- Latitude
    uint8_t  m_flag188;    // +0x188  ctor 0
    uint8_t  _pad189[3];   // +0x189
    float    m_savedParamA; // +0x18C  saved orig moon celestial param (system vtbl[104]) restored on deactivate; setter 0x182AD7080, reader 0x182AD724C
    float    m_savedParamB; // +0x190  saved orig moon celestial param (system vtbl[96]) restored on deactivate; setter 0x182AD7080, reader 0x182AD724C
    int32_t  m_unk194;     // +0x194  ctor 0; no writer beyond ctor across 36 vtable methods (scanned) -- reserved/tail pad
};
static_assert(sizeof(C_MoonEffect) == 0x198, "modeled extent (ctor field extent; alloc UNPROVEN)");

}  // namespace wh::environmentmodule
