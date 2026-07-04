#pragma once
#include "../crysystem/CScriptableBase.h"

// -----------------------------------------------
// wh::xgenaimodule::C_ScriptBindSmartObject -- smart-object INSTANCE-method Lua bind
// (KCD2 1.5.6, kd7u).  sizeof 0x70 (alloc 112).
// -----------------------------------------------
// RTTI TD rva 0x4FE8A00; vtable 0x183b19fc0 : ::CScriptableBase (0x60).
// ctor sub_18114CECC: Init flag 1 (m_bInstanceMethods=1 -> per-instance userdata method
// table; SetGlobalName NOT called -- attached to smart-object userdata by the caller),
// method registration sub_18114CF3C. Creator sub_18114CE20 = lazy module-global
// singleton qword_1854961D8 (allocator qword_18549D378(112)).
//
// Registered methods (sub_18114CF3C; 5 in KCD2 -- KCD1 documented 6, one method
// dropped/renamed [UNVERIFIED which]):
//   GetHelpers()                              delegate{sub_1834223C8, sub_18041C37C}
//   GetHelpersCategory(categoryName)          sub_183422460
//   GetHelperLinks(helperName)                sub_183422214
//   GetHelperLinkTarget(helperName,linkName)  sub_183422120
//   GetHelperUserData(helperName,userDataKey) sub_1834222E8

namespace wh::xgenaimodule {

class C_ScriptBindSmartObject : public ::CScriptableBase   // +0x00  (0x60)
{
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ScriptBindSmartObject;
    void* m_pScriptSvc;      // +0x60  script-system service obj copy (pSS)
    void* m_pMethodsTable;   // +0x68  CreateTable() copy [pointee type unresolved]
};
static_assert(sizeof(C_ScriptBindSmartObject) == 0x70, "C_ScriptBindSmartObject must be 0x70 (alloc 112)");

}  // namespace wh::xgenaimodule
