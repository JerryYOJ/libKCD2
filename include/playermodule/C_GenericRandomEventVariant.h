#pragma once
#include <cstddef>

#include "C_RandomEventVariantBase.h"

namespace wh::playermodule {

class C_GenericRandomEventVariant : public C_RandomEventVariantBase {
public:
    C_GenericRandomEventVariant();
    RTTR_ENABLE(C_RandomEventVariantBase) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                            // [27] 0x182EAD800
};

static_assert(sizeof(C_GenericRandomEventVariant) == 0x280,
              "C_GenericRandomEventVariant size mismatch");

} // namespace wh::playermodule
