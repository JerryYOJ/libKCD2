#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "ECharacterMoveType.h"
#include "SPredictedCharacterStates.h"

struct SCharacterMoveRequest {
    ECharacterMoveType type;              // +0x00
    Vec3 velocity;                        // +0x04
    Quat rotation;                        // +0x10
    SPredictedCharacterStates prediction; // +0x20
    bool allowStrafe;                     // +0x40
    std::uint8_t _pad41[3];               // +0x41
    float proceduralLeaning;              // +0x44
    bool jumping;                         // +0x48
    std::uint8_t _pad49[3];               // +0x49
};
static_assert(sizeof(SCharacterMoveRequest) == 0x4C,
              "SCharacterMoveRequest must be 0x4C");
static_assert(offsetof(SCharacterMoveRequest, prediction) == 0x20);
static_assert(offsetof(SCharacterMoveRequest, proceduralLeaning) == 0x44);
static_assert(offsetof(SCharacterMoveRequest, jumping) == 0x48);
