#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

// -----------------------------------------------
// wh::rpgmodule::S_POITypeWrapper
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x10. No vtable.
// -----------------------------------------------
// Strong GUID id: type-data sizeof 0x10, RTTR string converter over a CryGUID.

namespace wh {
namespace rpgmodule {

struct S_POITypeWrapper {
    CryGUID m_id;                                         // +0x00
};

static_assert(offsetof(S_POITypeWrapper, m_id) == 0x00,
              "S_POITypeWrapper::m_id offset mismatch");
static_assert(sizeof(S_POITypeWrapper) == 0x10,
              "S_POITypeWrapper size mismatch");

}  // namespace rpgmodule
}  // namespace wh
