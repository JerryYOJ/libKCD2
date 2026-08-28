#pragma once
#include <cstdint>

// Native actor-mount policy enum used by C_ActorStateTrigger. The binary proves
// a one-byte underlying type; no registration exposes the enumerator labels.

namespace wh::entitymodule {

struct E_ActorMountState {
    enum Type : std::uint8_t;
};

static_assert(sizeof(E_ActorMountState::Type) == 1,
              "E_ActorMountState::Type size mismatch");

}  // namespace wh::entitymodule
