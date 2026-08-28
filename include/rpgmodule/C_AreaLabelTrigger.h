#pragma once
#include <cstddef>
#include <cstdint>
#include <map>
#include <vector>
#include "../CryEngine/CryCommon/CryString.h"
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "../framework/WUID.h"
#include "../xgenaimodule/I_LabelTracker.h"
#include "I_Soul.h"

namespace wh::rpgmodule {

class C_AreaLabelTrigger
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>,
      public wh::xgenaimodule::I_LabelTracker {
public:
    C_AreaLabelTrigger();
    ~C_AreaLabelTrigger() override;                               // primary [0], secondary [3]
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>) // primary [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                               // primary [27]
    void OnEffectActivate() override;                             // primary [43]
    void OnEffectDeactivate() override;                           // primary [44]

    void OnLabelEntered(void* event) override;                    // secondary [0]
    void OnLabelLeft(void* event) override;                       // secondary [1]
    void OnLabelEntityRemoved(void* event) override;              // secondary [2]

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<I_Soul*>> m_souls;                            // +0xB8
    wh::conceptmodule::C_TypedPortRef<CryStringT<char>> m_label;  // +0xF8
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAllEnter;               // +0x138
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onEnter;                  // +0x178
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAllLeave;               // +0x1B8
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onLeave;                  // +0x1F8
    wh::conceptmodule::C_TypedPortRef<I_Soul*> m_soul;           // +0x238
    std::map<wh::framework::WUID, I_Soul*> m_soulsByNpcWuid;     // +0x278
    CryStringT<char> m_runtimeLabelCache;                         // +0x288 role unresolved
    std::vector<wh::framework::WUID> m_insideSoulWuids;          // +0x290
    bool m_trackerRegistered;                                    // +0x2A8
    bool m_anonymous;                                            // +0x2A9
    std::uint8_t m_padding2AA[6];                               // +0x2AA
};

static_assert(sizeof(C_AreaLabelTrigger) == 0x2B0,
              "C_AreaLabelTrigger size mismatch");
static_assert(offsetof(C_AreaLabelTrigger, m_souls) == 0xB8,
              "C_AreaLabelTrigger souls offset mismatch");
static_assert(offsetof(C_AreaLabelTrigger, m_soul) == 0x238,
              "C_AreaLabelTrigger event soul offset mismatch");
static_assert(offsetof(C_AreaLabelTrigger, m_soulsByNpcWuid) == 0x278,
              "C_AreaLabelTrigger soul map offset mismatch");
static_assert(offsetof(C_AreaLabelTrigger, m_insideSoulWuids) == 0x290,
              "C_AreaLabelTrigger inside-souls offset mismatch");
static_assert(offsetof(C_AreaLabelTrigger, m_trackerRegistered) == 0x2A8,
              "C_AreaLabelTrigger tracker flag offset mismatch");

} // namespace wh::rpgmodule
