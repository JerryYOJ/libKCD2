#pragma once

#include "FlashInit/FlashInit.h"

namespace hooks {

inline bool Install()
{
    return FlashInitHook::Install();
}

inline void Uninstall()
{
    FlashInitHook::Uninstall();
}

}  // namespace hooks
