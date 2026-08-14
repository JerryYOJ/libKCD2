#include "xgenaimodule/navigation/C_ReplanMoveAreaRegistry.h"
#include "xgenaimodule/navigation/C_Navigation.h"
#include "xgenaimodule/C_XGenAIModule.h"
#include "game/S_GameContext.h"
#include <algorithm>

namespace wh::xgenaimodule::navigation {

C_ReplanMoveAreaRegistry* C_ReplanMoveAreaRegistry::GetInstance()
{
    auto* context = game::S_GameContext::GetInstance();
    auto* module = context ? context->m_pXGenAIModule : nullptr;
    auto* navigation = module ? module->m_pNavigation : nullptr;
    return navigation ? navigation->GetReplanMoveAreaRegistry() : nullptr;
}

C_ReplanMoveArea* C_ReplanMoveAreaRegistry::FindByWuid(const framework::WUID& wuid)
{
    const auto it = std::lower_bound(
        m_entries.begin(), m_entries.end(), wuid,
        [](const S_ReplanMoveAreaRegistryEntry& entry, const framework::WUID& key) {
            return entry.wuid < key;
        });
    return it != m_entries.end() && it->wuid == wuid ? it->area : nullptr;
}

}  // namespace wh::xgenaimodule::navigation
