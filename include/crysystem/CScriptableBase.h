#pragma once
#include <cstdint>
#include "../Offsets/vtables/IScriptTable.h"
#include "../Offsets/vtables/IScriptSystem.h"

// CScriptableBase -- CryEngine ScriptBind base (KCD2 WHGame.dll 1.5.6, kd7u).
// sizeof 0x60; vtable 0x183AA4AD8, exactly four slots.

namespace Offsets { struct ISystem; }

class CScriptableBase {
public:
    virtual ~CScriptableBase();  // [0] per-class scalar-deleting destructor
    virtual void Init(Offsets::IScriptSystem* scriptSystem, Offsets::ISystem* system,
                      int32_t instanceMethods);  // [1] 0x18144CE0C
    virtual void Done();  // [2] 0x1819D5648
    virtual void unk_03();  // [3] 0x1803B6E80

    char                    m_sGlobalName[64];   // +0x08
    Offsets::IScriptTable*  m_pMethodsTable;    // +0x48
    Offsets::IScriptSystem* m_pSS;              // +0x50
    int32_t                 m_bInstanceMethods; // +0x58
    uint32_t                _pad5C;             // +0x5C
};
static_assert(sizeof(CScriptableBase) == 0x60, "CScriptableBase must be 0x60");
static_assert(offsetof(CScriptableBase, m_pMethodsTable) == 0x48, "methods table at 0x48");
