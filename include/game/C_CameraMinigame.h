#pragma once
#include <cstdint>
#include <cstddef>
#include "C_Camera.h"

// -----------------------------------------------
// wh::game::C_CameraMinigame -- minigame compose delegate (KCD2 WHGame.dll
// Steam 1.5.6, sjw7).  sizeof 0x18.  Vtable 0x18408EB60.  RTTI
// .?AVC_CameraMinigame@game@wh@@ TD 0x18504f3c0.  Embedded at
// C_CameraManager+0x338.  Queries playermodule::I_MinigameCamera; does not
// inherit it.
// -----------------------------------------------

namespace wh::game {

class C_CameraMinigame : public C_Camera {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CameraMinigame;

    virtual ~C_CameraMinigame();                                  // [0]  0x1839C3188
    virtual void Compose(SViewParams* params);                    // [1]  0x1839C3714
    virtual bool unk_4() const;                                   // [4]  0x1839C3EB4
    virtual bool unk_5() const;                                   // [5]  return true
    virtual const char* GetName() const;                          // [6]  0x181AB4730 "Minigame"
    virtual float GetFov() const;                                 // [7]  0x1839C369C
    virtual bool WantsDof() const;                                // [11] 0x1839C36E4  I_MinigameCamera slot 5 else true

    uint64_t m_unk10;                                             // +0x10  ctor 0; unread by slots 4/7/11
};
static_assert(sizeof(C_CameraMinigame) == 0x18, "C_CameraMinigame must be 0x18");

}  // namespace wh::game
