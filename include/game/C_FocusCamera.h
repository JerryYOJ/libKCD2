#pragma once
#include <cstdint>
#include <cstddef>
#include <vector>
#include "../CryEngine/CryCommon/Cry_Math.h"

// -----------------------------------------------
// C_FocusCamera -- per-player "focus view on target" controller (KCD2 WHGame.dll
// Steam 1.5.6, sjw7).  sizeof 0x98 (alloc in ctor helper sub_180BC7590 of
// C_Player::ctor_180BC780C).  Lives at C_Player+0xCF0.
// -----------------------------------------------
// Class name from RTTI ".?AVI_TargetPositionProvider@C_FocusCamera@@" (nested
// interface; outer class is UNNAMESPACED like the CryAction-side game classes --
// game/ placement is inferred).  Own vtable is runtime-filled .data unk_185666D28
// (unloaded in the IDB) -- slots UNRECOVERED.
//
// Install_1808B811C (REL::ID 47607) push_backs a setup into m_setups and
// insertion-sorts (0x181F21560) by m_flag05 DESCENDING -- node-installed setups
// (flag05=1) outrank the combat lock's (flag05=0); returns ++m_idCounter as the
// removal id.  Tick Update_1808BA014 (REL::ID 47642, from C_Player vfunc[217]
// post-update) only ever reads m_setups.front(): activates when its target
// resolves (ShouldBeActive_1808B9B78 -- false when the target soul is the player's
// own), then per-frame Apply_1808B8BFC (REL::ID 47626) rotates the actor
// view-state quat (C_Actor+0x238 obj, +0x24, WORLD-space) toward the target frame
// (step min(dt*100,1)/(stiffness+1), math sub_1808B8C5C) and clamps it
// TARGET-RELATIVE (the horse-relative ViewLimit pinning) via SetViewRotation
// sub_1806440AC.  Deactivate_1808B8A04 restores C_Player vfunc[135] and writes the
// camera manager's FOV-blend fields (+0x3F8/+0x46C).  NOTE: the mounted A/D
// camera-follow itself is NOT this system -- it is the first-person compose's
// world-yaw mix (C_CameraFirstPerson::Compose 0x18094D030); this system only adds
// the pull toward the target and the target-relative look limits.

namespace wh::entitymodule { class C_Player; }
struct S_FocusCameraSetup;
typedef unsigned int EntityId;   // matches Offsets/vtables/IEntity.h

class C_FocusCamera {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_FocusCamera;
    // Target source of an installed setup (RTTI-named nested interface). Impls:
    // combat raw-id provider (0x10 bytes, vtable 0x183E5FB28, id @+0x08); the
    // C_FocusCameraNode entity-id provider sub_1827D7E80 (stored uint32 IEntity id,
    // GetTargetPosition samples entity part/slot 9) and its direct-object fallback
    // sub_1827D7F28 (GetEntityId may return 0).
    class I_TargetPositionProvider {
    public:
        virtual ~I_TargetPositionProvider() = default;   // [0]
        virtual void GetTargetPosition(void* out) = 0;   // [1] out 0x10: byte valid @+0 + position; exact layout UNVERIFIED (consumer 0x1808B8C5C)
        virtual EntityId GetEntityId() = 0;              // [2] target IEntity id (0/none when unset)  VERIFIED ABI (ShouldBeActive_1808B9B78)
    };

    virtual ~C_FocusCamera();              // [0] placeholder for the unrecovered runtime vtable (see banner)

    uint64_t m_unk08;                      // +0x08
    wh::entitymodule::C_Player* m_pPlayer; // +0x10  owner backptr  VERIFIED (Update_1808BA014 derefs +0x238 view-state / +0x38 entity / +0x990)
    std::vector<S_FocusCameraSetup*> m_setups; // +0x18  ctor empty (NO default setup); sorted by m_flag05 DESC on install; the tick reads front() only
    int32_t  m_idCounter;                  // +0x30  ctor -1; pre-incremented per install -> setup m_id
    uint32_t _pad34;                       // +0x34
    void*    m_pTracker;                   // +0x38  align tracker: +0x08 provider copy, +0x18 target-frame Matrix34*, +0x20/+0x28 limit pairs, +0x30..+0x3C align speeds (tuning[0x13C..0x148]), +0x40 stiffness; class UNRESOLVED
    uint32_t m_flags;                      // +0x40  0x1 tick-enable (set by first Install) | 0x2 active | 0x4/0x8/0x10/0x20/0x40 mode-2 recenter substates (Activate sets 0x2, Deactivate clears 0x66)
    uint32_t _pad44;                       // +0x44
    int64_t  m_timer48;                    // +0x48  CTimeValue (ctor -100000); mode-2 recenter timer, armed with tuning[0x150]
    int64_t  m_timer50;                    // +0x50  CTimeValue (ctor -100000); armed 0.5s on look input during mode-2
    Quat     m_capturedFlatView;           // +0x58  mode-2: view-state +0x34 flat-yaw quat captured at activation (ctor: identity, w @+0x64 = 1.0)
    uint8_t  m_recenterInterp[0x30];       // +0x68  quat interpolator state, init sub_180A70610(tuning[0x154], identity) (ctor: identity quat @+0x68); layout UNRESOLVED
};
static_assert(sizeof(C_FocusCamera) == 0x98, "C_FocusCamera must be 0x98");
static_assert(offsetof(C_FocusCamera, m_pPlayer) == 0x10);
static_assert(offsetof(C_FocusCamera, m_setups) == 0x18);
static_assert(offsetof(C_FocusCamera, m_idCounter) == 0x30);
static_assert(offsetof(C_FocusCamera, m_pTracker) == 0x38);
static_assert(offsetof(C_FocusCamera, m_flags) == 0x40);
static_assert(offsetof(C_FocusCamera, m_capturedFlatView) == 0x58);
