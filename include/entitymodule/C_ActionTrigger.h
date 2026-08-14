#pragma once
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "I_InteractionTrigger.h"

namespace wh::entitymodule {

class C_ActionTrigger
    : public Offsets::CGameObjectExtensionHelper<
          C_ActionTrigger,
          I_InteractionTrigger,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ActionTrigger;
    ~C_ActionTrigger() override; // [0] 0x1811EDED0
};
static_assert(sizeof(C_ActionTrigger) == 0x68, "C_ActionTrigger must be 0x68");

}  // namespace wh::entitymodule
