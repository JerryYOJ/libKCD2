#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

// -----------------------------------------------
// wh::entitymodule::S_ItemClassGUID -- strong-typedef of an item-class GUID (KCD2 1.5.6, kd7u).
// sizeof 0x10.
// -----------------------------------------------
// RTTR type "S_ItemClassGUID" (type creator 0x181967E84, sizeof 16). Compared qword-wise
// against S_ItemClass::m_guid (a CryGUID) by C_ItemClassDescriptor vf[4] 0x18096F1B8.
// Member spelling reconstructed (single 16-byte payload; no field names survive).

namespace wh::entitymodule {

struct S_ItemClassGUID {
    CryGUID m_guid;    // +0x00
};
static_assert(sizeof(S_ItemClassGUID) == 0x10, "S_ItemClassGUID must be 0x10 (RTTR sizeof 16)");

}  // namespace wh::entitymodule
