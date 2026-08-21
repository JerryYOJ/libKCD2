#pragma once
#include <cstdint>
#include <cstddef>
#include "I_RiderExpansion.h"

// -----------------------------------------------
// wh::entitymodule::C_RiderExpansion -- KCD2 WHGame.dll.  sizeof 0x18.
// -----------------------------------------------
// RTTI : I_RiderExpansion. Factory sub_181EC7680 (alloc 0x18).

namespace wh::entitymodule {

class C_ActionActor;

class C_RiderExpansion : public I_RiderExpansion {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_RiderExpansion;
    C_ActionActor* m_pOwner;          // +0x08  factory a3
    uint32_t       m_horseEntityId;   // +0x10
    uint32_t       _pad14;            // +0x14
};
static_assert(sizeof(C_RiderExpansion) == 0x18, "C_RiderExpansion must be 0x18");
static_assert(offsetof(C_RiderExpansion, m_horseEntityId) == 0x10, "horse id");

}  // namespace wh::entitymodule
