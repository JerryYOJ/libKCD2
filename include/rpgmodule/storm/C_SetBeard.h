#pragma once
#include <cstddef>
#include "C_SetCharacterComponentBase.h"

namespace wh::rpgmodule::storm {

class C_SetBeard : public C_SetCharacterComponentBase {
public:
    ~C_SetBeard() override;
    void unk_08(C_Soul* soul, C_Rule* rule) override;
    RTTR_ENABLE(C_SetCharacterComponentBase)
};

static_assert(sizeof(C_SetBeard) == 0x20, "C_SetBeard size mismatch");

}  // namespace wh::rpgmodule::storm
