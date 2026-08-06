// LuaUtils - KCSE plugin exposing the item/equipment Lua API the vanilla
// surface lacks (per-instance equip status, item stats, sanctioned setters).
//
// Registration:
//  - ItemManager (vanilla global, extended): MinHook on the C_ScriptBindItemManager
//    fn-table registrar - after the original registers the 7 vanilla fns, our
//    descriptors are added into the same methods table (CScriptableBase+0x48).
//    KCSE loads plugins from the dinput8 proxy at process start, before the
//    bind factory runs, so the hook always catches the registration.
//  - EquipmentManager (new global): MCM SetGlobalAny pattern at PreDataLoaded.

#include <MinHook.h>

#include "KCSE/KCSEAPI.h"
#include "REL.h"
#include "crysystem/CScriptableBase.h"
#include "crysystem/SSystemGlobalEnvironment.h"
#include "entitymodule/C_ScriptBindItemManager.h"
#include "playermodule/C_ScriptBindMinigame.h"
#include "audio/AudioManager.h"
#include "hooks/ActiveTriggerPortTrigger/ActiveTriggerPortTrigger.h"
#include "scriptbind/ScriptBind_AudioManager.h"
#include "scriptbind/ScriptBind_EquipmentManager.h"
#include "scriptbind/ScriptBind_ItemManager.h"
#include "scriptbind/ScriptBind_Minigame.h"
#include "scriptbind/ScriptBind_RTTR.h"
#include "scriptbind/ScriptBind_SKALD.h"

// ------------------------------------------------------------------ hooks ---

namespace {

    class {
    public:
        static bool Install() {
            void* target = reinterpret_cast<void*>(REL::ID(104708).address());  // 0x1812B2D38
            if (MH_CreateHook(target, reinterpret_cast<void*>(&RegisterFunctions),
                              reinterpret_cast<void**>(&orig)) != MH_OK)
                return false;

            return MH_EnableHook(target) == MH_OK;
        }

    protected:
        static void RegisterFunctions(wh::entitymodule::C_ScriptBindItemManager* self) {
            orig(self);
            luautils::g_itemManagerExt.Attach(self->m_pSS, self->m_pMethodsTable);
        }

        static inline REL::Relocation<decltype(&RegisterFunctions)> orig;
    } hkItemManagerRegisterFunctions;

    class {
    public:
        static bool Install() {
            void* target = reinterpret_cast<void*>(REL::ID(136563).address());  // 0x181795808
            if (MH_CreateHook(target, reinterpret_cast<void*>(&RegisterFunctions),
                              reinterpret_cast<void**>(&orig)) != MH_OK)
                return false;

            return MH_EnableHook(target) == MH_OK;
        }

    protected:
        static void RegisterFunctions(wh::playermodule::C_ScriptBindMinigame* self) {
            orig(self);
            luautils::g_minigameExt.Attach(self->m_pSS, self->m_pMethodsTable);
        }

        static inline REL::Relocation<decltype(&RegisterFunctions)> orig;
    } hkMinigameRegisterFunctions;

    bool g_audioTickQueued = false;
    bool g_skaldTickQueued = false;

    void TickAudio()
    {
        luautils::audio::g_audioManager.Tick();
        if (auto* tasks = KCSE::GetTaskInterface())
            tasks->AddTask(&TickAudio);
    }

    void TickSkald()
    {
        luautils::skald::g_skaldRuntime.DeliverQueuedEvents();
        if (auto* tasks = KCSE::GetTaskInterface())
            tasks->AddTask(&TickSkald);
    }

}  // namespace

// -------------------------------------------------------------- KCSE glue ---

static void InitScriptBinds()
{
    if (auto* env = SSystemGlobalEnvironment::GetInstance(); env && env->pScriptSystem) {
        if (!luautils::g_rttrBind.IsInitialized())
            luautils::g_rttrBind.Init(env->pScriptSystem);
        if (!luautils::g_skaldBind.IsInitialized())
            luautils::g_skaldBind.Init(env->pScriptSystem);
        if (!luautils::g_equipmentManagerBind.IsInitialized())
            luautils::g_equipmentManagerBind.Init(env->pScriptSystem);
        if (!luautils::g_audioManagerBind.IsInitialized())
            luautils::g_audioManagerBind.Init(env->pScriptSystem);

        // KCD2 executes Scripts/Mods/luautils.lua from the mounted mod PAK
        // after PreDataLoaded returns. That script owns the generated RTTR-first,
        // SKALD-second module order.
    }
}

KCSE_PLUGIN_INFO("LuaUtils", "JerryYOJ", 1);

KCSE_PLUGIN_LOAD(kcse)
{
    if (MH_Initialize() != MH_OK)
        return false;
    if (!hkItemManagerRegisterFunctions.Install())
        return false;
    if (!hkMinigameRegisterFunctions.Install())
        return false;
    if (!luautils::hooks::ActiveTriggerPortTriggerHook::Install())
        return false;

    kcse->GetMessagingInterface()->RegisterListener([](KCSE::Message* msg) {
        switch (msg->type) {
        case KCSE::IMessagingInterface::kMessage_PreDataLoaded:
            InitScriptBinds();
            if (!g_audioTickQueued) {
                if (auto* tasks = KCSE::GetTaskInterface()) {
                    g_audioTickQueued = true;
                    tasks->AddTask(&TickAudio);
                }
            }
            if (!g_skaldTickQueued) {
                if (auto* tasks = KCSE::GetTaskInterface()) {
                    g_skaldTickQueued = true;
                    tasks->AddTask(&TickSkald);
                }
            }
            break;
        case KCSE::IMessagingInterface::kMessage_LoadGame:
        case KCSE::IMessagingInterface::kMessage_NewGame:
            luautils::g_skaldBind.ClearRuntime();
            luautils::g_rttrBind.ClearHandles();
            break;
        default:
            break;
        }
    });
    return true;
}
