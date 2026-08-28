#pragma once
#include <cstddef>
#include <cstdint>
#include "../../rttr/rttr_enable.h"
#include "../E_ActorGender.h"
#include "../E_Race.h"

namespace wh::entitymodule::clothing {
class C_BloodMask {
public:
    virtual ~C_BloodMask();
    RTTR_ENABLE()  // [1..3]
    CryStringT<char> m_name;  // +0x8 RTTR "Name"
    Vec3 m_center;  // +0x10 RTTR "Center"
    float m_radius;  // +0x1C RTTR "Radius"
    std::uint32_t m_zoneIdx;  // +0x20 RTTR "ZoneIdx"
    E_Race::Type m_race;  // +0x24 RTTR "Race"
    E_ActorGender m_gender;  // +0x28 RTTR "Gender"
    std::uint8_t m_unknown29[0x7];                  // +0x29
};

static_assert(offsetof(C_BloodMask, m_zoneIdx) == 0x20, "C_BloodMask::m_zoneIdx offset mismatch");
static_assert(offsetof(C_BloodMask, m_radius) == 0x1c, "C_BloodMask::m_radius offset mismatch");
static_assert(offsetof(C_BloodMask, m_center) == 0x10, "C_BloodMask::m_center offset mismatch");
static_assert(offsetof(C_BloodMask, m_name) == 0x8, "C_BloodMask::m_name offset mismatch");
static_assert(sizeof(C_BloodMask) == 0x30, "C_BloodMask size mismatch");

}  // namespace wh::entitymodule::clothing
