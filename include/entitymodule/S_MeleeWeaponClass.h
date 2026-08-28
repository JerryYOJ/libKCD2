#pragma once
#include <cstddef>
#include "S_WeaponClass.h"

namespace wh::entitymodule {

class S_MeleeWeaponClass : public S_WeaponClass {
public:
    ~S_MeleeWeaponClass() override;
    RTTR_ENABLE(S_WeaponClass)
};

static_assert(sizeof(S_MeleeWeaponClass) == 0x98,
              "S_MeleeWeaponClass size mismatch");

}  // namespace wh::entitymodule
