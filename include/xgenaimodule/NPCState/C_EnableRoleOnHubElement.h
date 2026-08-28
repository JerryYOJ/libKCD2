#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Element.h"

// -----------------------------------------------
// wh::xgenaimodule::NPCState::C_EnableRoleOnHubElement : I_Element
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x28, 33-slot vtable.
// -----------------------------------------------
// No RTTR members. Extra bytes after I_Element (0x18) are an unknown region
// pending ctor/writer tracing.

namespace wh::xgenaimodule::NPCState {

class C_EnableRoleOnHubElement : public I_Element {
public:
    ~C_EnableRoleOnHubElement() override;
    E_ElementType::Type unk_02() override;
    I_Element* unk_09() override;
    std::uint64_t unk_10() override;
    bool unk_24() override;
    bool unk_25() override;
    RTTR_ENABLE(I_Element)
    std::uint8_t m_unknown18[0x10];                // +0x18
};

static_assert(offsetof(C_EnableRoleOnHubElement, m_unknown18) == 0x18,
              "C_EnableRoleOnHubElement::m_unknown18 offset mismatch");
static_assert(sizeof(C_EnableRoleOnHubElement) == 0x28,
              "C_EnableRoleOnHubElement size mismatch");

}  // namespace wh::xgenaimodule::NPCState
