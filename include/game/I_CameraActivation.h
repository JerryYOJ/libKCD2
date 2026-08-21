#pragma once
#include <cstdint>
#include <cstddef>

// -----------------------------------------------
// wh::game::I_CameraActivation -- MI interface on C_CameraBoneAnimated only
// (KCD2 WHGame.dll Steam 1.5.6, sjw7).  sizeof 0x10.  6 slots at
// 0x183A5A168 (no ??_7I_CameraActivation symbol).  RTTI
// .?AVI_CameraActivation@game@wh@@ TD 0x18504d680.  Standalone CHD (not a
// C_Camera base).  Slot 0 is a lazy-bind, not a destructor.
// -----------------------------------------------

namespace wh::game {

class I_CameraActivation {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_CameraActivation;

    virtual void unk_0();                                         // [0]  0x1839BB444 lazy-bind from AnimationModule
    virtual void unk_1();                                         // [1]  0x1839BAEA0
    virtual void unk_2();                                         // [2]  0x1839BAEA0  same impl as [1]
    virtual void unk_3();                                         // [3]  0x1839BB350
    virtual bool IsActive();                                      // [4]  0x1809E5C48  ptr && *(int32*)(ptr+0x30) != -1
    virtual void unk_5(int32_t value);                            // [5]  0x181AB45A0  writes ptr+0x34

    void* m_pObject;                                              // +0x08  activation object (+0x30 id, +0x34 dword)
};
static_assert(sizeof(I_CameraActivation) == 0x10, "I_CameraActivation must be 0x10");
static_assert(offsetof(I_CameraActivation, m_pObject) == 0x08);

}  // namespace wh::game
