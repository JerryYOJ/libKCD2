#pragma once
#include <cstddef>
#include <cstdint>
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../databasemodule/C_ObjectDatabaseKeyIndexed.h"
#include "../databasemodule/C_ObjectDatabaseDefaultKeyExtractor.h"
#include "S_SkillTeacher.h"

namespace wh::rpgmodule {

using C_SkillTeacherDatabaseBase = wh::databasemodule::C_ObjectDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<S_SkillTeacher>,
          wh::databasemodule::C_ObjectDatabaseDefaultKeyExtractor<S_SkillTeacher>>;

class C_SkillTeacherDatabase : public C_SkillTeacherDatabaseBase {
public:
    ~C_SkillTeacherDatabase() override;
    RTTR_ENABLE(C_SkillTeacherDatabaseBase) // [18..20]
};

static_assert(sizeof(C_SkillTeacherDatabase) == 0x78,
              "C_SkillTeacherDatabase size mismatch");

} // namespace wh::rpgmodule
