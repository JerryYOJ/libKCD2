#pragma once
#include <cstdint>
#include <cstddef>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../framework/C_ModelProperty.h"
#include "I_HorseRiderSync.h"
#include "I_HorseMoveAdapter.h"
#include "S_HorseValueSignal.h"
#include "S_HorseRoadFollow.h"
#include "S_HorseCollisionAvoider.h"
#include "S_HorseSlopeState.h"
#include "S_HorseAnimBind.h"

// -----------------------------------------------
// wh::entitymodule::S_HorseData -- KCD2 WHGame.dll.  sizeof 0x4C8.
// -----------------------------------------------
// Heap controller at C_Horse+0x9E8. Alloc 0x4C8 (Init sub_180BE0A18),
// ctor sub_180BE0B28 / head sub_180BE0F00. Update sub_1806CEB68.

namespace wh::entitymodule {

class C_Horse;
class AnimationPoseModifier_BridlePoseModifier;

using S_HorseRiderSyncProperty = wh::shared::C_ModelProperty<
    I_HorseRiderSync*,
    wh::shared::traits::C_StaticDefaultValueTrait<I_HorseRiderSync*, nullptr>,
    wh::shared::traits::C_SignalWithOldValueTrait<I_HorseRiderSync*>,
    wh::shared::traits::C_DebugNoTrace,
    wh::shared::traits::C_NoSaveLoad,
    wh::shared::traits::C_OwnershipEmpty>;
static_assert(sizeof(S_HorseRiderSyncProperty) == 0x30, "HorseRiderSync property is 0x30");

class S_HorseData : public S_HorseRiderSyncProperty {
public:
    S_HorseValueSignal<uint8_t> m_horseState;      // +0x30  E_HorseState
    S_HorseValueSignal<bool>    m_flag48;          // +0x48  no SET writer
    S_HorseValueSignal<bool>    m_hasAction1B;     // +0x60  RiderSync slot 10
    S_HorseValueSignal<bool>    m_headNo;          // +0x78  overspurr / clamped speedup
    S_HorseValueSignal<bool>    m_avoiding;        // +0x90
    S_HorseValueSignal<float>   m_headAlign;       // +0xA8
    S_HorseValueSignal<float>   m_headAlignTime;   // +0xC0
    S_HorseValueSignal<float>   m_headEventTime;   // +0xD8
    S_HorseData*                m_pSelf;           // +0xF0
    C_Horse*                    m_pHorse;          // +0xF8
    I_HorseMoveAdapter*         m_pMove;           // +0x100 C_RiderPlayerInput
    bool                        m_rear;            // +0x108
    bool                        m_jump;            // +0x109
    bool                        m_scared;          // +0x10A
    bool                        m_fastStop;        // +0x10B
    bool                        m_jumpRequest;     // +0x10C
    bool                        m_jumpImpulse;     // +0x10D
    bool                        m_moraleHit;       // +0x10E
    uint8_t                     _pad10F;           // +0x10F
    float                       m_pseudoSpeed;     // +0x110
    float                       m_prevPseudoSpeed; // +0x114
    float                       m_speed;           // +0x118  -1 = recompute
    int32_t                     m_fragment;        // +0x11C
    int32_t                     m_tag;             // +0x120
    bool                        m_backwards;       // +0x124
    bool                        m_fastSlowDown;    // +0x125
    uint16_t                    _pad126;           // +0x126
    float                       m_yawSmoothed;     // +0x128  SmoothCD state chasing m_magnetYaw (sub_18059B800); zeroed on sign flip / pseudoSpeed<0.1 (0x180A4FDF1). NOT world heading.
    float                       m_yawVel;          // +0x12C  SmoothCD damper velocity
    float                       m_magnetYaw;       // +0x130  raw yaw command (rider ApplySMOutput / magnetism apply)
    float                       m_jumpDelta;       // +0x134  consumed with m_jumpImpulse
    bool                        m_magnetismLive;   // +0x138
    uint8_t                     _pad139[3];        // +0x139
    Vec3                        m_magnetHit;       // +0x13C
    S_HorseData*                m_pGate;           // +0x148
    bool                        m_gateSet;         // +0x150
    uint8_t                     _pad151[7];        // +0x151
    S_HorseRoadFollow           m_roadFollow;      // +0x158
    S_HorseData*                m_pAvoidOwner;     // +0x1D8
    S_HorseCollisionAvoider     m_avoider;         // +0x1E0
    S_HorseSlopeState           m_slope;           // +0x420
    S_HorseAnimBind             m_animBind;        // +0x448
    S_HorseData*                m_pCommand;        // +0x498
    float                       m_commandTime;     // +0x4A0
    uint32_t                    _pad4A4;           // +0x4A4
    S_HorseData*                m_pBridle;         // +0x4A8
    AnimationPoseModifier_BridlePoseModifier* m_pBridlePose; // +0x4B0
    void*                       m_pBridleRef;      // +0x4B8  refcount block
    float                       m_slopeEps;        // +0x4C0
    float                       m_slopeMax;        // +0x4C4
};
static_assert(sizeof(S_HorseData) == 0x4C8, "S_HorseData must be 0x4C8");
static_assert(offsetof(S_HorseData, m_pMove) == 0x100, "move adapter");
static_assert(offsetof(S_HorseData, m_fastStop) == 0x10B, "fast stop");
static_assert(offsetof(S_HorseData, m_yawSmoothed) == 0x128, "yaw smoother");
static_assert(offsetof(S_HorseData, m_roadFollow) == 0x158, "road follow");
static_assert(offsetof(S_HorseData, m_avoider) == 0x1E0, "avoider");
static_assert(offsetof(S_HorseData, m_commandTime) == 0x4A0, "command time");

}  // namespace wh::entitymodule
