#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>
#include "../../CryEngine/CryCommon/CryString.h"
#include "../../rttr/rttr_enable.h"

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
    virtual ~C_Component();                             // [0] 0x18291721C
    virtual std::shared_ptr<C_Component> Clone() const; // [1] 0x181E960A0
    virtual const CryStringT<char>& GetName() const;    // [2] 0x18176CF80
    virtual void unk_03(const C_Component* source);     // [3] 0x18068E674
    virtual bool unk_04() const;                        // [4] 0x180838AE0
    virtual bool unk_05() const;                        // [5] 0x180838AE0
    virtual bool unk_06() const;                        // [6] 0x180838AE0
    virtual bool unk_07(const C_Component* other) const;// [7] 0x18097208C
    virtual bool unk_08(bool value) const;              // [8] 0x1809722B0
    virtual const void* unk_09() const;                 // [9] 0x181A84660
    virtual void unk_10(void* collector) const;         // [10] 0x1809714E0
    virtual void unk_11();                              // [11] 0x180E11E70
    RTTR_ENABLE()                                        // [12..14], vtable 0x183A4F6E0

    CryStringT<char> m_name;                           // +0x08  RTTR "Name"; DB map key; Hood matches "{Name}_up"
    std::uint8_t     _unk10[0x70];                     // +0x10  layout UNVERIFIED
    std::vector<std::shared_ptr<C_Component>> m_derivedComponents; // +0x80  RTTR "DerivedComponents"
    std::uint8_t     _unk98[0x88];                     // +0x98  layout UNVERIFIED
};
static_assert(sizeof(C_Component) == 0x120, "C_Component must be 0x120 (factory 0x1815017FC alloc)");
static_assert(offsetof(C_Component, m_name) == 0x08);
static_assert(offsetof(C_Component, m_derivedComponents) == 0x80);

}  // namespace wh::entitymodule::clothing
