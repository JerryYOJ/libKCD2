#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::entitymodule {

struct E_UseHandContext {
    enum Type : std::uint8_t {
        none               = 0,
        miniGame           = 1,
        miniGameShort      = 2,
        throwDecoy         = 3,
        carryCorpse        = 4,
        carryCorpsePutdown = 5,
        carryItem          = 6,
        procClip           = 7,
        ladder             = 8,
        crouch             = 9,
        mount              = 10,
        dismount           = 11,
        bed                = 12,
        stealth            = 13,
        dialog             = 14,
        syncAnim           = 15,
        lightSource        = 16,
        butchering         = 17,
        cart               = 18,
        forgeBuilder       = 19,
    };
};
static_assert(sizeof(E_UseHandContext::Type) == 1, "E_UseHandContext::Type size mismatch");

}  // namespace wh::entitymodule
