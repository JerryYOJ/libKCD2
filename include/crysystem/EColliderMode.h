#pragma once
#include <cstdint>

enum EColliderMode : std::int32_t {
    eColliderMode_Undefined = 0,
    eColliderMode_Disabled,
    eColliderMode_GroundedOnly,
    eColliderMode_Pushable,
    eColliderMode_NonPushable,
    eColliderMode_PushesPlayersOnly,
    eColliderMode_Spectator,
    eColliderMode_COUNT,
    eColliderMode_FF = 0xFF,
};
static_assert(sizeof(EColliderMode) == 0x04,
              "EColliderMode must be 0x04");
