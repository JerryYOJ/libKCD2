#pragma once
#include <cstddef>
#include "../conceptmodule/C_Effect.h"

namespace wh::entitymodule {
class C_DisableHorseInventory : public wh::conceptmodule::C_Effect {
public:
    ~C_DisableHorseInventory() override;
    RTTR_ENABLE(wh::conceptmodule::C_Effect)
    void OnEffectActivate() override;
    void OnEffectDeactivate() override;
};

static_assert(sizeof(C_DisableHorseInventory) == 0x88,
              "C_DisableHorseInventory size mismatch");

}  // namespace wh::entitymodule
