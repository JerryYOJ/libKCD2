#pragma once

#include <cstdint>
#include "../Offsets/vtables/IActor.h"

// -----------------------------------------------
// C_Actor - Warhorse base actor class (KCD2)
// -----------------------------------------------
// RTTI:  .?AVC_Actor@entitymodule@wh@@
// Target: WHGame.dll 1.5.6 (KCD2), image base 0x180000000
// Constructor:          0x1803f0be9  (sub_1803F0BB8)
// Base-object dtor:     0x1808e120c  (sub_1808E120C)
// Scalar deleting dtor: 0x18285a354  -> operator delete(this, 0x9C0)
//
// vtable (IActor primary):          0x183e74198  (275 slots, +0x00)
// vtable (IGameObjectView):         +0x40
// vtable (IGameObjectProfileMgr):   +0x48
//
// sizeof = 0x9C0 (recovered from the scalar deleting dtor's operator delete).
// KCD1 was 0x930; KCD2 grew by 0x90 and reorganised the health / pointer blocks.
//
// -------- Verification status --------
// VERIFIED (ctor stores / decompiled accessors): the three MI vtables, m_health/
//   m_maxHealth/m_gravity (+0x164/+0x168/+0x16C, ctor 100/100/9.81), viewDist
//   (+0x4D0/+0x4D4 = 11.0), perception angles (+0x570/+0x574/+0x578 = 5deg/30deg/1),
//   m_pMovementController(+0x180, slot 69), m_pRagdollManager(+0x190, slot 37 IsDead),
//   m_pCombatActor(+0x1A0, slot 193), m_pActionActor(+0x1A8, slot 142),
//   m_pAnimatedCharacter(+0x268, slot 220/221 + ctor arg), m_pSoul(+0x668, GetHealth),
//   the +0x160 spec-mode byte block (slot 117/118), tail flags @0x9B0..0x9B4.
// TENTATIVE: sub-object *sizes* are bounded by the gap between adjacent ctor/dtor
//   member touches (same technique as the KCD1 header) and their semantic names are
//   ported from KCD1 - each is flagged inline. The offsets themselves are exact.

namespace wh::combatmodule { class C_CombatActor; }

