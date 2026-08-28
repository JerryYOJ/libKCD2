#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::rpgmodule {

class I_SkirmishHandleProvider;

class I_SkirmishListener {
public:
    virtual ~I_SkirmishListener() = default;                        // [0]
    virtual void OnSkirmishStarted(
        I_SkirmishHandleProvider* skirmish,
        std::uint32_t matchFlag) = 0;                               // [1]
    virtual void OnSkirmishEnded() = 0;                             // [2]
};

static_assert(sizeof(I_SkirmishListener) == 0x08,
              "I_SkirmishListener size mismatch");

} // namespace wh::rpgmodule
