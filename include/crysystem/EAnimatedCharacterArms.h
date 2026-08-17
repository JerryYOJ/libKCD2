#pragma once
#include <cstdint>

enum EAnimatedCharacterArms : std::int32_t {
    eACA_RightArm = 1,
    eACA_LeftArm,
    eACA_BothArms,
};
static_assert(sizeof(EAnimatedCharacterArms) == 0x04,
              "EAnimatedCharacterArms must be 0x04");
