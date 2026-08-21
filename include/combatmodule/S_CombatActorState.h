#pragma once
#include <cstddef>
#include <cstdint>
#include <set>
#include "CombatModelTraits.h"
#include "E_AnimActionMovementState.h"
#include "E_BlockMode.h"
#include "E_CombatActorStateId.h"
#include "E_GuardRequestScope.h"
#include "S_RestrictedInputClass.h"
#include "../entitymodule/E_HandSlot.h"
#include "../framework/C_ModelArrayProperty.h"
#include "../framework/C_ModelContextProperty.h"
#include "../framework/C_ModelProperty.h"
#include "../framework/C_ModelRefProperty.h"
#include "../framework/C_ModelSetProperty.h"
#include "../framework/C_Signal.h"
#include "../framework/WUID.h"
#include "../CryEngine/CryCommon/TimeValue.h"

namespace wh::combatmodule {

class I_CombatActor;
class I_CombatTarget;
class C_CombatActor;
struct E_BlockModeContext;

struct S_CombatActorState {
    template<class T>      using Prop       = wh::shared::C_ModelProperty<T>;
    template<class T>      using PropCustom = wh::shared::C_ModelProperty<T, wh::shared::traits::C_CustomDefaultValueTrait<T>>;
    template<class T, T V> using PropStatic = wh::shared::C_ModelProperty<T, wh::shared::traits::C_StaticDefaultValueTrait<T, V>>;
    using PropRefBool      = wh::shared::C_ModelRefProperty<traits::C_CombatSignalWithNewValueTrait<bool>>;
    using PropRefBoolActor = wh::shared::C_ModelRefProperty<traits::C_CombatSignalWithNewValueTrait<bool, I_CombatActor&>>;
    using E_HandSlot       = wh::entitymodule::E_HandSlot;

    Prop<bool> m_pInCombat;                                      // +0x000
    wh::shared::C_ModelProperty<
        E_CombatActorStateId::Type,
        wh::shared::traits::C_StaticDefaultValueTrait<E_CombatActorStateId::Type, E_CombatActorStateId::Idle>,
        traits::C_CombatSignalWithOldValueTrait<E_CombatActorStateId::Type>>
        m_pStateId;                                              // +0x030
    PropCustom<std::int32_t> m_pGuardTypeId;                     // +0x060
    PropCustom<std::int32_t> m_pGuardTypeOverrideId;             // +0x090
    PropCustom<std::int32_t> m_pGuardStanceId;                   // +0x0C0
    PropCustom<std::int32_t> m_pAttackZoneId;                    // +0x0F0
    PropStatic<std::int32_t, -1> m_pPendingAttackZoneId;         // +0x120
    PropCustom<std::int32_t> m_pDefenseZoneId;                   // +0x150
    PropStatic<std::int32_t, -1> m_pCommittedAttackZone;         // +0x180
    PropStatic<E_HandSlot, E_HandSlot::Left> m_pAttackingHand;   // +0x1B0
    Prop<float> m_pAttackStrength;                               // +0x1E0
    PropStatic<std::int32_t, -1> m_pAttackTypeId;                // +0x210
    PropStatic<std::int32_t, -1> m_pAttackInputClassId;          // +0x240
    PropStatic<std::int32_t, -1> m_pExecutedAttackZone;          // +0x270
    Prop<bool> m_pAttackRequested;                               // +0x2A0
    Prop<bool> m_pIsAttacking;                                   // +0x2D0
    Prop<bool> m_pIsBlocking;                                    // +0x300
    Prop<bool> m_pIsFreeBlocking;                                // +0x330
    Prop<bool> m_pIsInCombo;                                     // +0x360
    Prop<bool> m_pIsRiposteAttack;                               // +0x390
    Prop<bool> m_pClenchedHandActive;                            // +0x3C0
    PropCustom<float> m_pBlockTimeToStart;                       // +0x3F0
    PropCustom<float> m_pBlockTimeToEnd;                         // +0x420
    PropCustom<float> m_pBlockTimeToHit;                         // +0x450
    Prop<bool> m_pAttackTargetIsCurrentOpponent;                 // +0x480
    Prop<bool> m_pIsOpponentInReach;                             // +0x4B0
    Prop<bool> m_pIsOpponentInExtendedReach;                     // +0x4E0
    PropRefBool m_pHasAttackerInExtendedReach;                   // +0x510
    Prop<bool> m_pComboAttackPending;                            // +0x540
    Prop<float> m_pPlayerNormalAttackTimeOffset;                 // +0x570
    Prop<bool> m_pAttackHitPositionReachable;                    // +0x5A0
    PropStatic<std::int32_t, -1> m_pOpponentAttackZoneId;        // +0x5D0
    PropStatic<E_HandSlot, E_HandSlot::Left> m_pBlockingHand;    // +0x600

