#include "FlashInit.h"

#include <MinHook.h>

#include "FastTravel.h"
#include "KCSE/KCSEAPI.h"
#include "CryEngine/CryCommon/CFlashPlayer.h"
#include "CryEngine/CryCommon/SFlashVarValue.h"
#include "Offsets/vtables/IFlashPlayer.h"
#include "Offsets/vtables/IFlashVariableObject.h"

using Offsets::FlashVarPtr;

namespace hooks {

bool FlashInitHook::Install()
{
    void* target = reinterpret_cast<void*>(REL::ID(24).address());
    if (MH_CreateHook(target, reinterpret_cast<void*>(&Init),
                      reinterpret_cast<void**>(&orig)) != MH_OK)
        return false;
    return MH_EnableHook(target) == MH_OK;
}

void FlashInitHook::Uninstall()
{
    MH_RemoveHook(reinterpret_cast<void*>(REL::ID(24).address()));
}

bool FlashInitHook::Init(CFlashUIElement* self, bool load)
{
    const bool ok = orig(self, load);
    if (!ok || !load)
        return ok;
    if (self->m_sName != "ApseMap")
        return ok;

    const auto& fp = self->m_pFlashPlayer;
    if (!fp)
        return ok;

    if (!fp->IsAvailable("_root.map.navOverlay"))
    {
        FlashVarPtr map;
        if (fp->GetVariable("_root.map", map.put()) && map)
        {
            FlashVarPtr ov;
            if (map->CreateEmptyMovieClip(ov.put(), "navOverlay") && ov)
            {
                SFlashVarValue url("navigation.gfx");
                if (ov->Invoke("loadMovie", &url, 1))
                {
                    if (auto* movie = static_cast<CFlashPlayer*>(fp.get())->GetMovieRoot())
                        movie->ProcessLoadQueue();
                }
            }
        }
    }

    if (auto* tasks = KCSE::GetTaskInterface())
        tasks->AddTask(&FastTravel::RestoreOnInit);
    return ok;
}

}  // namespace hooks
