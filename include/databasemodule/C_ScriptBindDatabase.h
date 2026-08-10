#pragma once
#include <cstddef>
#include "I_DatabaseModule.h"
#include "../crysystem/CScriptableBase.h"
#include "../Offsets/vtables/IFunctionHandler.h"

// wh::databasemodule::C_ScriptBindDatabase -- Lua global `Database` binding.
// sizeof 0x68 (allocation at 0x180EF600D); vtable 0x183ACE0F8, four slots.

namespace wh::databasemodule {

class C_ScriptBindDatabase : public ::CScriptableBase {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ScriptBindDatabase;

    int LoadTable(Offsets::IFunctionHandler* function, const char* tableName);  // 0x182748F38
    int GetTableInfo(Offsets::IFunctionHandler* function, const char* tableName);  // 0x182748C18
    int GetColumnInfo(Offsets::IFunctionHandler* function, const char* tableName,
                      int32_t columnIndex);  // 0x1827488D0
    int GetTableLine(Offsets::IFunctionHandler* function, const char* tableName,
                     uint32_t rowIndex);  // 0x182748D24
    int GetTableColumnData(Offsets::IFunctionHandler* function, const char* tableName,
                           int32_t columnIndex);  // 0x1827489F0

    I_DatabaseModule* m_pDatabaseModule;  // +0x60, borrowed
};
static_assert(sizeof(C_ScriptBindDatabase) == 0x68, "C_ScriptBindDatabase must be 0x68");
static_assert(offsetof(C_ScriptBindDatabase, m_pDatabaseModule) == 0x60,
              "database module pointer at 0x60");

}  // namespace wh::databasemodule
