#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

// -----------------------------------------------
// wh::entitymodule::S_WeaponPresetGUID
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x10. No vtable.
// -----------------------------------------------
// Strong GUID id: type-data sizeof 0x10, RTTR string converter over a CryGUID.

namespace wh {
namespace entitymodule {

struct S_WeaponPresetGUID {
    CryGUID m_id;                                         // +0x00
};

static_assert(offsetof(S_WeaponPresetGUID, m_id) == 0x00,
              "S_WeaponPresetGUID::m_id offset mismatch");
static_assert(sizeof(S_WeaponPresetGUID) == 0x10,
              "S_WeaponPresetGUID size mismatch");

}  // namespace entitymodule
}  // namespace wh
