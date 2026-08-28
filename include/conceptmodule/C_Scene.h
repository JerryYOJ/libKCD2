#pragma once
#include <cstddef>
#include "C_ModuleBase.h"

namespace wh::conceptmodule {

class C_Scene : public C_ModuleBase {
public:
    C_Scene();                                               // default RTTR construction path 0x1800932F0
    RTTR_ENABLE(C_ModuleBase)                                // [5..7]
    void EnumerateNodeVariants(
        definition::NodeDefinitionSink sink,
        bool allVariants) override;                          // [27] 0x1826DD3B0
};

static_assert(sizeof(C_Scene) == 0xA0,
              "C_Scene size mismatch");

}  // namespace wh::conceptmodule
