#pragma once
#include <cstdint>
#include <cstddef>
#include "C_Camera.h"

// -----------------------------------------------
// wh::game::C_CameraDebug -- debug fly/orbit/link camera (KCD2 WHGame.dll
// Steam 1.5.6, sjw7).  sizeof 0xE8.  Vtable 0x183A5A4C0.  RTTI
// .?AVC_CameraDebug@game@wh@@ TD 0x18504ef48.  Embedded at
// C_CameraManager+0x230.  Ctor 0x1808970EC.  Not in SelectActive.
// -----------------------------------------------
// GetName 0x1839BB3F8 switches +0x10: 0 FREE / 1 FROZEN / 2 ORBIT / 3 LINKED /
// 4 UNDEFINED.  Enumerator source name UNVERIFIED.  Pose blocks at +0x20 are
// four 0x2C (Quat+Vec3) identity-w copies; interior names UNVERIFIED.

namespace wh::game {

class C_CameraDebug : public C_Camera {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CameraDebug;

    virtual ~C_CameraDebug();                                     // [0]  0x1839BAE0C
    virtual void Compose(SViewParams* params);                    // [1]  0x1839BC7EC
    virtual void unk_2(void* event);                              // [2]  0x1839BAF2C
    virtual bool unk_3() const;                                   // [3]  0x1839BB55C
    virtual const char* GetName() const;                          // [6]  0x1839BB3F8

    int32_t  m_submode;                                           // +0x10  ctor 4 (UNDEFINED)
    int32_t  m_unk14;                                             // +0x14  ctor 0
    uint64_t m_unk18;                                             // +0x18  ctor 0
    uint8_t  m_poseBlocks[0xB0];                                  // +0x20  4 × 0x2C Quat+Vec3
    uint8_t  m_unkD0[0xC];                                        // +0xD0
    int32_t  m_unkDC;                                             // +0xDC
    uint8_t  m_unkE0;                                             // +0xE0
    uint8_t  _padE1[7];                                           // +0xE1
};
static_assert(sizeof(C_CameraDebug) == 0xE8, "C_CameraDebug must be 0xE8");
static_assert(offsetof(C_CameraDebug, m_submode) == 0x10);
static_assert(offsetof(C_CameraDebug, m_poseBlocks) == 0x20);

}  // namespace wh::game
