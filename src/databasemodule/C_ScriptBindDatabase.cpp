#include "databasemodule/C_ScriptBindDatabase.h"
#include "Offsets/Offsets.h"

namespace wh::databasemodule {

int C_ScriptBindDatabase::LoadTable(Offsets::IFunctionHandler* function, const char* tableName)
{
    using Fn = int (__fastcall*)(C_ScriptBindDatabase*, Offsets::IFunctionHandler*, const char*);
    static REL::Relocation<Fn> fn{ REL::ID(328660) };
    return fn(this, function, tableName);
}

int C_ScriptBindDatabase::GetTableInfo(Offsets::IFunctionHandler* function, const char* tableName)
{
    using Fn = int (__fastcall*)(C_ScriptBindDatabase*, Offsets::IFunctionHandler*, const char*);
    static REL::Relocation<Fn> fn{ REL::ID(328658) };
    return fn(this, function, tableName);
}

int C_ScriptBindDatabase::GetColumnInfo(Offsets::IFunctionHandler* function, const char* tableName,
                                        int32_t columnIndex)
{
    using Fn = int (__fastcall*)(C_ScriptBindDatabase*, Offsets::IFunctionHandler*, const char*, int32_t);
    static REL::Relocation<Fn> fn{ REL::ID(328656) };
    return fn(this, function, tableName, columnIndex);
}

int C_ScriptBindDatabase::GetTableLine(Offsets::IFunctionHandler* function, const char* tableName,
                                       uint32_t rowIndex)
{
    using Fn = int (__fastcall*)(C_ScriptBindDatabase*, Offsets::IFunctionHandler*, const char*, uint32_t);
    static REL::Relocation<Fn> fn{ REL::ID(328659) };
    return fn(this, function, tableName, rowIndex);
}

int C_ScriptBindDatabase::GetTableColumnData(Offsets::IFunctionHandler* function, const char* tableName,
                                             int32_t columnIndex)
{
    using Fn = int (__fastcall*)(C_ScriptBindDatabase*, Offsets::IFunctionHandler*, const char*, int32_t);
    static REL::Relocation<Fn> fn{ REL::ID(328657) };
    return fn(this, function, tableName, columnIndex);
}

}  // namespace wh::databasemodule
