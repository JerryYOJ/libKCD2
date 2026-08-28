#pragma once

#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryString.h"
#include "S_WeaponItemClass.h"

namespace wh::entitymodule {

class S_MeleeWeaponItemClass : public S_WeaponItemClass {
public:
    std::uint8_t m_unknown138[0x10];                                     // +0x138 accessor-backed AttackMod* live here
    CryStringT<char> m_sharpeningAnimSuffix;                             // +0x148 RTTR "SharpeningAnimSuffix"
};

static_assert(offsetof(S_MeleeWeaponItemClass, m_sharpeningAnimSuffix) == 0x148,
              "S_MeleeWeaponItemClass::m_sharpeningAnimSuffix offset mismatch");
static_assert(sizeof(S_MeleeWeaponItemClass) == 0x150,
              "S_MeleeWeaponItemClass size mismatch");

} // namespace wh::entitymodule
