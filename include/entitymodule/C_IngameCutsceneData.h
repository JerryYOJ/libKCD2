#pragma once
#include "C_CutsceneData.h"

namespace wh::entitymodule {

class C_IngameCutsceneData
    : public Offsets::CGameObjectExtensionHelper<
          C_IngameCutsceneData,
          C_CutsceneData,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_IngameCutsceneData;

    ~C_IngameCutsceneData() override; // [0] 0x18116D748
};
static_assert(sizeof(C_IngameCutsceneData) == 0x40,
              "C_IngameCutsceneData must be 0x40");

}  // namespace wh::entitymodule
