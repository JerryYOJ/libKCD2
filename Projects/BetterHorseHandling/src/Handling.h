#pragma once

#include "entitymodule/C_ActorPhysicsState.h"
#include "entitymodule/C_RiderPlayerInput.h"
#include "entitymodule/S_HorseData.h"
#include "entitymodule/S_RiderSMPackedInput.h"

namespace Handling {

inline int   g_enableLookSteer = 1;
inline int   g_enableCameraTurret = 1;
inline int   g_enableGaitDuringFollow = 1;
inline float g_lookSteerRate = 0.8f;
inline float g_keyWeight = 1.38f;
inline float g_holdThreshold = 0.20f;
inline int   g_gaitLow  = 3;
inline int   g_gaitHigh = 4;

inline constexpr float kSpeedDeadzone   = 0.15f;
inline constexpr float kSpeedFull       = 1.0f;
inline constexpr float kForwardMin      = 0.5f;
inline constexpr float kLateralMax      = 0.2f;
inline constexpr float kErrDeadzone     = 0.08f;
inline constexpr float kErrArrive       = 0.01f;
inline constexpr float kLargeErr        = 2.0f;
inline constexpr float kLargeErrScale   = 0.4f;
inline constexpr float kMaxCmd          = 1.5707964f;
inline constexpr float kDashRefillBelow = 1.0f;

void ApplyGaitControl(wh::entitymodule::C_RiderPlayerInput* input,
                      wh::entitymodule::S_RiderSMPackedInput* packed);
void ArmFollowTick(wh::entitymodule::C_RiderPlayerInput* input,
                   wh::entitymodule::S_HorseData* data);
void ApplyFollowPathInput(wh::entitymodule::S_RiderSMPackedInput* packed,
                          wh::entitymodule::S_HorseData* data);
void ApplyLookSteer(wh::entitymodule::C_RiderPlayerInput* input,
                    wh::entitymodule::S_HorseData* data);
void ApplyLateralHoldInput(wh::entitymodule::C_RiderPlayerInput* input,
                           wh::entitymodule::S_RiderSMPackedInput* packed,
                           wh::entitymodule::S_HorseData* data);
void ApplyTurretCompensation(wh::entitymodule::C_ActorPhysicsState* viewState);
void SyncRideSession();

}  // namespace Handling
