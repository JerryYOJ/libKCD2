#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh {
class S_ModInfo {
public:
    virtual ~S_ModInfo();
    RTTR_ENABLE()  // [1..3]
    std::uint8_t m_unknown08[0x8];                  // +0x8
    CryStringT<char> m_name;  // +0x10 RTTR "Name"
    std::uint8_t m_unknown18[0x8];                  // +0x18
    CryStringT<char> m_author;  // +0x20 RTTR "Author"
    CryStringT<char> m_version;  // +0x28 RTTR "Version"
    std::uint8_t m_unknown30[0x8];                  // +0x30
    bool m_modifiesLevel;  // +0x38 RTTR "ModifiesLevel"
    std::uint8_t m_unknown39[0x7];                  // +0x39
};

static_assert(offsetof(S_ModInfo, m_modifiesLevel) == 0x38, "S_ModInfo::m_modifiesLevel offset mismatch");
static_assert(offsetof(S_ModInfo, m_version) == 0x28, "S_ModInfo::m_version offset mismatch");
static_assert(offsetof(S_ModInfo, m_author) == 0x20, "S_ModInfo::m_author offset mismatch");
static_assert(offsetof(S_ModInfo, m_name) == 0x10, "S_ModInfo::m_name offset mismatch");
static_assert(sizeof(S_ModInfo) == 0x40, "S_ModInfo size mismatch");

}  // namespace wh
