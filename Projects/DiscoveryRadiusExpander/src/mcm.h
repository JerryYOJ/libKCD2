#pragma once

#include <cstring>

#include "MCM_API.h"
#include "crysystem/SSystemGlobalEnvironment.h"
#include "Offsets/vtables/ICVar.h"
#include "persist.h"

inline float g_shop        = 4.f;
inline float g_workstation = 3.f;
inline float g_service     = 3.f;
inline float g_landmark    = 1.f;
inline float g_wilderness  = 1.f;
inline float g_secret      = 1.f;
inline float g_fastTravel  = 1.f;

inline constexpr const char* kMcmModId   = "discoveryradiusexpander";
inline constexpr const char* kMcmModName = "Discovery Radius Expander";

struct S_McmBinding {
    const char* settingId;
    const char* cvarName;
    float*      store;
    const char* label;
    const char* tooltip;
    float       defaultValue;
};

inline constexpr S_McmBinding kMcmBindings[] = {
    { "shop",        "kcse_dre_shop",        &g_shop,        "Shops",
      "Craftsmen and traders: blacksmith, armourer, baker, tailor, and the rest.", 4.f },
    { "workstation", "kcse_dre_workstation", &g_workstation, "Workstations",
      "Alchemy bench, grindstone, smokehouse, dryer, dice table.", 3.f },
    { "service",     "kcse_dre_service",     &g_service,     "Services",
      "Pub, inn, baths, bed, arena, bailiff.", 3.f },
    { "landmark",    "kcse_dre_landmark",    &g_landmark,    "Landmarks",
      "Grave, shrine, nest, hive, mine entrance.", 1.f },
    { "wilderness",  "kcse_dre_wilderness",  &g_wilderness,  "Wilderness",
      "Hunting spots and camps.", 1.f },
    { "secret",      "kcse_dre_secret",      &g_secret,      "Secrets",
      "Unnamed general POIs and leftovers.", 1.f },
    { "fasttravel",  "kcse_dre_fasttravel",  &g_fastTravel,  "Fast travel",
      "Fast-travel points (already 100 m by default).", 1.f },
};

inline void HandleMcmMessage(KCSE::Message* msg)
{
    if (msg->type == MCM::kMessage_BuildSettings) {
        auto* b = static_cast<MCM::ISettingsBuilder*>(msg->data);
        b->AddMod(kMcmModId, kMcmModName);
        b->AddCategory(kMcmModId, "Radius", "");
        for (const auto& bind : kMcmBindings) {
            b->AddSlider(kMcmModId, bind.settingId, bind.label, bind.tooltip,
                         0.25, 8.0, 0.25, bind.defaultValue, "x");
            b->SetValue(kMcmModId, bind.settingId, static_cast<double>(*bind.store));
        }
    } else if (msg->type == MCM::kMessage_ValueChanged) {
        auto* v = static_cast<const MCM::ValueChanged*>(msg->data);
        if (std::strcmp(v->modId, kMcmModId) != 0)
            return;
        for (const auto& bind : kMcmBindings) {
            if (std::strcmp(v->settingId, bind.settingId) != 0)
                continue;
            auto* env = SSystemGlobalEnvironment::GetInstance();
            ICVar* cvar = env && env->pConsole ? env->pConsole->GetCVar(bind.cvarName) : nullptr;
            if (cvar)
                cvar->SetFloat(static_cast<float>(v->value));
            else
                *bind.store = static_cast<float>(v->value);
            DRE::PersistSetting(bind.cvarName, v->value);
            break;
        }
    }
}
