#pragma once
#include <cstdint>
#include <cstddef>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "C_FocusCamera.h"

// -----------------------------------------------
// S_FocusCameraSetup -- one installed C_FocusCamera focus request (KCD2 WHGame.dll
// Steam 1.5.6, sjw7).  sizeof 0x38.  SYNTHETIC name (plain heap struct, no RTTI).
// -----------------------------------------------
// Created by sub_1808B847C (zero-init, m_id = -1, m_mode = 1, m_stiffness = 1.0);
// filled by the two installers (combat lock sub_1808B8548, C_FocusCameraNode
// activate 0x1827DBE94) and handed to C_FocusCamera::Install_1808B811C (REL::ID
// 47607).  Activate_1808B9DB8 copies the limit pairs to tracker+0x20/+0x28 and
// m_stiffness to tracker+0x40.  Which limit pair is yaw vs pitch is UNVERIFIED
// (both feed the tracker delta clamp sub_18177BA60).

struct S_FocusCameraSetup {
    int32_t  m_id;             // +0x00  install handle (-1 until installed)
    uint8_t  m_mode;           // +0x04  0/1/2 (default 1); 2 = hard mode with recenter timers + player vfunc[135] + entity-yaw coupling
    uint8_t  m_priority;       // +0x05  install-sort key (Install_1808B811C sorts m_setups by this DESC; sort 0x181F21560): FocusCameraNode writes 1, combat lock 0
    uint8_t  _pad06[2];        // +0x06
    C_FocusCamera::I_TargetPositionProvider* m_pTargetProvider;  // +0x08  _smart_ptr (ref via sub_180396184/sub_18039AE88)
    uint8_t  _pad10[8];        // +0x10
    uint8_t  m_limitAEnable;   // +0x18  optional angle-limit pair A (FocusCameraNode port +0x108)
    uint8_t  _pad19[3];        // +0x19
    Vec2     m_limitA;         // +0x1C  min/max radians -> tracker+0x20
    uint8_t  m_limitBEnable;   // +0x24  optional angle-limit pair B (FocusCameraNode port +0xC8)
    uint8_t  _pad25[3];        // +0x25
    Vec2     m_limitB;         // +0x28  min/max radians -> tracker+0x28
    float    m_stiffness;      // +0x30  align smoothing divisor: step *= min(dt*100,1)/(m_stiffness+1)
    uint8_t  m_flag34;         // +0x34  FocusCameraNode writes 1; passed into ShouldBeActive_1808B9B78
    uint8_t  _pad35[3];        // +0x35
};
static_assert(sizeof(S_FocusCameraSetup) == 0x38, "S_FocusCameraSetup must be 0x38");
static_assert(offsetof(S_FocusCameraSetup, m_pTargetProvider) == 0x08);
static_assert(offsetof(S_FocusCameraSetup, m_limitA) == 0x1C);
static_assert(offsetof(S_FocusCameraSetup, m_limitB) == 0x28);
static_assert(offsetof(S_FocusCameraSetup, m_stiffness) == 0x30);
