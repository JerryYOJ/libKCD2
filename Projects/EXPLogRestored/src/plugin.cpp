#include <MinHook.h>

#include "KCSE/KCSEAPI.h"
#include "REL.h"

#include "framework/C_GameEventLog.h"
#include "framework/C_TextEvent.h"
#include "game/S_GameContext.h"

namespace {

// C_TextEvent ctor. All 9 retail callers omit the KCD1 dispatch walk and only
// set dispatcher+0x18. No other code xrefs exist.
class {
public:
    static bool Install()
    {
        void* target = reinterpret_cast<void*>(REL::ID(66746).address());
        if (MH_CreateHook(target, reinterpret_cast<void*>(&C_TextEvent),
            reinterpret_cast<void**>(&orig)) != MH_OK)
            return false;
        return MH_EnableHook(target) == MH_OK;
    }

    static void Uninstall()
    {
        void* target = reinterpret_cast<void*>(REL::ID(66746).address());
        MH_RemoveHook(target);
    }

protected:
    static wh::framework::C_TextEvent* C_TextEvent(
        wh::framework::C_TextEvent* self,
        int32_t type,
        int32_t subtype,
        int32_t level,
        CryStringT<char>* text)
    {
        wh::framework::C_TextEvent* event = orig(self, type, subtype, level, text);
        if (wh::game::S_GameContext* ctx = wh::game::S_GameContext::GetInstance())
        {
            if (wh::framework::C_GameEventLog* log = ctx->m_pGameEventLog)
                log->Dispatch(*event);
        }
        return event;
    }

    static inline REL::Relocation<decltype(&C_TextEvent)> orig;
} hkTextEvent;

}  // namespace

bool InstallHooks()
{
    if (MH_Initialize() != MH_OK)
        return false;
    return hkTextEvent.Install();
}

KCSE_PLUGIN_INFO("EXPLogRestored", "JerryYOJ", 1);
KCSE_PLUGIN_LOAD(kcse)
{
    return InstallHooks();
}
