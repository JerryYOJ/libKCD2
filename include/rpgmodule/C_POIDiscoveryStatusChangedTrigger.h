#pragma once
#include <cstddef>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "I_LocationListener.h"
#include "S_POITypeWrapper.h"

namespace wh::rpgmodule {

class C_POIDiscoveryStatusChangedTrigger
    : public wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>,
      public I_LocationListener {
public:
    C_POIDiscoveryStatusChangedTrigger();
    ~C_POIDiscoveryStatusChangedTrigger() override;               // primary [0]
    RTTR_ENABLE(wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>) // primary [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                               // primary [27]
    void OnEffectActivate() override;                             // primary [43]
    void OnEffectDeactivate() override;                           // primary [44]

    void _vf0() override;                                        // secondary [0]
    void _vf1(void* discoveryEvent) override;                     // secondary [1]
    void _vf2() override;                                        // secondary [2]
    void _vf3() override;                                        // secondary [3]
    void _vf4() override;                                        // secondary [4]
    void _vf5() override;                                        // secondary [5]
    void _vf6() override;                                        // secondary [6]
    void OnRegistered(I_RPGLocationManager* manager) override;    // secondary [7]
    void OnUnregistered(I_RPGLocationManager* manager) override;  // secondary [8]
    void OnLocationOccupied(
        I_RPGLocationManager* manager,
        I_Location* location) override;                           // secondary [9]

    wh::conceptmodule::C_TypedPortRef<
        S_POITypeWrapper> m_poiType;                              // +0xB8
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onUnknown;                // +0xF8
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onKnownUndiscovered;      // +0x138
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onDiscovered;             // +0x178
    S_POITypeWrapper m_resolvedPOIType;                            // +0x1B8
};

static_assert(sizeof(C_POIDiscoveryStatusChangedTrigger) == 0x1C8,
              "C_POIDiscoveryStatusChangedTrigger size mismatch");
static_assert(offsetof(C_POIDiscoveryStatusChangedTrigger, m_poiType) == 0xB8,
              "C_POIDiscoveryStatusChangedTrigger POI type offset mismatch");
static_assert(offsetof(C_POIDiscoveryStatusChangedTrigger, m_onDiscovered) == 0x178,
              "C_POIDiscoveryStatusChangedTrigger discovered offset mismatch");
static_assert(offsetof(C_POIDiscoveryStatusChangedTrigger, m_resolvedPOIType) == 0x1B8,
              "C_POIDiscoveryStatusChangedTrigger resolved type offset mismatch");

} // namespace wh::rpgmodule
