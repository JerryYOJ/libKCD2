#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../entitymodule/I_RemovedEntityListener.h"

namespace wh::playermodule {

class C_Battlement;

class C_DisableMinigameEffect
    : public wh::conceptmodule::C_Effect,
      public wh::entitymodule::I_RemovedEntityListener {
public:
    C_DisableMinigameEffect();
    ~C_DisableMinigameEffect() override;                        // primary [0], secondary [0]
    RTTR_ENABLE(wh::conceptmodule::C_Effect) // primary [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // primary [27] 0x182DE00E4
    void OnEffectActivate() override;                           // primary [43] 0x180DA619C
    void OnEffectDeactivate() override;                         // primary [44] 0x180DA629C

    bool OnBeforeSpawn(SEntitySpawnParams& params) override;    // secondary [1], returns true
    void OnSpawn(IEntity* entity, SEntitySpawnParams& params) override; // secondary [2]
    bool OnRemove(IEntity* entity) override;                    // secondary [3] 0x181274E8C
    void OnReused(IEntity* entity, SEntitySpawnParams& params) override; // secondary [4]
    void OnEvent(IEntity* entity, SEntityEvent& event) override; // secondary [5]
    void GetMemoryUsage(ICrySizer* sizer) const override;       // secondary [6]
    const char* GetName() const override;                       // secondary [7] 0x181A97A90

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<C_Battlement*>> m_minigameObjects;          // +0x90
    bool m_listenerRegistered;                                  // +0xD0
    std::uint8_t m_paddingD1[7];                               // +0xD1
    std::vector<std::uint32_t> m_disabledEntityIds;             // +0xD8
};

static_assert(sizeof(C_DisableMinigameEffect) == 0xF0,
              "C_DisableMinigameEffect size mismatch");
static_assert(offsetof(C_DisableMinigameEffect, m_minigameObjects) == 0x90,
              "C_DisableMinigameEffect objects offset mismatch");
static_assert(offsetof(C_DisableMinigameEffect, m_listenerRegistered) == 0xD0,
              "C_DisableMinigameEffect listener flag offset mismatch");
static_assert(offsetof(C_DisableMinigameEffect, m_disabledEntityIds) == 0xD8,
              "C_DisableMinigameEffect entity ids offset mismatch");

} // namespace wh::playermodule
