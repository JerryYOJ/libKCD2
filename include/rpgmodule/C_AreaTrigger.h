#pragma once
#include "C_AreaTriggerBase.h"

namespace wh::rpgmodule {

class C_AreaTrigger : public C_AreaTriggerBase {
public:
    C_AreaTrigger();
    ~C_AreaTrigger() override;                                  // [0]
    RTTR_ENABLE(C_AreaTriggerBase) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                              // [27]
};

static_assert(sizeof(C_AreaTrigger) == 0x310,
              "C_AreaTrigger size mismatch");

} // namespace wh::rpgmodule
