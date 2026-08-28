#pragma once
#include <cstdint>

// RTTR labels, values, and underlying type recovered from WHGame.dll
// Steam 1.5.6. Scopedness follows the verified reflected-enum corpus.

namespace wh::dialogmodule::data {

struct E_DecisionPriority {
    enum Type : std::uint8_t {
        MainQuestAssignment  = 0,
        MainQuestSubmission  = 1,
        MainQuestAdditionals = 2,
        SideQuestAssignment  = 3,
        SideQuestSubmission  = 4,
        SideQuestAdditionals = 5,
        Default              = 6,
        General              = 7,
        QuestGiver           = 8,
        SkillTraining        = 9,
        Shop                 = 10,
        Repair               = 11,
    };
};
static_assert(sizeof(E_DecisionPriority::Type) == 1, "E_DecisionPriority::Type size mismatch");

}  // namespace wh::dialogmodule::data
