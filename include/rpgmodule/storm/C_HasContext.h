#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Selector.h"

namespace wh::rpgmodule::storm {
class C_HasContext : public I_Selector {
public:
    ~C_HasContext() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
    std::uint8_t m_unknown08[0x10];                  // +0x8
};

static_assert(sizeof(C_HasContext) == 0x18, "C_HasContext size mismatch");

}  // namespace wh::rpgmodule::storm
