#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::playermodule {

class C_TutorialManager {
public:
    virtual ~C_TutorialManager();                           // [0]
    RTTR_ENABLE()                                           // [1..3]

    std::uint8_t m_unknown08[0x48];                         // +0x08
};

static_assert(sizeof(C_TutorialManager) == 0x50,
              "C_TutorialManager size mismatch");

}  // namespace wh::playermodule
