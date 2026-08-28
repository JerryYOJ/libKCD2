#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"

namespace wh::entitymodule {

class C_AnimDoor;

class C_DisableDoorInteractivity : public wh::conceptmodule::C_Effect {
public:
    C_DisableDoorInteractivity();                                       // 0x1814FDE0C
    ~C_DisableDoorInteractivity() override;                             // [0] 0x1817590DC
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                            // [5..7], vtable 0x183BA6960
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                                    // [27] 0x18295EE5C
    void OnEffectActivate() override;                                  // [43] 0x180CC162C
    void OnEffectDeactivate() override;                                // [44] 0x18295F91C

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<C_AnimDoor*>> m_doors;                              // +0x88 RTTR "Doors"
    std::vector<C_AnimDoor*> m_resolvedDoors;                           // +0xC8 sorted and deduplicated on activation
    bool m_isApplied;                                                   // +0xE0 interactivity is currently disabled
    std::uint8_t m_paddingE1[7];                                       // +0xE1
};

static_assert(offsetof(C_DisableDoorInteractivity, m_doors) == 0x88,
              "C_DisableDoorInteractivity::m_doors offset mismatch");
static_assert(offsetof(C_DisableDoorInteractivity, m_resolvedDoors) == 0xC8,
              "C_DisableDoorInteractivity::m_resolvedDoors offset mismatch");
static_assert(offsetof(C_DisableDoorInteractivity, m_isApplied) == 0xE0,
              "C_DisableDoorInteractivity::m_isApplied offset mismatch");
static_assert(sizeof(C_DisableDoorInteractivity) == 0xE8,
              "C_DisableDoorInteractivity size mismatch");

} // namespace wh::entitymodule
