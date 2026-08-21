#pragma once
#include <cstddef>
#include <cstdint>
#include "C_ItemPropertyDescriptor.h"
#include "S_ItemClassGUID.h"

// -----------------------------------------------
// wh::entitymodule::C_ItemClassDescriptor -- class-keyed item filter (KCD2 1.5.6, kd7u).
// sizeof 0x50.
// -----------------------------------------------
// REAL RTTI .?AVC_ItemClassDescriptor@entitymodule@wh@@ (TD 0x184C646E8, COL 0x18413F888;
// RTTR "ItemClassDescriptor"). Vtable 0x183A3D5E8 (10 slots). Built shared_ptr-owned by the
// RTTR method CreateItemClassDescriptor: registrar 0x180EB5DC0 -> impl 0x180517508 ->
// make_shared 0x1805175A4 (_Ref_count_obj2, alloc 0x60 = 0x10 ctrl + 0x50). Sibling factory
// 0x180516C98 forces m_negateClass = 0.
// vf[4] override 0x18096F1B8: empty GUID (both qwords 0) skips the class test; otherwise
// proceed to the Property matcher IFF (guidEqual == !m_negateClass), else FAIL-CLOSED
// (returns reason 1).
// NOTE: this is NOT the S_ItemClass vf[16..20] parameter -- that is the non-polymorphic 0xF8
// create-blob (see S_ItemInstanceData.h).

namespace wh::entitymodule {

class C_ItemClassDescriptor : public C_ItemPropertyDescriptor {
public:
    S_ItemClassGUID m_itemClass;                 // +0x38  RTTR param "ItemClass"; vs S_ItemClass::m_guid via GetClassData 0x1804695B4
    bool            m_negateClass;               // +0x48  RTTR param "NegateClass"
    std::uint8_t    _pad49[7];                   // +0x49
};
static_assert(sizeof(C_ItemClassDescriptor) == 0x50, "C_ItemClassDescriptor must be 0x50 (make_shared 0x60 - 0x10)");
static_assert(offsetof(C_ItemClassDescriptor, m_itemClass) == 0x38, "class GUID at 0x38 (vf[4])");
static_assert(offsetof(C_ItemClassDescriptor, m_negateClass) == 0x48, "negate at 0x48");

}  // namespace wh::entitymodule
