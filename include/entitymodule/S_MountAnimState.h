#pragma once
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"

// -----------------------------------------------
// wh::entitymodule::S_MountAnimState  sizeof 0x70  POD, no RTTI.
// -----------------------------------------------
// Per-frame actor movement/look request. Produced by C_ActorMovementController
// vf13 (REL 28376 / 0x1804B8E88) into a stack instance zeroed by 0x180A709E8,
// then consumed by the view-state tick (REL 26156, copies +0x18 -> m_lookDeltaRequest)
// and C_Actor vf250 (0x180640950, look/aim IK). C_Horse caches a copy at +0x9F0
// (vf269 0x1806CF62C). Name is a KCD1 carry-over -- the type is not mount-specific.
//
// +0x24/+0x30 are world-space look/aim-at points (built as origin + dir*10, then
// angle-clamped by 0x180D6B850). vf250 debug-labels +0x30 "aimDirection".

namespace wh::entitymodule {

struct S_MountAnimState {
    Vec3     m_extraMove;        // +0x00  += controller+0x178 when request bit 0x2000000
    Vec3     m_desiredVelocity;  // +0x0C  += controller+0x8C when request bit 0x20; world-rotated
    Ang3     m_deltaAngles;      // +0x18  per-frame look delta (pitch@+0x18, yaw@+0x20); tick copies to m_lookDeltaRequest
    Vec3     m_lookTarget;       // +0x24  world look-at point; valid iff m_hasLookTarget
    Vec3     m_aimTarget;        // +0x30  world aim-at point; valid iff m_hasAimTarget
    Quat     m_rootRotation;     // +0x3C  raw copy of controller+0x11C (MED -- quat vs 4-float unverified)
    Vec3     m_rootTranslation;  // +0x4C  raw copy of controller+0x12C
    int16_t  m_rootMeta;         // +0x58  UNVERIFIED
    uint8_t  m_rootCount;        // +0x5A  additional-movement valid flag (sub_180E97DC4)
    uint8_t  _pad5B;
    bool     m_hasLookTarget;    // +0x5C
    bool     m_hasAimTarget;     // +0x5D
    uint8_t  m_flag5E;           // +0x5E  request-flags bit 0x80000 (sub_1823CE124)
    uint8_t  _pad5F;
    uint64_t m_unk60;            // +0x60  ctor-zeroed; vf13 never writes
    uint8_t  m_flag68;           // +0x68  request-flags bit 0x200000 (sub_1823CE130)
    uint8_t  _pad69[7];
};

static_assert(sizeof(S_MountAnimState) == 0x70, "S_MountAnimState must be 0x70");
static_assert(offsetof(S_MountAnimState, m_deltaAngles) == 0x18);
static_assert(offsetof(S_MountAnimState, m_lookTarget) == 0x24);
static_assert(offsetof(S_MountAnimState, m_hasLookTarget) == 0x5C);
static_assert(offsetof(S_MountAnimState, m_unk60) == 0x60);

}  // namespace wh::entitymodule
