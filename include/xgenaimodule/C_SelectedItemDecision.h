#pragma once

#include <cstddef>
#include <cstdint>

#include "I_StoredDecision.h"

namespace wh::xgenaimodule {

class C_SelectedItemDecision : public I_StoredDecision {
public:
    C_SelectedItemDecision();                                            // 0x1802D5CE0
    ~C_SelectedItemDecision() override;                                  // [0] 0x18198ED10
    void _vf1() override;
    void _vf2() override;
    void _vf3() override;
    void _vf4() override;
    void _vf5() override;
    void _vf6() override;
    void _vf7() override;
    std::uint8_t m_unknown08[0x18];                                      // +0x08
    // trio [5..7] on vtable 0x183A596F0
};

static_assert(sizeof(C_SelectedItemDecision) == 0x20,
              "C_SelectedItemDecision size mismatch");

} // namespace wh::xgenaimodule
