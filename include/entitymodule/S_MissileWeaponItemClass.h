#pragma once

#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryString.h"
#include "S_WeaponItemClass.h"

namespace wh::entitymodule {

class S_MissileWeaponItemClass : public S_WeaponItemClass {
public:
    float m_power;                                                       // +0x138 RTTR "Power"
    float m_limbResistance;                                              // +0x13C RTTR "LimbResistance"
    bool m_oldFormula;                                                   // +0x140 RTTR "OldFormula"
    std::uint8_t m_padding141[7];                                        // +0x141
    CryStringT<char> m_soundSwitch;                                      // +0x148 RTTR "SoundSwitch"
    float m_fireSoundMultiplicator;                                      // +0x150 RTTR "FireSoundMultiplicator"
    std::uint8_t m_padding154[4];                                        // +0x154
};

static_assert(offsetof(S_MissileWeaponItemClass, m_power) == 0x138,
              "S_MissileWeaponItemClass::m_power offset mismatch");
static_assert(offsetof(S_MissileWeaponItemClass, m_soundSwitch) == 0x148,
              "S_MissileWeaponItemClass::m_soundSwitch offset mismatch");
static_assert(offsetof(S_MissileWeaponItemClass, m_fireSoundMultiplicator) == 0x150,
              "S_MissileWeaponItemClass fire-sound offset mismatch");
static_assert(sizeof(S_MissileWeaponItemClass) == 0x158,
              "S_MissileWeaponItemClass size mismatch");

} // namespace wh::entitymodule
