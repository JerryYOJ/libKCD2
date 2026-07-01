#pragma once
#include <cstdint>
#include "../Offsets/Offsets_VTABLE.h"
#include "../Offsets/vtables/IMovieSystem.h"
#include "SCameraParams.h"

// -----------------------------------------------
// CMovieSystem : IMovieSystem  (CryMovie / TrackView) -- KCD2 WHGame.dll 1.5.6 (kd7u)
// -----------------------------------------------
// RTTI ??_7CMovieSystem@@6B@   primary vtable 0x18407E648   ctor sub_180D61DA4
// sizeof 0xBC8 (scalar-deleting dtor slot0 @0x18387B080 -> operator delete(this,3016)).
// Single base (IMovieSystem @ +0x00). GetCameraParams=slot59, SetCameraParams=slot60.
//
// [FUNDAMENTAL vs KCD1] primary vtable RVA 0x279FD10 -> 0x407E648, and the get/set
// camera-params pair shifted +2 (vtable grew 92->93 slots): SetCameraParams slot 58 -> 60.
// [MODERATE vs KCD1] m_pUser +0x70->+0x40, m_pCallback +0x78->+0x48, m_cameraParams +0xE4->+0x118.

namespace Offsets { struct ISystem; struct IMovieUser; }

struct CMovieSystem : Offsets::IMovieSystem {   // vtable @ +0x00
    inline static constexpr auto VTABLE = Offsets::VTABLE_CMovieSystem;  // primary vtable @ 0x407E648 (slot 60 = SetCameraParams)

    uint8_t              _pad08[0x30];       // +0x08  name/handle sub-objects (opaque)
    Offsets::ISystem*    m_pSystem;          // +0x38  ctor arg                                    VERIFIED
    Offsets::IMovieUser* m_pUser;            // +0x40  notified by SetCameraParams (user-vtbl+0x08) VERIFIED
    void*                m_pCallback;        // +0x48  notified by SetCameraParams (cb-vtbl+0x10)    VERIFIED
    uint8_t              _pad50[0xC8];       // +0x50  SRWLOCKs, lists, cvar defaults (opaque)
    SCameraParams        m_cameraParams;     // +0x118 GetCameraParams returns &this                VERIFIED
    uint8_t              _pad13C[0xA8C];     // +0x13C tail internals -> sizeof 0xBC8
};
static_assert(sizeof(CMovieSystem) == 0xBC8, "CMovieSystem must be 0xBC8");
