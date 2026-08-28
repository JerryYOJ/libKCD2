#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::playermodule {

enum class E_AlchemyItemType : std::int32_t {
    E_AIT_BOWL         = 0,
    E_AIT_SANDGLASS    = 1,
    E_AIT_MORTAR       = 2,
    E_AIT_PESTLE       = 3,
    E_AIT_RETORT       = 4,
    E_AIT_POTION_FLASK = 5,
    E_AIT_POT          = 6,
    E_AIT_HERBS1       = 7,
    E_AIT_HERBS2       = 8,
    E_AIT_HERBS3       = 9,
    E_AIT_SPECIAL1     = 10,
    E_AIT_SPECIAL2     = 11,
    E_AIT_SPECIAL3     = 12,
    E_AIT_GLASS1       = 13,
    E_AIT_GLASS2       = 14,
    E_AIT_GLASS3       = 15,
    E_AIT_GLASS4       = 16,
    E_AIT_FLASK_FAKE   = 17,
    E_AIT_BELLOWS      = 18,
    E_AIT_BOOK         = 19,
    E_AIT_POT_HALTER   = 20,
    E_AIT_LAST         = 21,
};
static_assert(sizeof(E_AlchemyItemType) == 4, "E_AlchemyItemType size mismatch");

}  // namespace wh::playermodule
