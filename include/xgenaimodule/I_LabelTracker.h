#pragma once
#include <cstddef>

// -----------------------------------------------
// wh::xgenaimodule::I_LabelTracker -- KCD2 WHGame.dll 1.5.6. sizeof 0x08.
// -----------------------------------------------
// C_AreaLabelTrigger secondary table 0x183AEC308 proves three event callbacks
// followed by the deleting destructor. The event records carry the tracked WUID
// at +0x08; their complete source type remains unresolved.

namespace wh::xgenaimodule {

class I_LabelTracker {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_LabelTracker;
    virtual void OnLabelEntered(void* event) = 0;                   // [0]
    virtual void OnLabelLeft(void* event) = 0;                      // [1]
    virtual void OnLabelEntityRemoved(void* event) = 0;             // [2]
    virtual ~I_LabelTracker() = default;                             // [3]
};

static_assert(sizeof(I_LabelTracker) == 0x08,
              "I_LabelTracker size mismatch");

} // namespace wh::xgenaimodule
