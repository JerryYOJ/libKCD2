#pragma once
#include <cstdint>
#include <cstddef>
#include <vector>
#include "I_MagnetismController.h"

// -----------------------------------------------
// wh::entitymodule::S_AutoController -- KCD2 WHGame.dll.  sizeof 0x48.
// -----------------------------------------------
// RTTI .?AVS_AutoController@entitymodule@wh@@ : I_MagnetismController.
// Factory sub_1829FC188 (alloc 0x48, vt 0x183EAAE18). Mode 2 of RoadMagnetism.
// a2 = S_HorseData* (from S_HorseRoadFollow+0).

namespace wh::entitymodule {

class S_HorseData;

class S_AutoController : public I_MagnetismController {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_S_AutoController;
    uint64_t           m_reserved08;    // +0x08  ctor 0
    uint64_t           m_reserved10;    // +0x10  ctor 0
    uint64_t           m_reserved18;    // +0x18  ctor 0
    std::vector<float> m_path;          // +0x20  sub_180BE0D10
    S_HorseData*       m_pHorseData;    // +0x38  factory a2
    int32_t            m_zero40;        // +0x40
    uint8_t            m_flag44;        // +0x44
    uint8_t            _pad45[3];       // +0x45
};
static_assert(sizeof(S_AutoController) == 0x48, "S_AutoController must be 0x48");
static_assert(offsetof(S_AutoController, m_path) == 0x20, "path");
static_assert(offsetof(S_AutoController, m_pHorseData) == 0x38, "horse data");

}  // namespace wh::entitymodule
