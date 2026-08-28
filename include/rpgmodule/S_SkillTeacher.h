#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "S_SkillTeacherLesson.h"

namespace wh::rpgmodule {
struct S_SkillTeacher {
    CryGUID m_level;  // +0x0 RTTR "Level"
    bool m_defaultActive;  // +0x10 RTTR "DefaultActive"
    std::uint8_t m_unknown11[0x7];                  // +0x11
    std::vector<S_SkillTeacherLesson> m_lessons;  // +0x18 RTTR "Lessons"
};

static_assert(offsetof(S_SkillTeacher, m_lessons) == 0x18, "S_SkillTeacher::m_lessons offset mismatch");
static_assert(offsetof(S_SkillTeacher, m_defaultActive) == 0x10, "S_SkillTeacher::m_defaultActive offset mismatch");
static_assert(offsetof(S_SkillTeacher, m_level) == 0x0, "S_SkillTeacher::m_level offset mismatch");
static_assert(sizeof(S_SkillTeacher) == 0x30, "S_SkillTeacher size mismatch");

}  // namespace wh::rpgmodule
