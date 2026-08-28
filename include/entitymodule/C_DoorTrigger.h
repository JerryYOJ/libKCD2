#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_EventNode.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "I_RemovedEntityListener.h"

namespace wh::rpgmodule {
class I_Soul;
}

namespace wh::entitymodule {

class C_AnimDoor;
using C_DoorTriggerBase =
    wh::conceptmodule::C_EventNode<wh::conceptmodule::C_Effect>;

class C_DoorTrigger
    : public C_DoorTriggerBase,
      public I_RemovedEntityListener {
public:
    C_DoorTrigger();                                                    // 0x18161F538
    ~C_DoorTrigger() override;                                         // [0] 0x1816A7424
    RTTR_ENABLE(C_DoorTriggerBase)                                     // [5..7], vtable 0x183BD7660
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                    // [27] 0x1829A8FC4
    void OnEffectActivate() override;                                  // [43] 0x1829A999C
    void OnEffectDeactivate() override;                                // [44] 0x1829A9C4C

    bool OnRemove(IEntity* entity) override;                            // +0xB0 [3] 0x1829A9F1C
    const char* GetName() const override;                               // +0xB0 [7] 0x181A86D70

    wh::conceptmodule::C_TypedPortRef<C_AnimDoor*> m_door;             // +0xB8 RTTR "Door"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onOpened;                       // +0xF8 RTTR "OnOpened"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onClosed;                       // +0x138 RTTR "OnClosed"
    wh::conceptmodule::C_TypedPortRef<
        wh::rpgmodule::I_Soul*> m_soul;                                // +0x178 RTTR "Soul"
    bool m_isConnected;                                                 // +0x1B8
    std::uint8_t m_padding1B9[7];                                      // +0x1B9
    C_AnimDoor* m_activeDoor;                                          // +0x1C0 borrowed callback source
};

static_assert(offsetof(C_DoorTrigger, m_door) == 0xB8,
              "C_DoorTrigger::m_door offset mismatch");
static_assert(offsetof(C_DoorTrigger, m_onOpened) == 0xF8,
              "C_DoorTrigger::m_onOpened offset mismatch");
static_assert(offsetof(C_DoorTrigger, m_onClosed) == 0x138,
              "C_DoorTrigger::m_onClosed offset mismatch");
static_assert(offsetof(C_DoorTrigger, m_soul) == 0x178,
              "C_DoorTrigger::m_soul offset mismatch");
static_assert(offsetof(C_DoorTrigger, m_isConnected) == 0x1B8,
              "C_DoorTrigger::m_isConnected offset mismatch");
static_assert(offsetof(C_DoorTrigger, m_activeDoor) == 0x1C0,
              "C_DoorTrigger::m_activeDoor offset mismatch");
static_assert(sizeof(C_DoorTrigger) == 0x1C8,
              "C_DoorTrigger size mismatch");

} // namespace wh::entitymodule
