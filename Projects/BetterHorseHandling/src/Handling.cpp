#include "Handling.h"

#include <cmath>

#include "crysystem/CCamera.h"
#include "crysystem/CCryAction.h"
#include "crysystem/SSystemGlobalEnvironment.h"
#include "Offsets/vtables/ISystem.h"
#include "Offsets/vtables/IEntity.h"
#include "entitymodule/C_ActorPhysicsState.h"
#include "entitymodule/C_Horse.h"
#include "entitymodule/C_Player.h"
#include "entitymodule/E_RiderGait.h"

namespace Handling {
namespace {

using wh::entitymodule::E_RiderGait;
using B = wh::entitymodule::E_RiderInputBits;

bool  s_prevHeld = false;
float s_heldTime = 0.f;
bool  s_runLatched = false;
bool  s_dashEngaged = false;
bool  s_lookSteerEngaged = false;
float s_lookSteerErr = 0.f;

float WrapPi(float a)
{
    return atan2f(sinf(a), cosf(a));
}

uint8_t ClampGait(int gait, int lo, int hi)
{
    return static_cast<uint8_t>(gait < lo ? lo : (gait > hi ? hi : gait));
}

}  // namespace

void ApplyGaitControl(wh::entitymodule::C_RiderPlayerInput* input,
                      wh::entitymodule::S_RiderSMPackedInput* packed)
{
    if (!input || !packed)
        return;

    packed->m_inputBits &= ~(B::SpeedupHeld | B::DoubleTap);
    const auto& sm = input->m_smInput;

    const uint8_t lowGait = ClampGait(g_gaitLow, E_RiderGait::Walk, E_RiderGait::HorseSprint);
    const uint8_t highGait = ClampGait(g_gaitHigh, lowGait, E_RiderGait::HorseSprint);

    const bool held = input->m_speedupHeld;
    if (held) {
        s_heldTime = s_prevHeld ? s_heldTime + packed->m_dt : 0.f;
    } else if (s_prevHeld) {
        if (s_dashEngaged)
            s_runLatched = true;
        else if (s_heldTime < g_holdThreshold) {
            if ((packed->m_inputBits & B::Forward) && sm.m_state >= E_RiderGait::Walk)
                s_runLatched = sm.m_state < highGait;
            else
                s_runLatched = !s_runLatched;
        }
        s_dashEngaged = false;
    }
    s_prevHeld = held;
    const bool dashHeld = held && s_heldTime >= g_holdThreshold;

    if (packed->m_forcedState != E_RiderGait::None)
        return;
    if (packed->m_inputBits & B::Backward)
        return;

    if (dashHeld && (packed->m_inputBits & B::Forward)) {
        s_dashEngaged = true;
        packed->m_inputBits &= ~B::WalkMod;
        if (packed->m_maxGait < E_RiderGait::HorseDash)
            return;
        if (sm.m_inputBits & B::SpeedupHeld)
            return;
        if (sm.m_state < E_RiderGait::HorseDash) {
            packed->m_inputBits |= B::SpeedupHeld;
            if (sm.m_state <= E_RiderGait::Idle2Move)
                packed->m_inputBits |= B::DoubleTap;
        } else if (sm.m_dashTimer < kDashRefillBelow) {
            packed->m_inputBits |= B::SpeedupHeld;
        }
        return;
    }

    const uint8_t cruise = s_runLatched ? highGait : lowGait;

    if (cruise <= E_RiderGait::Walk)
        packed->m_inputBits |= B::WalkMod;
    else
        packed->m_inputBits &= ~B::WalkMod;
    if (packed->m_maxGait > cruise)
        packed->m_maxGait = cruise;

    if (cruise > E_RiderGait::Run && (packed->m_inputBits & B::Forward)
        && sm.m_state >= E_RiderGait::Walk && sm.m_state < cruise
        && !(sm.m_inputBits & B::SpeedupHeld))
        packed->m_inputBits |= B::SpeedupHeld;
}

void ApplyLookSteer(wh::entitymodule::C_RiderPlayerInput* input, wh::entitymodule::S_HorseData* data)
{
    auto disengage = [] {
        s_lookSteerEngaged = false;
        s_lookSteerErr = 0.f;
    };

    if (!g_enableLookSteer || !input || !data) {
        disengage();
        return;
    }
    if (data->m_magnetismLive) {
        disengage();
        return;
    }
    if (input->m_pOwner && input->m_pOwner->m_missileWeaponController.m_isAiming) {
        disengage();
        return;
    }

    const float speed = fabsf(data->m_pseudoSpeed);
    if (speed <= kSpeedDeadzone) {
        disengage();
        return;
    }
    const float speedScale = fminf((speed - kSpeedDeadzone) / (kSpeedFull - kSpeedDeadzone), 1.f);

    const float lat = input->m_move.x;
    const float fwd = input->m_move.y;
    if (fwd < 0.f) {
        disengage();
        return;
    }
    if (fwd <= kForwardMin && fabsf(lat) < kLateralMax) {
        disengage();
        return;
    }

    auto* env = SSystemGlobalEnvironment::GetInstance();
    if (!env || !env->pSystem) {
        disengage();
        return;
    }
    wh::entitymodule::C_Horse* horse = data->m_pHorse;
    if (!horse || !horse->m_pEntity) {
        disengage();
        return;
    }
    const Matrix34* tm = horse->m_pEntity->GetWorldTMPtr();
    if (!tm) {
        disengage();
        return;
    }

    const Vec3 dir = env->pSystem->GetViewCamera().GetViewdir();
    const float camYaw = atan2f(-dir.x, dir.y);
    const float horseYaw = atan2f(-tm->m01, tm->m11);
    const float keyAng = atan2f(-lat * g_keyWeight, fwd);
    const float lookOff = WrapPi(camYaw - horseYaw);
    float err = WrapPi(camYaw + keyAng - horseYaw);
    if (lookOff * keyAng > 0.f && err * keyAng < 0.f)
        err = copysignf(fabsf(err), keyAng);

    if (fabsf(err) >= kErrDeadzone)
        s_lookSteerEngaged = true;
    else if (s_lookSteerEngaged && (fabsf(err) < kErrArrive || s_lookSteerErr * err < 0.f))
        disengage();

    float cmd = 0.f;
    if (s_lookSteerEngaged) {
        s_lookSteerErr = err;
        const float largeErrScale = (fabsf(err) > kLargeErr) ? kLargeErrScale : 1.f;
        cmd = fminf(fmaxf(err * g_lookSteerRate, -kMaxCmd), kMaxCmd) * speedScale * largeErrScale;
    }
    input->m_turn = -cmd;
}

void ArmFollowTick(wh::entitymodule::C_RiderPlayerInput* input,
                   wh::entitymodule::S_HorseData* data)
{
    if (!g_enableGaitDuringFollow || !input || !data)
        return;
    if (data->m_magnetismLive)
        input->m_updateArmed = true;
}

void ApplyFollowPathInput(wh::entitymodule::S_RiderSMPackedInput* packed,
                          wh::entitymodule::S_HorseData* data)
{
    if (!g_enableGaitDuringFollow || !packed || !data || !data->m_magnetismLive)
        return;
    if (packed->m_inputBits & B::Backward)
        return;
    packed->m_inputBits |= B::Forward;
}

void ApplyLateralHoldInput(wh::entitymodule::C_RiderPlayerInput* input,
                           wh::entitymodule::S_RiderSMPackedInput* packed,
                           wh::entitymodule::S_HorseData* data)
{
    if (!g_enableLookSteer || !input || !packed || !data)
        return;
    if (data->m_magnetismLive)
        return;
    if (fabsf(data->m_pseudoSpeed) <= kSpeedDeadzone)
        return;
    const float fwd = input->m_move.y;
    if (fwd < 0.f || fwd > kForwardMin || (packed->m_inputBits & B::Backward))
        return;
    if (fabsf(input->m_move.x) < kLateralMax)
        return;
    packed->m_inputBits |= B::Forward;
}

void SyncRideSession()
{
    auto* fw = CCryAction::GetInstance();
    auto* player = fw ? static_cast<wh::entitymodule::C_Player*>(fw->GetClientActor())
                      : nullptr;
    auto* input = player && player->m_pRiderPlayerControl
                      ? player->m_pRiderPlayerControl->m_pPlayerInput
                      : nullptr;
    if (input && input->m_pHorse)
        return;
    s_prevHeld = false;
    s_heldTime = 0.f;
    s_runLatched = false;
    s_dashEngaged = false;
    s_lookSteerEngaged = false;
    s_lookSteerErr = 0.f;
}

void ApplyTurretCompensation(wh::entitymodule::C_ActorPhysicsState* viewState)
{
    static float s_prevHullYaw = 0.f;
    static bool  s_baselined = false;

    if (!g_enableCameraTurret || !viewState)
        return;
    auto* fw = CCryAction::GetInstance();
    auto* player = fw ? static_cast<wh::entitymodule::C_Player*>(fw->GetClientActor())
                      : nullptr;
    if (!player || viewState != player->m_pPhysicsState)
        return;
    auto* input = player->m_pRiderPlayerControl ? player->m_pRiderPlayerControl->m_pPlayerInput
                                                : nullptr;
    wh::entitymodule::C_Horse* horse = input ? input->m_pHorse : nullptr;
    if (!horse || !horse->m_pEntity) {
        s_baselined = false;
        return;
    }
    if (horse->m_pHorseData && horse->m_pHorseData->m_magnetismLive) {
        s_baselined = false;
        return;
    }
    const Matrix34* tm = horse->m_pEntity->GetWorldTMPtr();
    if (!tm)
        return;

    const float hullYaw = atan2f(-tm->m01, tm->m11);
    if (!s_baselined) {
        s_baselined = true;
        s_prevHullYaw = hullYaw;
        return;
    }
    const float delta = WrapPi(hullYaw - s_prevHullYaw);
    s_prevHullYaw = hullYaw;
    if (fabsf(delta) < 1e-6f)
        return;

    viewState->m_lookAngles.z = WrapPi(viewState->m_lookAngles.z - delta);
}

}  // namespace Handling
