#pragma once
#include <cstddef>
#include <cstdint>
#include "C_UIFlashBase.h"
#include "C_UIForgeBuilderPlan.h"
#include "framework/C_ModelProperty.h"
#include "framework/I_UIForgeBuilder.h"
#include "playermodule/E_ForgePlanState.h"
#include "xgenaimodule/I_AreaTracker.h"

namespace wh::guimodule {

class C_UIForgeBuilder : public C_UIFlashBase,
                         public wh::framework::I_UIForgeBuilder,
                         public wh::xgenaimodule::I_AreaTracker {
public:
    using PlanState = wh::playermodule::E_ForgePlanState::Type;
    using PlanStateProperty = wh::shared::C_ModelProperty<
        PlanState,
        wh::shared::traits::C_StaticDefaultValueTrait<
            PlanState, static_cast<PlanState>(0)>,
        wh::shared::traits::C_SignalWithOldValueTrait<PlanState>,
        wh::shared::traits::C_DebugNoTrace,
        wh::shared::traits::C_NoSaveLoad,
        wh::shared::traits::C_OwnershipEmpty>;

    C_UIForgeBuilder();                                       // 0x181F77440
    ~C_UIForgeBuilder() override;                             // primary [0] 0x181F78180

    void Init(C_GUIModule* module) override;                  // [1] 0x181F78D40
    void Deinit() override;                                   // [2] 0x181F786D0
    void OnModuleMessage(void* message) override;             // [3] 0x181F79AF0
    void Update() override;                                   // [4] 0x181F7B340
    RTTR_ENABLE(C_UIBase, wh::framework::I_UIForgeBuilder)    // primary [7..9], interface [12..14]
    const char* GetElementName() const override;              // [11] 0x181A8E8F0

    void* unk_01() override;                                  // I_UIForgeBuilder [1] 0x181A73520
    void* unk_02() override;                                  // I_UIForgeBuilder [2] 0x181F78B60
    void unk_03(const void* slots) override;                  // I_UIForgeBuilder [3] 0x181F7ADB0
    void unk_04(const void* assets) override;                 // I_UIForgeBuilder [4] 0x181F7AA40
    void unk_05() override;                                   // I_UIForgeBuilder [5] 0x181F78580
    void unk_06(
        int activeSequence,
        std::int64_t value,
        std::uint8_t selection) override;                     // I_UIForgeBuilder [6] 0x181F7A1B0
    void unk_07(
        int activeSequence,
        std::int64_t value,
        std::uint8_t selection,
        std::int64_t slot) override;                          // I_UIForgeBuilder [7] 0x181F7A0E0
    void unk_08(float strength, float duration) override;     // I_UIForgeBuilder [8] 0x181F7B010
    void unk_09(float duration) override;                     // I_UIForgeBuilder [9] 0x181F78CF0
    void unk_10() override;                                   // I_UIForgeBuilder [10] 0x181F7AC40
    void unk_11() override;                                   // I_UIForgeBuilder [11] 0x181F78660

    void OnAreaEntered(
        wh::xgenaimodule::I_NPC* npc,
        wh::framework::WUID areaWuid,
        std::int32_t eventFlags) override;                     // I_AreaTracker [0] 0x181F79DA0
    void OnAreaLeft(
        wh::xgenaimodule::I_NPC* npc,
        wh::framework::WUID areaWuid,
        std::int32_t eventFlags) override;                     // I_AreaTracker [1] 0x181F79DB0
    void OnAreaRemoved(wh::xgenaimodule::I_Area* area) override; // I_AreaTracker [2] 0x181F7B2E0
    void OnNPCRemoved(wh::xgenaimodule::I_NPC* npc) override;    // I_AreaTracker [3] 0x181F7B2E0

    PlanStateProperty m_planState;                            // +0x68
    void* m_subscription;                                     // +0x90
    std::uint32_t m_unknown98;                                // +0x98, ctor 0
    std::uint32_t m_unknown9C;                                // +0x9C
    CryStringT<char> m_planName;                              // +0xA0
    C_UIForgeBuilderPlan m_plans[3];                          // +0xA8
    std::uint64_t m_unknown258;                               // +0x258
    std::uint16_t m_unknown260;                               // +0x260, ctor 0
    std::uint8_t m_padding262[6];
};

static_assert(sizeof(C_UIForgeBuilder::PlanStateProperty) == 0x28,
              "C_UIForgeBuilder::PlanStateProperty size mismatch");
static_assert(offsetof(C_UIForgeBuilder, m_planState) == 0x68,
              "C_UIForgeBuilder::m_planState offset mismatch");
static_assert(offsetof(C_UIForgeBuilder, m_plans) == 0xA8,
              "C_UIForgeBuilder::m_plans offset mismatch");
static_assert(sizeof(C_UIForgeBuilder) == 0x268,
              "C_UIForgeBuilder size mismatch");

}  // namespace wh::guimodule
