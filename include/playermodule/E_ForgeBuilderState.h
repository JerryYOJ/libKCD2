#pragma once
#include <cstdint>

namespace wh::playermodule {

struct E_ForgeBuilderState {
    enum Type : std::uint8_t {};
};

static_assert(sizeof(E_ForgeBuilderState::Type) == 1,
              "E_ForgeBuilderState::Type size mismatch");

} // namespace wh::playermodule
