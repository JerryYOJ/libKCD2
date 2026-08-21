#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>
#include "../../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::entitymodule::clothing::C_Component -- clothing-asset tree node base (KCD2 1.5.6, kd7u).
// sizeof 0x120.
// -----------------------------------------------
// RTTI .?AVC_Component@clothing@entitymodule@wh@@   vtable 0x183A4F6E0   ctor sub_180754FE0
// copy sub_181E95450. RTTR as_std_shared_ptr factory 0x1815017FC (alloc 0x120); clone vf[1]
// 0x181E960A0 (alloc 0x130 = _Ref_count_obj2 hdr 0x10 + object). Lives in the clothing DB
// C_ObjectTreeDatabaseKeyIndexed<..., map<CryStringT, shared_ptr<C_Component>>> (singleton
// 0x185323C90, map root 0x185323D08). Concrete siblings: C_Clothing / C_Body / C_Hair /
// C_Head / C_Beard (all mdisp 0; they share the name-key vf[2] 0x181A71D30 = &m_name).
// Slot map beyond [0..2]/[12] UNVERIFIED; middle slots kept as placeholders. [0]=dtor is
// MSVC convention, not decompile-proven.

namespace wh::entitymodule::clothing {

class C_Component {
public:
    virtual ~C_Component();                            // [0]  (convention; deleter runs via shared_ptr ctrl block)
    virtual std::shared_ptr<C_Component> Clone() const; // [1]  base 0x181E960A0 (_Ref_count_obj2 alloc 0x130)
    virtual void* unk2();                              // [2]  base 0x18176CF80 -> BSS 0x18557AFD8; derived 0x181A71D30 -> &m_name
    virtual void unk3();                               // [3]
    virtual void unk4();                               // [4]
    virtual void unk5();                               // [5]
    virtual void unk6();                               // [6]
    virtual void unk7();                               // [7]
    virtual void unk8();                               // [8]
    virtual void unk9();                               // [9]
    virtual void unk10();                              // [10]
    virtual void unk11();                              // [11]
    virtual void* GetRttrType() const;                 // [12] +0x60  base 0x180FE3258 -> C_Component type (0x18110F8A0); C_Clothing 0x1809734B8 -- exact-type gate key

    CryStringT<char> m_name;                           // +0x08  RTTR "Name"; DB map key; Hood matches "{Name}_up"
    std::uint8_t     _unk10[0x70];                     // +0x10  layout UNVERIFIED
    std::vector<std::shared_ptr<C_Component>> m_derivedComponents; // +0x80  RTTR "DerivedComponents"
    std::uint8_t     _unk98[0x88];                     // +0x98  layout UNVERIFIED
};
static_assert(sizeof(C_Component) == 0x120, "C_Component must be 0x120 (factory 0x1815017FC alloc)");
static_assert(offsetof(C_Component, m_name) == 0x08);
static_assert(offsetof(C_Component, m_derivedComponents) == 0x80);

}  // namespace wh::entitymodule::clothing
