#pragma once
#include <cstdint>

// Native actor-idle policy enum used by C_ActorStateTrigger. The binary proves
// a one-byte underlying type; no registration exposes the enumerator labels.

namespace wh::entitymodule {

struct E_ActorIdleState {
    enum Type : std::uint8_t;
};

static_assert(sizeof(E_ActorIdleState::Type) == 1,
              "E_ActorIdleState::Type size mismatch");

}  // namespace wh::entitymodule
