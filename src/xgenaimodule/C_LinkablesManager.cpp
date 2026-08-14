#include "xgenaimodule/C_LinkablesManager.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule {

C_LinkablesManager* C_LinkablesManager::GetInstance()
{
    using Fn = C_LinkablesManager* (__fastcall*)();
    static REL::Relocation<Fn> fn{ REL::ID(152665) }; // sub_1819E016C
    return fn();
}

C_LinkableObject* C_LinkablesManager::FindByWuid(const framework::WUID& wuid)
{
    using Fn = C_LinkableObject* (__fastcall*)(C_LinkablesManager*, const framework::WUID*);
    static REL::Relocation<Fn> fn{ REL::ID(27378) }; // sub_18047C1AC
    return fn(this, &wuid);
}

}  // namespace wh::xgenaimodule
