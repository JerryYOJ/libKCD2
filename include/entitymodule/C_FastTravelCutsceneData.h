#pragma once
#include "C_CutsceneData.h"

namespace wh::entitymodule {

class C_FastTravelCutsceneData
    : public Offsets::CGameObjectExtensionHelper<
          C_FastTravelCutsceneData,
          C_CutsceneData,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_FastTravelCutsceneData;

    ~C_FastTravelCutsceneData() override; // [0] 0x18116D748
};
static_assert(sizeof(C_FastTravelCutsceneData) == 0x40,
              "C_FastTravelCutsceneData must be 0x40");

}  // namespace wh::entitymodule
