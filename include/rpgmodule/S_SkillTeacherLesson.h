#pragma once
#include <cstddef>
#include <cstdint>
#include "E_SoulSkill.h"

namespace wh::rpgmodule {
struct S_SkillTeacherLesson {
    E_SoulSkill m_lesson;  // +0x0 RTTR "wh::rpgmodule::SkillTeacher::Lesson"
    std::int32_t m_level;  // +0x4 RTTR "Level"
    bool m_defaultOpen;  // +0x8 RTTR "DefaultOpen"
    bool m_defaultKnown;  // +0x9 RTTR "DefaultKnown"
    std::uint8_t m_unknown0A[0x2];                  // +0xA
};

static_assert(offsetof(S_SkillTeacherLesson, m_defaultKnown) == 0x9, "S_SkillTeacherLesson::m_defaultKnown offset mismatch");
static_assert(offsetof(S_SkillTeacherLesson, m_defaultOpen) == 0x8, "S_SkillTeacherLesson::m_defaultOpen offset mismatch");
static_assert(offsetof(S_SkillTeacherLesson, m_level) == 0x4, "S_SkillTeacherLesson::m_level offset mismatch");
static_assert(offsetof(S_SkillTeacherLesson, m_lesson) == 0x0, "S_SkillTeacherLesson::m_lesson offset mismatch");
static_assert(sizeof(S_SkillTeacherLesson) == 0xc, "S_SkillTeacherLesson size mismatch");

}  // namespace wh::rpgmodule
