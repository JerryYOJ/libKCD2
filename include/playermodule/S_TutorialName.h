#pragma once
#include <cstddef>
#include "../rttr/rttr_enable.h"

namespace wh::playermodule {
class S_TutorialName {
public:
    RTTR_ENABLE()  // [0..2]
    CryStringT<char> m_name;  // +0x08
};

static_assert(sizeof(S_TutorialName) == 0x10,
              "S_TutorialName size mismatch");

}  // namespace wh::playermodule
