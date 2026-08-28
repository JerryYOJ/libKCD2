#pragma once
#include <cstddef>
#include "../../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::entitymodule::clothing::S_SerializedUberlodSource
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x10. No vtable.
// -----------------------------------------------

namespace wh::entitymodule::clothing {

struct S_SerializedUberlodSource {
    CryStringT<char> m_component;                         // +0x00 RTTR "Component"
    CryStringT<char> m_equipmentPart;                     // +0x08 RTTR "EquipmentPart"
};

static_assert(offsetof(S_SerializedUberlodSource, m_component) == 0x00,
              "S_SerializedUberlodSource::m_component offset mismatch");
static_assert(sizeof(S_SerializedUberlodSource) == 0x10,
              "S_SerializedUberlodSource size mismatch");

}  // namespace wh::entitymodule::clothing
