#pragma once
#include "C_CutsceneData.h"

namespace wh::entitymodule {

class C_SkipTimeCutsceneData
    : public Offsets::CGameObjectExtensionHelper<
          C_SkipTimeCutsceneData,
          C_CutsceneData,
          64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_SkipTimeCutsceneData;

    ~C_SkipTimeCutsceneData() override; // [0] 0x18116D748
};
static_assert(sizeof(C_SkipTimeCutsceneData) == 0x40,
              "C_SkipTimeCutsceneData must be 0x40");

}  // namespace wh::entitymodule
