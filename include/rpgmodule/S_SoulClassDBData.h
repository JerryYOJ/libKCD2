#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/T_TableString.h"

namespace wh::rpgmodule {

struct S_SoulClassDBData {
    int m_id;                                                // +0x00 table "soul_class_id"
    std::uint32_t m_unknown04;                               // +0x04
    wh::databasemodule::T_TableString m_name;                // +0x08 RTTR "Name"
    float m_courage;                                         // +0x10 table "soul_class_courage"
    float m_huntingCoefficient;                              // +0x14 table "hunting_coef"
    int m_huntingRole;                                       // +0x18 table "hunting_role"
    float m_huntingCapacityCost;                             // +0x1C table "hunting_capacity_cost"
};

static_assert(offsetof(S_SoulClassDBData, m_name) == 0x08,
              "S_SoulClassDBData::m_name offset mismatch");
static_assert(offsetof(S_SoulClassDBData, m_courage) == 0x10,
              "S_SoulClassDBData::m_courage offset mismatch");
static_assert(offsetof(S_SoulClassDBData, m_huntingRole) == 0x18,
              "S_SoulClassDBData::m_huntingRole offset mismatch");
static_assert(sizeof(S_SoulClassDBData) == 0x20,
              "S_SoulClassDBData size mismatch");

}  // namespace wh::rpgmodule
