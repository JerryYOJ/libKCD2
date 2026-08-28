#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Selector.h"

namespace wh::rpgmodule::storm {
class C_HasFaction : public I_Selector {
public:
    ~C_HasFaction() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
    std::uint8_t m_unknown08[0x8];                  // +0x8
};

static_assert(sizeof(C_HasFaction) == 0x10, "C_HasFaction size mismatch");

}  // namespace wh::rpgmodule::storm
