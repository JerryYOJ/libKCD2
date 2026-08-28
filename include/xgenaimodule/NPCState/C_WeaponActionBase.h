#pragma once

#include <cstddef>
#include <cstdint>

#include "../../entitymodule/E_StanceCategory.h"
#include "C_CodeAction.h"

namespace wh::xgenaimodule::NPCState {

class C_WeaponActionBase : public C_CodeAction {
public:
    ~C_WeaponActionBase() override;                                          // [0] 0x1819AD034
    RTTR_ENABLE(C_CodeAction)                                                // [24..26], vtable 0x183BA4CE0

    wh::entitymodule::E_StanceCategory::Type m_stance;                       // +0xC0 RTTR "Stance"
    std::uint8_t m_unknownC4[0x2C];                                          // +0xC4
};

static_assert(offsetof(C_WeaponActionBase, m_stance) == 0xC0,
              "C_WeaponActionBase::m_stance offset mismatch");
static_assert(sizeof(C_WeaponActionBase) == 0xF0,
              "C_WeaponActionBase size mismatch");

} // namespace wh::xgenaimodule::NPCState
