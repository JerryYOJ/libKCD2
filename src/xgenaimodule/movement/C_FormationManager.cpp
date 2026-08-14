#include "xgenaimodule/movement/C_FormationManager.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule::movement {

C_FormationManager* C_FormationManager::GetInstance()
{
    using Fn = C_FormationManager* (__fastcall*)();
    static REL::Relocation<Fn> fn{ REL::ID(98677) }; // sub_1811DC510
    return fn();
}

C_Formation* C_FormationManager::FindByWuid(const framework::WUID& wuid)
{
    using Fn = C_Formation* (__fastcall*)(C_FormationManager*, const framework::WUID*);
    static REL::Relocation<Fn> fn{ REL::ID(43276) }; // sub_1807D3648
    return fn(this, &wuid);
}

}  // namespace wh::xgenaimodule::movement
