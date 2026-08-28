#pragma once

#include <cstddef>
#include <cstdint>

#include "C_FastForwardHandlingAction.h"

namespace wh::xgenaimodule::NPCState {

class C_LoadWeaponAction : public C_FastForwardHandlingAction {
public:
    ~C_LoadWeaponAction() override;
    RTTR_ENABLE(C_FastForwardHandlingAction)                                 // [24..26], vtable 0x18476E7E0

    std::uint8_t m_unknownC8[8];                                             // +0xC8
};

static_assert(sizeof(C_LoadWeaponAction) == 0xD0,
              "C_LoadWeaponAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
