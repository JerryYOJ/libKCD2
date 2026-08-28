#pragma once
#include <cstdint>

#include "../framework/I_Action.h"

namespace wh::playermodule {

class I_BlacksmithActionListener {
public:
    virtual void OnBlacksmithActionEvent(
        _smart_ptr<wh::framework::I_Action> action,
        std::uint8_t event) = 0;                            // [0]
    virtual void OnBlacksmithEvent(std::uint8_t event) = 0; // [1]
    virtual void ResetBlacksmithActions() = 0;              // [2]
};

static_assert(sizeof(I_BlacksmithActionListener) == 0x08,
              "I_BlacksmithActionListener size mismatch");

} // namespace wh::playermodule
