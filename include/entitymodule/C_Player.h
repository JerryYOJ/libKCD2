#pragma once
#include <cstdint>
#include <vector>
#include "C_Human.h"
#include "I_EquipmentManagerListener.h"
#include "C_AuxLightAttachment.h"
#include "C_PlayerMaterialEffects.h"
#include "C_MissileWeaponPlayerController.h"
#include "../framework/C_Signal.h"
#include "../framework/C_ModelProperty.h"
#include "../Offsets/vtables/IGame.h"   // Offsets::IGameFrameworkListener

// -----------------------------------------------
// wh::entitymodule::C_Player : C_Human, I_EquipmentManagerListener, IGameFrameworkListener
// KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0xE00.
// -----------------------------------------------
// RTTI .?AVC_Player@entitymodule@wh@@  primary vtable 0x183AA4B98 (289 slots)
// ctor 0x180BC780C  scalar-deleting dtor 0x1819D25BC.  Own members occupy +0xA70..+0xE00; base C_Human.
// Bases (ctor vtable writes): C_Human @+0x00; I_EquipmentManagerListener vptr @+0xA60;
//   IGameFrameworkListener vptr @+0xA68. Own members begin at +0xA70.
//
// [FUNDAMENTAL vs KCD1] New player sub-controllers (C_ChatFollowManager, C_PlayerCarryCorpse,
//   C_PlayerUnconscious, C_PlayerTenseCircumstance, C_MissileWeaponPlayerController); m_pDogInteractionMgr
//   is no longer a direct member (moved inside C_PlayerInteractor). KCD1 also listed
//   I_ExactPosHelperListener / I_ItemAttachmentListener as secondary bases -- NOT confirmed in KCD2
//   (no ctor/dtor vtable writes for them), flagged UNVERIFIED.
//
// C_Ptr<X> members are 8-byte intrusive pointers to heap sub-controllers (each holds a back-ptr to the
// player); typed as X* here. void* m_pDelegate/m_pHandler slots are tiny player-back-pointer wrappers
// (event/mailbox listeners) whose precise types are unresolved. The six 0x10 members at
// +0xA70..+0xAB0/+0xDB0 are ALL verified wh::shared::C_Signal (connect/invoke-thunk analysis);
// their arg TYPES are thunk-derived inferences and the NAMES are semantic proposals, both flagged.

namespace wh::xgenaimodule::BehaviorTree { namespace E_TrespassLevel { enum Type : uint8_t; } }

