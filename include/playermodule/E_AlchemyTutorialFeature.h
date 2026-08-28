#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_AlchemyTutorialFeature {
    enum Type : std::uint8_t {
        PourLiquidsDisabled    = 0,
        ResetDisabled          = 1,
        ShiftCauldronDisabled  = 2,
        BlowBellowsDisabled    = 3,
        InventoryDisabled      = 4,
        AddHerb1Disabled       = 5,
        AddHerb2Disabled       = 6,
        AddHerb3Disabled       = 7,
        TurnHourglassDisabled  = 8,
        CrushDisabled          = 9,
        TakeFlaskDisabled      = 10,
        FinishPotionDisabled   = 11,
        CauldronDisabled       = 12,
        BackDisabled           = 13,
        AbortDisabled          = 14,
        RecipeSelectDisabled   = 15,
        OthersDisabled         = 16,
        PourLiquidsInvisible   = 17,
        ResetInvisible         = 18,
        ShiftCauldronInvisible = 19,
        BlowBellowsInvisible   = 20,
        InventoryInvisible     = 21,
        AddHerb1Invisible      = 22,
        AddHerb2Invisible      = 23,
        AddHerb3Invisible      = 24,
        TurnHourglassInvisible = 25,
        CrushInvisible         = 26,
        TakeFlaskInvisible     = 27,
        FinishPotionInvisible  = 28,
        CauldronInvisible      = 29,
        BackInvisible          = 30,
        AbortInvisible         = 31,
        RecipeSelectInvisible  = 32,
        OthersInvisible        = 33,
    };
};
static_assert(sizeof(E_AlchemyTutorialFeature::Type) == 1, "E_AlchemyTutorialFeature::Type size mismatch");

}  // namespace wh::playermodule
