#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::entitymodule::I_ChatFollowManager -- KCD2 WHGame.dll.  sizeof 8.  3 slots.
// -----------------------------------------------
// RTTI .?AVI_ChatFollowManager@entitymodule@wh@@. Primary of C_ChatFollowManager
// (vt 0x183A80ED0). Slot 0 is NotifyFollowIndex, not a dtor.

namespace wh::entitymodule {

class I_ChatFollowManager {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_ChatFollowManager;
    virtual void NotifyFollowIndex(uint32_t index, bool flag) = 0; // [0] 0x182AA0538
    virtual bool IsFollowing() const = 0;                          // [1] 0x18082E634
    virtual void Destroy(uint8_t dealloc) = 0;                     // [2] 0x1819A1E78
};
static_assert(sizeof(I_ChatFollowManager) == 8, "I_ChatFollowManager is vtable-only");

}  // namespace wh::entitymodule
