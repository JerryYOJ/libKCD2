#pragma once
#include <cstdint>
#include <cstddef>
#include <functional>
#include "../xgenaimodule/I_LabelTracker.h"
#include "../Offsets/vtables/ISystem.h"
#include "../framework/C_Signal.h"

// -----------------------------------------------
// wh::entitymodule::C_RiderPlayerControl -- KCD2 WHGame.dll.  sizeof 0xA8.
// -----------------------------------------------
// RTTI : I_LabelTracker @0, ISystemEventListener @8.
// Factory sub_180A4C5D0 (alloc 0xA8), ctor sub_180A4D05C.
// Stored at C_Player+0xD68. Owns C_RiderPlayerInput* at +0x28.
// +0x40 is MSVC std::function<float()> (0x40) + 0x10 tail; bound
// C_RiderPlayerControl::DashWeight_180A4F93C (1.0 iff horse rank==3).

namespace wh::entitymodule {

class C_Player;
class C_RiderPlayerInput;

class C_RiderPlayerControl : public wh::xgenaimodule::I_LabelTracker, public Offsets::ISystemEventListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_RiderPlayerControl;

    wh::shared::C_Signal<> m_signal;              // +0x10  sentinel 0x1856683C8
    C_Player*              m_pOwner;              // +0x20
    C_RiderPlayerInput*    m_pPlayerInput;        // +0x28
    uint8_t                m_whistling;           // +0x30  player:SetWhistling
    uint8_t                m_unk31;               // +0x31  cleared on soul state 0
    uint8_t                m_mountSession;        // +0x32  soul states 1/2
    uint8_t                _pad33;                // +0x33
    uint32_t               m_zero34;              // +0x34  ctor 0
    uint8_t                m_labelArmed;          // +0x38  I_LabelTracker[0]/[1]
    uint8_t                m_speedLimiterOn;      // +0x39
    uint8_t                m_speedLimiterHooked;  // +0x3A
    uint8_t                _pad3B[5];             // +0x3B
    std::function<float()> m_dashWeight;          // +0x40  0x40
    int32_t                m_dashCache0;          // +0x80
    int32_t                m_dashCache1;          // +0x84
    float                  m_dashFovChangeSpeed;  // +0x88  S_HorseCVars+0xFC
    uint8_t                m_hudFilterDirty;      // +0x90
    uint8_t                m_hudFilterAlt;        // +0x91
    uint8_t                _pad92[2];             // +0x92
    float                  m_sessionTime;         // +0x94
    uint8_t                m_labelCallActive;     // +0x98
    uint8_t                _pad99[7];             // +0x99
    uint64_t               m_calledId;            // +0xA0  invalid = qword_185324A78
};
static_assert(sizeof(std::function<float()>) == 0x40, "MSVC std::function is 0x40");
static_assert(sizeof(C_RiderPlayerControl) == 0xA8, "C_RiderPlayerControl must be 0xA8");
static_assert(offsetof(C_RiderPlayerControl, m_pPlayerInput) == 0x28, "owns player input");
static_assert(offsetof(C_RiderPlayerControl, m_dashWeight) == 0x40, "dash fn");
static_assert(offsetof(C_RiderPlayerControl, m_dashFovChangeSpeed) == 0x88, "fov speed");
static_assert(offsetof(C_RiderPlayerControl, m_calledId) == 0xA0, "called id");

}  // namespace wh::entitymodule
