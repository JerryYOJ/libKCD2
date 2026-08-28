#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Selector.h"

namespace wh::rpgmodule::storm {
class C_HasName : public I_Selector {
public:
    ~C_HasName() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
    std::uint8_t m_unknown08[0x18];                  // +0x8
};

static_assert(sizeof(C_HasName) == 0x20, "C_HasName size mismatch");

}  // namespace wh::rpgmodule::storm
