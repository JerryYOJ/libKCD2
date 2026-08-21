#pragma once
#include <cstdint>
#include <cstddef>
#include "E_RiderGait.h"

// -----------------------------------------------
// wh::entitymodule::S_RiderSMInput -- KCD2 WHGame.dll.  sizeof 0x40.
// -----------------------------------------------
// ctor sub_180A4DBD4. Embedded at C_RiderPlayerInput+0x960.
// THIS is the gait FSM (dispatch 0x181ECAF60 reads *pair[1]).
// Tick 0x180A4EC44 copies the packed input onto +0x04..+0x1B AFTER dispatch,
// so during a tick these fields hold the PREVIOUS frame's values — every
// "bits&0x10 && !(+0x14&0x10)" test in the state handlers is a rising-edge
// check (one gait climb / dash pump per fresh speedup press).

namespace wh::entitymodule {

struct S_RiderSMInput {
    uint8_t  m_state;            // +0x00  E_RiderGait; ctor 1 Idle2Move
    uint8_t  _pad01[3];          // +0x01
    float    m_dt;               // +0x04  blob[0]
    float    m_stickMag;         // +0x08  blob+4
    float    m_moveX;            // +0x0C
    float    m_moveY;            // +0x10
    uint8_t  m_inputBits;        // +0x14  prev frame's E_RiderInputBits (edge-detect reference)
    uint8_t  m_inputBits1;       // +0x15
    uint8_t  m_minGait;          // +0x16
    uint8_t  m_maxGait;          // +0x17  ctor 5
    E_RiderGait::Type m_forcedState; // +0x18  ctor None
    uint8_t  _pad19[3];          // +0x19
    float    m_dashTimer;        // +0x1C  dash reservoir: -=dt in HorseDash, 0 -> drop to Sprint;
                                 //        spur pump 0x1829F1B84 += S_Constants[0x96] cap [0x95];
                                 //        SetState zeroes it on any non-Dash entry
    float    m_stateDwell;       // +0x20
    uint8_t  m_flags24;          // +0x24  bit0 in HorseDash
    uint8_t  m_overSpurCount;    // +0x25  ++ per pump past reservoir cap (spam counter); 0 on Dash exit
    uint8_t  _pad26[2];          // +0x26
    float    m_stopHintConst;    // +0x28  S_Constants[0x9C]
    float    m_timer2C;          // +0x2C
    float    m_fastStopHold;     // +0x30  CVars.m_FastStopHoldTime
    float    m_timer34;          // +0x34
    float    m_timer38;          // +0x38
    float    m_timer3C;          // +0x3C
};
static_assert(sizeof(S_RiderSMInput) == 0x40, "S_RiderSMInput must be 0x40");
static_assert(offsetof(S_RiderSMInput, m_state) == 0x00, "gait");
static_assert(offsetof(S_RiderSMInput, m_forcedState) == 0x18, "forced");
static_assert(offsetof(S_RiderSMInput, m_fastStopHold) == 0x30, "fast stop");

}  // namespace wh::entitymodule
