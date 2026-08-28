#pragma once
#include <cstddef>
#include "C_CompositeSelector.h"

namespace wh::rpgmodule::storm {

class C_AndSelector : public C_CompositeSelector {
public:
    ~C_AndSelector() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(C_CompositeSelector)
};

static_assert(sizeof(C_AndSelector) == 0x20, "C_AndSelector size mismatch");

}  // namespace wh::rpgmodule::storm
