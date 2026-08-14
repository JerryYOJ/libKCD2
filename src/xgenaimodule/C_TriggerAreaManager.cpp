#include "xgenaimodule/C_TriggerAreaManager.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule {

C_TriggerAreaManager* C_TriggerAreaManager::GetInstance()
{
    using Fn = C_TriggerAreaManager* (__fastcall*)();
    static REL::Relocation<Fn> fn{ REL::ID(87893) }; // sub_181008984
    return fn();
}

C_TriggerArea* C_TriggerAreaManager::FindByWuid(const framework::WUID& wuid)
{
    using Fn = C_TriggerArea* (__fastcall*)(C_TriggerAreaManager*, framework::WUID);
    static REL::Relocation<Fn> fn{ REL::ID(51773) }; // sub_18096BF40
    return fn(this, wuid);
}

}  // namespace wh::xgenaimodule
