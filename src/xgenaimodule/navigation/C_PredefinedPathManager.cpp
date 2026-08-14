#include "xgenaimodule/navigation/C_PredefinedPathManager.h"
#include "xgenaimodule/navigation/C_Navigation.h"
#include "xgenaimodule/navigation/C_PathManager.h"
#include "xgenaimodule/C_XGenAIModule.h"
#include "game/S_GameContext.h"
#include "Offsets/Offsets.h"

namespace wh::xgenaimodule::navigation {

C_PredefinedPathManager* C_PredefinedPathManager::GetInstance()
{
    auto* context = game::S_GameContext::GetInstance();
    auto* module = context ? context->m_pXGenAIModule : nullptr;
    auto* navigation = module ? module->m_pNavigation : nullptr;
    auto* pathManager = navigation ? navigation->GetPathManager() : nullptr;
    return pathManager ? pathManager->GetPredefinedPathManager() : nullptr;
}

C_PredefinedPath* C_PredefinedPathManager::FindByWuid(const framework::WUID& wuid)
{
    using Fn = C_PredefinedPath* (__fastcall*)(C_PredefinedPathManager*, const framework::WUID*);
    static REL::Relocation<Fn> fn{ REL::ID(77752) }; // sub_180E5E9B4
    return fn(this, &wuid);
}

}  // namespace wh::xgenaimodule::navigation
