#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {
class S_LayerProfile {
public:
    RTTR_ENABLE()  // [0..2]
    CryStringT<char> m_name;  // +0x8 RTTR "Name"
};

static_assert(offsetof(S_LayerProfile, m_name) == 0x8, "S_LayerProfile::m_name offset mismatch");
static_assert(sizeof(S_LayerProfile) == 0x10, "S_LayerProfile size mismatch");

}  // namespace wh::entitymodule
