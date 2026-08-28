#pragma once
#include <cstddef>
#include "C_ModuleBase.h"

namespace wh::conceptmodule {

class C_Module : public C_ModuleBase {
public:
    C_Module();                                              // default RTTR construction path 0x180090B10
    explicit C_Module(CryStringT<char> const& name);         // reflected named constructor
    RTTR_ENABLE(C_ModuleBase)                                // [5..7]
    void EnumerateNodeVariants(
        definition::NodeDefinitionSink sink,
        bool allVariants) override;                          // [27] 0x180EF6F30
};

static_assert(sizeof(C_Module) == 0xA0,
              "C_Module size mismatch");

}  // namespace wh::conceptmodule
