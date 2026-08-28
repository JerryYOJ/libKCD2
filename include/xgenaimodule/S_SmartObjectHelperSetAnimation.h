#pragma once

#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../CryEngine/CryCommon/Cry_Quat.h"

namespace wh::xgenaimodule {

struct S_SmartObjectHelperSetAnimation {
    std::int32_t m_type;                                                     // +0x00 RTTR class name
    QuatT m_helperTransformLocal;                                            // +0x04 RTTR "HelperTransformLocal"
    CryGUID m_fragmentGuid;                                                  // +0x20 RTTR "FragmentGuid"
    QuatT m_startTransform;                                                  // +0x30 RTTR "StartTransform"
    QuatT m_animRelativeMovement;                                            // +0x4C RTTR "AnimRelativeMovement"
    bool m_hasAlignProcclip;                                                 // +0x68 RTTR "HasAlignProcclip"
    std::uint8_t m_padding69[7];                                             // +0x69
};

static_assert(offsetof(S_SmartObjectHelperSetAnimation, m_helperTransformLocal) ==
                  0x04,
              "S_SmartObjectHelperSetAnimation::m_helperTransformLocal offset mismatch");
static_assert(offsetof(S_SmartObjectHelperSetAnimation, m_fragmentGuid) == 0x20,
              "S_SmartObjectHelperSetAnimation::m_fragmentGuid offset mismatch");
static_assert(offsetof(S_SmartObjectHelperSetAnimation, m_hasAlignProcclip) ==
                  0x68,
              "S_SmartObjectHelperSetAnimation::m_hasAlignProcclip offset mismatch");
static_assert(sizeof(S_SmartObjectHelperSetAnimation) == 0x70,
              "S_SmartObjectHelperSetAnimation size mismatch");

} // namespace wh::xgenaimodule
