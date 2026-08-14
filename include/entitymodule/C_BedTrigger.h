#pragma once
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "I_InteractionTrigger.h"

namespace wh::entitymodule {

class C_BedTrigger
    : public Offsets::CGameObjectExtensionHelper<
          C_BedTrigger,
          I_InteractionTrigger,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_BedTrigger;
    ~C_BedTrigger() override; // [0] 0x1811EDED0
};
static_assert(sizeof(C_BedTrigger) == 0x68, "C_BedTrigger must be 0x68");

}  // namespace wh::entitymodule
