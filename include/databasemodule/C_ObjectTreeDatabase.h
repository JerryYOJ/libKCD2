#pragma once
#include <cstdint>
#include "C_ObjectDatabase.h"
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::databasemodule::C_ObjectTreeDatabase<TObject> -- name-registered tree database layer
// (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// RTTI: .?AV?$C_ObjectTreeDatabase@V<Row>@...@Vvector@std@@@databasemodule@wh@@ (row types seen:
// rpgmodule::C_SoulStateEffectContextData, combatmodule::C_CombatCombo,
// C_CombatFragmentMetaData, C_CombatAnimationStepData, ...).  Sibling of C_ObjectTableDatabase:
// where table databases bind to a .tbl/.xml table, tree databases register BY CLASS NAME with
// namespace/name/group strings (CryStringT, not the table layer's std::string).
// Layout from C_SoulStateEffectContextDatabase's ctor sub_180F9FCB4 (global @0x185330430):
// base ctor sub_180EF4F30(this, 1), rows vector zeroed @+0x30 (C_ObjectDatabase layer), then
// +0x48 ns ("wh::rpgmodule::"), +0x50 name ("SoulStateEffectContext"), +0x58 group ("rpg"),
// +0x60 byte 0, +0x68 = sub_1803F7FAC() allocation [tree root INFERRED from the class name],
// +0x70 zeroed.

namespace wh::databasemodule {

template <typename TObject>
class C_ObjectTreeDatabase : public C_ObjectDatabase<TObject> {
public:
    CryStringT<char> m_namespace;   // +0x48  e.g. "wh::rpgmodule::"
    CryStringT<char> m_name;        // +0x50  e.g. "SoulStateEffectContext"
    CryStringT<char> m_group;       // +0x58  e.g. "rpg"
    uint8_t  m_flag60;              // +0x60  ctor 0 [role UNVERIFIED]
    uint8_t  _pad61[7];             // +0x61
    void*    m_pRoot;               // +0x68  sub_1803F7FAC() allocation [tree root INFERRED]
    uint64_t m_unk70;               // +0x70  ctor 0 [role UNVERIFIED]
};

}  // namespace wh::databasemodule
