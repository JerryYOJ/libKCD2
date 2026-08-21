#pragma once
#include <cstdint>
#include <cstddef>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "C_Camera.h"

// -----------------------------------------------
// wh::game::C_CameraUI -- highest-priority UI compose (KCD2 WHGame.dll
// Steam 1.5.6, sjw7).  sizeof 0x30.  Vtable 0x183A5A280.  RTTI
// .?AVC_CameraUI@game@wh@@ TD 0x18504f358.  Embedded at
// C_CameraManager+0x390.  Ctor 0x180896FF4.  Does NOT implement
// framework::I_UICamera (that is C_UIApseCamera).
// -----------------------------------------------

namespace wh::game {

class C_CameraUI : public C_Camera {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CameraUI;

    virtual ~C_CameraUI();                                        // [0]  0x1839C31E0
    virtual void Compose(SViewParams* params);                    // [1]  0x1809E5314
    virtual const char* GetName() const;                          // [6]  0x181AB4760 "UI"
    virtual float GetFov() const;                                 // [7]  0x181A9C8A0  return m_fov
    virtual void Activate(C_Camera* previous);                    // [8]  0x18192B560  snapshots previous compose
    virtual bool WantsDof() const;                                // [11] return false

    float m_fov;                                                  // +0x10  ctor from GameContext+0x20+0xF8 deg→rad
    Quat  m_cachedRotation;                                       // +0x14  Activate snapshot
    Vec3  m_cachedPosition;                                       // +0x24  Activate snapshot
};
static_assert(sizeof(C_CameraUI) == 0x30, "C_CameraUI must be 0x30");
static_assert(offsetof(C_CameraUI, m_fov) == 0x10);
static_assert(offsetof(C_CameraUI, m_cachedRotation) == 0x14);
static_assert(offsetof(C_CameraUI, m_cachedPosition) == 0x24);

}  // namespace wh::game
