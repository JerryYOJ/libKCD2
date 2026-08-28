#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::playermodule {

class I_UIPickpocketing {
public:
    virtual ~I_UIPickpocketing();
    virtual void Open(void* state) = 0; // [1]
    virtual void SetBoostProgress(
        float progress, float limit,
        std::int32_t state, std::int32_t value) = 0; // [2]
};

static_assert(sizeof(I_UIPickpocketing) == 0x08,
              "I_UIPickpocketing size mismatch");

}  // namespace wh::playermodule
