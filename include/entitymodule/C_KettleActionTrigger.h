#pragma once
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "I_InteractionTrigger.h"

namespace wh::entitymodule {

class C_KettleActionTrigger
    : public Offsets::CGameObjectExtensionHelper<
          C_KettleActionTrigger,
          I_InteractionTrigger,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_KettleActionTrigger;
    ~C_KettleActionTrigger() override; // [0] 0x1811EDED0
};
static_assert(sizeof(C_KettleActionTrigger) == 0x68,
              "C_KettleActionTrigger must be 0x68");

}  // namespace wh::entitymodule
