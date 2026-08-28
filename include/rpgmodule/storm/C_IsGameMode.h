#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Selector.h"
#include "../../game/E_GameMode.h"

namespace wh::rpgmodule::storm {
class C_IsGameMode : public I_Selector {
public:
    ~C_IsGameMode() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
    wh::game::E_GameMode::Type m_mode;  // +0x8 RTTR "mode"
    std::uint8_t m_unknown0C[0x4];                  // +0xC
};

static_assert(offsetof(C_IsGameMode, m_mode) == 0x8, "C_IsGameMode::m_mode offset mismatch");
static_assert(sizeof(C_IsGameMode) == 0x10, "C_IsGameMode size mismatch");

}  // namespace wh::rpgmodule::storm
