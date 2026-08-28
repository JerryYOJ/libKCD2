#pragma once
#include <cstdint>

namespace wh::playermodule {

struct E_ForgePlanState {
    enum Type : std::uint8_t;
};

static_assert(sizeof(E_ForgePlanState::Type) == 0x01,
              "E_ForgePlanState::Type size mismatch");

}  // namespace wh::playermodule
