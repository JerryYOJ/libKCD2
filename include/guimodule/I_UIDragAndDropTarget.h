#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::guimodule::I_UIDragAndDropTarget -- KCD2 WHGame.dll 1.5.6 (kd7u).  Pure interface, 6 slots.
// -----------------------------------------------
// RTTI .?AVI_UIDragAndDropTarget@guimodule@wh@@ (TD 0x184C93080). Drop-target hook of
// the Apse drag-and-drop machinery (C_UIDragAndDropHelper). Standalone (pure) vtable
// 0x183ED92E8: [0] dtor 0x182AFDB20, [1..2] _purecall, [3..5] rttr trio.
// Implementors: C_UICharacterSlots (subobj vtable 0x183B8F2B8: [1] 0x1811A234C,
// [2] 0x1811A2A40) and C_UIApseInventory @+0x5D0 (0x183D2EE78: [1] 0x1811A2850,
// [2] 0x1811A29B8).
// Method roles/signatures UNVERIFIED (coined; void() until traced).

namespace rttr {
class type;
namespace detail { struct derived_info; }
}  // namespace rttr

namespace wh::guimodule {

class I_UIDragAndDropTarget {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_UIDragAndDropTarget;
    virtual ~I_UIDragAndDropTarget();                       // [0] 0x182AFDB20 (standalone)
    virtual void _vf1() = 0;                                // [1] role UNVERIFIED
    virtual void _vf2() = 0;                                // [2] role UNVERIFIED
    // RTTR_ENABLE() expansion.
    virtual rttr::type get_type() const;                    // [3]
    virtual void* get_ptr();                                // [4]
    virtual rttr::detail::derived_info get_derived_info();  // [5]
};
static_assert(sizeof(I_UIDragAndDropTarget) == 8);

}  // namespace wh::guimodule
