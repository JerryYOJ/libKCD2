#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Selector.h"

namespace wh::rpgmodule::storm {
class C_HasFactionLabel : public I_Selector {
public:
    ~C_HasFactionLabel() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
    std::uint8_t m_unknown08[0x8];                  // +0x8
};

static_assert(sizeof(C_HasFactionLabel) == 0x10, "C_HasFactionLabel size mismatch");

}  // namespace wh::rpgmodule::storm
