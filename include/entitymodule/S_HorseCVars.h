#pragma once
#include <cstdint>
#include <cstddef>

// -----------------------------------------------
// wh::entitymodule::S_HorseCVars -- KCD2 WHGame.dll.  sizeof 0x21C.
// -----------------------------------------------
// No RTTI. Global 0x1855DC6E0, getter sub_1806CDCF4, registrar sub_1810A75D8.
// Next TLS guard 0x1855DC8FC pins size. Offsets from lea rdx,[rdi+N] at each
// wh_horse_* RegisterCVar. RoadMagnetism mode 0/1/2 is NOT here -- it lives on
// the options object returned by sub_1804AADE0 at +0xB0.

namespace wh::entitymodule {

struct S_HorseCVars {
    int32_t m_Idle2MoveWithPlayer;                         // +0x00
    int32_t m_CollisionAvoider;                            // +0x04
    int32_t m_CollisionAvoiderDebug;                       // +0x08
    float   m_CollisionAvoiderRaycastDistMult;             // +0x0C
    float   m_CollisionAvoiderRaycastDistMultRoad;         // +0x10
    float   m_CollisionAvoiderRaycastDistMin;              // +0x14
    float   m_CollisionAvoiderRaycastDistMinRoad;          // +0x18
    float   m_CollisionAvoiderRaycastMinDegreeUp;          // +0x1C
    float   m_CollisionAvoiderRaycastMinElevation;         // +0x20
    float   m_CollisionAvoiderRaycastHeight[3];            // +0x24  top, mid, low
    float   m_CollisionAvoiderRaycastWidth[3];             // +0x30  left, center, right
    float   m_CollisionAvoiderRaycastRotationAmount;       // +0x3C
    float   m_CollisionAvoiderSmoothNormalsTime;           // +0x40
    int32_t m_CollisionAvoiderRaycastSmoothMaxTriangleCount; // +0x44
    int32_t m_CollisionAvoiderRaycastFlags;                // +0x48
    float   m_CollisionAvoiderFenceTurnDegree;             // +0x4C
    float   m_MaxBboxSizeForStrafing;                      // +0x50
    int32_t m_CollisionAvoidance;                          // +0x54
    int32_t m_CollisionAvoidanceDebug;                     // +0x58
    int32_t m_CollisionAvoidanceMoraleHits;                // +0x5C
    int32_t m_CollisionAvoidanceNoAvoiding;                // +0x60
    float   m_RoadMagnetismMaxDelta;                       // +0x64
    int32_t m_RoadMagnetismDebug;                          // +0x68
    float   m_RoadMagnetismRoadCosLimit;                   // +0x6C
    float   m_RoadMagnetismFlickLimit;                     // +0x70
    float   m_RoadMagnetismFlickMinAngle;                  // +0x74
    int32_t m_RoadMagnetismFlickDebug;                     // +0x78
    int32_t m_RoadMagnetismForce;                          // +0x7C
    float   m_RoadMagnetismInterruptTime;                  // +0x80
    float   m_RoadMagnetismEnterAngle;                     // +0x84
    float   m_RoadMagnetismRemainAngle;                    // +0x88
    float   m_RoadMagnetismPathWidthCoeff;                 // +0x8C
    float   m_RoadMagnetismPathMinWidth;                   // +0x90
    float   m_RoadMagnetismPathMaxWidth;                   // +0x94
    float   m_RoadMagnetismSnapTime;                       // +0x98
    float   m_RoadMagnetismCartWidth;                      // +0x9C
    float   m_RoadMagnetismCartHeight;                     // +0xA0
    float   m_RoadMagnetismCartCenterOffsetY;              // +0xA4
    float   m_RoadMagnetismCrossroadPredictionLen;         // +0xA8
    float   m_RoadMagnetismBacktrackPathLength;            // +0xAC
    float   m_RoadMagnetismDashMaxDegree;                  // +0xB0
    float   m_RoadMagnetismSprintMaxDegree;                // +0xB4
    float   m_RoadMagnetismRunMaxDegree;                   // +0xB8
    float   m_RoadMagnetismTrendMaxSteer;                  // +0xBC
    float   m_RoadMagnetismTrendMinWidth;                  // +0xC0
    float   m_RoadMagnetismTrendMaxWidth;                  // +0xC4
    float   m_RoadMagnetismTrendMinSteer;                  // +0xC8
    float   m_RoadMagnetismTrendSteerWeight;               // +0xCC
    float   m_RoadMagnetismTrendWidthWeight;               // +0xD0
    float   m_RoadMagnetismOnPressRoadDistOff;             // +0xD4
    float   m_RoadMagnetismOnPressRoadDistOn;              // +0xD8
    float   m_RoadMagnetismAutoRoadDistOff;                // +0xDC
    float   m_RoadMagnetismAutoRoadDistOn;                 // +0xE0
    float   m_StuckLimit;                                  // +0xE4
    float   m_RotationMax;                                 // +0xE8
    float   m_RotationSmoothOutSpeed;                      // +0xEC
    float   m_RotationSmoothInSpeed;                       // +0xF0
    int32_t m_DebugControls;                               // +0xF4
    float   m_DashFovMultiplier;                           // +0xF8
    float   m_DashFovChangeSpeed;                          // +0xFC
    float   m_CameraCentering;                             // +0x100
    float   m_CameraCenteringTime;                         // +0x104
    float   m_CameraCenteringTimeInCombat;                 // +0x108
    float   m_CameraCenteringSwayCoeff;                    // +0x10C
    float   m_CameraCenteringPitchOffset;                  // +0x110
    float   m_CameraCenteringMagnetismDegreeLimit;         // +0x114
    int32_t m_HideReinsWhenMounted;                        // +0x118
    float   m_FollowPlayerTimer;                           // +0x11C
    int32_t m_SpawnOnCall;                                 // +0x120
    float   m_CallMinDistance;                             // +0x124
    float   m_CallMaxDistance;                             // +0x128
    float   m_StraightenMovementMaxAngle;                  // +0x12C
    float   m_JumpOnSlopeNormalZLimit;                     // +0x130
    float   m_JumpHeight;                                  // +0x134
    float   m_JumpGravityMult;                             // +0x138
    float   m_WhistleTeleportInFrontDistance;              // +0x13C
    float   m_WhistleTeleportBackDistance;                 // +0x140
    float   m_AutoResetBridleDist;                         // +0x144
    int32_t m_GroundBodingEnabled;                         // +0x148  game spelling
    float   m_StopHintDelay;                               // +0x14C
    float   m_StopHintDuration;                            // +0x150
    float   m_FastStopHoldTime;                            // +0x154
    float   m_ViewLimitWide;                               // +0x158
    float   m_ViewLimitNarrow;                             // +0x15C
    float   m_ViewLimitBottom;                             // +0x160
    float   m_SpurDebuffGenerosity;                        // +0x164
    float   m_PushNPCsForce;                               // +0x168
    float   m_ClampDelta;                                  // +0x16C
    float   m_RotationCoeff;                               // +0x170
    float   m_CameraTwitchAmount;                          // +0x174
    int32_t m_CameraTwitchDebug;                           // +0x178
    float   m_DashInterruptDuration;                       // +0x17C
    float   m_InstaMountCollisionActivationDelay;          // +0x180
    int32_t m_DisableInventoryMinTrespassLevel;            // +0x184
    float   m_AdditionalPhysicsMass;                       // +0x188
    float   m_MountLockDuration;                           // +0x18C
    float   m_DismountLockDuration;                        // +0x190
    float   m_MountLockSaddleRotation;                     // +0x194
    float   m_DismountLockSaddleRotation;                  // +0x198
    float   m_FollowMaxForwardSpeed;                       // +0x19C
    float   m_FollowMaxBackwardSpeed;                      // +0x1A0
    float   m_FollowTurnAroundSpeed;                       // +0x1A4
    float   m_ControlMapPow;                               // +0x1A8
    int32_t m_AltControls;                                 // +0x1AC
    int32_t m_DashInterruptMask;                           // +0x1B0
    float   m_YeetMultiplier;                              // +0x1B4
    int32_t m_DropRiderOnLowStamina;                       // +0x1B8
    int32_t m_EnableRiderHeadCollision;                    // +0x1BC
    float   m_MovementSpeedMultMult;                       // +0x1C0
    float   m_MovementSpeedMultClamp;                      // +0x1C4
    float   m_MovementSpeedMultPow;                        // +0x1C8
    int32_t m_SmoothTerrainTraversal;                      // +0x1CC
    float   m_LevelBarrierDistanceMult;                    // +0x1D0
    float   m_TurnSlowdownCoeff[4];                        // +0x1D4  Walk, Run, Sprint, Dash
    float   m_TurnSlowdownPow[4];                          // +0x1E4
    float   m_TurnSlowdownMaxAngle[4];                     // +0x1F4
    float   m_RoadMagnetismDeactivateTime;                 // +0x204
    float   m_RoadMagnetismReactivateTime;                 // +0x208
    float   m_RoadMagnetismDisableHintsVisibleTime;        // +0x20C
    float   m_SlowdownSpeed;                               // +0x210
    float   m_SlowdownMinSpeedCoeff;                       // +0x214
    float   m_SlowdownSpeedPow;                            // +0x218
};
static_assert(sizeof(S_HorseCVars) == 0x21C, "S_HorseCVars must be 0x21C");
static_assert(offsetof(S_HorseCVars, m_RoadMagnetismForce) == 0x7C, "Force");
static_assert(offsetof(S_HorseCVars, m_FastStopHoldTime) == 0x154, "FastStopHoldTime");
static_assert(offsetof(S_HorseCVars, m_TurnSlowdownCoeff) == 0x1D4, "TurnSlowdownCoeff[Walk]");
static_assert(offsetof(S_HorseCVars, m_RoadMagnetismDeactivateTime) == 0x204, "DeactivateTime");
static_assert(offsetof(S_HorseCVars, m_SlowdownSpeedPow) == 0x218, "last field");

}  // namespace wh::entitymodule
