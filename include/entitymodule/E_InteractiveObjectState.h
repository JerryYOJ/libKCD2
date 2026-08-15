#pragma once
#include <cstdint>

namespace wh::entitymodule {

// Type and enumerator spellings are reconstructed from the closed m_state domain.
enum class E_InteractiveObjectState : std::uint32_t {
    Initial = 0,
    InUse = 1,
    ReadyForNextInteraction = 2,
    Exhausted = 3,
};
static_assert(sizeof(E_InteractiveObjectState) == 0x04,
              "E_InteractiveObjectState must be 0x04");

}  // namespace wh::entitymodule
