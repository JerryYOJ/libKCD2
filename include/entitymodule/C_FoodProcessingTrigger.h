#pragma once
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "I_InteractionTrigger.h"

namespace wh::entitymodule {

class C_FoodProcessingTrigger
    : public Offsets::CGameObjectExtensionHelper<
          C_FoodProcessingTrigger,
          I_InteractionTrigger,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_FoodProcessingTrigger;
    ~C_FoodProcessingTrigger() override; // [0] 0x1811EDED0
};
static_assert(sizeof(C_FoodProcessingTrigger) == 0x68,
              "C_FoodProcessingTrigger must be 0x68");

}  // namespace wh::entitymodule
