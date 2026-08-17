#pragma once

#include <cstring>

#include "MCM_API.h"
#include "crysystem/SSystemGlobalEnvironment.h"
#include "Offsets/vtables/ICVar.h"
#include "persist.h"

// Floating Damage's MCM (Mod Configuration Menu) integration.  Soft dependency
// on MCM.dll -- if it isn't installed, nothing ever broadcasts sender="MCM"
// messages, so HandleMcmMessage (registered via MCM::ListenForMessages in
// plugin.cpp) never fires and these defaults stand.  Every knob is ALSO a
// console CVar (kcse_fd_*, plugin.cpp binds this storage directly); int not
// bool because IConsole::RegisterCVarInt wants int storage.
//
// PERSISTENCE (persist.h) is MCM-ONLY by design: every menu edit is recorded
// into Mods/FloatingDamage/mod.cfg, which the engine replays next launch
// (values held by the console until our cvars register).  Console edits apply
// for the session but are NOT recorded.  BuildSettings pushes the live values
// back with SetValue so the menu shows the persisted state, not the defaults.

inline float g_minTextSizePx  = 32.0f;
inline float g_maxTextSizePx  = 48.0f;
inline float g_minScaleDamage = 40.0f;   // |amount| at/below this reads at g_minTextSizePx
inline float g_maxScaleDamage = 350.0f;  // |amount| at/above this reads at g_maxTextSizePx
inline int   g_onlyShowPlayerAttacks = 0;  // hide popups for hits the player didn't deal (taken, or NPC-vs-NPC)
inline float g_decayStartDist   = 8.0f;  // meters; popups farther than this shrink inverse-linearly (0 = decay off). Player-DEALT hits never decay.
inline float g_minDistanceScale = 40.0f; // decay floor as a percent of the damage-scaled size (slider / cvar units; *0.01 at use)

inline constexpr const char* kMcmModId              = "floating_damage";
inline constexpr const char* kMcmModName            = "Floating Damage";
inline constexpr const char* kSettingMinTextSize    = "min_text_size";
inline constexpr const char* kSettingMaxTextSize    = "max_text_size";
inline constexpr const char* kSettingMinScaleDmg    = "min_scale_damage";
inline constexpr const char* kSettingMaxScaleDmg    = "max_scale_damage";
inline constexpr const char* kSettingOnlyPlayerAtk  = "only_player_attacks";
inline constexpr const char* kSettingDecayStartDist = "decay_start_distance";
inline constexpr const char* kSettingMinDistScale   = "min_distance_scale";

// setting <-> cvar <-> storage bindings; exactly one store pointer is set per
// row.  Drives the ValueChanged write-through AND the BuildSettings SetValue
// reflection.  Store units match the MCM widget (min_distance_scale is percent).
struct S_McmBinding {
    const char* settingId;
    const char* cvarName;
    int*        intStore;
    float*      floatStore;
};
inline constexpr S_McmBinding kMcmBindings[] = {
    { kSettingMinTextSize,    "kcse_fd_min_text_size",        nullptr,                    &g_minTextSizePx },
    { kSettingMaxTextSize,    "kcse_fd_max_text_size",        nullptr,                    &g_maxTextSizePx },
    { kSettingMinScaleDmg,    "kcse_fd_min_scale_damage",     nullptr,                    &g_minScaleDamage },
    { kSettingMaxScaleDmg,    "kcse_fd_max_scale_damage",     nullptr,                    &g_maxScaleDamage },
    { kSettingOnlyPlayerAtk,  "kcse_fd_only_player_attacks",  &g_onlyShowPlayerAttacks,    nullptr },
    { kSettingDecayStartDist, "kcse_fd_decay_start_distance", nullptr,                    &g_decayStartDist },
    { kSettingMinDistScale,   "kcse_fd_min_distance_scale",   nullptr,                    &g_minDistanceScale },
};

inline void HandleMcmMessage(KCSE::Message* msg) {
    if (msg->type == MCM::kMessage_BuildSettings) {
        auto* b = static_cast<MCM::ISettingsBuilder*>(msg->data);
        b->AddMod(kMcmModId, kMcmModName);
        b->AddSlider(kMcmModId, kSettingMinTextSize, "Min Text Size",
            "Popup text size floor, in pixels (for the smallest hits).",
            16.0, 64.0, 1.0, 32, "px");
        b->AddSlider(kMcmModId, kSettingMaxTextSize, "Max Text Size",
            "Popup text size ceiling, in pixels (for the biggest hits).",
            16.0, 96.0, 1.0, 48, "px");
        b->AddSlider(kMcmModId, kSettingMinScaleDmg, "Min Scale Damage",
            "Damage at/below which the popup stays at Min Text Size.",
            0.0, 200.0, 5.0, 40, "");
        b->AddSlider(kMcmModId, kSettingMaxScaleDmg, "Max Scale Damage",
            "Damage at/above which the popup reaches Max Text Size.",
            50.0, 1000.0, 10.0, 350, "");
        b->AddToggle(kMcmModId, kSettingOnlyPlayerAtk, "Only Player Attacks",
            "Only show damage numbers for hits the player deals -- hides damage the "
            "player takes and NPC-vs-NPC fights.", false);
        b->AddSlider(kMcmModId, kSettingDecayStartDist, "Decay Start Distance",
            "Popups farther from the player than this shrink with distance "
            "(half size at double the distance). Player-dealt hits never shrink. 0 = off.",
            0.0, 50.0, 1.0, 8, "m");
        b->AddSlider(kMcmModId, kSettingMinDistScale, "Min Distance Scale",
            "Smallest a distance-shrunk popup can get, as a percentage of its normal size.",
            10.0, 100.0, 5.0, 40, "%");
        // Reflect the LIVE values (persisted edits, console edits) -- without this
        // the menu would show the Add* defaults after a restart even though the
        // settings applied.
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
            // Write THROUGH the cvar (its bound storage IS the global) so a
            // console inspection of kcse_fd_* shows the menu value too.
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
            FloatingDamage::PersistSetting(bind.cvarName, v->value, bind.floatStore != nullptr);
            break;
        }
    }
}
