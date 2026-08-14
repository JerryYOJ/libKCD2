#include "xgenaimodule/C_DynamicLinkablesManager.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule {

C_DynamicLinkablesManager* C_DynamicLinkablesManager::GetInstance()
{
    static REL::Relocation<C_DynamicLinkablesManager**> instance{ REL::ID(1270288) }; // qword_1854961A0
    return *instance;
}

C_DynamicLinkableObject* C_DynamicLinkablesManager::FindByWuid(const framework::WUID& wuid)
{
    using Fn = C_DynamicLinkableObject* (__fastcall*)(C_DynamicLinkablesManager*, const framework::WUID*);
    static REL::Relocation<Fn> fn{ REL::ID(27375) }; // sub_18047C068
    return fn(this, &wuid);
}

}  // namespace wh::xgenaimodule
