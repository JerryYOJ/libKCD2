#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <vector>

#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "C_RandomEventVariantBase_S_NpcGroup.h"
#include "S_RandomEventTag.h"

namespace wh::playermodule {

class C_RandomEventVariant : public C_RandomEventVariantBase {
public:
    C_RandomEventVariant();
    ~C_RandomEventVariant() override;                         // [0] 0x1804C560C
    RTTR_ENABLE(C_RandomEventVariantBase) // [5..7]
    bool Load(XmlNodeRef node) override;                      // [11] 0x182ECE454
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                           // [27] 0x181413680
    void OnExecute(
        wh::conceptmodule::S_NodeExecuteContext const& context) override; // [33] 0x181477468

    CryStringT<char> GetProfile() const override;             // [55] 0x18136450C
    bool GetDespawnOnTimeskip() const override;               // [56] 0x18062218C
    void EnumerateNpcGroups(NpcGroupSink sink) const override; // [57] 0x182041BF0
    std::shared_ptr<S_RandomEventFastTravelData>
        GetFastTravelData(float direction, bool requireOptions) const override; // [58] 0x180620990
    std::vector<S_RandomEventOption*>
        GetFastTravelOptions() const override;                // [59] 0x182ECD4C8
    void InitializeVariant() override;                        // [60] 0x181421AC0
    bool IsAvailable() const override;                        // [61] 0x18142D2A8
    bool HasTag(CryStringT<char> const& tag) const override;  // [62] 0x182ECE078
    bool HasFastTravelOptions() const override;               // [63] 0x182ECE024

    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_activateCooldown;     // +0x280
    std::optional<CryStringT<char>> m_profile;                // +0x2C0
    std::optional<bool> m_despawnOnTimeskip;                  // +0x2D0
    std::optional<bool> m_npcGroupsAdditive;                  // +0x2D2
    std::uint8_t m_padding2D4[4];
    std::vector<S_NpcGroup> m_npcGroups;                      // +0x2D8
    std::vector<S_RandomEventTag> m_tags;                     // +0x2F0
    std::shared_ptr<S_RandomEventFastTravelData>
        m_playerInitiatedFastTravelData;                      // +0x308
};

static_assert(sizeof(C_RandomEventVariant) == 0x318,
              "C_RandomEventVariant size mismatch");
static_assert(offsetof(C_RandomEventVariant, m_activateCooldown) == 0x280,
              "C_RandomEventVariant cooldown trigger offset mismatch");
static_assert(offsetof(C_RandomEventVariant, m_profile) == 0x2C0,
              "C_RandomEventVariant profile offset mismatch");
static_assert(offsetof(C_RandomEventVariant, m_npcGroups) == 0x2D8,
              "C_RandomEventVariant NPC groups offset mismatch");
static_assert(offsetof(C_RandomEventVariant, m_tags) == 0x2F0,
              "C_RandomEventVariant tags offset mismatch");
static_assert(offsetof(C_RandomEventVariant,
                       m_playerInitiatedFastTravelData) == 0x308,
              "C_RandomEventVariant player fast-travel data offset mismatch");

} // namespace wh::playermodule
