#pragma once
#include <boost/container/flat_set.hpp>
#include <cstddef>
#include "../S_Genderace.h"

namespace wh::entitymodule::clothing {

class C_Component;

struct S_UberlodQuery {
    wh::entitymodule::S_Genderace m_equipmentPart;           // +0x00 RTTR "EquipmentPart"
    boost::container::flat_set<const C_Component*> m_components; // +0x08 RTTR "Components"
};

static_assert(offsetof(S_UberlodQuery, m_components) == 0x08,
              "S_UberlodQuery::m_components offset mismatch");
static_assert(sizeof(S_UberlodQuery) == 0x20,
              "S_UberlodQuery size mismatch");

}  // namespace wh::entitymodule::clothing
