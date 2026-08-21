#pragma once

#include "REL.h"
#include "playermodule/C_LockPicking.h"

namespace hooks {

class LockPickingTeardownHook {
public:
    static bool Install();
    static void Uninstall();

private:
    static void Teardown(wh::playermodule::C_LockPicking* self);

    inline static REL::Relocation<decltype(&Teardown)> orig;
};

}  // namespace hooks
