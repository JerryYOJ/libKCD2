#pragma once

#include <cstring>

#include "MCM_API.h"

// Autobrew's MCM (Mod Configuration Menu) integration.  Soft dependency on MCM.dll -- if it
// isn't installed, nothing ever broadcasts sender="MCM" messages, so HandleMcmMessage
// (registered via MCM::ListenForMessages in plugin.cpp) never fires and these defaults stand.
// Both knobs are ALSO console CVars (kcse_autobrew_*, plugin.cpp binds these ints directly);
// int not bool because IConsole::RegisterCVarInt wants int storage.

inline int g_enableAutobrew = 1;   // main switch, START gate only: prompt hidden while off
inline int g_enableLooping  = 1;   // off = one brew per press (vanilla result popup returns)

inline constexpr const char* kMcmModId        = "autobrew";
inline constexpr const char* kMcmModName      = "Autobrew";
inline constexpr const char* kSettingEnable   = "enable";
inline constexpr const char* kSettingLooping  = "enable_looping";

inline void HandleMcmMessage(KCSE::Message* msg) {
    if (msg->type == MCM::kMessage_BuildSettings) {
        auto* b = static_cast<MCM::ISettingsBuilder*>(msg->data);
        b->AddMod(kMcmModId, kMcmModName);
        b->AddToggle(kMcmModId, kSettingEnable, "Enable Autobrew",
            "Master switch: show the Auto Brew prompt in the recipe book and drive the "
            "brewing automation.  Turning it off cancels a running brew.", true);
        b->AddToggle(kMcmModId, kSettingLooping, "Enable Looping",
            "Keep brewing the same recipe until the ingredients run out, with the results "
            "shown as toasts.  Off = one brew per press with the normal result popup.", true);
    } else if (msg->type == MCM::kMessage_ValueChanged) {
        auto* v = static_cast<const MCM::ValueChanged*>(msg->data);
        if (std::strcmp(v->modId, kMcmModId) != 0) return;
        if (std::strcmp(v->settingId, kSettingEnable) == 0) g_enableAutobrew = v->value != 0.0;
        else if (std::strcmp(v->settingId, kSettingLooping) == 0) g_enableLooping = v->value != 0.0;
    }
}
