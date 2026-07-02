#pragma once
#include <cstdint>
#include <cstddef>
#include <cstring>
#include "CombatModelTraits.h"
#include "../framework/C_Signal.h"
#include "../framework/C_ModelProperty.h"
#include "../framework/C_ModelRefProperty.h"
#include "../framework/C_ModelContextProperty.h"
#include "../framework/C_ModelSetProperty.h"
#include "../framework/C_ModelArrayProperty.h"
#include "../framework/WUID.h"
#include "../CryEngine/CryCommon/TimeValue.h"

// -----------------------------------------------
// wh::combatmodule::S_CombatActorState -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0xD10.
// -----------------------------------------------
// Per-actor combat runtime state. Heap-allocated by the C_CombatActor subsystem builder
// (sub_180916ECC, alloc 3344) and stored at C_CombatActor+0x210 (m_pState). ctor sub_1810F10CC,
// field-init sub_1810F1D80. No RTTI / no own vtable -- a plain aggregate.
//
// [FUNDAMENTAL vs KCD1] KCD1's 0xD08 struct was 63 raw C_Signals followed by raw state fields.
// KCD2 redesigned it into a flat sequence of C_ModelProperty<T> sub-objects (stored value + its
// change signal unified, stride 0x30), then 8 standalone C_Signals and a small raw tail.
// A KCD1-style scalar read becomes `state->property.m_value` (value @ propertyOffset+0x08).
// [FUNDAMENTAL vs KCD1] m_pOpponent / m_pCurrentTarget / m_pPrevTarget are GONE from this struct;
// opponent tracking moved to C_CombatActorOpponentManager (C_CombatActor+0x3B8).
//
// Types/offsets/defaults are ctor-verified. Names marked (tentative) are inferred from type,
// default value and KCD1 ordering, NOT accessor-verified. The exact committed-attack-zone slot
// (KCD1 m_committedAttackZone) is one of the StaticDefault<-1> int properties -- unresolved.

namespace wh::entitymodule { enum class E_HandSlot : int32_t; }

namespace wh::combatmodule {

class I_CombatActor;
class C_CombatActor;
enum class E_CombatActorStateId : int32_t;   // (values not recovered)
enum class E_BlockModeContext : int32_t;     // context tag of the block-mode property (kind assumed enum)
namespace E_BlockMode               { enum Type : int32_t; }
namespace E_AnimActionMovementState { enum Type : int32_t; }
namespace E_GuardRequestScope       { enum Type : int32_t; }

// Element of the restricted-input set property (payload 0x20 proven from the set's node size;
// contents + real comparator unrecovered -- the memcmp ordering below is a layout-only stand-in).
struct S_RestrictedInputClass {
    uint8_t _raw[0x20];
    bool operator<(const S_RestrictedInputClass& o) const { return std::memcmp(_raw, o._raw, sizeof(_raw)) < 0; }
};

struct S_CombatActorState {
    // -- shorthand aliases for the property instantiations used below --
    template<class T>      using Prop       = wh::shared::C_ModelProperty<T>;
    template<class T>      using PropCustom = wh::shared::C_ModelProperty<T, wh::shared::traits::C_CustomDefaultValueTrait<T>>;
    template<class T, T V> using PropStatic = wh::shared::C_ModelProperty<T, wh::shared::traits::C_StaticDefaultValueTrait<T, V>>;
    using PropRefBool      = wh::shared::C_ModelRefProperty<traits::C_CombatSignalWithNewValueTrait<bool>>;
    using PropRefBoolActor = wh::shared::C_ModelRefProperty<traits::C_CombatSignalWithNewValueTrait<bool, I_CombatActor&>>;
    using E_HandSlot       = wh::entitymodule::E_HandSlot;

