#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::framework {

struct E_GameReleaseVersion {
    enum Type : std::int32_t {
        Invalid      = 2147483647,
        ver_01_00    = 10000,
        ver_01_01    = 10100,
        ver_01_01_01 = 10101,
        ver_01_01_02 = 10102,
        ver_01_02    = 10200,
        ver_01_02_01 = 10201,
        ver_01_02_02 = 10202,
        ver_01_02_03 = 10203,
        ver_01_02_04 = 10204,
        ver_01_03    = 10300,
        ver_01_03_01 = 10301,
        ver_01_03_02 = 10302,
        ver_01_04    = 10400,
        ver_01_04_01 = 10401,
        ver_01_04_02 = 10402,
        ver_01_05    = 10500,
        ver_01_05_01 = 10501,
        ver_01_05_02 = 10502,
        ver_01_05_03 = 10503,
        ver_01_05_05 = 10505,
        ver_01_05_06 = 10506,
    };
};
static_assert(sizeof(E_GameReleaseVersion::Type) == 4, "E_GameReleaseVersion::Type size mismatch");

}  // namespace wh::framework
