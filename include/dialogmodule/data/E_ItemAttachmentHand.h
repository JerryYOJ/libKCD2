#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule::data {

struct E_ItemAttachmentHand {
    enum Type : std::uint8_t {
        Left  = 0,
        Right = 1,
    };
};
static_assert(sizeof(E_ItemAttachmentHand::Type) == 1, "E_ItemAttachmentHand::Type size mismatch");

}  // namespace wh::dialogmodule::data
