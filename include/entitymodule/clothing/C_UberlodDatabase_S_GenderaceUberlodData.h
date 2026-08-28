#pragma once
#include <boost/container/flat_map.hpp>
#include <cstddef>
#include <vector>

#include "../S_EquipmentPart.h"
#include "C_UberlodDatabase.h"
#include "S_Uberlod.h"

namespace wh::entitymodule::clothing {

class C_Component;

struct C_UberlodDatabase::S_GenderaceUberlodData {
    boost::container::flat_map<
        const wh::entitymodule::S_EquipmentPart*,
        std::vector<const C_Component*>> m_uberlodSources; // +0x00 RTTR "UberlodSources"
    S_Uberlod m_defaultUberlod;                           // +0x18 RTTR "DefaultUberlod"
};

static_assert(offsetof(C_UberlodDatabase::S_GenderaceUberlodData,
                       m_defaultUberlod) == 0x18,
              "S_GenderaceUberlodData::m_defaultUberlod offset mismatch");
static_assert(sizeof(C_UberlodDatabase::S_GenderaceUberlodData) == 0x50,
              "S_GenderaceUberlodData size mismatch");

} // namespace wh::entitymodule::clothing
