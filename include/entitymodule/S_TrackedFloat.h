#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::entitymodule {

struct S_TrackedFloat {
    float value;          // +0x00
    bool changed;         // +0x04
    std::uint8_t _pad05[3]; // +0x05
};
static_assert(sizeof(S_TrackedFloat) == 0x08,
              "S_TrackedFloat must be 0x08");

}  // namespace wh::entitymodule