    Prop<bool>                                       m_pInCombat;          // +0x000  value m_isInCombat @+0x008; the KCD1 m_onCombatEnter/m_isInCombat pair (combo-mgr connects state+0)
    wh::shared::C_ModelProperty<E_CombatActorStateId,
        wh::shared::traits::C_StaticDefaultValueTrait<E_CombatActorStateId, (E_CombatActorStateId)1>,
        traits::C_CombatSignalWithOldValueTrait<E_CombatActorStateId>>
                                                     m_pStateId;           // +0x030  value @+0x038 (init 1); old-value signal = KCD1 m_onStateChange (tentative name)
    PropCustom<int>                                  m_pIntCfg060;         // +0x060  init dword_185320CD4 (cvar-style; name unresolved)
    PropCustom<int>                                  m_pIntCfg090;         // +0x090  init -1
    PropCustom<int>                                  m_pIntCfg0C0;         // +0x0C0  init dword_185320BDC
    PropCustom<int>                                  m_pIntCfg0F0;         // +0x0F0  init dword_1853218D0
    PropStatic<int, -1>                              m_pZone120;           // +0x120  -1-reset zone/id candidate (name unresolved)
    PropCustom<int>                                  m_pIntCfg150;         // +0x150  init dword_1853218D0
    PropStatic<int, -1>                              m_pZone180;           // +0x180
    PropStatic<E_HandSlot, (E_HandSlot)1>            m_pHandSlot1B0;       // +0x1B0
    Prop<float>                                      m_pFloat1E0;          // +0x1E0
    PropStatic<int, -1>                              m_pZone210;           // +0x210
    PropStatic<int, -1>                              m_pZone240;           // +0x240
    PropStatic<int, -1>                              m_pZone270;           // +0x270
    Prop<bool>                                       m_pBool2A0;           // +0x2A0
    Prop<bool>                                       m_pBool2D0;           // +0x2D0
    Prop<bool>                                       m_pBool300;           // +0x300
    Prop<bool>                                       m_pBool330;           // +0x330
    Prop<bool>                                       m_pComboBool360;      // +0x360  combo-mgr connects (tentative m_isInCombo)
    Prop<bool>                                       m_pBool390;           // +0x390
    Prop<bool>                                       m_pBool3C0;           // +0x3C0
    PropCustom<float>                                m_pFloat3F0;          // +0x3F0  init/default -1.0
    PropCustom<float>                                m_pFloat420;          // +0x420  init -1.0
    PropCustom<float>                                m_pFloat450;          // +0x450  init -1.0
    Prop<bool>                                       m_pComboBool480;      // +0x480  combo-mgr connects (tentative m_comboTriggerActive)
    Prop<bool>                                       m_pBool4B0;           // +0x4B0
    Prop<bool>                                       m_pBool4E0;           // +0x4E0
    PropRefBool                                      m_pRefBool510;        // +0x510
    Prop<bool>                                       m_pBool540;           // +0x540
    Prop<float>                                      m_pFloat570;          // +0x570
    Prop<bool>                                       m_pBool5A0;           // +0x5A0
    PropStatic<int, -1>                              m_pZone5D0;           // +0x5D0
    PropStatic<E_HandSlot, (E_HandSlot)1>            m_pHandSlot600;       // +0x600
    wh::shared::C_ModelContextProperty<E_BlockModeContext, E_BlockMode::Type, 0>
                                                     m_blockModeContext;   // +0x630  (0x20)
    Prop<E_BlockMode::Type>                          m_pBlockMode;         // +0x650
    Prop<bool>                                       m_pBlockingBool680;   // +0x680  after the block cluster (tentative m_isBlocking)
    PropRefBool                                      m_pRefBool6B0;        // +0x6B0
    Prop<CTimeValue>                                 m_pTime6E0;           // +0x6E0
    Prop<CTimeValue>                                 m_pTime710;           // +0x710
    PropRefBoolActor                                 m_pRefBoolActor740;   // +0x740
    PropRefBoolActor                                 m_pRefBoolActor770;   // +0x770
    PropRefBoolActor                                 m_pRefBoolActor7A0;   // +0x7A0
    PropRefBoolActor                                 m_pRefBoolActor7D0;   // +0x7D0
    PropRefBoolActor                                 m_pRefBoolActor800;   // +0x800
    Prop<bool>                                       m_pBool830;           // +0x830
    Prop<bool>                                       m_pComboBool860;      // +0x860  combo-mgr connects
    wh::shared::C_ModelProperty<bool, wh::shared::traits::C_StandardDefaultValueTrait<bool>,
        traits::C_CombatSignalWithNewValueTrait<bool, I_CombatActor*>>
                                                     m_pAttackTargetIsOpponent;  // +0x890  KCD1 m_attackTargetIsCurrentOpponent analogue (tentative)
    wh::shared::C_ModelArrayProperty<wh::framework::WUID, E_HandSlot, 2,
        wh::shared::traits::C_CustomDefaultValueTrait<wh::framework::WUID>>
                                                     m_weaponIdBySlot;     // +0x8C0  (0x50) default = invalid-WUID sentinel
    wh::shared::C_ModelArrayProperty<int, E_HandSlot, 2,
        wh::shared::traits::C_CustomDefaultValueTrait<int>>
                                                     m_weaponAimConfigBySlot;  // +0x910  (0x48) default -1 (tentative name)
    wh::shared::C_ModelArrayProperty<int, E_HandSlot, 2,
        wh::shared::traits::C_CustomDefaultValueTrait<int>>
                                                     m_weaponAux2BySlot;   // +0x958  (0x48) default -1 (tentative name)
    Prop<bool>                                       m_pBool9A0;           // +0x9A0
    Prop<E_AnimActionMovementState::Type>            m_pAnimMovementState; // +0x9D0
    Prop<float>                                      m_pFloatA00;          // +0xA00
    Prop<float>                                      m_pFloatA30;          // +0xA30
    Prop<float>                                      m_pFloatA60;          // +0xA60
    Prop<float>                                      m_pFloatA90;          // +0xA90
    PropCustom<float>                                m_pFloatAC0;          // +0xAC0  init/default -1.0
    PropRefBool                                      m_pRefBoolAF0;        // +0xAF0
    wh::shared::C_ModelSetProperty<S_RestrictedInputClass>
                                                     m_restrictedInput;    // +0xB20  (0x38) KCD1 m_onRestrictedInput analogue
    wh::shared::C_ModelArrayProperty<bool, E_GuardRequestScope::Type, 8>
                                                     m_guardRequestByScope;// +0xB58  (0x48) KCD1 m_onGuardRequest analogue
    Prop<unsigned int>                               m_pAttackersInReachCount;  // +0xBA0  value @+0xBA8 (KCD1 +0xC1C analogue, tentative name)
    // -- 8 standalone signals (argument lists unrecovered; only descriptor identity known) --
    wh::shared::C_Signal<>                           m_signalBD0;          // +0xBD0  desc unk_1855D4D30
    wh::shared::C_Signal<>                           m_signalBE0;          // +0xBE0  desc unk_1855D4D30
    wh::shared::C_Signal<>                           m_signalBF0;          // +0xBF0  desc unk_185666A40
    wh::shared::C_Signal<>                           m_signalC00;          // +0xC00  desc unk_185666A40
    wh::shared::C_Signal<>                           m_signalC10;          // +0xC10  desc unk_185666930
    wh::shared::C_Signal<>                           m_signalC20;          // +0xC20  desc unk_185666888; combo-mgr connects (sub_180B21CD0)
    wh::shared::C_Signal<>                           m_signalC30;          // +0xC30  desc unk_1856668A8
    wh::shared::C_Signal<>                           m_signalC40;          // +0xC40  desc unk_1856668A8
    Prop<bool>                                       m_pBoolC50;           // +0xC50  trailing bool cluster: trigger-active candidates
    Prop<bool>                                       m_pBoolC80;           // +0xC80
    Prop<bool>                                       m_pBoolCB0;           // +0xCB0
    // -- raw tail --
    C_CombatActor*                                   m_pOwner;             // +0xCE0  = ctor arg
    void*                                            m_blockCtxDelegate0;  // +0xCE8  cached block-context delegate (tentative)
    void*                                            m_blockCtxDelegate1;  // +0xCF0
    void*                                            m_field_CF8;          // +0xCF8
    void*                                            m_triggerListHead;    // +0xD00  -> 32B self-linked intrusive-list sentinel (sub_180472128)
    void*                                            m_field_D08;          // +0xD08
};
static_assert(sizeof(S_CombatActorState) == 0xD10, "S_CombatActorState must be 0xD10");
static_assert(offsetof(S_CombatActorState, m_pStateId) == 0x030, "m_pStateId offset");
static_assert(offsetof(S_CombatActorState, m_blockModeContext) == 0x630, "m_blockModeContext offset");
static_assert(offsetof(S_CombatActorState, m_weaponIdBySlot) == 0x8C0, "m_weaponIdBySlot offset");
static_assert(offsetof(S_CombatActorState, m_restrictedInput) == 0xB20, "m_restrictedInput offset");
static_assert(offsetof(S_CombatActorState, m_signalBD0) == 0xBD0, "m_signalBD0 offset");
static_assert(offsetof(S_CombatActorState, m_pOwner) == 0xCE0, "m_pOwner offset");

}  // namespace wh::combatmodule
