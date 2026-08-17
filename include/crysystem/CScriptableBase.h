#pragma once
#include <cstddef>
#include <cstdint>
#include "../Offsets/vtables/IScriptTable.h"
#include "../Offsets/vtables/IScriptSystem.h"

class ICrySizer;
namespace Offsets { struct ISystem; }

// CryEngine ScriptBind base. KCD2 table has exactly four slots.
class CScriptableBase {
public:
    virtual ~CScriptableBase(); // [0]
    virtual void Init(Offsets::IScriptSystem* scriptSystem,
                      Offsets::ISystem* system,
                      std::int32_t nParamIdOffset); // [1] 0x18144CE0C
    virtual void Done(); // [2] 0x1819D5648
    virtual void GetMemoryStatistics(ICrySizer* sizer); // [3] 0x1803B6E80

    char m_sGlobalName[64];                  // +0x08
    Offsets::IScriptTable* m_pMethodsTable;  // +0x48, retained
    Offsets::IScriptSystem* m_pSS;           // +0x50, borrowed
    std::int32_t m_nParamIdOffset;           // +0x58
    std::uint32_t _pad5C;                    // +0x5C
};
static_assert(sizeof(CScriptableBase) == 0x60,
              "CScriptableBase must be 0x60");
static_assert(offsetof(CScriptableBase, m_pMethodsTable) == 0x48,
              "scriptable methods table must be at 0x48");
static_assert(offsetof(CScriptableBase, m_nParamIdOffset) == 0x58,
              "script parameter-ID offset must be at 0x58");
