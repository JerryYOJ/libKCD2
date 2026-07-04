#pragma once
#include <cstdint>
#include "guimodule/I_Cutscene.h"

// -----------------------------------------------
// wh::guimodule::C_FastTravelCutscene -- KCD2 WHGame.dll 1.5.6 (kd7u).  sizeof 0x70 (ALLOC-PROVEN).
// -----------------------------------------------
// RTTI TD 0x184CB0568; vtable 0x183B2DED0. Simple I_Cutscene leaf (the fast-travel
// transition screen; playermodule C_FastTravel drives it); creator sub_1811CF500
// (alloc 0x70 @0x1811cf52d). Own slots: [0] 0x182B36154, [1] 0x182B38364,
// [2] 0x182B37678, [3] 0x182B37CA4, [4] 0x181A8CA50, [5] 0x180838AE0, [6] 0x18041A6A0,
// [7] 0x182B3777C.

namespace wh::guimodule {

class C_FastTravelCutscene : public I_Cutscene {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_FastTravelCutscene;
    void Play() override;            // [1] 0x182B38364
    void Stop() override;            // [2] 0x182B37678
    void Update() override;          // [3] 0x182B37CA4
    void Reset() override;           // [4] 0x181A8CA50
    void _vf5() override;            // [5] 0x180838AE0
    int  GetType() const override;   // [6] 0x18041A6A0
    bool IsActive() const override;  // [7] 0x182B3777C

    uint8_t _unk60[0xE];   // +0x60  ctor-untouched [UNVERIFIED]
    bool    m_flag6E;      // +0x6E  ctor 0 [role UNVERIFIED]
    uint8_t _pad6F;        // +0x6F
};
static_assert(sizeof(C_FastTravelCutscene) == 0x70, "C_FastTravelCutscene must be 0x70 (creator sub_1811CF500)");

}  // namespace wh::guimodule
