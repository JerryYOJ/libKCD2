#pragma once
#include <cstddef>
#include <cstdint>
#include <map>
#include <vector>
#include <boost/container/vector.hpp>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "../framework/WUID.h"
#include "../xgenaimodule/I_Area.h"
#include "../xgenaimodule/I_AreaTracker.h"
#include "../xgenaimodule/I_NPC.h"
#include "I_Soul.h"

namespace wh::rpgmodule {

class C_AreaTriggerBase
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>,
      public wh::xgenaimodule::I_AreaTracker {
public:
    C_AreaTriggerBase();
    ~C_AreaTriggerBase() override;                              // primary [0]
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>) // primary [5..7]
    void OnEffectActivate() override;                           // primary [43]
    void OnEffectDeactivate() override;                         // primary [44]
    void OnEffectShutdown() override;                           // primary [45]

    void OnAreaEntered(
        wh::xgenaimodule::I_NPC* npc,
        wh::framework::WUID areaWuid,
        std::int32_t eventFlags) override;                      // secondary [0]
    void OnAreaLeft(
        wh::xgenaimodule::I_NPC* npc,
        wh::framework::WUID areaWuid,
        std::int32_t eventFlags) override;                      // secondary [1]
    void OnAreaRemoved(wh::xgenaimodule::I_Area* area) override; // secondary [2]
    void OnNPCRemoved(wh::xgenaimodule::I_NPC* npc) override;    // secondary [3]

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<I_Soul*>> m_souls;                         // +0xB8
    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<wh::xgenaimodule::I_Area*>> m_areas;       // +0xF8
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAllEnter;            // +0x138
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onEnter;               // +0x178
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAllLeave;            // +0x1B8
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onLeave;               // +0x1F8
    wh::conceptmodule::C_TypedPortRef<I_Soul*> m_soul;        // +0x238
    wh::conceptmodule::C_TypedPortRef<
        wh::xgenaimodule::I_Area*> m_area;                     // +0x278
    bool m_anonymous;                                          // +0x2B8
    std::uint8_t m_padding2B9[7];                             // +0x2B9
    std::map<wh::framework::WUID, I_Soul*> m_soulsByNpcWuid; // +0x2C0
    std::map<wh::framework::WUID,
             wh::xgenaimodule::I_Area*> m_areasByWuid;        // +0x2D0
    boost::container::vector<
        wh::framework::WUID> m_initializedSoulWuids;          // +0x2E0
    std::map<
        wh::framework::WUID,
        boost::container::vector<wh::framework::WUID>>
        m_areasBySoulWuid;                                    // +0x2F8
    bool m_trackerRegistered;                                 // +0x308
    bool m_restartRequested;                                  // +0x309
    std::uint8_t m_padding30A[6];                             // +0x30A
};

static_assert(sizeof(wh::conceptmodule::C_EventNode<
                  wh::conceptmodule::C_Effect>) == 0xB0,
              "C_AreaTriggerBase primary base size mismatch");
static_assert(sizeof(C_AreaTriggerBase) == 0x310,
              "C_AreaTriggerBase size mismatch");
static_assert(offsetof(C_AreaTriggerBase, m_souls) == 0xB8,
              "C_AreaTriggerBase souls offset mismatch");
static_assert(offsetof(C_AreaTriggerBase, m_areas) == 0xF8,
              "C_AreaTriggerBase areas offset mismatch");
static_assert(offsetof(C_AreaTriggerBase, m_soulsByNpcWuid) == 0x2C0,
              "C_AreaTriggerBase soul map offset mismatch");
static_assert(offsetof(C_AreaTriggerBase, m_areasByWuid) == 0x2D0,
              "C_AreaTriggerBase area map offset mismatch");
static_assert(offsetof(C_AreaTriggerBase, m_initializedSoulWuids) == 0x2E0,
              "C_AreaTriggerBase initialized-souls offset mismatch");
static_assert(offsetof(C_AreaTriggerBase, m_areasBySoulWuid) == 0x2F8,
              "C_AreaTriggerBase occupancy map offset mismatch");
static_assert(offsetof(C_AreaTriggerBase, m_trackerRegistered) == 0x308,
              "C_AreaTriggerBase tracker flag offset mismatch");

} // namespace wh::rpgmodule
