#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::rpgmodule {

struct E_BodyPart {
    enum Type : std::uint8_t {
        Body      = 0,
        Head      = 1,
        Hair      = 2,
        Beard     = 3,
        Underwear = 4,
    };
};
static_assert(sizeof(E_BodyPart::Type) == 1, "E_BodyPart::Type size mismatch");

}  // namespace wh::rpgmodule
