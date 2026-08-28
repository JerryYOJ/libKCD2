#pragma once
#include <cstddef>
#include "../conceptmodule/C_Effect.h"

namespace wh::entitymodule {
class C_DisablePlayerCartDismount : public wh::conceptmodule::C_Effect {
public:
    ~C_DisablePlayerCartDismount() override;
    RTTR_ENABLE(wh::conceptmodule::C_Effect)
    void OnEffectActivate() override;
    void OnEffectDeactivate() override;
};

static_assert(sizeof(C_DisablePlayerCartDismount) == 0x88,
              "C_DisablePlayerCartDismount size mismatch");

}  // namespace wh::entitymodule
