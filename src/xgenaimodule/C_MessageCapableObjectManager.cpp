#include "xgenaimodule/C_MessageCapableObjectManager.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule {

C_MessageCapableObjectManager* C_MessageCapableObjectManager::GetInstance()
{
    static REL::Relocation<C_MessageCapableObjectManager**> instance{ REL::ID(1270287) }; // qword_185496198
    return *instance;
}

C_MessageCapableObject* C_MessageCapableObjectManager::FindByWuid(const framework::WUID& wuid)
{
    using Fn = C_MessageCapableObject* (__fastcall*)(C_MessageCapableObjectManager*, const framework::WUID*);
    static REL::Relocation<Fn> fn{ REL::ID(39016) }; // sub_18070DB90
    return fn(this, &wuid);
}

}  // namespace wh::xgenaimodule
