#pragma once
#include <cstddef>
#include <cstdint>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../entitymodule/S_ItemClassGUID.h"
#include "../rpgmodule/S_BuffDefinitionId.h"
#include "S_BlacksmithRecipeId.h"

namespace wh::playermodule {

class C_Blacksmithing;
class C_Smithery;

class C_BlacksmithTrigger
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect> {
public:
    C_BlacksmithTrigger();
    ~C_BlacksmithTrigger() override;                            // [0] 0x18178A0B4
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27] 0x182DDFE74
    void GetPortDefinitions(
        wh::conceptmodule::definition::PortDefinitionSink sink,
        bool includeAll) override;                              // [28] 0x1813E6194
    void OnEffectActivate() override;                           // [43] 0x1809F2864
    void OnEffectDeactivate() override;                         // [44] 0x1809F27FC

    wh::conceptmodule::C_TypedPortRef<C_Smithery*> m_smithery;  // +0xB0
    wh::conceptmodule::C_TypedPortRef<
        S_BlacksmithRecipeId> m_recipe;                         // +0xF0
    wh::conceptmodule::C_TypedPortRef<
        wh::entitymodule::S_ItemClassGUID> m_productItemClass;  // +0x130
    wh::conceptmodule::C_TypedPortRef<
        std::uint32_t> m_productQuality;                        // +0x170
    wh::conceptmodule::C_TypedPortRef<float> m_productCondition; // +0x1B0
    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::S_BuffDefinitionId> m_productOnEquipBuff; // +0x1F0
    C_Blacksmithing* m_pBlacksmithing;                          // +0x230
};

static_assert(sizeof(C_BlacksmithTrigger) == 0x238,
              "C_BlacksmithTrigger size mismatch");
static_assert(offsetof(C_BlacksmithTrigger, m_smithery) == 0xB0,
              "C_BlacksmithTrigger smithery offset mismatch");
static_assert(offsetof(C_BlacksmithTrigger, m_productOnEquipBuff) == 0x1F0,
              "C_BlacksmithTrigger buff offset mismatch");
static_assert(offsetof(C_BlacksmithTrigger, m_pBlacksmithing) == 0x230,
              "C_BlacksmithTrigger session offset mismatch");

} // namespace wh::playermodule
