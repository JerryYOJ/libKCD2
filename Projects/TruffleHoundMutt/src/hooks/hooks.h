#pragma once

#include "PickDestination/PickDestination.h"
#include "TrackItemFilter/TrackItemFilter.h"

namespace hooks {

inline bool Install()
{
    return PickDestinationHook::Install() && TrackItemFilterHook::Install();
}

inline void Uninstall()
{
    TrackItemFilterHook::Uninstall();
    PickDestinationHook::Uninstall();
}

}  // namespace hooks
