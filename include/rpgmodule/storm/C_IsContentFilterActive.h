#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Selector.h"

namespace wh::rpgmodule::storm {
class C_IsContentFilterActive : public I_Selector {
public:
    ~C_IsContentFilterActive() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
    std::uint8_t m_unknown08[0x8];                  // +0x8
};

static_assert(sizeof(C_IsContentFilterActive) == 0x10, "C_IsContentFilterActive size mismatch");

}  // namespace wh::rpgmodule::storm
