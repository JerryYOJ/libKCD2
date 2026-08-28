#pragma once
#include <cstddef>
#include <memory>
#include <set>
#include <unordered_map>
#include "../crysystem/CXConsole.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../databasemodule/C_ObjectTreeDatabaseKeyIndexed.h"
#include "C_WorldStateToggle.h"

namespace wh::musicmodule {

class C_WorldStateTogglesDatabase
    : public wh::databasemodule::C_ObjectTreeDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<
              std::shared_ptr<C_WorldStateToggle>>,
          std::unordered_map<int, std::shared_ptr<C_WorldStateToggle>>>
    , public IConsoleArgumentAutoComplete {                    // +0xB8
public:
    ~C_WorldStateTogglesDatabase() override;                   // [0] 0x182F230C0
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase)     // [18..20]

    int GetCount() const override;                             // secondary [1] 0x180BE29A0
    const char* GetValue(int index) const override;            // secondary [2] 0x180C9C484

    std::set<int> m_deferredFlagDownIds;                       // +0xC0 drained during Update
};

static_assert(offsetof(C_WorldStateTogglesDatabase,
                       m_deferredFlagDownIds) == 0xC0,
              "C_WorldStateTogglesDatabase::m_deferredFlagDownIds offset mismatch");
static_assert(sizeof(C_WorldStateTogglesDatabase) == 0xD0,
              "C_WorldStateTogglesDatabase size mismatch");

}  // namespace wh::musicmodule
