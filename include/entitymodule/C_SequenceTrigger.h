#pragma once
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "I_InteractionTrigger.h"

namespace wh::entitymodule {

class C_SequenceTrigger
    : public Offsets::CGameObjectExtensionHelper<
          C_SequenceTrigger,
          I_InteractionTrigger,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_SequenceTrigger;
    ~C_SequenceTrigger() override; // [0] 0x1811EDED0
};
static_assert(sizeof(C_SequenceTrigger) == 0x68,
              "C_SequenceTrigger must be 0x68");

}  // namespace wh::entitymodule
