#pragma once
#include <cstddef>
#include "I_Selector.h"

namespace wh::rpgmodule::storm {

class C_HasAFaction : public I_Selector {
public:
    ~C_HasAFaction() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
};

static_assert(sizeof(C_HasAFaction) == 0x08, "C_HasAFaction size mismatch");

}  // namespace wh::rpgmodule::storm
