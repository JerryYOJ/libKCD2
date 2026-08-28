#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::xgenaimodule {

struct E_InformationMessageStatus {
    enum Type : std::uint8_t {
        Created  = 0,
        Received = 1,
        Deleted  = 2,
    };
};
static_assert(sizeof(E_InformationMessageStatus::Type) == 1, "E_InformationMessageStatus::Type size mismatch");

}  // namespace wh::xgenaimodule
