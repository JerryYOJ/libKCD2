#pragma once
#include <cstdint>
#include "E_ActionActorExpansionType.h"

// -----------------------------------------------
// wh::entitymodule::I_ActionActorExpansion -- KCD2 WHGame.dll.  sizeof 8.  8 slots.
// -----------------------------------------------
// RTTI .?AVI_ActionActorExpansion@entitymodule@wh@@.
// Standalone vt 0x183A3A778. Extra slots live on I_RiderExpansion.

namespace wh::entitymodule {

class I_ActionActorExpansion {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_ActionActorExpansion;
    virtual ~I_ActionActorExpansion() = default;                         // [0]
    virtual int32_t GetExpansionType() const = 0;                        // [1] Rider=5
    virtual void    vf10() = 0;                                          // [2]
    virtual void    vf18() = 0;                                          // [3]
    virtual void    vf20() = 0;                                          // [4]
    virtual void    vf28() = 0;                                          // [5]
    virtual void    vf30() = 0;                                          // [6]
    virtual void    ResetSharedPtr(void* out) = 0;                       // [7]
};
static_assert(sizeof(I_ActionActorExpansion) == 8, "I_ActionActorExpansion is vtable-only");

}  // namespace wh::entitymodule
