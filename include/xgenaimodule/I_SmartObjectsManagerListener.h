#pragma once

// -----------------------------------------------
// wh::xgenaimodule::I_SmartObjectsManagerListener -- three-callback smart-object
// lifecycle listener (KCD2 WHGame.dll Steam 1.5.6).  sizeof 0x08.
// -----------------------------------------------
// C_SmartObjectsManager dispatch proves [0] Added, [1] Removing, [2] Removed;
// all three receive the same C_SmartObject*.  The interface has no virtual
// destructor: the former fourth-slot claim was C_SmartEntityResolver's own new
// deleting destructor, while secondary listener vtables terminate after [2].

namespace wh::xgenaimodule {

class C_SmartObject;

class I_SmartObjectsManagerListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_SmartObjectsManagerListener;
    virtual void OnSmartObjectAdded(C_SmartObject* smartObject) = 0;    // [0]
    virtual void OnSmartObjectRemoving(C_SmartObject* smartObject) = 0; // [1]
    virtual void OnSmartObjectRemoved(C_SmartObject* smartObject) = 0;  // [2]
};
static_assert(sizeof(I_SmartObjectsManagerListener) == 0x08, "interface: vtable pointer only");

}  // namespace wh::xgenaimodule
