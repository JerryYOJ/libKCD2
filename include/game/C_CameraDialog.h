#pragma once
#include <cstdint>
#include <cstddef>
#include "C_Camera.h"

// -----------------------------------------------
// wh::game::C_CameraDialog -- game-layer dialog compose delegate (KCD2
// WHGame.dll Steam 1.5.6, sjw7).  sizeof 0x20.  Vtable 0x183A5A210.  RTTI
// .?AVC_CameraDialog@game@wh@@ TD 0x18504f328.  Embedded at
// C_CameraManager+0x318.  Distinct from dialogmodule::C_DialogCamera (0xC8).
// -----------------------------------------------

namespace wh::game {

class C_CameraDialog : public C_Camera {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CameraDialog;

    virtual ~C_CameraDialog();                                    // [0]  0x1839BADE0
    virtual void Compose(SViewParams* params);                    // [1]  0x18164C8FC
    virtual void unk_2(void* event);                              // [2]  0x1816E0688
    virtual const char* GetName() const;                          // [6]  0x181AB4720 "Dialog"
    virtual float GetFov() const;                                 // [7]  0x181A9A920  return m_fov
    virtual void Activate(C_Camera* previous);                    // [8]  0x18175D83C
    virtual void Deactivate(bool uiSwitch);                       // [9]  0x1819A7158
    virtual bool WantsDof() const;                                // [11] return false

    uint64_t m_unk10;                                             // +0x10  ctor 0; role UNVERIFIED
    float    m_fov;                                               // +0x18  ctor 1.04719758 (π/3)
    uint32_t _pad1C;                                              // +0x1C
};
static_assert(sizeof(C_CameraDialog) == 0x20, "C_CameraDialog must be 0x20");
static_assert(offsetof(C_CameraDialog, m_fov) == 0x18);

}  // namespace wh::game
