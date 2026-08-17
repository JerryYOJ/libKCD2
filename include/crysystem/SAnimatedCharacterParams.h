#pragma once
#include <cstddef>
#include <cstdint>

class IAnimationBlending;

struct SAnimatedCharacterParams {
    std::uint32_t flags;                  // +0x00
    float inertia;                        // +0x04
    float inertiaAccel;                   // +0x08
    float timeImpulseRecover;             // +0x0C
    float unknown10;                      // +0x10, meaning OPEN
    std::uint32_t _pad14;                 // +0x14
    IAnimationBlending* pAnimationBlending; // +0x18, borrowed
};
static_assert(sizeof(SAnimatedCharacterParams) == 0x20,
              "SAnimatedCharacterParams must be 0x20");
static_assert(offsetof(SAnimatedCharacterParams, pAnimationBlending) == 0x18);
