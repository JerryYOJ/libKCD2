#pragma once
#include <cstdint>
#include <cstddef>

// -----------------------------------------------
// wh::entitymodule::S_RiderMoveRequest -- KCD2 WHGame.dll.  sizeof 0x18.
// -----------------------------------------------
// [SYNTHETIC] no TypeDescriptor. Update stack object at rsp+0x30, zeroed then
// speed=-1. ApplySMOutput fills it from S_RiderSMOutput; ApplyOutputToHorse
// writes S_HorseData (m_jump +0x109, m_jumpRequest +0x10C, m_magnetYaw +0x130).

namespace wh::entitymodule {

struct S_RiderMoveRequest {
    uint8_t  _pad00[2];        // +0x00  no writer in ApplySMOutput
    uint8_t  m_jumpRequest;    // +0x02  SM out bit 0x10 → HorseData+0x10C
    uint8_t  m_jump;           // +0x03  SM out bit 0x20 → HorseData+0x109
    uint8_t  m_dash;           // +0x04  SM out bit 0x08
    uint8_t  m_forcedRear;     // +0x05  SM out bit 0x40
    uint8_t  m_fastSlowDown;   // +0x06  SM out[1] bit 0x01
    uint8_t  _pad07;           // +0x07
    float    m_yawRate;        // +0x08  dt * RotationCoeff * clamp * -1.2095776
    int32_t  m_speed;          // +0x0C  -1 = none
    int32_t  m_speedTag;       // +0x10  table via sub_1808324C0
    uint8_t  _pad14[4];        // +0x14  Update object is 0x18
};
static_assert(sizeof(S_RiderMoveRequest) == 0x18, "S_RiderMoveRequest must be 0x18");
static_assert(offsetof(S_RiderMoveRequest, m_yawRate) == 0x08, "yaw rate");
static_assert(offsetof(S_RiderMoveRequest, m_speedTag) == 0x10, "speed tag");

}  // namespace wh::entitymodule
