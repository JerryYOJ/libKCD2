#pragma once
#include <cstddef>
#include "../conceptmodule/C_Effect.h"

namespace wh::playermodule {
class C_DisableSkipTime : public wh::conceptmodule::C_Effect {
public:
    ~C_DisableSkipTime() override;
    RTTR_ENABLE(wh::conceptmodule::C_Effect)
    void OnEffectActivate() override;
    void OnEffectDeactivate() override;
};

static_assert(sizeof(C_DisableSkipTime) == 0x88,
              "C_DisableSkipTime size mismatch");

}  // namespace wh::playermodule
