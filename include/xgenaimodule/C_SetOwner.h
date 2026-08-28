#pragma once

#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "C_LinkableObject.h"

namespace wh::xgenaimodule {

class C_SetOwner : public wh::conceptmodule::C_Effect {
public:
    C_SetOwner();                                                            // 0x180EB9D20
    ~C_SetOwner() override;                                                  // [0] 0x1814CAC44
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                                 // [5..7], vtable 0x183B7B748
    void OnEffectActivate() override;                                        // [43] 0x1813B3038
    void OnEffectDeactivate() override;                                      // [44] 0x1813B3118

    wh::conceptmodule::C_TypedPortRef<C_LinkableObject*> m_what;             // +0x88 RTTR "What"
    wh::conceptmodule::C_TypedPortRef<C_LinkableObject*> m_who;              // +0xC8 RTTR "Who"
    std::uint8_t m_unknown108[8];                                            // +0x108
};

static_assert(offsetof(C_SetOwner, m_what) == 0x88,
              "C_SetOwner::m_what offset mismatch");
static_assert(offsetof(C_SetOwner, m_who) == 0xC8,
              "C_SetOwner::m_who offset mismatch");
static_assert(sizeof(C_SetOwner) == 0x110,
              "C_SetOwner size mismatch");

} // namespace wh::xgenaimodule
