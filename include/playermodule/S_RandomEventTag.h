#pragma once
#include <cstddef>
#include <cstdint>

namespace wh::playermodule {
struct S_RandomEventTag {
    CryStringT<char> m_randomEventTag;  // +0x0 RTTR "wh::playermodule::RandomEventTag"
};

static_assert(offsetof(S_RandomEventTag, m_randomEventTag) == 0x0, "S_RandomEventTag::m_randomEventTag offset mismatch");
static_assert(sizeof(S_RandomEventTag) == 0x8, "S_RandomEventTag size mismatch");

}  // namespace wh::playermodule
