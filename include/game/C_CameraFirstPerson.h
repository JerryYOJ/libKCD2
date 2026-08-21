#pragma once
#include <cstdint>
#include <cstddef>
#include "C_Camera.h"

// -----------------------------------------------
// wh::game::C_CameraFirstPerson -- default on-foot compose (KCD2 WHGame.dll
// Steam 1.5.6, sjw7).  sizeof 0x20.  Vtable 0x183A5A0F8.  RTTI
// .?AVC_CameraFirstPerson@game@wh@@ TD 0x18504ef10.  Embedded at
// C_CameraManager+0x1E8.  Compose 0x18094D030 (REL::ID 51045).
// -----------------------------------------------

namespace wh::game {

class C_CameraFirstPerson : public C_Camera {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CameraFirstPerson;

    virtual ~C_CameraFirstPerson();                               // [0]  0x1839BADE0
    virtual void Compose(SViewParams* params);                    // [1]  0x18094D030
    virtual bool unk_4() const;                                   // [4]  0x180838AE0 return false
    virtual bool unk_5() const;                                   // [5]  0x18041A6A0 return true
    virtual const char* GetName() const;                          // [6]  0x181AB4590 "FIRST PERSON"
    virtual void PostCompose(SViewParams* params);                // [10] 0x180E89480  optional +0x18 pos offset

    int32_t m_unk10;                                              // +0x10  ctor 0; role UNVERIFIED
    uint8_t m_useBoneRotation;                                    // +0x14  ctor 0; Compose bone-quat path when set
    uint8_t _pad15[3];                                            // +0x15
    float   m_posOffset;                                          // +0x18  PostCompose: if m_useBoneRotation, -this on position
};
static_assert(sizeof(C_CameraFirstPerson) == 0x20, "C_CameraFirstPerson must be 0x20");
static_assert(offsetof(C_CameraFirstPerson, m_useBoneRotation) == 0x14);
static_assert(offsetof(C_CameraFirstPerson, m_posOffset) == 0x18);

}  // namespace wh::game
