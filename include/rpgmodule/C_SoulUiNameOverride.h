#pragma once
#include <cstddef>
#include <cstdint>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../framework/C_LocalizedString.h"
#include "I_Soul.h"

namespace wh::rpgmodule {

class C_SoulUiNameOverride : public wh::conceptmodule::C_Effect {
public:
    C_SoulUiNameOverride();
    ~C_SoulUiNameOverride() override;                           // [0]
    RTTR_ENABLE(wh::conceptmodule::C_Effect) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27]
    void OnEffectActivate() override;                           // [43]
    void OnEffectDeactivate() override;                         // [44]

    wh::conceptmodule::C_TypedPortRef<I_Soul*> m_soul;         // +0x88
    wh::conceptmodule::C_TypedPortRef<
        wh::framework::C_LocalizedString> m_name;                // +0xC8
    bool m_overrideApplied;                                     // +0x108
    std::uint8_t m_padding109[7];                              // +0x109
};

static_assert(sizeof(C_SoulUiNameOverride) == 0x110,
              "C_SoulUiNameOverride size mismatch");
static_assert(offsetof(C_SoulUiNameOverride, m_soul) == 0x88,
              "C_SoulUiNameOverride soul offset mismatch");
static_assert(offsetof(C_SoulUiNameOverride, m_name) == 0xC8,
              "C_SoulUiNameOverride name offset mismatch");
static_assert(offsetof(C_SoulUiNameOverride, m_overrideApplied) == 0x108,
              "C_SoulUiNameOverride applied flag offset mismatch");

} // namespace wh::rpgmodule
