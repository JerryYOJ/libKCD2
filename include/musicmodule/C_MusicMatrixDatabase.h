#pragma once
#include <cstddef>
#include <memory>
#include <unordered_map>
#include "../crysystem/CXConsole.h"
#include "../databasemodule/C_ObjectTreeDatabase.h"
#include "../databasemodule/C_ObjectTreeDatabaseKeyIndexed.h"
#include "C_MusicMatrixRow.h"

namespace wh::musicmodule {

class C_MusicMatrixDatabase
    : public wh::databasemodule::C_ObjectTreeDatabaseKeyIndexed<
          wh::databasemodule::C_ObjectTreeDatabase<
              std::shared_ptr<C_MusicMatrixRow>>,
          std::unordered_map<int, std::shared_ptr<C_MusicMatrixRow>>>
    , public IConsoleArgumentAutoComplete {                    // +0xB8
public:
    ~C_MusicMatrixDatabase() override;                         // [0] 0x182F10224
    RTTR_ENABLE(wh::databasemodule::C_ObjectDatabaseBase)     // [18..20]

    int GetCount() const override;                             // secondary [1] 0x180BE29A0
    const char* GetValue(int index) const override;            // secondary [2] 0x182F104E4

    std::shared_ptr<C_MusicMatrixRow> m_defaultRow;            // +0xC0 empty/wildcard address row
};

static_assert(offsetof(C_MusicMatrixDatabase, m_defaultRow) == 0xC0,
              "C_MusicMatrixDatabase::m_defaultRow offset mismatch");
static_assert(sizeof(C_MusicMatrixDatabase) == 0xD0,
              "C_MusicMatrixDatabase size mismatch");

}  // namespace wh::musicmodule
