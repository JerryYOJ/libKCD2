#pragma once
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"

// -----------------------------------------------
// wh::entitymodule::C_ActorPhysicsState -- per-actor look-angle state (KCD2 WHGame.dll 1.5.6, sjw7).  sizeof 0x98.
// -----------------------------------------------
// No vtable. Allocated (0x98) by factory 0x181110A8C from C_Actor ctor 0x1803F0BB8; owned at
// C_Actor+0x238. NAME IS SYNTHETIC (no RTTI) -- kept from the C_Actor.h forward declaration, but
// the object is really the look-angle state machine behind GetViewRotation/SetViewRotation.
//
// Per-frame pipeline (decompiled + confirmed live by a hardware write-watch, 2026-08-19):
//   C_Actor pre-physics update 0x181E7D6F0 (vf217 helper 0x18064474C, entity event 33)
//     -> movement controller (C_ActorMovementController, actor+0x180) vf13 0x1804B8E88 fills a
//        request struct; its +0x18 Ang3 lands in m_lookDeltaRequest (mouse-look path)
//     -> tick 0x1804415E0: m_lookDeltaCarried := m_lookDeltaPending; integrator 0x180441928:
//        m_lookAngles += m_lookAngleAccum + m_lookDeltaCarried + m_lookDeltaRequest, then the
//        view-limit clamp 0x18053B508 (six 0x28-byte channels at owner+0x2D0, axis defaults to the
//        entity frame) writes m_lookClamped; 0x180441B20 wraps yaw; m_lookQuat rebuilt.
//     -> quat build 0x180441730: m_viewRotation = AngToQuat(m_lookAngles + m_lookDeltaTransient)
//        for player-controlled owners (channel check 0x1804A8CE0), else a copy of m_lookQuat.
//     -> m_viewPitch/m_flatYaw refreshed; m_lookDeltaTransient + m_lookAngleAccum zeroed;
//        0x1804417B0 renormalizes the three quats.
//   SetViewRotation impl 0x1806440AC = QuatToAng3 into m_lookAngles (+ quat mirrors); it skips the
//   flat-yaw rebuild while either owner hold counter (C_Actor+0x174/+0x178; vf135 0x18040B580 /
//   vf136 0x18286139C step them +/-1) is positive.  AI actors (IsAIControlled byte C_Actor+0x63C)
//   instead slave m_lookAngles to their entity rotation (base slot-27 sync 0x180644B14).
// Mounted-camera glue: C_Horse flat-yaw override 0x1806CCAF8 (vf172, REL 37998) forwards the horse
// yaw delta into the RIDER's m_lookAngleAccum; camera centering 0x180A501E8 (REL 56442) adds there
// too (inert while wh_horse_CameraCentering < 0). Mouse look does NOT touch the accumulator.

namespace wh::entitymodule {

class C_Actor;

class C_ActorPhysicsState
{
public:
    C_Actor* m_pOwner;             // +0x00  backptr; hold counters read through it (0x180441AFC)
    Ang3     m_lookAngles;         // +0x08  base look Euler (x=pitch, z=yaw) -- THE persistent look state
    Quat     m_lookQuat;           // +0x14  quat of m_lookAngles alone (integrator tail 0x180441A7D)
    Quat     m_viewRotation;       // +0x24  GetViewRotation()/camera source; rebuilt every tick
    Quat     m_flatYawQuat;        // +0x34  yaw-only quat (SetFlatYaw impl 0x1806442A8)
    float    m_flatYaw;            // +0x44  yaw scalar (0x1806440AC atan2 of m_flatYawQuat)
    float    m_viewPitch;          // +0x48  pitch scalar (tick copies m_lookAngles.x)
    Ang3     m_lookDeltaTransient; // +0x4C  composed into m_viewRotation this frame only, then zeroed
    Ang3     m_lookDeltaPending;   // +0x58  decayed by 0x180441678; cinematic writer 0x18285E768
    Ang3     m_lookDeltaCarried;   // +0x64  tick copy of m_lookDeltaPending, summed by the integrator
    float    m_unk70[3];           // +0x70  UNVERIFIED -- untouched by the decoded pipeline
    Ang3     m_lookDeltaRequest;   // +0x7C  movement-controller request term (mouse look)
    Ang3     m_lookAngleAccum;     // +0x88  external additive pumps (horse glue, centering); zeroed each tick
    bool     m_lookClamped;        // +0x94  view-limit clamp changed the angles this tick
};

static_assert(offsetof(C_ActorPhysicsState, m_lookAngles) == 0x08);
static_assert(offsetof(C_ActorPhysicsState, m_viewRotation) == 0x24);
static_assert(offsetof(C_ActorPhysicsState, m_flatYawQuat) == 0x34);
static_assert(offsetof(C_ActorPhysicsState, m_viewPitch) == 0x48);
static_assert(offsetof(C_ActorPhysicsState, m_lookDeltaRequest) == 0x7C);
static_assert(offsetof(C_ActorPhysicsState, m_lookAngleAccum) == 0x88);
static_assert(offsetof(C_ActorPhysicsState, m_lookClamped) == 0x94);
static_assert(sizeof(C_ActorPhysicsState) == 0x98);

}  // namespace wh::entitymodule
