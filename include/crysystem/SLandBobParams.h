#pragma once
#include <cstddef>

struct SLandBobParams {
    float maxTime;     // +0x00
    float maxBob;      // +0x04
    float maxFallDist; // +0x08
};
static_assert(sizeof(SLandBobParams) == 0x0C,
              "SLandBobParams must be 0x0C");
