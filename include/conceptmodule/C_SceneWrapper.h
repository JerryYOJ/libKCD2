#pragma once
#include <cstddef>
#include "C_ModuleBase.h"

namespace wh::conceptmodule {

class C_SceneWrapper : public C_ModuleBase {
public:
    C_SceneWrapper();                                       // default RTTR construction path 0x1800948F0
    RTTR_ENABLE(C_ModuleBase)                                // [5..7]
    void EnumerateNodeVariants(
        definition::NodeDefinitionSink sink,
        bool allVariants) override;                          // [27] 0x1826DD4F4
};

static_assert(sizeof(C_SceneWrapper) == 0xA0,
              "C_SceneWrapper size mismatch");

}  // namespace wh::conceptmodule
