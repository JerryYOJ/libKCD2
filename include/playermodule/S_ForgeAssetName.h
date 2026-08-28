#pragma once
#include <cstddef>
#include "../rttr/rttr_enable.h"

namespace wh::playermodule {
class S_ForgeAssetName {
public:
    RTTR_ENABLE()  // [0..2]
    CryStringT<char> m_name;  // +0x08
};

static_assert(sizeof(S_ForgeAssetName) == 0x10,
              "S_ForgeAssetName size mismatch");

}  // namespace wh::playermodule
