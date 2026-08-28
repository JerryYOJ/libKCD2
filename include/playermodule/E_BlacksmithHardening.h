#pragma once
#include <cstdint>

namespace wh::playermodule {

struct E_BlacksmithHardening {
    enum Type : std::uint8_t {
        None = 0,
        Heating = 1,
        Hardening = 2,
    };
};

static_assert(sizeof(E_BlacksmithHardening::Type) == 1,
              "E_BlacksmithHardening::Type size mismatch");

} // namespace wh::playermodule
