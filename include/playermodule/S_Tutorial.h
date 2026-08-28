#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"
#include "../framework/S_TimeSpan.h"
#include "../game/E_GameMode.h"

namespace wh::playermodule {
class S_Tutorial {
public:
    virtual ~S_Tutorial();
    RTTR_ENABLE()  // [1..3]
    CryStringT<char> m_name;  // +0x8 RTTR "Name"
    bool m_remindAfterLongTime;  // +0x10 RTTR "RemindAfterLongTime"
    bool m_repeatable;  // +0x11 RTTR "Repeatable"
    std::uint8_t m_unknown12[0x6];                  // +0x12
    wh::framework::S_TimeSpan m_repeatCooldown;  // +0x18 RTTR "RepeatCooldown"
    wh::game::E_GameMode::Type m_gameModeFilter;  // +0x20 RTTR "GameModeFilter"
    std::uint8_t m_unknown24[0x4];                  // +0x24
};

static_assert(offsetof(S_Tutorial, m_repeatCooldown) == 0x18, "S_Tutorial::m_repeatCooldown offset mismatch");
static_assert(offsetof(S_Tutorial, m_repeatable) == 0x11, "S_Tutorial::m_repeatable offset mismatch");
static_assert(offsetof(S_Tutorial, m_remindAfterLongTime) == 0x10, "S_Tutorial::m_remindAfterLongTime offset mismatch");
static_assert(offsetof(S_Tutorial, m_name) == 0x8, "S_Tutorial::m_name offset mismatch");
static_assert(sizeof(S_Tutorial) == 0x28, "S_Tutorial size mismatch");

}  // namespace wh::playermodule