namespace wh::entitymodule {

class C_RagdollManager;
class C_ActionActor;

class C_Actor : public Offsets::IActor,                    // +0x00  (0x40 bytes)
                public Offsets::IGameObjectView,            // +0x40  (0x08 bytes)
                public Offsets::IGameObjectProfileManager   // +0x48  (0x08 bytes)
{
public:
    // ---- data members (+0x50 onward; base data at +0x08..+0x3F lives in IActor) ----

    void*    m_pUnk50;                       // +0x50   dtor sub_1823C8B4C            /* tentative */
    uint8_t  m_stateMachine[0x48];           // +0x58   CStateMachine<C_Actor>; ctor sub_1809CEFA0 (ptr@+0x68) /* tentative size */
    uint8_t  m_unkA0[0x10];                  // +0xA0   ctor sub_1808DDC28            /* tentative */

    // C_Signal / delegate list objects (each 0x10). KCD1 had CombatChanged x2 +
    // ItemChanged (0x30 each); KCD2 uses a wider set of 0x10-sized slots.
    uint8_t  m_signalB0[0x10];               // +0xB0   ctor sub_1803F0B9C; slot 206 returns &this
    uint8_t  m_signalC0[0x10];               // +0xC0   ctor sub_1803F0B9C; slot 207 returns &this
    uint8_t  m_signalD0[0x10];               // +0xD0   ctor sub_1803F0B80
    uint8_t  m_signalE0[0x10];               // +0xE0   ctor sub_1803F0B80
    uint8_t  m_signalF0[0x10];               // +0xF0   ctor sub_1803F1230
    uint8_t  m_signal100[0x10];              // +0x100  ctor sub_1803F1230
    uint8_t  m_signal110[0x10];              // +0x110  ctor sub_1803F1214
    uint8_t  m_signal120[0x10];              // +0x120  ctor sub_1803F1214
    uint8_t  m_signal130[0x10];              // +0x130  ctor sub_180BC83B4
    uint8_t  m_signal140[0x10];              // +0x140  ctor sub_1803F1140
    uint8_t  m_signal150[0x10];              // +0x150  ctor sub_1803F1140

    uint8_t  m_specMode[4];                  // +0x160  indexed byte block; slot 117 reads [+3], slot 118 writes; ctor sub_182864BC4
    float    m_health;                       // +0x164  100.0    VERIFIED (GetHealth/IsDeadByHealth fallback)
    float    m_maxHealth;                    // +0x168  100.0    VERIFIED (Get/SetMaxHealth slots 33/32)
    float    m_gravity;                      // +0x16C  9.81
    uint32_t m_unk170;                       // +0x170  0
    int32_t  m_counter174;                   // +0x174  slot 135 increments
    int32_t  m_counter178;                   // +0x178  slot 136 increments
    float    m_unk17C;                       // +0x17C  1.0

    void*    m_pMovementController;          // +0x180  VERIFIED (slot 69 GetMovementController)
    void*    m_pTaskHandle188;               // +0x188  dtor _AutoDeleter<_TaskProcHandle>   /* tentative */
    C_RagdollManager* m_pRagdollManager;     // +0x190  VERIFIED (slot 37 IsDead -> vfunc[1])
    void*    m_pUnk198;                       // +0x198  dtor sub_1808E15C8                   /* tentative */
    wh::combatmodule::C_CombatActor* m_pCombatActor; // +0x1A0  VERIFIED (slot 193 getter)
    C_ActionActor* m_pActionActor;           // +0x1A8  VERIFIED (slot 142 getter)
    void*    m_pUnk1B0;                       // +0x1B0  VERIFIED getter (slot 194); dtor sub_1808E1800
    void*    m_pUnk1B8;                       // +0x1B8  dtor sub_1808E15E8                   /* tentative */
    void*    m_pUnk1C0;                       // +0x1C0  dtor sub_1808E1730                   /* tentative */
    void*    m_pUnk1C8;                       // +0x1C8  dtor sub_1808E15E8                   /* tentative */

    uint8_t  m_lookAimIK[0x58];              // +0x1D0  ctor sub_1811FF97C (look/aim IK)     /* tentative size */

    CryStringT<char> m_string228;                    // +0x228  CryStringT<char>; ctor sub_1803D1670 /* tentative */
    CryStringT<char> m_string230;                    // +0x230  CryStringT<char>; ctor sub_1803D1670 /* tentative */
    void*    m_pStanceState;                 // +0x238  alloc 0x98; eye height @+0x48 (slot 59), view rot @+0x24 (slots 56-58)
    void*    m_pUnk240;                       // +0x240  dtor sub_18046B5D8                   /* tentative */
    void*    m_pUnk248;                       // +0x248  dtor sub_1808E165C                   /* tentative */
    void*    m_pUnk250;                       // +0x250  dtor sub_1808E1830; slot 171 (byte@+0x18) /* tentative */
    void*    m_pUnk258;                       // +0x258  dtor sub_1808E1670                   /* tentative */
    void*    m_pUnk260;                       // +0x260  dtor sub_1808E16B8; slot 140         /* tentative */
    void*    m_pAnimatedCharacter;           // +0x268  VERIFIED (slots 220/221 GetAnimatedCharacter; = ctor 2nd arg)
    uint64_t m_unk270;                       // +0x270  0
    uint64_t m_unk278;                       // +0x278  0
    void*    m_pUnk280;                       // +0x280  dtor sub_18048D5D0; slot 203         /* tentative */

    uint8_t  m_subObject288[0x188];          // +0x288  ctor sub_180F2CEB4 (stance / damage zones region) /* tentative */
    uint8_t  m_unk410[0x20];                 // +0x410  ctor sub_1809CF028                   /* tentative */
    uint32_t m_unk430;                       // +0x430  0
    uint8_t  m_stateBlock[0x94];             // +0x434  memset 0x94 (state block)            /* tentative */
    float    m_unk4C8;                       // +0x4C8  1.0 (slot 218 getter)
    float    m_unk4CC;                       // +0x4CC  (slot 219 getter)
    float    m_viewDist1;                    // +0x4D0  11.0
    float    m_viewDist2;                    // +0x4D4  11.0
    uint8_t  _pad4D8[0x10];                  // +0x4D8
    uint8_t  m_unk4E8[0x0C];                 // +0x4E8  memset region                        /* tentative */
    uint32_t m_unk4F4;                       // +0x4F4  0  (unaligned qword in binary -> split to keep offset)
    uint32_t m_unk4F8;                       // +0x4F8  0
    uint32_t m_unk4FC;                       // +0x4FC  0
    float    m_unk500;                       // +0x500  1.0
    uint32_t _pad504;                        // +0x504
    uint8_t  m_unk508[0x58];                 // +0x508  ctor sub_180705668                   /* tentative */
    int32_t  m_audioId560;                   // +0x560  slot 146 setter (audio id)
    int32_t  m_bIsAIControlled;              // +0x564  cleared by slot 209                  /* tentative name */
    uint64_t m_unk568;                       // +0x568  cleared by slot 209
    float    m_perceptionMinAngle;           // +0x570  0.0872665 (5 deg)
    float    m_perceptionConeHalfAngle;      // +0x574  0.5235988 (30 deg)
    float    m_perceptionRangeScale;         // +0x578  1.0
    uint8_t  m_unk57C[0x84];                 // +0x57C  ctor sub_1810F44DC (flag byte @+0x5FC, slot 230) /* tentative */

    uint8_t  m_subObject600[0x48];           // +0x600  ctor sub_181237C88 (byte @+0x63D slot 125) /* tentative */
    uint8_t  m_unk648[0x10];                 // +0x648  ctor sub_1812B0C50                   /* tentative */
    uint8_t  m_unk658[0x10];                 // +0x658  ctor sub_180C48214                   /* tentative */
    void*    m_pSoul;                        // +0x668  VERIFIED (GetHealth/IsDeadByHealth read this; non-owning I_Soul*)
    uint8_t  m_unk670[0x10];                 // +0x670  ctor sub_1809CF050; dtor sub_1803D1648 /* tentative */
    uint8_t  m_unk680[0x10];                 // +0x680  subscription slot (ptr @+0x688, slot 127) /* tentative */
    uint8_t  m_subObject690[0xA8];           // +0x690  ctor sub_1808E25C4 / fini sub_1808DDEA8 /* tentative */
    void*    m_pUnk738;                       // +0x738  slots 133/134 getter                 /* tentative */
    uint8_t  m_navBlock740[0x60];            // +0x740  dtor sub_1823CF004 (invalid-id -1 @+0x768) /* tentative */
    uint8_t  m_boneSystem[0x1F0];            // +0x7A0  ctor sub_1809CEA50 (bone/slot system) /* tentative */
    void*    m_pUnk990;                       // +0x990  obj with vtable (+0x310 used, slots 122/184/231/235) /* tentative */
    uint8_t  m_unk998[0x18];                 // +0x998  memset region                        /* tentative */

    uint16_t m_flags9B0;                     // +0x9B0  initialised to 3
    uint8_t  m_flags9B2;                     // +0x9B2  bit4 set in ctor; slot 120 clears bit2
    uint8_t  m_flags9B3;                     // +0x9B3  slot 153 sets bit0
    uint8_t  m_flag9B4;                      // +0x9B4  0; checked by FullSerialize (slot 14)
    uint8_t  _pad9B5[3];                     // +0x9B5
    void*    m_pUnk9B8;                       // +0x9B8  last member; subscription; dtor sub_1808E15D8 /* tentative */
};
static_assert(sizeof(C_Actor) == 0x9C0);

} // namespace wh::entitymodule
