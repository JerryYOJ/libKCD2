#pragma once

#include <cstddef>
#include <cstdint>

#include "I_StoredDecision.h"

namespace wh::xgenaimodule {

class C_SelectedHorseDecision : public I_StoredDecision {
public:
    C_SelectedHorseDecision();                                           // 0x1802D5940
    ~C_SelectedHorseDecision() override;                                 // [0] 0x181998D60
    void _vf1() override;
    void _vf2() override;
    void _vf3() override;
    void _vf4() override;
    void _vf5() override;
    void _vf6() override;
    void _vf7() override;
    std::uint8_t m_unknown08[0x18];                                      // +0x08
    // trio [5..7] on vtable 0x183B41750
};

static_assert(sizeof(C_SelectedHorseDecision) == 0x20,
              "C_SelectedHorseDecision size mismatch");

} // namespace wh::xgenaimodule
