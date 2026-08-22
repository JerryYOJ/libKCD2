#pragma once

#include <cstring>

#include "MCM_API.h"
#include "crysystem/SSystemGlobalEnvironment.h"
#include "Offsets/vtables/ICVar.h"
#include "persist.h"

// TruffleHoundMutt's MCM (Mod Configuration Menu) integration.  Soft dependency on
// MCM.dll -- without it nothing ever broadcasts sender="MCM" messages, so
// HandleMcmMessage never fires and these defaults stand.  Every knob is ALSO a console
// CVar (kcse_trufflehoundmutt_*, plugin.cpp binds this storage directly).
//
// PERSISTENCE (persist.h) is MCM-ONLY by design: every menu edit is recorded into
// Mods/TruffleHoundMutt/mod.cfg, which the engine replays next launch (values held by
// the console until our cvars register).  Console edits apply for the session but are
// NOT recorded.  BuildSettings pushes the live values back with SetValue so the menu
// shows the persisted state, not the defaults.

// Balanced-by-default: the perk wall starts ON -- opting OUT is the cheat.
inline int   g_requirePerk = 1;    // wall herb tracking behind the Truffle Hound perk
inline int   g_showBeacon  = 1;    // light shaft on the found plant until the search ends
inline float g_maxRange    = 200.f; // metres from Mutt (Troskowitz→south-woods arrow)

inline constexpr const char* kMcmModId           = "trufflehoundmutt";
inline constexpr const char* kMcmModName         = "Truffle Hound Mutt";
inline constexpr const char* kSettingRequirePerk = "require_perk";
inline constexpr const char* kSettingShowBeacon  = "show_beacon";
inline constexpr const char* kSettingMaxRange    = "max_range";

// setting <-> cvar <-> storage bindings; exactly one store pointer is set per row.  Drives
// the ValueChanged write-through AND the BuildSettings SetValue reflection.
struct S_McmBinding {
    const char* settingId;
    const char* cvarName;
    int*        intStore;
    float*      floatStore;
};
inline constexpr S_McmBinding kMcmBindings[] = {
    { kSettingRequirePerk, "kcse_trufflehoundmutt_require_perk", &g_requirePerk, nullptr },
    { kSettingShowBeacon,  "kcse_trufflehoundmutt_show_beacon",  &g_showBeacon,  nullptr },
    { kSettingMaxRange,    "kcse_trufflehoundmutt_max_range",    nullptr,        &g_maxRange },
};

inline void HandleMcmMessage(KCSE::Message* msg) {
    if (msg->type == MCM::kMessage_BuildSettings) {
        auto* b = static_cast<MCM::ISettingsBuilder*>(msg->data);
        b->AddMod(kMcmModId, kMcmModName);
        b->AddCategory(kMcmModId, "Main", "");
        b->AddToggle(kMcmModId, kSettingRequirePerk, "Require the Truffle Hound Perk",
            "Mutt only tracks wild herbs from a sample after the Truffle Hound perk is "
            "bought in the Houndmaster perk tree (level 8).  Off = herb tracking "
            "available from the start.", true);
        b->AddToggle(kMcmModId, kSettingShowBeacon, "Plant Beacon",
            "Mark the plant Mutt is leading you to with a shaft of light that stays "
            "until he finishes the search.", true);
        b->AddSlider(kMcmModId, kSettingMaxRange, "Max Track Distance",
            "How far from Mutt a plant may be.  Beyond that he gives up, the same as "
            "tracking something out of the area.",
            100.0, 1000.0, 10.0, 200.0, "m");
        // Reflect the LIVE values (persisted edits, console edits) -- without this the
        // menu would show the Add* defaults after a restart.
        for (const auto& bind : kMcmBindings)
            b->SetValue(kMcmModId, bind.settingId,
                        bind.floatStore ? static_cast<double>(*bind.floatStore)
                                        : static_cast<double>(*bind.intStore));
    } else if (msg->type == MCM::kMessage_ValueChanged) {
        auto* v = static_cast<const MCM::ValueChanged*>(msg->data);
        if (std::strcmp(v->modId, kMcmModId) != 0) return;
        for (const auto& bind : kMcmBindings) {
            if (std::strcmp(v->settingId, bind.settingId) != 0)
                continue;
            // Write THROUGH the cvar (its bound storage IS the global) so a console
            // inspection of kcse_trufflehoundmutt_* shows the menu value too.
            auto* env = SSystemGlobalEnvironment::GetInstance();
            ICVar* cvar = env && env->pConsole ? env->pConsole->GetCVar(bind.cvarName) : nullptr;
            if (cvar) {
                if (bind.floatStore)
                    cvar->SetFloat(static_cast<float>(v->value));
                else
                    cvar->SetInt(static_cast<int>(v->value));
            } else {   // cvar not registered (never the case for in-game menu edits)
                if (bind.floatStore)
                    *bind.floatStore = static_cast<float>(v->value);
                else
                    *bind.intStore = static_cast<int>(v->value);
            }
            TruffleHoundMutt::PersistSetting(bind.cvarName, v->value, bind.floatStore != nullptr);
            break;
        }
    }
}
