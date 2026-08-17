#pragma once
#include <cstdint>

enum EMovementControlMethod : std::int32_t {
    eMCM_Undefined = 0,
    eMCM_Entity = 1,
    eMCM_Animation = 2,
    eMCM_DecoupledCatchUp = 3,
    eMCM_ClampedEntity = 4,
    eMCM_SmoothedEntity = 5,
    eMCM_AnimationHCollision = 6,
    eMCM_COUNT,
    eMCM_FF = 0xFF,
};
static_assert(sizeof(EMovementControlMethod) == 0x04,
              "EMovementControlMethod must be 0x04");