    wh::shared::C_ModelContextProperty<E_BlockModeContext, E_BlockMode::Type, 0>
        m_blockModeContext;                                      // +0x630
    Prop<E_BlockMode::Type> m_blockMode;                         // +0x650
    Prop<bool> m_perfectBlockActionActive;                       // +0x680
    PropRefBool m_freeBlockShieldUp;                             // +0x6B0
    Prop<CTimeValue> m_lastHitAsSourceTime;                      // +0x6E0
    Prop<CTimeValue> m_lastHitAsTargetTime;                      // +0x710
    PropRefBoolActor m_blockTrigger;                             // +0x740
    PropRefBoolActor m_perfectBlockTrigger;                      // +0x770  sub actor-vt[153/154]
    PropRefBoolActor m_syncPerfectBlockTrigger;                  // +0x7A0  sub actor-vt[157/158]
    PropRefBoolActor m_masterStrikeTrigger;                      // +0x7D0  sub actor-vt[159/160]
    PropRefBoolActor m_dodgeTrigger;                             // +0x800  sub actor-vt[161/162]
    Prop<bool> m_riposteTriggerActive;                           // +0x830  sub actor-vt[127/128]
    Prop<bool> m_comboTriggerActive;                             // +0x860  sub actor-vt[131/132]
    // TRACED 2026-08-21 -- sole writer: C_CombatTriggerBlock (vtbl 0x183B813F8) via setter
    // 0x18090A100: OnOpen[14] 0x180908A9C sets TRUE if the bound attacker (0x180908CF4) already
    // has stateId==Striking(8), else subscribes the ATTACKER's m_pStateId (cb 0x1809089AC) and
    // flips TRUE on strike entry; OnClose[15] 0x180908B50 sets FALSE. Signal payload = attacker.
    // Value byte @+0x898, signal @+0x8A8 (connect 0x180C58D68 / disconnect 0x180C58E0C).
    // Subscribers: C_CombatAutomationBlock hdl 0x18148345C (automation req type 6 vs attacker);
    // C_CombatActorActionBlockTrigger start[57]/stop[58] hdl 0x181482DA0 (auto-block 0x181483250).
    // Both gated by actor+0x280. NPC path: the stateId cb itself creates+pushes the BlockTrigger
    // action (ActionManager 0x181699500 -> Director PushAction 0x18090C850) when blockModeContext
    // vf[2] allows -- that action IS the native auto-block executor.
    wh::shared::C_ModelProperty<
        bool,
        wh::shared::traits::C_StandardDefaultValueTrait<bool>,
        traits::C_CombatSignalWithNewValueTrait<bool, I_CombatActor*>>
        m_blockTriggerTargetAttacking;                           // +0x890
    wh::shared::C_ModelArrayProperty<
        wh::framework::WUID, E_HandSlot, 2,
        wh::shared::traits::C_CustomDefaultValueTrait<wh::framework::WUID>>
        m_equippedItemWuidBySlot;                                // +0x8C0
    wh::shared::C_ModelArrayProperty<
        std::int32_t, E_HandSlot, 2,
        wh::shared::traits::C_CustomDefaultValueTrait<std::int32_t>>
        m_weaponClassIdBySlot;                                   // +0x910
    wh::shared::C_ModelArrayProperty<
        std::int32_t, E_HandSlot, 2,
        wh::shared::traits::C_CustomDefaultValueTrait<std::int32_t>>
        m_weaponSubClassIdBySlot;                                // +0x958
    Prop<bool> m_hasUsableGuardAction;                           // +0x9A0
    Prop<E_AnimActionMovementState::Type> m_combatAnimMovementState; // +0x9D0
    Prop<float> m_attackOptimalDistanceSample;                   // +0xA00
    Prop<float> m_predictedAttackDistance;                       // +0xA30
    Prop<float> m_blockDistance;                                 // +0xA60
    Prop<float> m_afterHitDistance;                              // +0xA90
    PropCustom<float> m_optimalDistanceRatio;                    // +0xAC0
    PropRefBool m_waitingForPathToTarget;                        // +0xAF0
    wh::shared::C_ModelSetProperty<S_RestrictedInputClass> m_restrictedInput; // +0xB20
    wh::shared::C_ModelArrayProperty<bool, E_GuardRequestScope::Type, 8>
        m_guardRequestByScope;                                   // +0xB58
    Prop<std::uint32_t> m_combatFlags;                           // +0xBA0

