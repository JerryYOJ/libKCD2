#pragma once
#include <cstddef>
#include <vector>
#include "../CryEngine/CryCommon/CryString.h"
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../xgenaimodule/I_SmartObjectsManagerListener.h"

namespace wh::combatmodule {

class C_BattleRegistrationEffect
    : public wh::conceptmodule::C_Effect
    , public wh::xgenaimodule::I_SmartObjectsManagerListener { // +0x88
public:
    ~C_BattleRegistrationEffect() override;                    // primary [0] 0x18164A6F0
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                   // primary [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                     // primary [27] 0x18277D7DC
    void OnEffectActivate() override;                          // primary [43] 0x18277DC70
    void OnEffectDeactivate() override;                        // primary [44] 0x18277E2FC

    void OnSmartObjectAdded(
        wh::xgenaimodule::C_SmartObject* smartObject) override;    // secondary [0] nullsub
    void OnSmartObjectRemoving(
        wh::xgenaimodule::C_SmartObject* smartObject) override;    // secondary [1] 0x18277E958
    void OnSmartObjectRemoved(
        wh::xgenaimodule::C_SmartObject* smartObject) override;    // secondary [2] nullsub

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<wh::xgenaimodule::C_SmartObject*>> m_smartObjects; // +0x90 RTTR "SmartObjects"
    wh::conceptmodule::C_TypedPortRef<CryStringT<char>> m_linkFilter;  // +0xD0 RTTR "LinkFilter"
    std::vector<wh::xgenaimodule::C_SmartObject*>
        m_registeredSmartObjects;                              // +0x110
};

static_assert(offsetof(C_BattleRegistrationEffect, m_smartObjects) == 0x90,
              "C_BattleRegistrationEffect::m_smartObjects offset mismatch");
static_assert(offsetof(C_BattleRegistrationEffect, m_linkFilter) == 0xD0,
              "C_BattleRegistrationEffect::m_linkFilter offset mismatch");
static_assert(offsetof(C_BattleRegistrationEffect,
                       m_registeredSmartObjects) == 0x110,
              "C_BattleRegistrationEffect::m_registeredSmartObjects offset mismatch");
static_assert(sizeof(C_BattleRegistrationEffect) == 0x128,
              "C_BattleRegistrationEffect size mismatch");

}  // namespace wh::combatmodule
