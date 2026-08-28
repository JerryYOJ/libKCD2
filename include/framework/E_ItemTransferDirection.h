#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::framework {

struct E_ItemTransferDirection {
    enum Type : std::uint8_t {
        ToPlayer     = 0,
        FromPlayer   = 1,
        Confiscation = 2,
    };
};
static_assert(sizeof(E_ItemTransferDirection::Type) == 1, "E_ItemTransferDirection::Type size mismatch");

}  // namespace wh::framework
