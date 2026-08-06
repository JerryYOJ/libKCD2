#include "hooks/ActiveTriggerPortTrigger/ActiveTriggerPortTrigger.h"

#include <MinHook.h>

#include <utility>

#include "skald/SkaldRuntime.h"

namespace luautils::hooks {

bool ActiveTriggerPortTriggerHook::Install()
{
    void* target = reinterpret_cast<void*>(REL::ID(34189).address());
    if (MH_CreateHook(target, reinterpret_cast<void*>(&Trigger),
                      reinterpret_cast<void**>(&orig)) != MH_OK)
        return false;

    if (MH_EnableHook(target) == MH_OK)
        return true;

    MH_RemoveHook(target);
    return false;
}

void ActiveTriggerPortTriggerHook::Uninstall()
{
    void* target = reinterpret_cast<void*>(REL::ID(34189).address());
    MH_DisableHook(target);
    MH_RemoveHook(target);
}

void ActiveTriggerPortTriggerHook::Trigger(
    wh::conceptmodule::C_ActiveTriggerPort* port)
{
    auto capture = skald::g_skaldRuntime.CaptureOutputTrigger(port);
    orig(port);
    skald::g_skaldRuntime.EnqueueOutputTrigger(std::move(capture));
}

}  // namespace luautils::hooks
