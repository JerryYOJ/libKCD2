#pragma once
#include <cstdint>
#include <cstddef>
#include "../crysystem/SViewParams.h"

// -----------------------------------------------
// wh::game::C_Camera -- abstract camera-mode base (KCD2 WHGame.dll Steam 1.5.6,
// sjw7).  sizeof 0x10.  Vtable 0x18408e588, 13 slots.  Abstract (Compose / GetName
// are _purecall).  RTTI .?AVC_Camera@game@wh@@ TD 0x18504d6e8.  No I_Camera /
// C_CameraBase parent (CHD numBases=1).
// -----------------------------------------------
// Leaves live by value inside C_CameraManager.  Slot roles from SelectActive
// 0x1809E58CC and blend 0x1807F2A9C.  Slots 2-5 have no recovered source names.

namespace wh::game {

class C_Camera {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Camera;

    virtual ~C_Camera();                                          // [0]  0x1839BAD4C
    virtual void Compose(SViewParams* params) = 0;                // [1]
    virtual void unk_2(void* event) {}                            // [2]  0x1803B6E80 nullsub; TP/Dialog/Combat override
    virtual bool unk_3() const { return false; }                  // [3]  0x180838AE0
    virtual bool unk_4() const { return true; }                   // [4]  0x18041A6A0; FP/Rider return false
    virtual bool unk_5() const { return false; }                  // [5]  0x180838AE0; FP/Rider/Minigame return true
    virtual const char* GetName() const = 0;                      // [6]
    virtual float GetFov() const;                                 // [7]  0x1808B8BD8 radians from GameContext+0x20+0xF8
    virtual void Activate(C_Camera* previous) {}                  // [8]  0x1803B6E80
    virtual void Deactivate(bool uiSwitch) {}                     // [9]  0x1803B6E80
    virtual void PostCompose(SViewParams* params) {}              // [10] 0x1803B6E80
    virtual bool WantsDof() const { return true; }                // [11] 0x18041A6A0; UI/Dialog return false
    virtual int32_t GetModeId() const;                            // [12] 0x181A72970  return m_modeId

    int32_t m_modeId;                                             // +0x08  GetModeId source; FP and Rider both write 0
    uint32_t _pad0C;                                              // +0x0C  never written
};
static_assert(sizeof(C_Camera) == 0x10, "C_Camera must be 0x10");
static_assert(offsetof(C_Camera, m_modeId) == 0x08);

}  // namespace wh::game
