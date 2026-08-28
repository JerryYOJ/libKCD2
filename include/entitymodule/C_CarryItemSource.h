#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"

namespace wh::entitymodule {

class C_CarryItemPile;

class C_CarryItemSource : public wh::conceptmodule::C_Effect {
public:
    C_CarryItemSource();                                                // 0x1810D5EFC
    ~C_CarryItemSource() override;                                      // [0] 0x18177AD88
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                            // [5..7], vtable 0x183B06830
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                    // [27] 0x18295ECBC
    void OnEffectActivate() override;                                  // [43] 0x180D7AE1C
    void OnEffectDeactivate() override;                                // [44] 0x180D7A72C

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<C_CarryItemPile*>> m_ciPiles;                       // +0x88 RTTR "CIPiles"
    std::vector<C_CarryItemPile*> m_resolvedPiles;                      // +0xC8 activation-time source set
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onEmpty;                        // +0xE0 RTTR "OnEmpty"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onItemPickedUp;                 // +0x120 RTTR "OnItemPickedUp"
    std::uint32_t m_emptyPileCount;                                    // +0x160 maintained by pile callbacks
    std::uint32_t m_padding164;                                        // +0x164
};

static_assert(offsetof(C_CarryItemSource, m_ciPiles) == 0x88,
              "C_CarryItemSource::m_ciPiles offset mismatch");
static_assert(offsetof(C_CarryItemSource, m_resolvedPiles) == 0xC8,
              "C_CarryItemSource::m_resolvedPiles offset mismatch");
static_assert(offsetof(C_CarryItemSource, m_onEmpty) == 0xE0,
              "C_CarryItemSource::m_onEmpty offset mismatch");
static_assert(offsetof(C_CarryItemSource, m_onItemPickedUp) == 0x120,
              "C_CarryItemSource::m_onItemPickedUp offset mismatch");
static_assert(offsetof(C_CarryItemSource, m_emptyPileCount) == 0x160,
              "C_CarryItemSource::m_emptyPileCount offset mismatch");
static_assert(sizeof(C_CarryItemSource) == 0x168,
              "C_CarryItemSource size mismatch");

} // namespace wh::entitymodule