namespace wh::entitymodule {

namespace E_CombatState { enum Type : uint8_t; }   // (values not recovered; stored as 1 byte)

class C_PlayerInteractor;
class C_LevelBarrierInteractor;
class C_PlayerInput;
class C_RigidOnlyCollision;
class C_FrontCollision;
class C_ChatFollowManager;
class C_PlayerCarryCorpse;
class C_PlayerUnconscious;
class C_PlayerTenseCircumstance;

class C_Player
    : public C_Human                                   // +0x00   (0xA60)
    , public I_EquipmentManagerListener                // +0xA60  (secondary vtable)
    , public Offsets::IGameFrameworkListener           // +0xA68  (secondary vtable)
{
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Player;
    wh::shared::C_Signal<> m_onRecipeAdded;            // +0xA70  1 recipe-handle arg (thunk sub_182AFF8E8 fires GUI "Recipes"/"AddRecipe"); name tentative
    wh::shared::C_Signal<> m_onRecipeAdded2;           // +0xA80  second recipe-add channel (different payload builder); name tentative
    wh::shared::C_Signal<> m_onEquipVisualSlotChanged; // +0xA90  1 uint8 slot-index arg (thunk sub_182B8E574); name tentative
    wh::shared::C_Signal<> m_onEquipItemChanged;       // +0xAA0  1 object-ptr arg (thunk sub_182B8E5C0); name tentative
    wh::shared::C_Signal<> m_onRpgActionSignal;        // +0xAB0  1 arg forwarded into an RPG action (thunk sub_183283050); name LOW confidence
    std::vector<void*> m_listeners;                    // +0xAC0  (element type unidentified)
    uint64_t m_unkAD8;                                 // +0xAD8  (ctor 0)
    uint32_t m_unkAE0;                                 // +0xAE0  (ctor 0)
    uint8_t  m_playerFlags;                            // +0xAE4  bitflags ((v&0xA0)|0x11; horse-inventory etc.)
    uint8_t  _padAE5[3];                               // +0xAE5
    uint32_t m_unkAE8;                                 // +0xAE8  (ctor 0)
    uint8_t  m_reservedAEC[0xC];                       // +0xAEC  (untouched by ctor)
    uint64_t m_invalidEntitySentinel;                  // +0xAF8  init 0x8000000000000000 (WUID sentinel)
    int64_t  m_invalidTimeB00;                         // +0xB00  init -100000 ("invalid time" marker)
    C_PlayerInteractor* m_pInteractor;                 // +0xB08  C_Ptr (0x5B8, ctor sub_1809EDF08)  VERIFIED
    C_LevelBarrierInteractor* m_pLevelBarrierInteractor; // +0xB10  C_Ptr (0x28)  VERIFIED
    uint32_t m_unkB18;                                 // +0xB18  (ctor 0)
    uint32_t _padB1C;                                  // +0xB1C
    // --- state-property block +0xB20..+0xB80 (ctor helper sub_180BC735C). GENERIC 0x20-stride
    //     model properties (owner elided under C_OwnershipEmpty). ---
    bool     m_stateFlagB20;                           // +0xB20  (ctor 0; role unresolved)
    uint8_t  _padB21[7];                               // +0xB21
    wh::shared::C_ModelProperty<wh::xgenaimodule::BehaviorTree::E_TrespassLevel::Type,
        wh::shared::traits::C_StandardDefaultValueTrait<wh::xgenaimodule::BehaviorTree::E_TrespassLevel::Type>,
        wh::shared::traits::C_SignalWithNewValueTrait<wh::xgenaimodule::BehaviorTree::E_TrespassLevel::Type>,
        wh::shared::traits::C_DebugNoTrace, wh::shared::traits::C_NoSaveLoad,
        wh::shared::traits::C_OwnershipEmpty> m_trespassLevel;   // +0xB28  (0x20; vtable 0x183A80F28)
    void*    m_deferredB48;                            // +0xB48  never ctor-written (deferred-init or reserved; unresolved)
    bool     m_stateFlagB50;                           // +0xB50  (ctor 0)
    uint8_t  _padB51[3];                               // +0xB51
    uint32_t m_stateB54;                               // +0xB54  (4-aligned qword-zero pair with +0xB58 -- NOT a pointer)
    uint32_t m_stateB58;                               // +0xB58
    uint32_t m_stateB5C;                               // +0xB5C  (ctor 0)
    wh::shared::C_ModelProperty<E_CombatState::Type,
        wh::shared::traits::C_StandardDefaultValueTrait<E_CombatState::Type>,
        wh::shared::traits::C_SignalWithNewValueTrait<E_CombatState::Type>,
        wh::shared::traits::C_DebugNoTrace, wh::shared::traits::C_NoSaveLoad,
        wh::shared::traits::C_OwnershipEmpty> m_combatState;     // +0xB60  (0x20; vtable 0x183A80F50)
    void*    m_deferredB80;                            // +0xB80  independent deferred-init member (parent ctor skips it)
    C_PlayerInput* m_pPlayerInput;                     // +0xB88  C_Ptr (0x2D8)  VERIFIED (pointee name from alloc site; slot name tentative)
    uint64_t m_unkB90;                                 // +0xB90  (ctor 0)
    uint64_t m_unkB98;                                 // +0xB98  (ctor 0)
    uint64_t m_unkBA0;                                 // +0xBA0  (ctor 0)
    C_AuxLightAttachment m_auxLight;                   // +0xBA8  (0x48) torch/aux-light attachment (the old "camera/aim helper" label was wrong)
    C_PlayerMaterialEffects m_materialEffects;         // +0xBF0  (0xB8)
    C_RigidOnlyCollision* m_pRigidOnlyCollision;       // +0xCA8  C_Ptr (0x30)  VERIFIED
    C_FrontCollision* m_pFrontCollision;               // +0xCB0  C_Ptr (0x28)  VERIFIED
    uint64_t m_unkCB8;                                 // +0xCB8  (ctor 0)
    uint64_t m_unkCC0;                                 // +0xCC0  (ctor 0)
    uint64_t m_unkCC8;                                 // +0xCC8  (ctor 0)
    uint64_t m_unkCD0;                                 // +0xCD0  (ctor 0)
    uint32_t m_unkCD8;                                 // +0xCD8  (ctor 0)
    float    m_floatCDC;                               // +0xCDC  init 1.0
    void*    m_pHelperCE0;                             // +0xCE0  C_Ptr player-bound helper (0x28; -100000 timer)
    C_ChatFollowManager* m_pChatFollowManager;         // +0xCE8  C_Ptr (0x78)  VERIFIED (NEW in KCD2)
    void*    m_pManagerCF0;                            // +0xCF0  C_Ptr manager (0x98)  tentative
    int32_t  m_arrayCF8[8];                            // +0xCF8  inline int32 array (ctor zeroed)
    void*    m_pDelegateD18;                           // +0xD18  C_Ptr player-back-ptr wrapper (8B)
    C_PlayerCarryCorpse* m_pCarryCorpse;               // +0xD20  C_Ptr (0x18)  VERIFIED (NEW in KCD2)
    void*    m_pDelegateD28;                           // +0xD28  C_Ptr player-back-ptr wrapper (8B)
    void*    m_pDelegateD30;                           // +0xD30  C_Ptr player-back-ptr wrapper (8B)
    uint64_t m_unkD38;                                 // +0xD38  (ctor 0)
    void*    m_pDelegateD40;                           // +0xD40  C_Ptr wrapper (0x10 {player,byte})
    C_PlayerUnconscious* m_pPlayerUnconscious;         // +0xD48  C_Ptr (0x30)  VERIFIED (NEW in KCD2)
    void*    m_pHandlerD50;                            // +0xD50  C_Ptr handler (0x20)
    void*    m_pHandlerD58;                            // +0xD58  C_Ptr wrapper (0x10 {player,0})
    C_PlayerTenseCircumstance* m_pTenseCircumstance;   // +0xD60  C_Ptr (0x20)  VERIFIED (NEW in KCD2)
    void*    m_pRefCountedD68;                         // +0xD68  ref-counted ptr (Init-set; dtor releases)
    C_MissileWeaponPlayerController m_missileWeaponController;   // +0xD70  (0x40)
    wh::shared::C_Signal<> m_signalDB0;                // +0xDB0  verified C_Signal; args/purpose UNRESOLVED (uses the binary-wide shared "default" signal family)
    uint64_t m_unkDC0;                                 // +0xDC0  (ctor 0)
    uint8_t  m_reservedDC8[0x14];                      // +0xDC8  (untouched by ctor)
    uint32_t m_actionMapFilterId;                      // +0xDDC  init 4 (KCD1 action-map filter; tentative)
    void*    m_pActionMapManager;                      // +0xDE0  runtime singleton qword_185325EE8 (tentative)
    uint64_t m_unkDE8;                                 // +0xDE8  (ctor 0)
    uint64_t m_reservedDF0;                            // +0xDF0  (untouched by ctor)
    void*    m_globalDF8;                              // +0xDF8  runtime singleton qword_185325B58 (tentative)
};
static_assert(sizeof(C_Player) == 0xE00, "C_Player must be 0xE00");

}  // namespace wh::entitymodule
