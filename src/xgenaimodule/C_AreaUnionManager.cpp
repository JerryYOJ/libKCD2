#include "xgenaimodule/C_AreaUnionManager.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule {

C_AreaUnionManager* C_AreaUnionManager::GetInstance()
{
    using Fn = C_AreaUnionManager* (__fastcall*)();
    static REL::Relocation<Fn> fn{ REL::ID(97304) }; // 0x1811A47C8
    return fn();
}

C_AreaUnion* C_AreaUnionManager::Create(Offsets::IEntity* entity)
{
    using Fn = C_AreaUnion* (__fastcall*)(C_AreaUnionManager*, Offsets::IEntity*);
    static REL::Relocation<Fn> fn{ REL::ID(97319) }; // 0x1811A4DF4
    return fn(this, entity);
}

}  // namespace wh::xgenaimodule
