#pragma once

#include <cstddef>

#include "C_WeaponActionBase.h"

namespace wh::xgenaimodule::NPCState {

class C_HolsterWeaponAction : public C_WeaponActionBase {
public:
    ~C_HolsterWeaponAction() override;
    RTTR_ENABLE(C_WeaponActionBase)                                          // [24..26], vtable 0x183BA5138
};

static_assert(sizeof(C_HolsterWeaponAction) == 0xF0,
              "C_HolsterWeaponAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
