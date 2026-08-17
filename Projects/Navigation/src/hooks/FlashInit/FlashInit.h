#pragma once

#include "REL.h"
#include "CryEngine/CryCommon/CFlashUIElement.h"

namespace hooks {

class FlashInitHook {
public:
    static bool Install();
    static void Uninstall();

private:
    static bool Init(CFlashUIElement* self, bool load);

    inline static REL::Relocation<decltype(&Init)> orig;
};

}  // namespace hooks
