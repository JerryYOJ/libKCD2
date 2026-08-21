#pragma once
#include <cstdint>
#include "S_HorseMagnetismSample.h"

// -----------------------------------------------
// wh::entitymodule::I_MagnetismController -- KCD2 WHGame.dll.  sizeof 8.  4 slots.
// -----------------------------------------------
// RTTI .?AUI_MagnetismController@entitymodule@wh@@.
// Implementors: S_OnPressController (mode 1), S_AutoController (mode 2).

namespace wh::entitymodule {

class I_MagnetismController {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_MagnetismController;
    virtual ~I_MagnetismController() = default;                                    // [0]
    virtual void  SetHoldLatched(bool latched) = 0;                                // [1] 0x180A4E98C
    virtual void  Tick(S_HorseMagnetismSample* sample, int phase, float dt) = 0;   // [2] 0x180A4E768
    virtual float GetRoadDistance(bool deactivate) const = 0;                      // [3] OnPress D4/D8, Auto DC/E0
};
static_assert(sizeof(I_MagnetismController) == 8, "I_MagnetismController is vtable-only");

}  // namespace wh::entitymodule
