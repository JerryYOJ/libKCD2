#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "S_SkillLessonLevel.h"

namespace wh::rpgmodule {

using C_SkillLessonLevelDatabaseBase = wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<S_SkillLessonLevel>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<S_SkillLessonLevel>>;

class C_SkillLessonLevelDatabase : public C_SkillLessonLevelDatabaseBase {
public:
    ~C_SkillLessonLevelDatabase() override;
    RTTR_ENABLE(C_SkillLessonLevelDatabaseBase) // [18..20]
};

static_assert(sizeof(C_SkillLessonLevelDatabase) == 0x78,
              "C_SkillLessonLevelDatabase size mismatch");

} // namespace wh::rpgmodule
