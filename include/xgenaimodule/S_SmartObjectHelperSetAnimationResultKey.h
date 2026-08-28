#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

// -----------------------------------------------
// wh::xgenaimodule::S_SmartObjectHelperSetAnimationResultKey
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x14. No vtable.
// -----------------------------------------------

namespace wh::xgenaimodule {

#pragma pack(push, 4)
struct S_SmartObjectHelperSetAnimationResultKey {
    CryGUID m_fragmentGuid;                               // +0x00 RTTR "FragmentGuid"
    std::int32_t m_helperId;                              // +0x10 RTTR "HelperId"
};
#pragma pack(pop)

static_assert(offsetof(S_SmartObjectHelperSetAnimationResultKey, m_fragmentGuid) == 0x00,
              "S_SmartObjectHelperSetAnimationResultKey::m_fragmentGuid offset mismatch");
static_assert(sizeof(S_SmartObjectHelperSetAnimationResultKey) == 0x14,
              "S_SmartObjectHelperSetAnimationResultKey size mismatch");

}  // namespace wh::xgenaimodule
