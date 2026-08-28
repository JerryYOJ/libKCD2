#pragma once
#include <cstddef>

namespace wh::playermodule {

class I_PlayerManagerListener {
public:
    virtual void OnPlayerSwitchFinished(bool successful) = 0; // [0]
    virtual void Unk01() = 0;                                // [1] signature/role unresolved
};

static_assert(sizeof(I_PlayerManagerListener) == 0x08,
              "I_PlayerManagerListener size mismatch");

} // namespace wh::playermodule
