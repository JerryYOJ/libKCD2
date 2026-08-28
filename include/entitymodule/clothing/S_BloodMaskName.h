#pragma once
#include <cstddef>
#include "../../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::entitymodule::clothing::S_BloodMaskName
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. No vtable.
// -----------------------------------------------
// Strong string id: type-data sizeof 8, RTTR string converter, no extra members.

namespace wh {
namespace entitymodule {
namespace clothing {

struct S_BloodMaskName {
    CryStringT<char> m_name;                              // +0x00
};

static_assert(offsetof(S_BloodMaskName, m_name) == 0x00,
              "S_BloodMaskName::m_name offset mismatch");
static_assert(sizeof(S_BloodMaskName) == 0x08,
              "S_BloodMaskName size mismatch");

}  // namespace clothing
}  // namespace entitymodule
}  // namespace wh
