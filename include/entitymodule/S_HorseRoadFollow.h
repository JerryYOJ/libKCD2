#pragma once
#include <cstdint>
#include <cstddef>
#include <vector>
#include "I_MagnetismController.h"
#include "S_HorseFollowStick.h"

// -----------------------------------------------
// wh::entitymodule::S_HorseRoadFollow -- KCD2 WHGame.dll.  sizeof 0x80.
// -----------------------------------------------
// [SYNTHETIC name] ctor sub_180BE0C8C. Embedded at S_HorseData+0x158.
// Tick sub_180A4E5AC. Hosts S_OnPressController (mode 1) or S_AutoController
// (mode 2) at +0x68. Mode is rebuilt by sub_180A4E9B8 from options+0xB0.
// Path vectors are 4-byte elements (reserve >> 2 in sub_180689DD8).

namespace wh::entitymodule {

class S_HorseData;

class S_HorseRoadFollow {
public:
    S_HorseData*           m_pHorseData;     // +0x00
    uint64_t               m_stickUser;      // +0x08  back-target of m_stick.m_pUser
    S_HorseFollowStick     m_stick;          // +0x10
    std::vector<float>     m_pathA;          // +0x30  sub_180BE0D10 reserve 0x14
    std::vector<float>     m_pathB;          // +0x48
    uint8_t                m_latched;        // +0x60
    uint8_t                _pad61[7];        // +0x61
    I_MagnetismController* m_pMagnetism;     // +0x68
    int32_t                m_mode;           // +0x70  0 off / 1 on-press / 2 auto
    uint32_t               _pad74;           // +0x74
    uint64_t               m_reserved78;     // +0x78  ctor does not write
};
static_assert(sizeof(S_HorseRoadFollow) == 0x80, "S_HorseRoadFollow must be 0x80");
static_assert(offsetof(S_HorseRoadFollow, m_pMagnetism) == 0x68, "magnetism");
static_assert(offsetof(S_HorseRoadFollow, m_mode) == 0x70, "mode");

}  // namespace wh::entitymodule
