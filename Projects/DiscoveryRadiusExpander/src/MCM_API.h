// MCM_API.h — public API of the MCM (Mod Configuration Menu) KCSE plugin.
// Consuming plugins vendor this header; there is no import lib.

#pragma once

#include <cstdint>

#include "KCSE/KCSEAPI.h"

namespace MCM {

    constexpr uint32_t kMessage_ValueChanged = 0x4D434D01;   // 'MCM',1

    struct ValueChanged {
        const char* modId;
        const char* settingId;
        double      value;
    };

    constexpr uint32_t kMessage_BuildSettings = 0x4D434D02;  // 'MCM',2

    struct ISettingsBuilder {
        virtual void AddMod(const char* modId, const char* displayName) = 0;
        virtual void AddCategory(const char* modId, const char* label,
                                 const char* tooltip) = 0;
        virtual void AddToggle(const char* modId, const char* id, const char* label,
                               const char* tooltip, bool defaultOn) = 0;
        virtual void AddDropdown(const char* modId, const char* id, const char* label,
                                 const char* tooltip, const char* options,
                                 int defaultIndex) = 0;
        virtual void AddSlider(const char* modId, const char* id, const char* label,
                               const char* tooltip, double mn, double mx, double step,
                               double defaultValue, const char* suffix) = 0;
        virtual void SetValue(const char* modId, const char* id, double value) = 0;
    };

    inline void ListenForMessages(KCSE::IMessagingInterface::EventCallback cb) {
        KCSE::GetMessagingInterface()->RegisterListener("MCM", cb);
    }
}  // namespace MCM
