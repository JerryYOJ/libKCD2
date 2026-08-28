#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh {

struct E_CreditsType {
    enum Type : std::uint8_t {
        Full       = 0,
        FirstPart  = 1,
        SecondPart = 2,
    };
};
static_assert(sizeof(E_CreditsType::Type) == 1, "E_CreditsType::Type size mismatch");

}  // namespace wh
