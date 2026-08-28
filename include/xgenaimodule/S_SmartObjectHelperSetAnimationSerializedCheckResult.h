#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::xgenaimodule {

struct S_SmartObjectHelperSetAnimationSerializedCheckResult {
    CryStringT<char> GetDropReasons() const;                 // 0x1832D8224
    void SetDropReasons(CryStringT<char> value);             // 0x18069D0E4

    std::uint32_t m_dropReasons;                             // +0x00 accessor-backed bit mask
};

static_assert(offsetof(S_SmartObjectHelperSetAnimationSerializedCheckResult, m_dropReasons) == 0x00,
              "SerializedCheckResult::m_dropReasons offset mismatch");
static_assert(sizeof(S_SmartObjectHelperSetAnimationSerializedCheckResult) == 0x04,
              "SerializedCheckResult size mismatch");

}  // namespace wh::xgenaimodule
