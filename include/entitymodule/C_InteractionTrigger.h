#pragma once
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "I_InteractionTrigger.h"

namespace wh::entitymodule {

class C_InteractionTrigger
    : public Offsets::CGameObjectExtensionHelper<
          C_InteractionTrigger,
          I_InteractionTrigger,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_InteractionTrigger;
    ~C_InteractionTrigger() override; // [0] 0x1811EDED0
};
static_assert(sizeof(C_InteractionTrigger) == 0x68,
              "C_InteractionTrigger must be 0x68");

}  // namespace wh::entitymodule
