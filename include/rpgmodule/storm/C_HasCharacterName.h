#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Selector.h"

namespace wh::rpgmodule::storm {
class C_HasCharacterName : public I_Selector {
public:
    ~C_HasCharacterName() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
    std::uint8_t m_unknown08[0x30];                  // +0x8
};

static_assert(sizeof(C_HasCharacterName) == 0x38, "C_HasCharacterName size mismatch");

}  // namespace wh::rpgmodule::storm
