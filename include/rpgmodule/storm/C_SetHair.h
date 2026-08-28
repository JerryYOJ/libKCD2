#pragma once
#include <cstddef>
#include "C_SetCharacterComponentBase.h"

// -----------------------------------------------
// wh::rpgmodule::storm::C_SetHair : C_SetCharacterComponentBase
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x20, 9-slot vtable.
// -----------------------------------------------

namespace wh::rpgmodule::storm {

class C_SetHair : public C_SetCharacterComponentBase {
public:
    ~C_SetHair() override;
    void unk_08(C_Soul* soul, C_Rule* rule) override;
    RTTR_ENABLE(C_SetCharacterComponentBase)
};

static_assert(sizeof(C_SetHair) == 0x20, "C_SetHair size mismatch");

}  // namespace wh::rpgmodule::storm
