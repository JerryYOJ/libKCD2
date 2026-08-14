#pragma once
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "I_InteractionTrigger.h"

namespace wh::entitymodule {

class C_SmartObjectTrigger
    : public Offsets::CGameObjectExtensionHelper<
          C_SmartObjectTrigger,
          I_InteractionTrigger,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_SmartObjectTrigger;
    ~C_SmartObjectTrigger() override; // [0] 0x1829FD784
};
static_assert(sizeof(C_SmartObjectTrigger) == 0x68,
              "C_SmartObjectTrigger must be 0x68");

}  // namespace wh::entitymodule
