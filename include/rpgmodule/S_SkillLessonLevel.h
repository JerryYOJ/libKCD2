#pragma once
#include <cstddef>
#include <cstdint>

// -----------------------------------------------
// wh::rpgmodule::S_SkillLessonLevel
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. No vtable.
// -----------------------------------------------

namespace wh::rpgmodule {

struct S_SkillLessonLevel {
    std::int32_t m_defaultActive;                         // +0x00 RTTR "DefaultActive"
    float m_price;                                        // +0x04 RTTR "Price"
};

static_assert(offsetof(S_SkillLessonLevel, m_defaultActive) == 0x00,
              "S_SkillLessonLevel::m_defaultActive offset mismatch");
static_assert(sizeof(S_SkillLessonLevel) == 0x08,
              "S_SkillLessonLevel size mismatch");

}  // namespace wh::rpgmodule
