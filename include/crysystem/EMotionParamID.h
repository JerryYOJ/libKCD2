#pragma once
#include <cstdint>

enum EMotionParamID : std::int32_t {
    eMotionParamID_TravelSpeed = 0,
    eMotionParamID_TurnSpeed,
    eMotionParamID_TravelAngle,
    eMotionParamID_TravelSlope,
    eMotionParamID_TurnAngle,
    eMotionParamID_TravelDist,
    eMotionParamID_StopLeg,
    eMotionParamID_BlendWeight,
    eMotionParamID_Duration,
    eMotionParamID_Height,
    eMotionParamID_Scale,
    eMotionParamID_TravelDistScale,
    eMotionParamID_WeightShift,
    eMotionParamID_Curving,
    eMotionParamID_COUNT,
};
static_assert(sizeof(EMotionParamID) == 0x04,
              "EMotionParamID must be 0x04");
