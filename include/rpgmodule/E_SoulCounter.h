#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

enum class E_SoulCounter : std::uint32_t {
    DistanceWalked                      = 0,
    DistanceRan                         = 1,
    DistanceSprinted                    = 2,
    DistanceRidden                      = 3,
    DistanceFastTraveled                = 4,
    DistanceTraveledWithPlayerOnBack    = 5,
    DeltaDistanceForXPAward             = 6,
    DeltaDistanceForShoeHealth          = 7,
    DeltaDistanceForHorseRidingXPAward  = 8,
    DeltaDistanceForClothingDirtying    = 9,
    DeltaDistanceForHorseEquipHealth    = 10,
    DeltaDistanceForEncumberanceXPAward = 11,
    DeltaClothingDirtAccumulated        = 12,
};
static_assert(sizeof(E_SoulCounter) == 4, "E_SoulCounter size mismatch");

}  // namespace wh::rpgmodule
