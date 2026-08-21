#pragma once
#include <cstdint>
#include <cstddef>
#include "C_Camera.h"
#include "I_CameraActivation.h"

// -----------------------------------------------
// wh::game::C_CameraBoneAnimated -- bone-driven compose (KCD2 WHGame.dll
// Steam 1.5.6, sjw7).  sizeof 0x20.  Primary vt 0x183A5A3D0; I_CameraActivation
// at +0x10 (vt 0x183A5A168, RTTI mdisp=16).  RTTI
// .?AVC_CameraBoneAnimated@game@wh@@ TD 0x18504d648.  Embedded at
// C_CameraManager+0x350.  SelectActive tests I_CameraActivation::IsActive
// at manager+0x360.
// -----------------------------------------------

namespace wh::game {

class C_CameraBoneAnimated : public C_Camera, public I_CameraActivation {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CameraBoneAnimated;

    virtual ~C_CameraBoneAnimated();                              // [0]  0x1839BADAC → 0x1839BA978
    virtual void Compose(SViewParams* params);                    // [1]  0x1839BC7E0
    virtual const char* GetName() const;                          // [6]  0x181AB4570 "BoneAnimated"
    virtual float GetFov() const;                                 // [7]  0x1839BB3E0  from activation object if id != -1
};
static_assert(sizeof(C_CameraBoneAnimated) == 0x20, "C_CameraBoneAnimated must be 0x20");

}  // namespace wh::game
