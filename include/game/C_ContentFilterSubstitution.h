#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"
#include "../framework/E_ContentFilter.h"

namespace wh::game {
class C_ContentFilterSubstitution {
public:
    RTTR_ENABLE()  // [0..2]
    CryStringT<char> m_originalObjectPath;  // +0x8 RTTR "OriginalObjectPath"
    wh::framework::E_ContentFilter::Type m_filter;  // +0x10 RTTR "Filter"
    std::uint8_t m_unknown11[0x7];                  // +0x11
    CryStringT<char> m_substitutedObjectPath;  // +0x18 RTTR "SubstitutedObjectPath"
};

static_assert(offsetof(C_ContentFilterSubstitution, m_substitutedObjectPath) == 0x18, "C_ContentFilterSubstitution::m_substitutedObjectPath offset mismatch");
static_assert(offsetof(C_ContentFilterSubstitution, m_filter) == 0x10, "C_ContentFilterSubstitution::m_filter offset mismatch");
static_assert(offsetof(C_ContentFilterSubstitution, m_originalObjectPath) == 0x8, "C_ContentFilterSubstitution::m_originalObjectPath offset mismatch");
static_assert(sizeof(C_ContentFilterSubstitution) == 0x20, "C_ContentFilterSubstitution size mismatch");

}  // namespace wh::game
