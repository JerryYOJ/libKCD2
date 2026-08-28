#pragma once

#include <cstddef>
#include <vector>

#include "../databasemodule/C_ObjectDatabaseBase.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "S_ScriptParam.h"

namespace wh::xgenaimodule {

using C_ScriptParamDatabaseBase =
    wh::databasemodule::C_ObjectTreeDatabase<S_ScriptParam, std::vector>;

class C_ScriptParamDatabase : public C_ScriptParamDatabaseBase {
public:
    ~C_ScriptParamDatabase() override;
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase)                    // [18..20], vtable 0x183BB08F0
};

static_assert(sizeof(C_ScriptParamDatabase) == 0x78,
              "C_ScriptParamDatabase size mismatch");

} // namespace wh::xgenaimodule
