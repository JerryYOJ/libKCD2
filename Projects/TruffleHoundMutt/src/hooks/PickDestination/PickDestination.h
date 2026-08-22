#pragma once

#include "REL.h"

namespace wh::xgenaimodule::activitysystem { class C_SearchItemDogObjective; }

namespace hooks {

// C_SearchItemDogObjective::PickDestination (0x18330F310, REL::ID 406230) -- Stopuj dest
// picker. Herb-first: yield / dried-yield GUIDs CommitDestination a plant pos and never
// fall through (vanilla Fails/barks on the empty Areas we Insert for picker eligibility).
class PickDestinationHook {
public:
    static bool Install();
    static void Uninstall();

private:
    static void PickDestination(wh::xgenaimodule::activitysystem::C_SearchItemDogObjective* self);

    inline static REL::Relocation<decltype(&PickDestination)> orig;
};

}  // namespace hooks
