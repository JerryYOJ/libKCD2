#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::tests {

enum class E_TestRttrEnum : std::int32_t {
    TestRttrEnumA = 0,
    TestRttrEnumB = 1,
    TestRttrEnumC = 2,
};
static_assert(sizeof(E_TestRttrEnum) == 4, "E_TestRttrEnum size mismatch");

}  // namespace wh::tests
