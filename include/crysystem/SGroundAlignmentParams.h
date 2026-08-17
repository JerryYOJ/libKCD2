#pragma once
#include <cstddef>
#include <cstdint>
#include "EGroundAlignment.h"

struct SGroundAlignmentParams {
    float ikDisableDistanceSqr; // +0x00
    std::uint8_t flags;         // +0x04, EGroundAlignment bits
    std::uint8_t _pad05[3];     // +0x05
};
static_assert(sizeof(SGroundAlignmentParams) == 0x08,
              "SGroundAlignmentParams must be 0x08");
static_assert(offsetof(SGroundAlignmentParams, flags) == 0x04);
