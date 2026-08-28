#pragma once
#include <cstddef>
#include "C_Node.h"

namespace wh::conceptmodule {

class C_Input : public C_Node {
public:
    C_Input();                                               // inlined after C_Node ctor at 0x1826D742B/0x1826D7A4F
    RTTR_ENABLE(C_Node)                                      // [5..7]
    void EnumerateNodeVariants(
        definition::NodeDefinitionSink sink,
        bool allVariants) override;                          // [27] 0x1826DD138, emits "Input"
};

static_assert(sizeof(C_Input) == 0x40,
              "C_Input size mismatch");

}  // namespace wh::conceptmodule
