#pragma once
#include <cstdint>
#include "../framework/WUID.h"

// -----------------------------------------------
// wh::xgenaimodule::I_AreaTracker -- area enter/leave tracking interface.
// KCD2 WHGame.dll 1.5.6 (kd7u).  Pure interface (sizeof 0x08).
// -----------------------------------------------
// RTTI .?AVI_AreaTracker@xgenaimodule@wh@@ (TD 0x184C92788).  Survives from KCD1
// (KCD1 C_CompassMark also derived it, 4 slots).  Implementor analyzed here:
// guimodule::C_CompassMark (base @+0x00, vtable 0x183A6B4C8 = 4 slots, no dtor slot).
//
// C_AreaTriggerBase's secondary table proves the full callback ABI. C_CompassMark
// and C_UIForgeBuilder ignore the arguments but occupy the same four slots.

namespace wh::xgenaimodule {

class I_Area;
class I_NPC;

class I_AreaTracker {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_AreaTracker;
    virtual void OnAreaEntered(
        I_NPC* npc,
        wh::framework::WUID areaWuid,
        std::int32_t eventFlags) = 0;                          // [0]
    virtual void OnAreaLeft(
        I_NPC* npc,
        wh::framework::WUID areaWuid,
        std::int32_t eventFlags) = 0;                          // [1]
    virtual void OnAreaRemoved(I_Area* area) = 0;              // [2]
    virtual void OnNPCRemoved(I_NPC* npc) = 0;                 // [3]
};
static_assert(sizeof(I_AreaTracker) == 0x08, "pure interface: vtable pointer only");

}  // namespace wh::xgenaimodule
