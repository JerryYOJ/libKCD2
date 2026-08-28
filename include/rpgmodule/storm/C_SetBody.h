#pragma once
#include <cstddef>
#include "C_SetCharacterComponentBase.h"

namespace wh::rpgmodule::storm {

class C_SetBody : public C_SetCharacterComponentBase {
public:
    ~C_SetBody() override;
    void unk_08(C_Soul* soul, C_Rule* rule) override;
    RTTR_ENABLE(C_SetCharacterComponentBase)
};

static_assert(sizeof(C_SetBody) == 0x20, "C_SetBody size mismatch");

}  // namespace wh::rpgmodule::storm
