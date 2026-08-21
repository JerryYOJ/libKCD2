#pragma once

#include "REL.h"
#include "playermodule/C_LockPicking.h"

namespace hooks {

class EnterCompleteHook {
public:
    static bool Install();
    static void Uninstall();

private:
    static void EnterComplete(wh::playermodule::C_LockPicking* self);

    inline static REL::Relocation<decltype(&EnterComplete)> orig;
};

}  // namespace hooks
