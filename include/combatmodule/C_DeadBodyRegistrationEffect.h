#pragma once
#include <cstddef>
#include <vector>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../xgenaimodule/I_SmartObjectsManagerListener.h"

namespace wh::combatmodule {

class C_DeadBodyRegistrationEffect
    : public wh::conceptmodule::C_Effect
    , public wh::xgenaimodule::I_SmartObjectsManagerListener { // +0x88
public:
    ~C_DeadBodyRegistrationEffect() override;                  // primary [0] 0x1817B1724
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                   // primary [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                     // primary [27] 0x18277D97C
    void OnEffectActivate() override;                          // primary [43] 0x18277DF48
    void OnEffectDeactivate() override;                        // primary [44] 0x18277E51C

    void OnSmartObjectAdded(
        wh::xgenaimodule::C_SmartObject* smartObject) override;    // secondary [0] nullsub
    void OnSmartObjectRemoving(
        wh::xgenaimodule::C_SmartObject* smartObject) override;    // secondary [1] 0x18277E9A4
    void OnSmartObjectRemoved(
        wh::xgenaimodule::C_SmartObject* smartObject) override;    // secondary [2] nullsub

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<wh::xgenaimodule::C_SmartObject*>> m_smartObjects; // +0x90 RTTR "SmartObjects"
    std::vector<wh::xgenaimodule::C_SmartObject*>
        m_registeredSmartObjects;                              // +0xD0
};

static_assert(offsetof(C_DeadBodyRegistrationEffect, m_smartObjects) == 0x90,
              "C_DeadBodyRegistrationEffect::m_smartObjects offset mismatch");
static_assert(offsetof(C_DeadBodyRegistrationEffect,
                       m_registeredSmartObjects) == 0xD0,
              "C_DeadBodyRegistrationEffect::m_registeredSmartObjects offset mismatch");
static_assert(sizeof(C_DeadBodyRegistrationEffect) == 0xE8,
              "C_DeadBodyRegistrationEffect size mismatch");

}  // namespace wh::combatmodule
