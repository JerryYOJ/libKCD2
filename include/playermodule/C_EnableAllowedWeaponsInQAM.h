#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../entitymodule/I_ItemDescriptor.h"
#include "../rpgmodule/I_Soul.h"

namespace wh::playermodule {

class C_EnableAllowedWeaponsInQAM : public wh::conceptmodule::C_Effect {
public:
    C_EnableAllowedWeaponsInQAM();
    ~C_EnableAllowedWeaponsInQAM() override;                     // [0] 0x1816ECB3C
    RTTR_ENABLE(wh::conceptmodule::C_Effect) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27] 0x182DE0354
    void OnEffectActivate() override;                           // [43] 0x182DE1078
    void OnEffectDeactivate() override;                         // [44] 0x182DE17E0

    wh::conceptmodule::C_TypedPortRef<
        std::shared_ptr<wh::entitymodule::I_ItemDescriptor>> m_mainHandDescriptor; // +0x88
    wh::conceptmodule::C_TypedPortRef<
        bool> m_requireMainHandEmpty;                           // +0xC8
    wh::conceptmodule::C_TypedPortRef<
        std::shared_ptr<wh::entitymodule::I_ItemDescriptor>> m_offHandDescriptor; // +0x108
    wh::conceptmodule::C_TypedPortRef<
        bool> m_requireOffHandEmpty;                            // +0x148
    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<wh::rpgmodule::I_Soul*>> m_playerSouls;    // +0x188

    std::shared_ptr<wh::entitymodule::I_ItemDescriptor>
        m_resolvedMainHandDescriptor;                          // +0x1C8
    bool m_resolvedRequireMainHandEmpty;                       // +0x1D8
    std::uint8_t m_padding1D9[7];                             // +0x1D9
    std::shared_ptr<wh::entitymodule::I_ItemDescriptor>
        m_resolvedOffHandDescriptor;                           // +0x1E0
    bool m_resolvedRequireOffHandEmpty;                        // +0x1F0
    std::uint8_t m_padding1F1[7];                             // +0x1F1
    bool m_applied;                                            // +0x1F8
    std::uint8_t m_padding1F9[7];                             // +0x1F9
};

static_assert(sizeof(C_EnableAllowedWeaponsInQAM) == 0x200,
              "C_EnableAllowedWeaponsInQAM size mismatch");
static_assert(offsetof(C_EnableAllowedWeaponsInQAM, m_mainHandDescriptor) == 0x88,
              "C_EnableAllowedWeaponsInQAM main-hand port offset mismatch");
static_assert(offsetof(C_EnableAllowedWeaponsInQAM, m_playerSouls) == 0x188,
              "C_EnableAllowedWeaponsInQAM souls offset mismatch");
static_assert(offsetof(C_EnableAllowedWeaponsInQAM,
                       m_resolvedMainHandDescriptor) == 0x1C8,
              "C_EnableAllowedWeaponsInQAM runtime state offset mismatch");
static_assert(offsetof(C_EnableAllowedWeaponsInQAM, m_applied) == 0x1F8,
              "C_EnableAllowedWeaponsInQAM applied offset mismatch");

} // namespace wh::playermodule
