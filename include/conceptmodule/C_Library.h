#pragma once
#include <cstddef>
#include "C_ModuleBase.h"

namespace wh::conceptmodule {

class C_Library : public C_ModuleBase {
public:
    C_Library();                                             // default RTTR construction path 0x18008F510
    RTTR_ENABLE(C_ModuleBase)                                // [5..7]
    void EnumerateNodeVariants(
        definition::NodeDefinitionSink sink,
        bool allVariants) override;                          // [27] 0x1826DD208
    std::uint8_t GetModuleKind() const override;             // [44] kind 2
};

static_assert(sizeof(C_Library) == 0xA0,
              "C_Library size mismatch");

}  // namespace wh::conceptmodule
