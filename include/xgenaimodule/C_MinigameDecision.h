#pragma once

#include <cstddef>
#include <cstdint>

#include "I_StoredDecision.h"

namespace wh::xgenaimodule {

class C_MinigameDecision : public I_StoredDecision {
public:
    C_MinigameDecision();                                                // 0x1802D55A0
    ~C_MinigameDecision() override;                                      // [0] 0x18197F7D8
    void _vf1() override;
    void _vf2() override;
    void _vf3() override;
    void _vf4() override;
    void _vf5() override;
    void _vf6() override;
    void _vf7() override;
    std::uint8_t m_unknown08[0x28];                                      // +0x08
    // trio [5..7] on vtable 0x183FEF7B8
};

static_assert(sizeof(C_MinigameDecision) == 0x30,
              "C_MinigameDecision size mismatch");

} // namespace wh::xgenaimodule
