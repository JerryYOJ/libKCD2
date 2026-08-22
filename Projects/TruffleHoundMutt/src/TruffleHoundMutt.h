#pragma once

#include "CryEngine/CryCommon/CryExtension/CryGUID.h"

namespace wh::xgenaimodule::activitysystem {
class C_SearchItemDogObjective;
}

namespace TruffleHoundMutt {

void RegisterYields();
bool TryHerbTrack(wh::xgenaimodule::activitysystem::C_SearchItemDogObjective* self);

// Picker-filter verdict for one item class: a registered fresh/dried yield GUID
// AND the perk gate (kcse_trufflehoundmutt_require_perk) is satisfied.
bool AllowHerb(const CryGUID& classGuid);

void KillPlantBeacon();

}  // namespace TruffleHoundMutt
