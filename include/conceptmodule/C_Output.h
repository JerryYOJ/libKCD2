#pragma once
#include <cstddef>
#include "C_Node.h"

namespace wh::conceptmodule {

class C_Output : public C_Node {
public:
    C_Output();                                              // inlined after C_Node ctor at 0x1806B2FA6/0x1826D7797
    RTTR_ENABLE(C_Node)                                      // [5..7]
    void EnumerateNodeVariants(
        definition::NodeDefinitionSink sink,
        bool allVariants) override;                          // [27] 0x1826DD2E0, emits "Output"
};

static_assert(sizeof(C_Output) == 0x40,
              "C_Output size mismatch");

}  // namespace wh::conceptmodule
