#include "TrackItemFilter.h"

#include <MinHook.h>

#include "entitymodule/C_Item.h"
#include "entitymodule/S_ItemClass.h"

#include "TruffleHoundMutt.h"

namespace hooks {

bool TrackItemFilterHook::Install()
{
    void* target = reinterpret_cast<void*>(REL::ID(194228).address());
    if (MH_CreateHook(target, reinterpret_cast<void*>(&TrackItemFilter),
                      reinterpret_cast<void**>(&orig)) != MH_OK)
        return false;

    return MH_EnableHook(target) == MH_OK;
}

void TrackItemFilterHook::Uninstall()
{
    MH_RemoveHook(reinterpret_cast<void*>(REL::ID(194228).address()));
}

bool TrackItemFilterHook::TrackItemFilter(void* funcImpl, wh::entitymodule::C_Item* item)
{
    if (orig(funcImpl, item))
        return true;
    auto* cls = item ? item->GetClassData() : nullptr;
    return cls && TruffleHoundMutt::AllowHerb(cls->m_guid);
}

}  // namespace hooks
