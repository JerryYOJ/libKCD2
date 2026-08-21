#pragma once
#include <cstdint>
#include <cstddef>

// -----------------------------------------------
// wh::framework::CScreenEffects -- post-process / screen-fx embed on
// C_CameraManager (KCD2 WHGame.dll Steam 1.5.6, sjw7).  Embed extent 0x58
// (manager +0x478..+0x4D0).  Vtable 0x183A5A440, 15 slots.  RTTI
// .?AVCScreenEffects@framework@wh@@ TD 0x184a69840.  Ctor 0x180897038 writes
// through +0x38 (two header-prefixed maps + two CryStringT); dtor
// 0x1825CD518.  Interior field names UNVERIFIED this wave — layout-only
// replica so the manager embed is a real type, not a raw vptr.
// -----------------------------------------------

namespace wh::framework {

class CScreenEffects {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_CScreenEffects;

    virtual ~CScreenEffects();                                    // [0]  0x1825CD518

    uint8_t _pad08[0x50];                                         // +0x08  maps / strings / UNVERIFIED tail to 0x58
};
static_assert(sizeof(CScreenEffects) == 0x58, "CScreenEffects embed is 0x58");

}  // namespace wh::framework
