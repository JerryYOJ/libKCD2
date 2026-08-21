#pragma once
#include <cstdint>
#include <cstddef>
#include "C_CameraFirstPerson.h"

// -----------------------------------------------
// wh::game::C_CameraRider -- mounted compose (KCD2 WHGame.dll Steam 1.5.6,
// sjw7).  sizeof 0x38.  Vtable 0x183A5A2F0.  RTTI .?AVC_CameraRider@game@wh@@
// TD 0x18504eee0 (CHD 3-base: self → FirstPerson → C_Camera).  Embedded at
// C_CameraManager+0x3C0.  Selected when C_RiderStateMachine::m_camFlag928 != 0
// (SelectActive pred 0x1809E6050).  Compose 0x1839C3748 (REL::ID 434788) =
// FirstPerson compose + SmoothCD on yaw/pitch.
// -----------------------------------------------

namespace wh::game {

class C_CameraRider : public C_CameraFirstPerson {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CameraRider;

    virtual ~C_CameraRider();                                     // [0]  0x1839BAE6C
    virtual void Compose(SViewParams* params);                    // [1]  0x1839C3748
    // [6] GetName is the same "FIRST PERSON" stub as C_CameraFirstPerson

    int32_t m_lastFrame;                                          // +0x20  ctor 0; mismatch vs timer vf[+0x600] resets SmoothCD
    float   m_smoothYaw;                                          // +0x24
    float   m_smoothYawVel;                                       // +0x28
    float   m_smoothPitch;                                        // +0x2C
    float   m_smoothPitchVel;                                     // +0x30
    uint32_t _pad34;                                              // +0x34
};
static_assert(sizeof(C_CameraRider) == 0x38, "C_CameraRider must be 0x38");
static_assert(offsetof(C_CameraRider, m_lastFrame) == 0x20);
static_assert(offsetof(C_CameraRider, m_smoothYaw) == 0x24);
static_assert(offsetof(C_CameraRider, m_smoothPitch) == 0x2C);

}  // namespace wh::game
