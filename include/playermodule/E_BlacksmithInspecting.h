#pragma once
#include <cstdint>

namespace wh::playermodule {

struct E_BlacksmithInspecting {
    enum Type : std::uint8_t {
        None = 0,
        Start = 1,
        Loop = 2,
    };
};

static_assert(sizeof(E_BlacksmithInspecting::Type) == 1,
              "E_BlacksmithInspecting::Type size mismatch");

} // namespace wh::playermodule
