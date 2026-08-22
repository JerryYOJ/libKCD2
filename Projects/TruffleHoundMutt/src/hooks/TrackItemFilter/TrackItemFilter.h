#pragma once

#include "REL.h"

namespace wh::entitymodule { class C_Item; }

namespace hooks {

// Stopuj item-picker filter: the std::function _Do_call at 0x181ED9A20 (REL::ID 194228),
// exclusive to track-start. Lambda body = captured C_SniffableItemManager (+0x08) ->
// Contains(item class guid). orig || herb: registered yield GUIDs pass when the perk
// gate is satisfied -- listing only, the PickDestination hook owns the destination.
class TrackItemFilterHook {
public:
    static bool Install();
    static void Uninstall();

private:
    static bool TrackItemFilter(void* funcImpl, wh::entitymodule::C_Item* item);

    inline static REL::Relocation<decltype(&TrackItemFilter)> orig;
};

}  // namespace hooks
