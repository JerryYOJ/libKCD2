#pragma once
#include <cstdint>

namespace wh::framework {

struct E_UIShopView {
    enum Type : std::uint8_t;
};

static_assert(sizeof(E_UIShopView::Type) == 0x01,
              "E_UIShopView::Type size mismatch");

}  // namespace wh::framework
