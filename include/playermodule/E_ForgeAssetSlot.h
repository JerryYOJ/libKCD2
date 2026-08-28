#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

struct E_ForgeAssetSlot {
    enum Type : std::uint8_t {
        armorer                  = 0,
        bed                      = 1,
        beehives                 = 2,
        bookshelf                = 3,
        candlesOrSinkOrTaxidermy = 4,
        cellar                   = 5,
        doors                    = 6,
        floorSlot                = 7,
        foodShelf                = 8,
        fresco                   = 9,
        gates                    = 10,
        ground                   = 11,
        chandelier               = 12,
        chest                    = 13,
        lowerFloor               = 14,
        maidenOrBarrel           = 15,
        path                     = 16,
        roofAndGable             = 17,
        signboard                = 18,
        smelter                  = 19,
        smokehouse               = 20,
        stables                  = 21,
        stove                    = 22,
        table                    = 23,
        upperFloor               = 24,
        wallPaint                = 25,
        wallSlot1                = 26,
        wallSlot2                = 27,
        wallStatuettesAndVine    = 28,
        wardrobe                 = 29,
        watertub                 = 30,
        well                     = 31,
        windows                  = 32,
        workshop                 = 33,
        writingShelf             = 34,
        wallPaintRoom            = 35,
    };
};
static_assert(sizeof(E_ForgeAssetSlot::Type) == 1, "E_ForgeAssetSlot::Type size mismatch");

}  // namespace wh::playermodule
