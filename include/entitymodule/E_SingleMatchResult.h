#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_SingleMatchResult {
    enum Type : std::uint8_t {
        Success                  = 0,
        WrongItem                = 1,
        EquippedMismatch         = 2,
        QuestMismatch            = 3,
        StolenMismatch           = 4,
        HealthMismatch           = 5,
        PriceMismatch            = 6,
        CharismaMismatch         = 7,
        ArmorSurfaceMismatch     = 8,
        QualityMismatch          = 9,
        ConditionMismatch        = 10,
        BloodMismatch            = 11,
        ShieldIngredientMismatch = 12,
    };
};
static_assert(sizeof(E_SingleMatchResult::Type) == 1, "E_SingleMatchResult::Type size mismatch");

}  // namespace wh::entitymodule
