#pragma once
#include <cstddef>
#include "C_Effect.h"
#include "C_EventNode.h"
#include "C_TypedPortRef.h"
#include "S_Trigger.h"
#include "xgenaimodule/C_LinkableObject.h"

namespace wh::conceptmodule {

class C_AssetTrigger : public C_EventNode<C_Effect> {
public:
    C_AssetTrigger();                                      // 0x18266ECBC
    ~C_AssetTrigger() override;                            // [0] 0x18266F140
    RTTR_ENABLE(C_EventNode<C_Effect>)                     // [5..7]
    void EnumerateNodeVariants(
        definition::NodeDefinitionSink sink,
        bool allVariants) override;                        // [27] 0x18266F3B0
    void OnEffectActivate() override;                      // [43] 0x18266F4F0
    void OnEffectDeactivate() override;                    // [44] 0x18266F6E4

    C_TypedPortRef<wh::xgenaimodule::C_LinkableObject*>
        m_origin;                                         // +0xB0 RTTR "Origin", In
    C_TypedPortRef<CryStringT<char>> m_assetName;         // +0xF0 RTTR "AssetName", In
    C_TypedPortRef<S_Trigger> m_onAdded;                  // +0x130 RTTR "OnAdded", Out
    C_TypedPortRef<S_Trigger> m_onRemoved;                // +0x170 RTTR "OnRemoved", Out
    CryStringT<char> m_activeAssetName;                   // +0x1B0, activation-time subscription key
};

static_assert(offsetof(C_AssetTrigger, m_origin) == 0xB0,
              "C_AssetTrigger::m_origin offset mismatch");
static_assert(offsetof(C_AssetTrigger, m_assetName) == 0xF0,
              "C_AssetTrigger::m_assetName offset mismatch");
static_assert(offsetof(C_AssetTrigger, m_onAdded) == 0x130,
              "C_AssetTrigger::m_onAdded offset mismatch");
static_assert(offsetof(C_AssetTrigger, m_onRemoved) == 0x170,
              "C_AssetTrigger::m_onRemoved offset mismatch");
static_assert(offsetof(C_AssetTrigger, m_activeAssetName) == 0x1B0,
              "C_AssetTrigger::m_activeAssetName offset mismatch");
static_assert(sizeof(C_AssetTrigger) == 0x1B8,
              "C_AssetTrigger size mismatch");

}  // namespace wh::conceptmodule
