#pragma once

#include <cstring>

#include "MCM_API.h"
#include "crysystem/SSystemGlobalEnvironment.h"
#include "Offsets/vtables/ICVar.h"
#include "persist.h"

inline float g_factor = 1.0f;
inline float g_tScale = 1.0f;
inline float g_shakeScale = 1.0f;

inline constexpr const char* kMcmModId = "LockpickingOverhaul";
inline constexpr const char* kMcmModName = "LockpickingOverhaul";
inline constexpr const char* kSettingFactor = "factor";
inline constexpr const char* kSettingTScale = "t_scale";
inline constexpr const char* kSettingShakeScale = "shake_scale";
inline constexpr const char* kCvarFactor = "kcse_lpo_factor";
inline constexpr const char* kCvarTScale = "kcse_lpo_t_scale";
inline constexpr const char* kCvarShakeScale = "kcse_lpo_shake_scale";

inline void ApplyFloatSetting(const char* cvarName, float* store, double value)
{
    auto* env = SSystemGlobalEnvironment::GetInstance();
    ICVar* cvar = env && env->pConsole ? env->pConsole->GetCVar(cvarName) : nullptr;
    if (cvar)
        cvar->SetFloat(static_cast<float>(value));
    else
        *store = static_cast<float>(value);
    LockpickOverhaul::PersistSetting(cvarName, value, true);
}

inline void HandleMcmMessage(KCSE::Message* msg)
{
    if (msg->type == MCM::kMessage_BuildSettings) {
        auto* b = static_cast<MCM::ISettingsBuilder*>(msg->data);
        b->AddMod(kMcmModId, kMcmModName);
        b->AddCategory(kMcmModId, "Main", "");
        b->AddSlider(kMcmModId, kSettingFactor, "Attempt factor",
            "Scales extra lockpicking attempts from the skill gap. 1 is the default curve.",
            0.0, 2.0, 0.05, 1.0, "x");
        b->SetValue(kMcmModId, kSettingFactor, static_cast<double>(g_factor));
        b->AddSlider(kMcmModId, kSettingTScale, "Gold-zone scale",
            "First-attempt gold radius as a multiple of the vanilla too-hard threshold. 1 = threshold (tiny). 2 = twice as wide. Last attempt is still 2x the first.",
            1.0, 3.0, 0.05, 1.0, "x");
        b->SetValue(kMcmModId, kSettingTScale, static_cast<double>(g_tScale));
        b->AddSlider(kMcmModId, kSettingShakeScale, "Shake scale",
            "Multiplies cursor shake after it is matched to the playable gold zone. 0 = still. 1 = vanilla for that gold size. 2 = twice as wild.",
            0.0, 2.0, 0.05, 1.0, "x");
        b->SetValue(kMcmModId, kSettingShakeScale, static_cast<double>(g_shakeScale));
    } else if (msg->type == MCM::kMessage_ValueChanged) {
        auto* v = static_cast<const MCM::ValueChanged*>(msg->data);
        if (std::strcmp(v->modId, kMcmModId) != 0)
            return;
        if (std::strcmp(v->settingId, kSettingFactor) == 0)
            ApplyFloatSetting(kCvarFactor, &g_factor, v->value);
        else if (std::strcmp(v->settingId, kSettingTScale) == 0)
            ApplyFloatSetting(kCvarTScale, &g_tScale, v->value);
        else if (std::strcmp(v->settingId, kSettingShakeScale) == 0)
            ApplyFloatSetting(kCvarShakeScale, &g_shakeScale, v->value);
    }
}
