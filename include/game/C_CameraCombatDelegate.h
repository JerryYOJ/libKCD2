#pragma once
#include <cstdint>
#include <cstddef>
#include "C_Camera.h"

// -----------------------------------------------
// wh::game::C_CameraCombatDelegate -- combat compose delegate (KCD2 WHGame.dll
// Steam 1.5.6, sjw7).  sizeof 0x20.  Vtable 0x183A5A360.  RTTI
// .?AVC_CameraCombatDelegate@game@wh@@ TD 0x18504ef78.  Embedded at
// C_CameraManager+0x370.  Distinct from combatmodule camera managers (they
// feed this).  Pointee at +0x10 type UNVERIFIED.
// -----------------------------------------------

namespace wh::game {

class C_CameraCombatDelegate : public C_Camera {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CameraCombatDelegate;

    virtual ~C_CameraCombatDelegate();                            // [0]  0x1839BADE0
    virtual void Compose(SViewParams* params);                    // [1]  0x1804FB998
    virtual void unk_2(void* event);                              // [2]  0x1804FB9B8
    virtual bool unk_4() const;                                   // [4]  0x1809E58A0
    virtual bool unk_5() const;                                   // [5]  0x1819C9F24
    virtual const char* GetName() const;                          // [6]  0x181AB4580 "COMBAT"
    virtual float GetFov() const;                                 // [7]  0x1809E4B40
    virtual void Activate(C_Camera* previous);                    // [8]  0x180C58558
    virtual void Deactivate(bool uiSwitch);                       // [9]  0x181147558

    void*   m_pCombatCamera;                                      // +0x10  ctor 0; compose / slots 2/4/5/7
    uint8_t m_unk18;                                              // +0x18  ctor 0
    uint8_t _pad19[7];                                            // +0x19
};
static_assert(sizeof(C_CameraCombatDelegate) == 0x20, "C_CameraCombatDelegate must be 0x20");
static_assert(offsetof(C_CameraCombatDelegate, m_pCombatCamera) == 0x10);

}  // namespace wh::game
