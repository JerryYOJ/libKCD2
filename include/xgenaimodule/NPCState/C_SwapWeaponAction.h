#pragma once

#include <cstddef>
#include <cstdint>

#include "C_WeaponActionBase.h"

namespace wh::xgenaimodule::NPCState {

class C_SwapWeaponAction : public C_WeaponActionBase {
public:
    ~C_SwapWeaponAction() override;
    RTTR_ENABLE(C_WeaponActionBase)                                          // [24..26], vtable 0x183BA4E60

    std::uint8_t m_unknownF0[8];                                             // +0xF0
};

static_assert(sizeof(C_SwapWeaponAction) == 0xF8,
              "C_SwapWeaponAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
