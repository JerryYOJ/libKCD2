#pragma once

#include "REL.h"
#include "playermodule/C_LockPicking.h"

namespace hooks {

class CommitResultHook {
public:
    static bool Install();
    static void Uninstall();

private:
    static void CommitResult(wh::playermodule::C_LockPicking* self, uint8_t success,
                             char skipLeave, void* scratch);

    inline static REL::Relocation<decltype(&CommitResult)> orig;
};

}  // namespace hooks
