#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Interactor.h"
#include "../framework/I_ModuleMessageListener.h"
#include "../framework/C_ModelProperty.h"
#include "../framework/C_Signal.h"
#include "../framework/S_ItemFlagInfo.h"
#include "../CryEngine/CryCommon/Cry_Math.h"

// -----------------------------------------------
// wh::entitymodule::C_PlayerInteractor -- KCD2 WHGame.dll 1.5.6 (kd7u). sizeof 0x5B8.
// -----------------------------------------------
// RTTI .?AVC_PlayerInteractor@entitymodule@wh@@. Bases: I_Interactor @+0x00 and
// framework::I_ModuleMessageListener @+0x10. Primary vtable 0x183A6A0C8 (6 slots),
// message-listener vtable 0x183A6A100 (2 slots). ctor sub_1809EDF08.
//
// The named prefix is constructor/getter/producer proven. +0x1B8..+0x5B8 contains the
// remaining selection caches, script state, listener objects, and interaction registries;
// their exact source types remain OPEN and are preserved as one explicit opaque tail.

namespace wh::entitymodule {

class C_PlayerInteractor : public I_Interactor,
                           public wh::framework::I_ModuleMessageListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PlayerInteractor;
    using ItemFlagProperty = wh::shared::C_ModelProperty<
        wh::framework::S_ItemFlagInfo,
        wh::shared::traits::C_StandardDefaultValueTrait<wh::framework::S_ItemFlagInfo>,
        wh::shared::traits::C_SignalWithNewValueTrait<wh::framework::S_ItemFlagInfo>,
        wh::shared::traits::C_DebugNoTrace,
        wh::shared::traits::C_NoSaveLoad,
        wh::shared::traits::C_OwnershipEmpty>;

    using CursorOffsetProperty = wh::shared::C_ModelProperty<
        Vec2_tpl<float>,
        wh::shared::traits::C_StandardDefaultValueTrait<Vec2_tpl<float>>,
        wh::shared::traits::C_SignalWithNewValueTrait<Vec2_tpl<float>>,
        wh::shared::traits::C_DebugNoTrace,
        wh::shared::traits::C_NoSaveLoad,
        wh::shared::traits::C_OwnershipEmpty>;

    ~C_PlayerInteractor() override;                         // [0] sub_1819D2578
    void Initialize(C_Player* pPlayer) override;            // [1] sub_1816DBAB4
    void ResetInteractionState() override;                  // [3] sub_1808E9300
    void Update() override;                                 // [5] sub_1807F2DD4
    void OnModuleMessage(void* pMessage) override;           // secondary [1] sub_18047A668

    wh::shared::C_Signal<> m_signal18;                      // +0x018  payload OPEN
    wh::shared::C_Signal<> m_signal28;                      // +0x028  payload OPEN
    ItemFlagProperty       m_itemFlagProperty;              // +0x038  signal @+0x070; sizeof 0x50
    CursorOffsetProperty   m_cursorOffsetProperty;          // +0x088  signal @+0x0A0; sizeof 0x30
    wh::shared::C_Signal<> m_signalB8;                      // +0x0B8  payload OPEN
    uint8_t                _unknownC8[0xB0];                // +0x0C8
    Vec3                   m_targetPosition;                // +0x178
    Vec3                   m_referencePosition;             // +0x184
    wh::framework::S_ItemFlagInfo m_itemFlagInfo;           // +0x190  source copied into m_itemFlagProperty
    uint8_t                _unknown1B8[0x400];              // +0x1B8  unresolved tail
};

static_assert(sizeof(C_PlayerInteractor::ItemFlagProperty) == 0x50,
              "item-flag model property must be 0x50");
static_assert(sizeof(C_PlayerInteractor::CursorOffsetProperty) == 0x30,
              "cursor-offset model property must be 0x30");
static_assert(sizeof(C_PlayerInteractor) == 0x5B8, "C_PlayerInteractor must be 0x5B8");
static_assert(offsetof(C_PlayerInteractor, m_itemFlagProperty) == 0x38,
              "m_itemFlagProperty must be at 0x38");
static_assert(offsetof(C_PlayerInteractor, m_targetPosition) == 0x178,
              "m_targetPosition must be at 0x178");
static_assert(offsetof(C_PlayerInteractor, m_itemFlagInfo) == 0x190,
              "m_itemFlagInfo must be at 0x190");

}  // namespace wh::entitymodule
