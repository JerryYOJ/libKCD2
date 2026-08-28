#pragma once
#include <cstddef>
#include "C_CompositeSelector.h"

namespace wh::rpgmodule::storm {

class C_OrSelector : public C_CompositeSelector {
public:
    ~C_OrSelector() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(C_CompositeSelector)
};

static_assert(sizeof(C_OrSelector) == 0x20, "C_OrSelector size mismatch");

}  // namespace wh::rpgmodule::storm
