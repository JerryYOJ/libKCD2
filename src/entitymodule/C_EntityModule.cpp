#include "entitymodule/C_EntityModule.h"
#include "game/S_GameContext.h"
#include "Offsets/Offsets.h"

namespace wh::entitymodule {

C_EntityModule* C_EntityModule::GetInstance()
{
    auto* context = game::S_GameContext::GetInstance();
    return context ? context->m_pEntityModule : nullptr;
}

C_ItemCollection* C_EntityModule::FindItemCollectionByWuid(framework::WUID wuid)
{
    using Fn = C_ItemCollection* (__fastcall*)(C_EntityModule*, framework::WUID);
    static REL::Relocation<Fn> fn{ REL::ID(65840) }; // sub_180C48338
    return fn(this, wuid);
}

}  // namespace wh::entitymodule
