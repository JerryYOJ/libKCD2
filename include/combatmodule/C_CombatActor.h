#pragma once
#include <cstdint>
#include <vector>
#include "I_CombatActor.h"
#include "E_AnimActionMovementState.h"
#include "E_CombatActorStateId.h"
#include "E_CombatAttackType.h"
#include "E_CombatGuardType.h"
#include "E_CombatInputClass.h"
#include "E_CombatSlotId.h"
#include "E_CombatZoneId.h"
#include "E_CounterActionType.h"
#include "E_SignalSource.h"
#include "E_WeaponKind.h"
#include "S_HitInfo.h"
#include "S_MeleeHitDetails.h"
#include "S_OptionalCombatGuardType.h"
#include "../rpgmodule/E_RpgDamageType.h"
#include "../CryEngine/CryCommon/smartptr.h"
#include "../crysystem/EntityEventListenerWithCleanup.h"
#include "../framework/C_Signal.h"
#include "../framework/C_Listeners.h"

// -----------------------------------------------
// wh::combatmodule::C_CombatActor -- per-entity combat state object (KCD2 1.5.6, kd7u).  sizeof 0x448.
// -----------------------------------------------
// RTTI primary vtable 0x183E3FAC8 (217 slots)  secondary EntityEventListenerWithCleanup @+0x08 0x183E3FAB0
// ctor sub_1810F01A8   dtor sub_1810EF698
// factory sub_1810EFEDC (alloc 0x448 via custom deleter qword_18549D358).
// The player's combat actor is reached via C_Actor::m_pCombatActor (C_Actor+0x278).
//
// Bases: I_CombatActor @+0x00 (declares primary slots [0..8]), EntityEventListenerWithCleanup @+0x08
// (2-slot secondary vtable). Own members from +0x10. Primary slots [9..174] are declared below
// ([9..106] named query/lifecycle API, [107..174] signal-subscribe band); [175..216] remain
// undeclared. The counter dispatch was located as the non-virtual core sub_181483580
// (see DispatchCounterAction below); the actor-level SetAction entry is the non-virtual sub_18090C850
// (copies the smart_ptr and forwards to the director's sub_1809CC3D4). Their vtable SLOT numbers (if any)
// remain unknown -- do NOT hardcode a slot, find it via a runtime vtable dump.
//
// [FUNDAMENTAL vs KCD1] sizeof 0x780 -> 0x448; every offset moved. MI: I_ItemAttachmentListener base
//   REMOVED, IEntityEventListener folded into EntityEventListenerWithCleanup. C_Signal shrank 0x30 -> 0x10;
//   28 signal heads @+0x38 (KCD1 had ~24). New KCD2 subsystems: GuardVarSystem, SlotPlanner, Weapons,
//   Clinch, Events, OpponentAimingListener, ClenchedHand, Activity.
//
// Signal heads +0x128..+0x188 and the dealt/received-hit heads +0x1D8/+0x1E8 are
// emit/consumer-verified. Earlier heads remain KCD1-correlated unless noted; +0x198..+0x1C8
// still lack recovered argument lists and therefore remain C_Signal<>.

struct SGameObjectEvent;

namespace Offsets { class IActor; }

namespace wh::entitymodule {
enum class E_HandSlot : int32_t;
struct S_WeaponClass;
}

