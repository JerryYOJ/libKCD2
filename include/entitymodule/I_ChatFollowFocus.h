#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::I_ChatFollowFocus -- KCD2 WHGame.dll.  sizeof 8.
// -----------------------------------------------
// [SYNTHETIC] no TypeDescriptor recovered. Pointee of C_ChatFollowManager
// +0x20 / +0x28. Known slots from StopFollow / HUD:
//   [2] vf+0x10 Release (sub_1806166D8)
//   [12] vf+0x60 HUD target id (sub_18082E694)

namespace wh::entitymodule {

class I_ChatFollowFocus {
public:
    virtual ~I_ChatFollowFocus() = default;  // [0]
    virtual void vf08() = 0;                 // [1]
    virtual void Release() = 0;              // [2]  0x10
};

}  // namespace wh::entitymodule
