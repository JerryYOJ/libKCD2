#include "combatmodule/C_CombatZoneDatabase.h"
#include "Offsets/Offsets.h"

namespace wh::combatmodule {

C_CombatZoneDatabase* C_CombatZoneDatabase::GetInstance()
{
    static REL::Relocation<C_CombatZoneDatabase*> inst{ REL::ID(1247641) };
    return reinterpret_cast<C_CombatZoneDatabase*>(inst.address());
}

const C_CombatZoneData& C_CombatZoneDatabase::GetById(int32_t combatZoneId)
{
    using Fn = C_CombatZoneData* (__fastcall*)(C_CombatZoneDatabase*, const int32_t*);
    static REL::Relocation<Fn> fn{ REL::ID(50580) };
    return *fn(this, &combatZoneId);
}

}  // namespace wh::combatmodule
