#pragma once
#include <cstddef>
#include "I_Selector.h"

namespace wh::rpgmodule::storm {

class C_IsPublicEnemy : public I_Selector {
public:
    ~C_IsPublicEnemy() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
};

static_assert(sizeof(C_IsPublicEnemy) == 0x08, "C_IsPublicEnemy size mismatch");

}  // namespace wh::rpgmodule::storm
