#pragma once
#include <cstdint>

namespace wh::guimodule {

struct E_UIShopState {
    enum Type : std::uint8_t;
};

static_assert(sizeof(E_UIShopState::Type) == 0x01,
              "E_UIShopState::Type size mismatch");

}  // namespace wh::guimodule
