#pragma once
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "I_InteractionTrigger.h"

namespace wh::entitymodule {

class C_WaterTubeActionTrigger
    : public Offsets::CGameObjectExtensionHelper<
          C_WaterTubeActionTrigger,
          I_InteractionTrigger,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_WaterTubeActionTrigger;
    ~C_WaterTubeActionTrigger() override; // [0] 0x1811EDED0
};
static_assert(sizeof(C_WaterTubeActionTrigger) == 0x68,
              "C_WaterTubeActionTrigger must be 0x68");

}  // namespace wh::entitymodule
