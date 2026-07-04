#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::guimodule::I_UIDragAndDropViewer -- KCD2 WHGame.dll 1.5.6 (kd7u).  Pure interface, 7 slots.
// -----------------------------------------------
// RTTI .?AVI_UIDragAndDropViewer@guimodule@wh@@ (TD 0x184CD0FD0). Drag-and-drop ghost
// visual on the HUD. C_UIHudHints implements it @+0x60 (vtable 0x183C34130):
//   [0] deleting-dtor thunk 0x18213A47C (-0x60 -> 0x182B8BE0C)
//   [1] 0x18170BFF0  flash "ShowDraggedAlternate"(item)
//   [2] 0x1816EA33C  flash "HideDraggedAlternate"()
//   [3] 0x181843BA4  flash "SetDraggedAlternateState"(uint8 state)
//   [4..6] RTTR_ENABLE() trio thunks (0x18213A65C/0x18213A608/0x18213A5A8, all -0x60)
// Names from the flash call names.

namespace rttr {
class type;
namespace detail { struct derived_info; }
}  // namespace rttr

namespace wh::guimodule {

class I_UIDragAndDropViewer {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_UIDragAndDropViewer;
    virtual ~I_UIDragAndDropViewer();                              // [0]
    virtual void ShowDraggedAlternate(uint64_t itemId) = 0;        // [1] 0x18170BFF0 (param type UNVERIFIED)
    virtual void HideDraggedAlternate() = 0;                       // [2] 0x1816EA33C
    virtual void SetDraggedAlternateState(uint8_t state) = 0;      // [3] 0x181843BA4
    // RTTR_ENABLE() trio.
    virtual rttr::type get_type() const;                           // [4]
    virtual void* get_ptr();                                       // [5]
    virtual rttr::detail::derived_info get_derived_info();         // [6]
};
static_assert(sizeof(I_UIDragAndDropViewer) == 8);

}  // namespace wh::guimodule