    wh::shared::C_Signal<I_CombatActor&, std::uint32_t, std::uint32_t, std::uint32_t>
        m_onCombatFlagsSet;                                      // +0xBD0
    wh::shared::C_Signal<I_CombatActor&, std::uint32_t, std::uint32_t, std::uint32_t>
        m_onCombatFlagsCleared;                                  // +0xBE0
    wh::shared::C_Signal<I_CombatActor&> m_onOpponentCleared;    // +0xBF0
    wh::shared::C_Signal<I_CombatActor&> m_onOpponentReplaced;   // +0xC00
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor*> m_onOpponentAcquired; // +0xC10
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor*, I_CombatActor*>
        m_onOpponentChange;                                      // +0xC20
    wh::shared::C_Signal<I_CombatActor&, I_CombatTarget*, I_CombatTarget*>
        m_onCommittedTargetChange;                               // +0xC30
    wh::shared::C_Signal<I_CombatActor&, I_CombatTarget*, I_CombatTarget*>
        m_onSelectedTargetChange;                                // +0xC40
    Prop<bool> m_committedTargetIsAiming;                        // +0xC50
    Prop<bool> m_guardVariationEnabled;                          // +0xC80
    Prop<bool> m_guardVariationOneShotActive;                    // +0xCB0

    C_CombatActor*  m_pOwner;                                   // +0xCE0
    I_CombatTarget* m_pCommittedTarget;                          // +0xCE8, owned
    I_CombatTarget* m_pSelectedTarget;                           // +0xCF0, owned
    C_CombatActor*  m_pOpponent;                                // +0xCF8, borrowed
    std::set<std::uint32_t> m_aimingOpponentEntityIds;          // +0xD00
};

static_assert(sizeof(S_CombatActorState) == 0xD10);
static_assert(offsetof(S_CombatActorState, m_pStateId) == 0x030);
static_assert(offsetof(S_CombatActorState, m_pCommittedAttackZone) == 0x180);
static_assert(offsetof(S_CombatActorState, m_pAttackingHand) == 0x1B0);
static_assert(offsetof(S_CombatActorState, m_pIsInCombo) == 0x360);
static_assert(offsetof(S_CombatActorState, m_pBlockTimeToStart) == 0x3F0);
static_assert(offsetof(S_CombatActorState, m_pAttackTargetIsCurrentOpponent) == 0x480);
static_assert(offsetof(S_CombatActorState, m_pHasAttackerInExtendedReach) == 0x510);
static_assert(offsetof(S_CombatActorState, m_blockModeContext) == 0x630);
static_assert(offsetof(S_CombatActorState, m_blockMode) == 0x650);
static_assert(offsetof(S_CombatActorState, m_perfectBlockActionActive) == 0x680);
static_assert(offsetof(S_CombatActorState, m_perfectBlockTrigger) == 0x770);
static_assert(offsetof(S_CombatActorState, m_masterStrikeTrigger) == 0x7D0);
static_assert(offsetof(S_CombatActorState, m_riposteTriggerActive) == 0x830);
static_assert(offsetof(S_CombatActorState, m_equippedItemWuidBySlot) == 0x8C0);
static_assert(offsetof(S_CombatActorState, m_restrictedInput) == 0xB20);
static_assert(offsetof(S_CombatActorState, m_guardRequestByScope) == 0xB58);
static_assert(offsetof(S_CombatActorState, m_combatFlags) == 0xBA0);
static_assert(offsetof(S_CombatActorState, m_onCombatFlagsSet) == 0xBD0);
static_assert(offsetof(S_CombatActorState, m_committedTargetIsAiming) == 0xC50);
static_assert(offsetof(S_CombatActorState, m_pOwner) == 0xCE0);
static_assert(offsetof(S_CombatActorState, m_pOpponent) == 0xCF8);
static_assert(offsetof(S_CombatActorState, m_aimingOpponentEntityIds) == 0xD00);

}  // namespace wh::combatmodule
