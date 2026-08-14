#include "xgenaimodule/C_IntelligentObjectManager.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule {

C_IntelligentObjectManager* C_IntelligentObjectManager::GetInstance()
{
    using Fn = C_IntelligentObjectManager* (__fastcall*)();
    static REL::Relocation<Fn> fn{ REL::ID(171675) }; // sub_181AA20A0
    return fn();
}

C_IntelligentObject* C_IntelligentObjectManager::FindByWuid(const framework::WUID& wuid)
{
    using Fn = C_IntelligentObject* (__fastcall*)(C_IntelligentObjectManager*, const framework::WUID*);
    static REL::Relocation<Fn> fn{ REL::ID(39016) }; // sub_18070DB90
    return fn(this, &wuid);
}

}  // namespace wh::xgenaimodule
