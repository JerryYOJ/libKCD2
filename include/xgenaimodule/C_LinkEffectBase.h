#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedArrayPortRef.h"
#include "C_LinkableObject.h"
#include "I_ObjectManagerBaseListener.h"

namespace wh::xgenaimodule {

class C_LinkEffectBase
    : public wh::conceptmodule::C_Effect,
      public I_ObjectManagerBaseListener {
public:
    ~C_LinkEffectBase() override;                                        // [0]
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                             // [5..7], vtable 0x183AEB420
    void OnObjectEvent(int event) override;                              // +0x88 [0]
    virtual void unk_46();                                               // [46]
    virtual void unk_47();                                               // [47]

    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<C_LinkableObject*>> m_from;                          // +0x90 RTTR "From"
    wh::conceptmodule::C_TypedArrayPortRef<
        std::vector<C_LinkableObject*>> m_to;                            // +0xD0 RTTR "To"
    std::uint8_t m_unknown110[0x40];                                     // +0x110
};

static_assert(offsetof(C_LinkEffectBase, m_from) == 0x90,
              "C_LinkEffectBase::m_from offset mismatch");
static_assert(offsetof(C_LinkEffectBase, m_to) == 0xD0,
              "C_LinkEffectBase::m_to offset mismatch");
static_assert(sizeof(C_LinkEffectBase) == 0x150,
              "C_LinkEffectBase size mismatch");

} // namespace wh::xgenaimodule
