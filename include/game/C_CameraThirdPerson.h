#pragma once
#include <cstdint>
#include <cstddef>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "C_Camera.h"

// -----------------------------------------------
// wh::game::C_CameraThirdPerson -- blend-only orbit camera (KCD2 WHGame.dll
// Steam 1.5.6, sjw7).  sizeof 0x28.  Vtable 0x183A5A1A0.  RTTI
// .?AVC_CameraThirdPerson@game@wh@@ TD 0x18504f388.  Embedded at
// C_CameraManager+0x208.  Not in SelectActive; composed only when
// manager+0x38 is set, via m_pBlendSource.
// -----------------------------------------------

namespace wh::game {

class C_CameraThirdPerson : public C_Camera {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CameraThirdPerson;

    virtual ~C_CameraThirdPerson();                               // [0]  0x1839C31B4
    virtual void Compose(SViewParams* params);                    // [1]  0x1839C3B90
    virtual void unk_2(void* event);                              // [2]  0x1839C3248 mouse orbit/zoom
    virtual bool unk_3() const;                                   // [3]  return true
    virtual bool unk_4() const;                                   // [4]  return true
    virtual bool unk_5() const;                                   // [5]  return false
    virtual const char* GetName() const;                          // [6]  0x181AB4750 "THIRD PERSON"

    Quat  m_orbit;                                                // +0x10  slot 2 reads/writes as orbit quat; w init 1.0
    float m_zoom;                                                 // +0x20  slot 2 action 0x10C; clamp vs GameContext+0x20+0x110
    uint32_t _pad24;                                              // +0x24
};
static_assert(sizeof(C_CameraThirdPerson) == 0x28, "C_CameraThirdPerson must be 0x28");
static_assert(offsetof(C_CameraThirdPerson, m_orbit) == 0x10);
static_assert(offsetof(C_CameraThirdPerson, m_zoom) == 0x20);

}  // namespace wh::game
