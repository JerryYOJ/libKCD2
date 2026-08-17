#pragma once

#include "CryEngine/CryCommon/Cry_Math.h"

namespace wh::playermodule { class C_FastTravel; }
namespace wh::guimodule { class C_UIMap; }

class FastTravel {
public:
    static wh::playermodule::C_FastTravel* Get();
    static bool RandomEventPromptOpen();
    static void TryCancel();
    static bool RouteArmedTo(const Vec3& dest);
    static bool IsArmed();
    static void HideLine(wh::guimodule::C_UIMap* map);
    static void ClearIfCheckpointGone();
    static void RestoreOnInit();
    static void RepathArmed();
    static bool OnConfirmPressed();
    static bool OnCancelPressed(int keyId);
};
