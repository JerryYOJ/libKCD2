#pragma once

#include <cstdint>

namespace wh::playermodule {

struct E_SkipTime {
    enum Value : std::int32_t;
};

static_assert(sizeof(E_SkipTime::Value) == 0x04,
              "E_SkipTime::Value size mismatch");

} // namespace wh::playermodule
