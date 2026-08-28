#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../conceptmodule/C_ModuleBase.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../framework/C_NumberWrapper.h"
#include "../framework/S_TimeSpan.h"
#include "../xgenaimodule/I_AreaTracker.h"
#include "E_RandomEventGlobalCooldown.h"

namespace wh::xgenaimodule { class C_TriggerArea; }

namespace wh::playermodule {

using C_RandomEventDifficulty = wh::framework::C_NumberWrapper<
    wh::framework::NumberWrapperPolicy::Clamp<
        0, 1, float, std::true_type, std::true_type>>;

class C_RandomEventPlace
    : public wh::conceptmodule::C_ModuleBase,
      public wh::xgenaimodule::I_AreaTracker {
public:
    C_RandomEventPlace();
    ~C_RandomEventPlace() override;                            // primary [0] 0x1815AB614
    RTTR_ENABLE(wh::conceptmodule::C_ModuleBase) // primary [5..7]
    bool Load(XmlNodeRef node) override;                       // primary [11] 0x182ECE3C4
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                            // primary [27] 0x180E8CA50
    bool unk29() override;                                    // primary [29] true
    void Serialize(TSerialize serializer) override;           // primary [30] 0x1820420F0
    bool unk32() override;                                    // primary [32] true
    void OnLifecycleEvent(std::int32_t event) override;       // primary [34] 0x180C9B99C
    void UnregisterAutoTrigger() override;                     // primary [38] 0x180F6ED38
    void ForceDeactivate() override;                          // primary [39] 0x180C9CF74
    void PropagateToPorts(bool propagate) override;           // primary [40] 0x180C9BB8C
    wh::conceptmodule::E_HibernateMode::Type
        GetHibernateMode() const override;                    // primary [43] 0x181A78EB0
    std::uint8_t GetModuleKind() const override;              // primary [44] 0x181A74A40

    void OnAreaEntered(
        wh::xgenaimodule::I_NPC* npc,
        wh::framework::WUID areaWuid,
        std::int32_t eventFlags) override;                    // secondary [0] 0x18061FAF8
    void OnAreaLeft(
        wh::xgenaimodule::I_NPC* npc,
        wh::framework::WUID areaWuid,
        std::int32_t eventFlags) override;                    // secondary [1] 0x1817AE048
    void OnAreaRemoved(
        wh::xgenaimodule::I_Area* area) override;             // secondary [2] 0x182ED0508
    void OnNPCRemoved(
        wh::xgenaimodule::I_NPC* npc) override;               // secondary [3] 0x182ED04DC

    wh::framework::S_TimeSpan m_cooldown;                    // +0xA8 RTTR "Cooldown"
    E_RandomEventGlobalCooldown::Type m_globalCooldownType;  // +0xB0 RTTR "GlobalCooldownType"
    std::uint8_t m_paddingB1[3];
    C_RandomEventDifficulty m_difficulty;                    // +0xB4 RTTR "Difficulty"
    C_RandomEventDifficulty m_difficultyMixRatio;            // +0xB8 RTTR "DifficultyMixRatio"
    float m_viewRadius;                                       // +0xBC RTTR "ViewRadius"
    bool m_allowConcurrentSpawn;                              // +0xC0 RTTR "AllowConcurrentSpawn"
    std::uint8_t m_paddingC1[7];
    wh::conceptmodule::C_TypedPortRef<bool> m_isEnabled;     // +0xC8 RTTR "IsEnabled"
    std::vector<wh::xgenaimodule::C_TriggerArea*> m_triggerAreas; // +0x108
    Vec3 m_cachedPosition;                                    // +0x120, zero resolves entity position
    std::uint8_t m_padding12C[4];
};

static_assert(sizeof(C_RandomEventDifficulty) == 0x04,
              "C_RandomEventDifficulty size mismatch");
static_assert(sizeof(C_RandomEventPlace) == 0x130,
              "C_RandomEventPlace size mismatch");
static_assert(offsetof(C_RandomEventPlace, m_cooldown) == 0xA8,
              "C_RandomEventPlace cooldown offset mismatch");
static_assert(offsetof(C_RandomEventPlace, m_difficulty) == 0xB4,
              "C_RandomEventPlace difficulty offset mismatch");
static_assert(offsetof(C_RandomEventPlace, m_isEnabled) == 0xC8,
              "C_RandomEventPlace enabled port offset mismatch");
static_assert(offsetof(C_RandomEventPlace, m_triggerAreas) == 0x108,
              "C_RandomEventPlace trigger areas offset mismatch");
static_assert(offsetof(C_RandomEventPlace, m_cachedPosition) == 0x120,
              "C_RandomEventPlace cached position offset mismatch");

} // namespace wh::playermodule
