#pragma once
#include <cstdint>
#include "C_WeaponEquipRuntimeData.h"

// -----------------------------------------------
// wh::entitymodule::C_WeaponRuntimeData -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0xD8.
// -----------------------------------------------
// RTTI .?AVC_WeaponRuntimeData@entitymodule@wh@@ (TD 0x184C6F078, COL 0x18432AAF8)
// vtable 0x183EC8470  ctor sub_180474450 (delegates to C_WeaponEquipRuntimeData).
// sizeof VERIFIED twice: pool sub_181F1D700 221184/1024 = 216 (stride 54 dwords) AND last member
// qword @+0xD0. The +0xC0..+0xC3 dword (with base pad +0xBC) is NOT written by the ctor --
// initialized later on the InitFromRequest path (string "RequiresRuntimeDataInitFromRequest"
// @0x183B80B28); its type is unknown.

namespace wh::entitymodule {

class C_WeaponRuntimeData : public C_WeaponEquipRuntimeData   // +0x00  (0xC0)
{
public:
    uint32_t m_unkC0;    // +0xC0  ctor-unwritten gap (late-init; type/role unresolved)
    int32_t  m_fieldC4;  // +0xC4  (=0; role unresolved)
    void*    m_fieldC8;  // +0xC8  (=0; role unresolved)
    void*    m_fieldD0;  // +0xD0  (=0; role unresolved)
};
static_assert(sizeof(C_WeaponRuntimeData) == 0xD8, "C_WeaponRuntimeData must be 0xD8");

}  // namespace wh::entitymodule
