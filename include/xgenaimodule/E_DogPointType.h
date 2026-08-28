#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::xgenaimodule::E_DogPointType::Type
// (KCD2 WHGame.dll 1.5.6). Underlying uint8_t.
// -----------------------------------------------
// Nested Type of struct E_DogPointType (RTTR "wh::xgenaimodule::DogPointType",
// wrapper class "DogPointTypeWrapper"). Registrar 0x1802C87A0.
// This is the type of S_DogPoint::Type (S_DogPoint.h, +0x20).
//
// 3 of 4 enumerators independently confirmed by decompile: the registrar builds
// (name, name-length, value) triples -- e.g. "MarkingSpot" has length 0xB=11,
// paired value byte 1; "WaterTubSpot" length 0xC=12, value 2; "MerchantCounterSpot"
// length 0x13=19, value 3. DrinkingSpot=0 is the array's index-0 slot (whose name
// write MSVC folded out of this decompile); independently corroborated by
// convergent leaf research (Mark/FunOnPoint/Dig/FunMove/Chase) that all cite the
// same name for value 0.
//
// Do NOT confuse with the unrelated switch-based stringer at 0x180A25AF8
// (Drink/Mark/TreeSniffing/CounterSniffing/WaterTubDrinking, 5 values, no RTTR
// registration) -- that names C_FunOnSoDogObjective::m_behaviorType, a distinct
// byte remapped from this enum by sub_180624374. Kept as a plain uint8_t there;
// see C_FunOnSoDogObjective.h.

namespace wh::xgenaimodule {

struct E_DogPointType {
    enum Type : uint8_t {
        DrinkingSpot        = 0,
        MarkingSpot         = 1,
        WaterTubSpot        = 2,
        MerchantCounterSpot = 3,
    };
};

}  // namespace wh::xgenaimodule
