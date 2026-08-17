#pragma once
#include <cstdint>

enum ECharacterMoveType : std::int32_t {
    eCMT_None = 0,
    eCMT_Normal,
    eCMT_Fly,
    eCMT_Swim,
    eCMT_ZeroG,
    eCMT_Impulse,
    eCMT_JumpInstant,
    eCMT_JumpAccumulate,
};
static_assert(sizeof(ECharacterMoveType) == 0x04,
              "ECharacterMoveType must be 0x04");
