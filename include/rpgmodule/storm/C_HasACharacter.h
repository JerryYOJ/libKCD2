#pragma once
#include <cstddef>
#include "I_Selector.h"

namespace wh::rpgmodule::storm {

class C_HasACharacter : public I_Selector {
public:
    ~C_HasACharacter() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
};

static_assert(sizeof(C_HasACharacter) == 0x08, "C_HasACharacter size mismatch");

}  // namespace wh::rpgmodule::storm
