#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule::data {

struct E_SkillCheckResult {
    enum Type : std::uint8_t {
        None            = 0,
        Fail            = 1,
        MajorFail       = 2,
        CriticalFail    = 3,
        Success         = 4,
        MajorSuccess    = 5,
        CriticalSuccess = 6,
    };
};
static_assert(sizeof(E_SkillCheckResult::Type) == 1, "E_SkillCheckResult::Type size mismatch");

}  // namespace wh::dialogmodule::data
