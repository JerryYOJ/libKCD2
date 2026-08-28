#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::framework {

struct E_AutoSaveType {
    enum Type : std::uint8_t {
        Important = 0,
        Regular   = 1,
    };
};
static_assert(sizeof(E_AutoSaveType::Type) == 1, "E_AutoSaveType::Type size mismatch");

}  // namespace wh::framework
