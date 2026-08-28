#pragma once
#include "C_AreaTriggerBase.h"

namespace wh::rpgmodule {

class C_AreaTriggerAnonymous : public C_AreaTriggerBase {
public:
    C_AreaTriggerAnonymous();
    ~C_AreaTriggerAnonymous() override;                         // [0]
    RTTR_ENABLE(C_AreaTriggerBase) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                              // [27]
};

static_assert(sizeof(C_AreaTriggerAnonymous) == 0x310,
              "C_AreaTriggerAnonymous size mismatch");

} // namespace wh::rpgmodule
