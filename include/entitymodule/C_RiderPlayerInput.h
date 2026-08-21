#pragma once
#include <cstdint>
#include <cstddef>
#include <map>
#include <vector>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "../framework/C_Signal.h"
#include "I_HorseMoveAdapter.h"
#include "I_MovementInputListener.h"
#include "I_RiderPlayerStateMachineModifier.h"
#include "C_RiderStateMachine.h"
#include "S_RiderSMInput.h"

// -----------------------------------------------
// wh::entitymodule::C_RiderPlayerInput -- KCD2 WHGame.dll.  sizeof 0xA18.
// -----------------------------------------------
// RTTI : I_HorseMoveAdapter @0, I_MovementInputListener @8.
// Factory sub_180A4D420 (alloc 0xA18), ctor sub_180A4D57C, tick [5] 0x180A4EAB4.
// Owned by C_RiderPlayerControl+0x28. +0x10 is the owner actor (C_Player*),
// not the Control. Gait lives in m_smInput+0.

namespace wh::entitymodule {

class C_Player;
class C_Horse;

class C_RiderPlayerInput : public I_HorseMoveAdapter, public I_MovementInputListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_RiderPlayerInput;

    C_Player*             m_pOwner;            // +0x10  Control ctor a2
    C_Horse*              m_pHorse;            // +0x18  bind 0x1810EA730
    std::map<CryStringT<char>, wh::shared::S_Delegate<>> m_actionListeners; // +0x20
    C_RiderStateMachine   m_stateMachine;      // +0x30  0x930
    S_RiderSMInput        m_smInput;           // +0x960
    bool                  m_updateArmed;       // +0x9A0
    uint8_t               _pad9A1[7];          // +0x9A1
    std::vector<I_RiderPlayerStateMachineModifier*> m_modifiers; // +0x9A8
    float                 m_speedupHold;       // +0x9C0
    bool                  m_speedupFromMask;   // +0x9C4  movement mask & 4
    bool                  m_jumpFromMask;      // +0x9C5  movement mask & 0x80000
    bool                  m_toggleRun;         // +0x9C6  toggle_run OnRelease
    bool                  m_speedupHeld;       // +0x9C7  sprint OnHold
    bool                  m_slowdownOneShot;   // +0x9C8  LCtrl
    bool                  m_speedupDoubleTap;  // +0x9C9
    uint8_t               _pad9CA[2];          // +0x9CA
    Vec3                  m_look;              // +0x9CC
    Vec3                  m_move;              // +0x9D8
    uint8_t               m_smOutGait;         // +0x9E4  SM out[0] bits, not a bool
    uint8_t               m_smOutSpur;         // +0x9E5  SM out[1] bits
    uint8_t               _pad9E6[2];          // +0x9E6
    float                 m_stopHintDelay;     // +0x9E8
    float                 m_stopHintTimer;     // +0x9EC
    float                 m_dashInterruptTimer;// +0x9F0
    float                 m_lastSpeedupPress;  // +0x9F4  OnSpeedup press time (double-tap window)
    wh::shared::S_Delegate<> m_onSpur;         // +0x9F8  Control C_Signal emit
    float                 m_turn;              // +0xA08
    float                 m_stickMag;          // +0xA0C
    bool                  m_speedupEdge;       // +0xA10
    bool                  m_spurEmitted;       // +0xA11
    uint8_t               _padA12[6];          // +0xA12
};
static_assert(sizeof(C_RiderPlayerInput) == 0xA18, "C_RiderPlayerInput must be 0xA18");
static_assert(offsetof(C_RiderPlayerInput, m_stateMachine) == 0x30, "SM");
static_assert(offsetof(C_RiderPlayerInput, m_smInput) == 0x960, "SM input");
static_assert(offsetof(C_RiderPlayerInput, m_modifiers) == 0x9A8, "modifiers");
static_assert(offsetof(C_RiderPlayerInput, m_move) == 0x9D8, "move");
static_assert(offsetof(C_RiderPlayerInput, m_stickMag) == 0xA0C, "stick mag");

}  // namespace wh::entitymodule