namespace wh::combatmodule {

class I_CombatActorAction;
class I_CombatTarget;
class I_CombatActorStealth;
class I_CombatActorHorsePullDown;
class I_CombatActorMercyKill;
class I_CombatActorHuntAttack;
class I_CombatActorEvents;
class I_CombatActorWeapons;
class I_CombatComboManager;
class I_CombatEnvironmentManager;
class I_CombatAutomation;
typedef _smart_ptr<I_CombatActorAction> I_CombatActorActionPtr;

// --- subsystem classes (each owned pointer below; RE'd separately) ---
class C_CombatActorDirector;
class C_CombatScene;
struct S_CombatActorState;
class C_CombatActorObject;
class C_CombatActorUpdatedObject;
class C_CombatActorCollisions;
class C_CombatActorAnimCollisions;
class C_CombatActorData;
class C_CombatEffects;
class C_CombatActorRestriction;
class C_CombatEnvironmentManager;
class C_CombatAutomation;
class C_CombatAlignmentManager;
class C_CombatActorVirtualWeapon;
class C_CombatModifierAim;
class C_CombatModifierLookEnemy;
class C_CombatRPG;
class C_CombatHumanPhysics;
class C_CombatActorActionManager;
class C_CombatComboManager;
class C_CombatActorOpponentManager;
class C_CombatActorTimeCop;
class C_CombatActorTimewarp;
class C_CombatActorNextGuardSelector;
class C_CombatActorGuardVarSystem;
class C_CombatActorSlotPlanner;
class C_CombatActorWeapons;
class C_CombatActorClinch;
class C_CombatActorStealth;
class C_CombatActorHorsePullDown;
class C_CombatActorMercyKill;
class C_CombatActorHuntAttack;
class C_CombatActorEvents;
class C_CombatOpponentAimingListener;
class C_CombatActorClenchedHand;
class C_CombatActorActivity;

class C_CombatActor
    : public I_CombatActor                             // +0x00  (217-slot primary vtable; GetEntity=slot7)
    , public ::EntityEventListenerWithCleanup          // +0x08  (2-slot secondary vtable)
{
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatActor;
    template<class... Args> using Delegate = wh::shared::S_Delegate<Args...>;

    // ---- primary vtable [9..106] (adversarial-verified 2026-08-21; 18/28/87/88/94 stay unk) ----
    virtual C_CombatActor* GetSelectedTargetCombatActor() = 0;                              // [9]  0x18072DB78
    virtual Offsets::IActor* LookupSelectedTarget() = 0;                                    // [10] 0x18072DBF8
    virtual Offsets::IEntity* GetSelectedTargetEntity() = 0;                                // [11] 0x180B233AC
    virtual uint32_t GetSelectedTargetEntityId() = 0;                                       // [12] 0x180B21308
    virtual const char* GetSelectedTargetName() = 0;                                        // [13] 0x182756694
    virtual E_CombatZoneId GetAttackZoneId() = 0;                                           // [14] 0x182756664
    virtual E_CombatGuardType GetGuardTypeId() = 0;                                         // [15] 0x181710620
    virtual I_CombatActorActionPtr GetAction(int32_t directorSlot) = 0;                     // [16] 0x18072E698  director m_actions index
    virtual void StopCombat() = 0;                                                          // [17] 0x180D5C6F0
    virtual bool unk_18() = 0;                                                              // [18] 0x18041A6A0  shared return-true stub
    virtual E_CombatActorStateId::Type GetStateId() = 0;                                    // [19] 0x18091268C
    virtual bool IsInState(E_CombatActorStateId::Type state) = 0;                           // [20] 0x18072EFDC
    virtual bool HasStateFlags(E_CombatActorStateId::Type mask) = 0;                        // [21] 0x1809D162C
    virtual bool IsOpponentInState(E_CombatActorStateId::Type state) = 0;                   // [22] 0x182756CC4
    virtual bool HasOpponentStateFlags(E_CombatActorStateId::Type mask) = 0;                // [23] 0x182756CA0
    virtual bool HasUsableGuard() = 0;                                                      // [24] 0x182755090
    virtual bool IsOpponentInReach() = 0;                                                   // [25] 0x180C55DD8
    virtual bool IsOpponentInExtendedReach() = 0;                                           // [26] 0x182755068
    virtual bool IsReadyToGuard() = 0;                                                      // [27] 0x18072E5A0
    virtual bool unk_28() = 0;                                                              // [28] 0x18041A6A0  shared return-true stub
    virtual bool IsConscious() = 0;                                                         // [29] 0x1809D15D0
    virtual bool HasCombatFlag10() = 0;                                                     // [30] 0x1809115EC  m_combatFlags bit 0x10
    virtual bool HasCombatFlag20() = 0;                                                     // [31] 0x182756D98  m_combatFlags bit 0x20
    virtual bool HasCombatFlag100() = 0;                                                    // [32] 0x182756D70  m_combatFlags bit 0x100
    virtual bool IsGuard() = 0;                                                             // [33] 0x180B23A80
    virtual bool IsStriking() = 0;                                                          // [34] 0x182756BE8
    virtual bool IsParryInPlace() = 0;                                                      // [35] 0x182756BF4
    virtual bool IsPerfectBlockActionActive() = 0;                                          // [36] 0x180D55EB8
    virtual bool IsRiposteAttack() = 0;                                                     // [37] 0x18072DA8C
    virtual bool IsHitBlockBroken() = 0;                                                    // [38] 0x180C52E2C
    virtual bool IsPerfectBlockTriggerActive() = 0;                                         // [39] 0x182756CE8
    virtual bool IsDodgeTriggerActive() = 0;                                                // [40] 0x182756C00
    virtual bool IsRiposteTriggerActive() = 0;                                              // [41] 0x180D4AE58
    virtual void CollectActiveSlots(std::vector<E_CombatSlotId::Type>& out) = 0;            // [42] 0x182756264
    virtual bool IsMeleeAttackAction() = 0;                                                 // [43] 0x180C50874
    virtual bool IsPerfectBlockAction() = 0;                                                // [44] 0x181647880
    virtual bool IsDodgeAction() = 0;                                                       // [45] 0x18072E630
    virtual bool IsHitAction() = 0;                                                         // [46] 0x180C507E4
    virtual bool IsOpponentMutual() = 0;                                                    // [47] 0x18072F000
    virtual bool IsMasterStrikeAction() = 0;                                                // [48] 0x180D53FB0
    virtual bool IsCommittedTargetAiming() = 0;                                             // [49] 0x182756BD0
    virtual float GetAttackDistanceForClass(const wh::entitymodule::S_WeaponClass* weaponClass) = 0; // [50] 0x18087B67C
    virtual float GetAttackDistance() = 0;                                                  // [51] 0x18087B624
    virtual float GetMaxAttackDistanceForClass(const wh::entitymodule::S_WeaponClass* weaponClass) = 0; // [52] 0x18087B6B8
    virtual float GetMaxAttackDistance() = 0;                                               // [53] 0x18087B650
    virtual float GetMeleeMaxAttackDistance() = 0;                                          // [54] 0x1807DAFB8
    virtual float GetHuntAttackDistanceForClass(const wh::entitymodule::S_WeaponClass* weaponClass) = 0; // [55] 0x180A51588
    virtual float GetHuntAttackDistance() = 0;                                              // [56] 0x180A5155C
    virtual float GetSyncGuardDistanceForClass(const wh::entitymodule::S_WeaponClass* weaponClass) = 0; // [57] 0x1816B76D0
    virtual float GetSyncGuardDistance() = 0;                                               // [58] 0x18177B454
    virtual bool IsStealthTakedownActive() = 0;                                             // [59] 0x1809D3968
    virtual bool HasCombatFlag80Or100() = 0;                                                // [60] 0x182756CFC
    virtual bool HasCombatFlag200() = 0;                                                    // [61] 0x182756D44
    virtual bool IsTackleAttack() = 0;                                                      // [62] 0x180D542CC
    virtual bool IsInHit() = 0;                                                             // [63] 0x180C5A6A0
    virtual float GetAutomationElapsedTime() = 0;                                           // [64] 0x1812248B0
    virtual I_CombatTarget* GetSelectedTarget() = 0;                                        // [65] 0x18072DA20
    virtual void SetSelectedTarget(Offsets::IEntity* entity) = 0;                           // [66] 0x180B21364
    virtual I_CombatTarget* GetCommittedTarget() = 0;                                       // [67] 0x181A7D7D0
    virtual E_CombatZoneId GetDefenseZoneId() = 0;                                          // [68] 0x180C562FC
    virtual E_CombatAttackType GetAttackTypeId() = 0;                                       // [69] 0x1827565D0
    virtual E_CombatZoneId GetExecutedAttackZone() = 0;                                     // [70] 0x18275667C
    virtual float GetAttackStrength() = 0;                                                  // [71] 0x1827565B8
    virtual wh::rpgmodule::E_RpgDamageType GetRpgDamageTypeId() = 0;                        // [72] 0x1827569B8
    virtual bool IsAttacking() = 0;                                                         // [73] 0x182756D58
    virtual void RequestAttack(E_CombatInputClass inputClass, bool requested) = 0;          // [74] 0x18093A28C
    virtual E_CombatZoneId GetOpponentAttackZoneId() = 0;                                   // [75] 0x1827565E8
    virtual void SetFreeBlockShieldUp(bool active) = 0;                                     // [76] 0x182757B4C
    virtual bool TryGetRiderGuardActionData(E_AnimActionMovementState::Type movement, void* out) = 0; // [77] 0x18275673C  out = 0x1C blob
    virtual I_CombatActorStealth* GetStealth() = 0;                                         // [78] 0x18082A6F0
    virtual I_CombatActorHorsePullDown* GetHorsePullDown() = 0;                             // [79] 0x18072FA90
    virtual I_CombatActorMercyKill* GetMercyKill() = 0;                                     // [80] 0x1816043E0
    virtual I_CombatActorHuntAttack* GetHuntAttack() = 0;                                   // [81] 0x180A518E0
    virtual I_CombatActorEvents* GetEvents() = 0;                                           // [82] 0x180D5B960
    virtual I_CombatActorWeapons* GetWeapons() = 0;                                         // [83] 0x18072D9B0
    virtual I_CombatComboManager* GetComboManager() = 0;                                    // [84] 0x18132C980
    virtual I_CombatEnvironmentManager* GetEnvironmentManager() = 0;                        // [85] 0x1809102E0
    virtual I_CombatAutomation* GetAutomation() = 0;                                        // [86] 0x1803EFE44  lazy-creates m_pAutomation
    virtual void unk_87() = 0;                                                              // [87] 0x1803EFE44  duplicate vptr of [86]
    virtual void unk_88() = 0;                                                              // [88] 0x1803B6E80  nullsub
    virtual bool IsFullyBuilt() = 0;                                                        // [89] 0x1810F2390
    virtual void BuildSubsystems() = 0;                                                     // [90] 0x180916ECC
    virtual bool Initialize() = 0;                                                          // [91] 0x180B80824
    virtual void DestroySubsystems() = 0;                                                   // [92] 0x1804CA9DC
    virtual void ClearCombat() = 0;                                                         // [93] 0x181002D18
    virtual void unk_94() = 0;                                                              // [94] 0x1803B6E80  nullsub
    virtual void PostSerialize() = 0;                                                       // [95] 0x1827571B0
    virtual void Reset(bool keepState) = 0;                                                 // [96] 0x182756F44
    virtual void ResetCollisions() = 0;                                                     // [97] 0x180C5F704
    virtual void BeginPrePhysicsUpdate() = 0;                                               // [98] 0x1809E3A58
    virtual void PrePhysicsUpdate(float frameTime) = 0;                                     // [99] 0x1809E3F9C
    virtual void Update(float frameTime) = 0;                                               // [100] 0x18072F644
    virtual void PostUpdate(float frameTime) = 0;                                           // [101] 0x181002E08
    virtual void HandleEvent(const SGameObjectEvent& event) = 0;                            // [102] 0x1803B6E80  nullsub; C_Actor forwards here
    virtual void Activate() = 0;                                                            // [103] 0x1810033EC
    virtual void Deactivate() = 0;                                                          // [104] 0x1827570F0
    virtual void OnEquipmentHandlerSet() = 0;                                               // [105] 0x1803B6E80  nullsub
    virtual bool TryEnterCombat(const S_OptionalCombatGuardType& guardType) = 0;            // [106] 0x180C5A1BC

    // ---- primary vtable [107..174]: signal-subscribe band, 34 Connect/Disconnect pairs ----
    // (all 34 pairs decompile-verified 2026-08-21) Connect = de-dup by {instance,invoke} -> reserve(5)
    // on first use -> append (index-writer sub_182420480); Disconnect = linear find -> emit-cursor
    // fixup -> in-place erase. The delegate is invoked as invoke(instance, <signal args>); prop-signal
    // args come from the property's Sig trait (CombatModelTraits.h), owner = property +0x10.
    // Subscribers MUST Disconnect with the SAME delegate before unload; connections die with the actor
    // (per-combat lifetime), so re-subscribe on actor recreation. Signals/props without a pair here are
    // engine-internal only.
    virtual void ConnectInCombatSignal(const Delegate<I_CombatActor&, bool>& d) = 0;                        // [107] 0x180914AB8  m_pState->m_pInCombat
    virtual void DisconnectInCombatSignal(const Delegate<I_CombatActor&, bool>& d) = 0;                     // [108] 0x180914A84
    virtual void ConnectOnActionBaseSignal(const Delegate<I_CombatActor&, const int&, const I_CombatActorActionPtr&, const I_CombatActorActionPtr&>& d) = 0;    // [109] 0x18090DF94  m_onActionBase
    virtual void DisconnectOnActionBaseSignal(const Delegate<I_CombatActor&, const int&, const I_CombatActorActionPtr&, const I_CombatActorActionPtr&>& d) = 0; // [110] 0x18090DF68
    virtual void ConnectSignalE8(const Delegate<I_CombatActor&, const int&, const I_CombatActorActionPtr&, const I_CombatActorActionPtr&>& d) = 0;              // [111] 0x18090DF3C  m_signalE8
    virtual void DisconnectSignalE8(const Delegate<I_CombatActor&, const int&, const I_CombatActorActionPtr&, const I_CombatActorActionPtr&>& d) = 0;           // [112] 0x18090DF10
    virtual void ConnectSignalF8(const Delegate<I_CombatActor&, I_CombatActor&, const int&, const I_CombatActorActionPtr&, const I_CombatActorActionPtr&>& d) = 0;    // [113] 0x180C58FCC  m_signalF8
    virtual void DisconnectSignalF8(const Delegate<I_CombatActor&, I_CombatActor&, const int&, const I_CombatActorActionPtr&, const I_CombatActorActionPtr&>& d) = 0; // [114] 0x180C59600
    virtual void ConnectOnCombatModeChangeSignal(const Delegate<I_CombatActor&, I_CombatActor&, bool>& d) = 0;    // [115] 0x1810EC824  m_onCombatModeChange
    virtual void DisconnectOnCombatModeChangeSignal(const Delegate<I_CombatActor&, I_CombatActor&, bool>& d) = 0; // [116] 0x1810EC270
    virtual void ConnectOnCombatZoneChangeSignal(const Delegate<I_CombatActor&, I_CombatActor&, bool>& d) = 0;    // [117] 0x182755200  m_onCombatZoneChange
    virtual void DisconnectOnCombatZoneChangeSignal(const Delegate<I_CombatActor&, I_CombatActor&, bool>& d) = 0; // [118] 0x18275543C
    virtual void ConnectCommittedTargetIsAimingSignal(const Delegate<I_CombatActor&, bool>& d) = 0;         // [119] 0x1810EDDE4  m_pState->m_committedTargetIsAiming
    virtual void DisconnectCommittedTargetIsAimingSignal(const Delegate<I_CombatActor&, bool>& d) = 0;      // [120] 0x1810EC924
    virtual void ConnectAttackZoneIdSignal(const Delegate<I_CombatActor&, E_CombatZoneId>& d) = 0;          // [121] 0x1810ED124  m_pState->m_pAttackZoneId
    virtual void DisconnectAttackZoneIdSignal(const Delegate<I_CombatActor&, E_CombatZoneId>& d) = 0;       // [122] 0x1810ED88C
    virtual void ConnectGuardTypeIdSignal(const Delegate<I_CombatActor&, E_CombatGuardType>& d) = 0;        // [123] 0x180C5A13C  m_pState->m_pGuardTypeId
    virtual void DisconnectGuardTypeIdSignal(const Delegate<I_CombatActor&, E_CombatGuardType>& d) = 0;     // [124] 0x1810ED8A0
    virtual void ConnectDefenseZoneIdSignal(const Delegate<I_CombatActor&, E_CombatZoneId>& d) = 0;         // [125] 0x18192E000  m_pState->m_pDefenseZoneId
    virtual void DisconnectDefenseZoneIdSignal(const Delegate<I_CombatActor&, E_CombatZoneId>& d) = 0;      // [126] 0x1810ED550
    virtual void ConnectRiposteTriggerActiveSignal(const Delegate<I_CombatActor&, bool>& d) = 0;            // [127] 0x1827551D8  m_pState->m_riposteTriggerActive
    virtual void DisconnectRiposteTriggerActiveSignal(const Delegate<I_CombatActor&, bool>& d) = 0;         // [128] 0x182755414
    virtual void ConnectOnRiposteAttackSignal(const Delegate<I_CombatActor&, I_CombatActor&, E_SignalSource::Type, bool>& d) = 0;    // [129] 0x180B1E028  m_onRiposteAttack
    virtual void DisconnectOnRiposteAttackSignal(const Delegate<I_CombatActor&, I_CombatActor&, E_SignalSource::Type, bool>& d) = 0; // [130] 0x180B1DE6C
    virtual void ConnectComboTriggerActiveSignal(const Delegate<I_CombatActor&, bool>& d) = 0;              // [131] 0x182755148  m_pState->m_comboTriggerActive
    virtual void DisconnectComboTriggerActiveSignal(const Delegate<I_CombatActor&, bool>& d) = 0;           // [132] 0x182755384
    virtual void ConnectIsInComboSignal(const Delegate<I_CombatActor&, bool>& d) = 0;                       // [133] 0x18275515C  m_pState->m_pIsInCombo
    virtual void DisconnectIsInComboSignal(const Delegate<I_CombatActor&, bool>& d) = 0;                    // [134] 0x182755398
    virtual void ConnectOnIsAttackingSignal(const Delegate<I_CombatActor&, I_CombatActor&, E_SignalSource::Type, bool>& d) = 0;    // [135] 0x180B1E190  m_onIsAttacking
    virtual void DisconnectOnIsAttackingSignal(const Delegate<I_CombatActor&, I_CombatActor&, E_SignalSource::Type, bool>& d) = 0; // [136] 0x180B1E1BC
    virtual void ConnectOnCommittedAttackZoneChangedSignal(const Delegate<I_CombatActor&, I_CombatActor&, E_SignalSource::Type>& d) = 0;    // [137] 0x182755228  m_onCommittedAttackZoneChanged
    virtual void DisconnectOnCommittedAttackZoneChangedSignal(const Delegate<I_CombatActor&, I_CombatActor&, E_SignalSource::Type>& d) = 0; // [138] 0x182755464
    virtual void ConnectOnBlockModeActiveSignal(const Delegate<I_CombatActor&, I_CombatActor&, E_SignalSource::Type, bool>& d) = 0;    // [139] 0x180B1DC84  m_onBlockModeActive
    virtual void DisconnectOnBlockModeActiveSignal(const Delegate<I_CombatActor&, I_CombatActor&, E_SignalSource::Type, bool>& d) = 0; // [140] 0x180B1DD00
    virtual void ConnectOnAutomationSignal(const Delegate<I_CombatActor&, I_CombatActor&, E_SignalSource::Type>& d) = 0;    // [141] 0x182755184  m_onAutomationSignal
    virtual void DisconnectOnAutomationSignal(const Delegate<I_CombatActor&, I_CombatActor&, E_SignalSource::Type>& d) = 0; // [142] 0x1827553C0
    virtual void ConnectOnAutomationTargetSignal(const Delegate<I_CombatActor&, I_CombatActor*>& d) = 0;    // [143] 0x180D5BB28  m_onAutomationTarget
    virtual void DisconnectOnAutomationTargetSignal(const Delegate<I_CombatActor&, I_CombatActor*>& d) = 0; // [144] 0x180D5BA34
    virtual void ConnectSignal198(const Delegate<>& d) = 0;                                                 // [145] 0x180E6BD68  m_signal198 (args unrecovered)
    virtual void DisconnectSignal198(const Delegate<>& d) = 0;                                              // [146] 0x180E6BE60
    virtual void ConnectOnHitDealtSignal(const Delegate<I_CombatActor&, I_CombatActor*, S_HitInfo&, S_MeleeHitDetails&>& d) = 0;    // [147] 0x180D4EC24  m_onHitDealt
    virtual void DisconnectOnHitDealtSignal(const Delegate<I_CombatActor&, I_CombatActor*, S_HitInfo&, S_MeleeHitDetails&>& d) = 0; // [148] 0x180D4EAD4
    virtual void ConnectOnHitReceivedSignal(const Delegate<I_CombatActor&, I_CombatActor*, S_HitInfo&, S_MeleeHitDetails&>& d) = 0;    // [149] 0x180B1E4EC  m_onHitReceived
    virtual void DisconnectOnHitReceivedSignal(const Delegate<I_CombatActor&, I_CombatActor*, S_HitInfo&, S_MeleeHitDetails&>& d) = 0; // [150] 0x180B1DC08
    virtual void ConnectOpponentAttackZoneIdSignal(const Delegate<I_CombatActor&, E_CombatZoneId>& d) = 0;  // [151] 0x182755114  m_pState->m_pOpponentAttackZoneId
    virtual void DisconnectOpponentAttackZoneIdSignal(const Delegate<I_CombatActor&, E_CombatZoneId>& d) = 0; // [152] 0x182755350
    virtual void ConnectPerfectBlockTriggerSignal(const Delegate<I_CombatActor&, bool, I_CombatActor&>& d) = 0;    // [153] 0x1827551C4  m_pState->m_perfectBlockTrigger
    virtual void DisconnectPerfectBlockTriggerSignal(const Delegate<I_CombatActor&, bool, I_CombatActor&>& d) = 0; // [154] 0x182755400
    virtual void ConnectPerfectBlockActionActiveSignal(const Delegate<I_CombatActor&, bool>& d) = 0;        // [155] 0x18192DF9C  m_pState->m_perfectBlockActionActive
    virtual void DisconnectPerfectBlockActionActiveSignal(const Delegate<I_CombatActor&, bool>& d) = 0;     // [156] 0x18192DF38
    virtual void ConnectSyncPerfectBlockTriggerSignal(const Delegate<I_CombatActor&, bool, I_CombatActor&>& d) = 0;    // [157] 0x1827551EC  m_pState->m_syncPerfectBlockTrigger
    virtual void DisconnectSyncPerfectBlockTriggerSignal(const Delegate<I_CombatActor&, bool, I_CombatActor&>& d) = 0; // [158] 0x182755428
    virtual void ConnectMasterStrikeTriggerSignal(const Delegate<I_CombatActor&, bool, I_CombatActor&>& d) = 0;    // [159] 0x1827551B0  m_pState->m_masterStrikeTrigger
    virtual void DisconnectMasterStrikeTriggerSignal(const Delegate<I_CombatActor&, bool, I_CombatActor&>& d) = 0; // [160] 0x1827553EC
    virtual void ConnectDodgeTriggerSignal(const Delegate<I_CombatActor&, bool, I_CombatActor&>& d) = 0;    // [161] 0x182755170  m_pState->m_dodgeTrigger
    virtual void DisconnectDodgeTriggerSignal(const Delegate<I_CombatActor&, bool, I_CombatActor&>& d) = 0; // [162] 0x1827553AC
    virtual void ConnectWeaponClassIdBySlotSignal(const Delegate<I_CombatActor&, bool>& d) = 0;             // [163] 0x180C5A2B8  m_pState->m_weaponClassIdBySlot aggregate signal (+0x30)
    virtual void DisconnectWeaponClassIdBySlotSignal(const Delegate<I_CombatActor&, bool>& d) = 0;          // [164] 0x180C5A2FC
    virtual void ConnectOnWeaponKindSignal(const Delegate<I_CombatActor&, E_SignalSource::Type, E_WeaponKind::Type>& d) = 0;    // [165] 0x18151C27C  m_onWeaponKind
    virtual void DisconnectOnWeaponKindSignal(const Delegate<I_CombatActor&, E_SignalSource::Type, E_WeaponKind::Type>& d) = 0; // [166] 0x18151C1F4 (0x85 bytes, extra teardown)
    virtual void ConnectOnSelectedTargetChangeSignal(const Delegate<I_CombatActor&, I_CombatTarget*, I_CombatTarget*>& d) = 0;    // [167] 0x180D5CA84  m_pState->m_onSelectedTargetChange
    virtual void DisconnectOnSelectedTargetChangeSignal(const Delegate<I_CombatActor&, I_CombatTarget*, I_CombatTarget*>& d) = 0; // [168] 0x180D5CA08
    virtual void ConnectOnCommittedTargetChangeSignal(const Delegate<I_CombatActor&, I_CombatTarget*, I_CombatTarget*>& d) = 0;    // [169] 0x180D5CAB8  m_pState->m_onCommittedTargetChange
    virtual void DisconnectOnCommittedTargetChangeSignal(const Delegate<I_CombatActor&, I_CombatTarget*, I_CombatTarget*>& d) = 0; // [170] 0x180D5CC08
    virtual void ConnectStateIdSignal(const Delegate<I_CombatActor&, E_CombatActorStateId::Type, E_CombatActorStateId::Type>& d) = 0;    // [171] 0x18090A240  m_pState->m_pStateId (old value)
    virtual void DisconnectStateIdSignal(const Delegate<I_CombatActor&, E_CombatActorStateId::Type, E_CombatActorStateId::Type>& d) = 0; // [172] 0x18090A210
    virtual void ConnectOnCombatActionStateChangeSignal(const Delegate<I_CombatActor&, I_CombatActor&, E_CombatActorStateId::Type, E_CombatActorStateId::Type>& d) = 0;    // [173] 0x1810ED138  m_onCombatActionStateChange
    virtual void DisconnectOnCombatActionStateChangeSignal(const Delegate<I_CombatActor&, I_CombatActor&, E_CombatActorStateId::Type, E_CombatActorStateId::Type>& d) = 0; // [174] 0x1810ECFF8

    // ---- non-virtual methods (forwarders in src/combatmodule/C_CombatActor.cpp) ----

    void DispatchCounterAction(I_CombatActorActionPtr* pOutAction, E_CounterActionType type,
                               uint32_t scopeIndex = 0, bool useOpponentDefenseZone = false,
                               int32_t queryId = -1);

    void SetOpponent(C_CombatActor* target);

    uint8_t  m_updateMode;                             // +0x28   init 4 (update-bucket mode; enum domain UNVERIFIED, no reader traced)
    uint8_t  _pad29[7];                                // +0x29
    uint64_t m_field30;                                // +0x30   dtor sub_1823C8B4C deregisters &this+0x31 from global registry qword_18492D988; init writer & type unrecovered

    // ---- signals (+0x38..+0x1F8, 28 x 0x10; verification split documented above) ----
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&, E_CombatActorStateId::Type, E_CombatActorStateId::Type> m_onCombatStateChange;       // +0x38
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&, E_CombatActorStateId::Type, E_CombatActorStateId::Type> m_onCombatActionStateChange; // +0x48
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&, bool> m_onCombatModeChange;                 // +0x58
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&, bool> m_onCombatZoneChange;                 // +0x68
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&, int>  m_onCombatGuardTypeChange;            // +0x78
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&, int>  m_onOpponentGuardType;                // +0x88
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&, int>  m_signal98;                           // +0x98   (KCD2-added int signal)
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&, int, wh::entitymodule::E_HandSlot> m_onOpponentHandSlot; // +0xA8
    wh::shared::C_Signal<I_CombatActor&, bool> m_onOpponentPBWindow;                                 // +0xB8
    wh::shared::C_Signal<I_CombatActor&, bool> m_signalC8;                                           // +0xC8
    wh::shared::C_Signal<I_CombatActor&, const int&, const I_CombatActorActionPtr&, const I_CombatActorActionPtr&> m_onActionBase; // +0xD8
    wh::shared::C_Signal<I_CombatActor&, const int&, const I_CombatActorActionPtr&, const I_CombatActorActionPtr&> m_signalE8;     // +0xE8
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&, const int&, const I_CombatActorActionPtr&, const I_CombatActorActionPtr&> m_signalF8;               // +0xF8
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&, const int&, const I_CombatActorActionPtr&, const I_CombatActorActionPtr&> m_onOpponentActionChanged; // +0x108
    wh::shared::C_Signal<> m_onCombatEvent;                                                          // +0x118  (parameterless; high confidence)
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&, E_SignalSource::Type, bool> m_onRiposteAttack; // +0x128
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&, E_SignalSource::Type, bool> m_onIsAttacking;   // +0x138
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&, E_SignalSource::Type> m_onCommittedAttackZoneChanged; // +0x148
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&, E_SignalSource::Type, bool> m_onBlockModeActive; // +0x158
    wh::shared::C_Signal<I_CombatActor&, E_SignalSource::Type, E_WeaponKind::Type> m_onWeaponKind; // +0x168
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor&, E_SignalSource::Type> m_onAutomationSignal; // +0x178
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor*> m_onAutomationTarget; // +0x188
    wh::shared::C_Signal<> m_signal198;                                                              // +0x198  (M-group; args unrecovered)
    wh::shared::C_Signal<> m_signal1A8;                                                              // +0x1A8  (M-group; args unrecovered)
    wh::shared::C_Signal<> m_signal1B8;                                                              // +0x1B8  (M-group; args unrecovered)
    wh::shared::C_Signal<> m_signal1C8;                                                              // +0x1C8  (M-group; args unrecovered)
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor*, S_HitInfo&, S_MeleeHitDetails&> m_onHitDealt;    // +0x1D8
    wh::shared::C_Signal<I_CombatActor&, I_CombatActor*, S_HitInfo&, S_MeleeHitDetails&> m_onHitReceived; // +0x1E8

    // ---- core pointers + subsystem region 1 (+0x1F8..+0x270) ----
    Offsets::IEntity*             m_pEntity;           // +0x1F8  (GetEntity slot7)  VERIFIED
    C_CombatActorDirector*        m_pDirector;         // +0x200  (0xB8)  VERIFIED
    C_CombatScene*                m_pCombatScene;      // +0x208  (ctor arg)  VERIFIED
    S_CombatActorState*           m_pState;            // +0x210  (0xD10)  VERIFIED
    C_CombatActorCollisions*      m_pCollisions;       // +0x218  (0x268)  VERIFIED
    C_CombatActorAnimCollisions*  m_pAnimCollisions;   // +0x220  (0x40)   VERIFIED
    C_CombatActorData*            m_pActorData;        // +0x228  (0x30)   VERIFIED
    C_CombatEffects*              m_pEffects;          // +0x230  (0x30)   VERIFIED
    C_CombatActorRestriction*     m_pRestriction;      // +0x238  (0x50)   VERIFIED
    C_CombatEnvironmentManager*   m_pEnvironmentManager; // +0x240 (0xA0)  VERIFIED
    C_CombatAutomation*           m_pAutomation;       // +0x248  LAZY (null until first use)  VERIFIED
    C_CombatAlignmentManager*     m_pAlignmentManager; // +0x250  (0x78)   VERIFIED
    C_CombatActorVirtualWeapon*   m_pVirtualWeapon;    // +0x258  (0x20)   VERIFIED
    C_CombatModifierAim*          m_pModifierAim;      // +0x260  (0x20)   VERIFIED
    C_CombatModifierLookEnemy*    m_pModifierLookEnemy; // +0x268 (0x20)   VERIFIED
    void*                         m_pActorRef0;        // +0x270  -> 8-byte heap cell holding C_CombatActor* back-ref (builder alloc(8); *cell=this)

    // ---- scalars + listeners (+0x278..+0x386) ----
    uint16_t m_flags278;                               // +0x278  (init 0)
    uint8_t  m_isFullyBuilt;                           // +0x27A  0 -> 1 when the builder finishes
    uint8_t  _pad27B;                                  // +0x27B
    int32_t  m_stateIndex;                             // +0x27C  init -1
    uint8_t  m_isInitialized;                          // +0x280  init 1; gates ALL internal auto-block paths (0x1809089AC/0x181482DA0/0x181809B30),
                                                       //         CLEARED by C_CombatAutomationBlock ctor 0x180C57EC8 => likely "internal auto-block enabled" (rename pending reader survey)
    uint8_t  m_flag281;                                // +0x281  (init 0)
    uint8_t  _pad282[2];                               // +0x282
    uint8_t  m_field284[8];                            // +0x284  combat runtime state; state-reset sub_1810EFF60 zeroes it as a qword (with m_stateIndex/m_flags278/timers); non-zero writer & sub-type unrecovered
    uint8_t  m_stateFlags28C;                          // +0x28C  masked &0xFC
    uint8_t  _pad28D[3];                               // +0x28D
    float    m_timerA;                                 // +0x290  init -1.0
    float    m_timerB;                                 // +0x294  init -1.0
    uint8_t  m_meleeRuntimeState[0x1C];                // +0x298  gameplay-set state block
    uint8_t  m_updatePhase;                            // +0x2B4  init 4 (per-frame update phase; enum domain UNVERIFIED)
    uint8_t  _pad2B5[3];                               // +0x2B5
    wh::shared::C_Listeners<C_CombatActorObject, 1>        m_objectListeners;   // +0x2B8  registered subsystem objects
    wh::shared::C_Listeners<C_CombatActorUpdatedObject, 1> m_updateListeners0;  // +0x2E0  per-frame update buckets
    wh::shared::C_Listeners<C_CombatActorUpdatedObject, 1> m_updateListeners1;  // +0x308
    wh::shared::C_Listeners<C_CombatActorUpdatedObject, 1> m_updateListeners2;  // +0x330
    wh::shared::C_Listeners<C_CombatActorUpdatedObject, 1> m_updateListeners3;  // +0x358
    int32_t  m_updateCounter;                          // +0x380  (init 0)
    int16_t  m_index384;                               // +0x384  init -1
    uint8_t  _pad386[2];                               // +0x386

    // ---- subsystem region 2 (+0x388..+0x438) ----
    C_CombatRPG*                    m_pCombatRPG;       // +0x388  (0x60)  VERIFIED
    void*                           m_pActorRef1;       // +0x390  -> 8-byte heap cell holding C_CombatActor* back-ref (builder alloc(8); *cell=this)
    C_CombatHumanPhysics*           m_pHumanPhysics;    // +0x398  (0x18)  VERIFIED
    void*                           m_pStateListener;   // +0x3A0  -> heap 0x20 non-poly obj (ctor sub_1809179E4): {C_CombatActor* owner; ListNode* conn; qword; qword}; subscribes cb sub_180C5B160 to m_pState(+0x210) signal @+0x18
    C_CombatActorActionManager*     m_pActionManager;   // +0x3A8  (0x70)  VERIFIED
    C_CombatComboManager*           m_pComboManager;    // +0x3B0  (0xF0)  VERIFIED
    C_CombatActorOpponentManager*   m_pOpponentManager; // +0x3B8  (0x40)  VERIFIED
    C_CombatActorTimeCop*           m_pTimeCop;         // +0x3C0  (0x98)  VERIFIED
    C_CombatActorTimewarp*          m_pTimewarp;        // +0x3C8  (0x48)  VERIFIED
    C_CombatActorNextGuardSelector* m_pNextGuardSelector; // +0x3D0 (0x20) VERIFIED
    C_CombatActorGuardVarSystem*    m_pGuardVarSystem;  // +0x3D8  (0x40)  VERIFIED (NEW in KCD2)
    C_CombatActorSlotPlanner*       m_pSlotPlanner;     // +0x3E0  (0x58)  VERIFIED (NEW in KCD2)
    C_CombatActorWeapons*           m_pWeapons;         // +0x3E8  (0x30)  VERIFIED (NEW in KCD2)
    C_CombatActorClinch*            m_pClinch;          // +0x3F0  (0x28)  VERIFIED (NEW in KCD2)
    C_CombatActorStealth*           m_pStealth;         // +0x3F8  (0xC8)  VERIFIED
    C_CombatActorHorsePullDown*     m_pHorsePullDown;   // +0x400  (0x28)  VERIFIED
    C_CombatActorMercyKill*         m_pMercyKill;       // +0x408  (0x20)  VERIFIED
    C_CombatActorHuntAttack*        m_pHuntAttack;      // +0x410  (0x20)  VERIFIED
    C_CombatActorEvents*            m_pEvents;          // +0x418  (0x78)  VERIFIED (NEW in KCD2)
    C_CombatOpponentAimingListener* m_pOpponentAimingListener; // +0x420 (0x18) VERIFIED (NEW in KCD2)
    C_CombatActorClenchedHand*      m_pClenchedHand;    // +0x428  (0x48)  VERIFIED (NEW in KCD2)
    C_CombatActorActivity*          m_pActivity;        // +0x430  (0x10)  VERIFIED (NEW in KCD2)
    void*                           m_field438;         // +0x438  ctor 0x1810F05CC zero-init; no writer in ctor/builder/dtor/reset; sits directly before m_lock (lock-guarded lazy ptr candidate, unconfirmed)
    void*                           m_lock;             // +0x440  SRWLOCK.Ptr -- ctor 0x1810F05D3 InitializeSRWLock(&this+0x440); field IS the lock (one pointer-sized word), not a pointer to a lock
};
static_assert(sizeof(C_CombatActor) == 0x448, "C_CombatActor must be 0x448");

}  // namespace wh::combatmodule
