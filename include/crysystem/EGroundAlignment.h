#pragma once
#include <cstdint>

enum EGroundAlignment : std::uint8_t {
    eGA_Enable = 1u << 0,
    eGA_AllowWithNoCollision = 1u << 1,
    eGA_AllowWhenHasGroundCollider = 1u << 2,
    eGA_PoseAlignerUseRootOffset = 1u << 3,
    eGA_Default = eGA_Enable,
};
static_assert(sizeof(EGroundAlignment) == 0x01,
              "EGroundAlignment must be 0x01");
