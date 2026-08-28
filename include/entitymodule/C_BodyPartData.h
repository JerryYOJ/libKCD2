#pragma once
#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../rpgmodule/E_BloodZoneId.h"
#include "E_Race.h"

namespace wh::entitymodule {

class C_BodyPartData {
public:
    C_BodyPartData();
    ~C_BodyPartData();

    std::int32_t m_id;                              // +0x00 body_part_id
    std::uint32_t m_padding04;
    CryStringT<char> m_name;                        // +0x08 body_part_name
    E_Race::Type m_race;                            // +0x10 race_id
    wh::rpgmodule::E_BloodZoneId m_bloodZone;       // +0x14 blood_zone_id
    CryStringT<char> m_mnTag;                       // +0x18 mn_tag
    CryGUID m_injuryBuffId;                         // +0x20 injury_buff_id
    CryStringT<char> m_uiName;                      // +0x30 ui_name
    float m_damageCoefficient;                      // +0x38 body_damage_coeff
    std::uint32_t m_padding3C;
};

static_assert(offsetof(C_BodyPartData, m_race) == 0x10,
              "C_BodyPartData::m_race offset mismatch");
static_assert(offsetof(C_BodyPartData, m_injuryBuffId) == 0x20,
              "C_BodyPartData::m_injuryBuffId offset mismatch");
static_assert(offsetof(C_BodyPartData, m_damageCoefficient) == 0x38,
              "C_BodyPartData::m_damageCoefficient offset mismatch");
static_assert(sizeof(C_BodyPartData) == 0x40,
              "C_BodyPartData size mismatch");

} // namespace wh::entitymodule
