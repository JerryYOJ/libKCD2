#pragma once
#include <cstddef>
#include "C_SetCharacterComponentBase.h"

namespace wh::rpgmodule::storm {

class C_SetUnderwear : public C_SetCharacterComponentBase {
public:
    ~C_SetUnderwear() override;
    void unk_08(C_Soul* soul, C_Rule* rule) override;
    RTTR_ENABLE(C_SetCharacterComponentBase)
};

static_assert(sizeof(C_SetUnderwear) == 0x20, "C_SetUnderwear size mismatch");

}  // namespace wh::rpgmodule::storm
