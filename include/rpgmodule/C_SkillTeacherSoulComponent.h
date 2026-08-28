#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <unordered_set>
#include "../game/I_EntitySideEffectCallback.h"
#include "../rttr/rttr_enable.h"
#include "E_SoulSkill.h"

namespace wh::guimodule {
struct S_EntityMapMark;
}

namespace wh::rpgmodule {

class C_Soul;

class C_SkillTeacherSoulComponent
    : public wh::game::I_EntitySideEffectCallback {
public:
    explicit C_SkillTeacherSoulComponent(C_Soul& soul);

    void OnEntitySideEffectAdded(
        std::uint8_t sideEffectId,
        wh::framework::WUID entityWuid) override;                  // [0] 0x182D29C8C
    void OnEntitySideEffectRemoved(
        std::uint8_t sideEffectId,
        wh::framework::WUID entityWuid) override;                  // [1] 0x182D29CAC
    virtual ~C_SkillTeacherSoulComponent();                        // [2] deleting 0x180A1A0A8
    RTTR_ENABLE() // [3..5]

    void StudyLesson(E_SoulSkill skill);                           // 0x182D29D74
    void VisitSkillTeacher(bool visiting);                         // 0x182D29C84
    void OpenLesson(E_SoulSkill skill);                            // 0x182D29374
    float GetLessonPrice(E_SoulSkill skill) const;                 // 0x182D281C4
    std::int32_t GetOpenLessonLevel(E_SoulSkill skill) const;      // 0x182D27F10

    C_Soul* m_pSoul;                                               // +0x08
    bool m_visitingSkillTeacher;                                   // +0x10
    std::uint8_t m_padding11[7];                                  // +0x11
    std::unordered_set<E_SoulSkill> m_unknownSkills;               // +0x18 role unresolved
    std::unordered_set<E_SoulSkill> m_openLessons;                 // +0x58
    std::unordered_set<E_SoulSkill> m_studiedLessons;              // +0x98
    std::shared_ptr<wh::guimodule::S_EntityMapMark> m_mapMark;     // +0xD8
    bool m_soulListenerConnected;                                  // +0xE8
    std::uint8_t m_paddingE9[7];                                  // +0xE9
};

static_assert(sizeof(C_SkillTeacherSoulComponent) == 0xF0,
              "C_SkillTeacherSoulComponent size mismatch");
static_assert(offsetof(C_SkillTeacherSoulComponent, m_pSoul) == 0x08,
              "C_SkillTeacherSoulComponent soul offset mismatch");
static_assert(offsetof(C_SkillTeacherSoulComponent, m_unknownSkills) == 0x18,
              "C_SkillTeacherSoulComponent first set offset mismatch");
static_assert(offsetof(C_SkillTeacherSoulComponent, m_openLessons) == 0x58,
              "C_SkillTeacherSoulComponent open-lessons offset mismatch");
static_assert(offsetof(C_SkillTeacherSoulComponent, m_studiedLessons) == 0x98,
              "C_SkillTeacherSoulComponent studied-lessons offset mismatch");
static_assert(offsetof(C_SkillTeacherSoulComponent, m_mapMark) == 0xD8,
              "C_SkillTeacherSoulComponent map-mark offset mismatch");
static_assert(offsetof(C_SkillTeacherSoulComponent, m_soulListenerConnected) == 0xE8,
              "C_SkillTeacherSoulComponent listener flag offset mismatch");

} // namespace wh::rpgmodule
