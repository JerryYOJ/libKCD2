#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Element.h"

// -----------------------------------------------
// wh::xgenaimodule::NPCState::C_AddBuffElement : I_Element
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x30, 33-slot vtable.
// -----------------------------------------------
// No RTTR members. Extra bytes after I_Element (0x18) are an unknown region
// pending ctor/writer tracing.

namespace wh::xgenaimodule::NPCState {

class C_AddBuffElement : public I_Element {
public:
    ~C_AddBuffElement() override;
    E_ElementType::Type unk_02() override;
    I_Element* Clone() const override;
    std::uint64_t GetHash() const override;
    bool WritePayload(void* writer) const override;
    bool ReadPayload(void* reader, void* ctxA, void* ctxB, bool* ok) override;
    RTTR_ENABLE(I_Element)
    std::uint8_t m_unknown18[0x18];                // +0x18
};

static_assert(offsetof(C_AddBuffElement, m_unknown18) == 0x18,
              "C_AddBuffElement::m_unknown18 offset mismatch");
static_assert(sizeof(C_AddBuffElement) == 0x30,
              "C_AddBuffElement size mismatch");

}  // namespace wh::xgenaimodule::NPCState
