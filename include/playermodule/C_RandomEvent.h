#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "C_RandomEventBase.h"
#include "S_RandomEventTag.h"

namespace wh::playermodule {

class C_RandomEvent : public C_RandomEventBase {
public:
    C_RandomEvent();
    ~C_RandomEvent() override;                              // [0] 0x1815331B8
    RTTR_ENABLE(C_RandomEventBase) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                         // [27] 0x1812BCD98
    void OnExecute(
        wh::conceptmodule::S_NodeExecuteContext const& context) override; // [33] 0x1814773F0
    void Reset() override;                                  // [37] 0x18175AD44

    bool CanSpawn() const override;                         // [55] 0x181832ACC
    bool CanDespawn() const override;                       // [59] 0x181460948
    bool HasTag(CryStringT<char> const& tag) const override; // [64] 0x182EAC018
    Vec3 GetSpawnPosition() const override;                 // [67] 0x182EAB614
    Quat GetSpawnRotation() const override;                 // [68] 0x182EAB838
    void OnStarted() override;                              // [69] 0x180622234

    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_activateCooldown;   // +0x1F0 RTTR "ActivateCooldown"
    wh::conceptmodule::C_TypedPortRef<bool> m_isEnabled;   // +0x230 RTTR "IsEnabled"
    std::vector<S_RandomEventTag> m_tags;                   // +0x270 RTTR "Tags"
};

static_assert(sizeof(C_RandomEvent) == 0x288,
              "C_RandomEvent size mismatch");
static_assert(offsetof(C_RandomEvent, m_activateCooldown) == 0x1F0,
              "C_RandomEvent cooldown trigger offset mismatch");
static_assert(offsetof(C_RandomEvent, m_isEnabled) == 0x230,
              "C_RandomEvent enabled port offset mismatch");
static_assert(offsetof(C_RandomEvent, m_tags) == 0x270,
              "C_RandomEvent tags offset mismatch");

} // namespace wh::playermodule
