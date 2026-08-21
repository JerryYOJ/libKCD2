#pragma once
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../framework/WUID.h"
#include "C_PlayerSynchroAnimBaseDogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_SearchItemDogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0xC0. 27 slots (no new virtuals vs parent).
// -----------------------------------------------
// RTTI .?AVC_SearchItemDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183C392F8. Embed C_DogCompanion pack +0x860. GetType 0x17.
// m_item is Item WUID (tag 2), not a C_Item*. DestCommit queues Search=7.

namespace wh::xgenaimodule::activitysystem {

class C_SearchItemDogObjective : public C_PlayerSynchroAnimBaseDogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_SearchItemDogObjective;

    int64_t CommitDestination(const Vec3& pos);  // 0x18330EF7C
    int64_t Fail();                              // 0x18330B484

    wh::framework::WUID m_item;  // +0xB8  Item WUID; invalid sentinel qword_18533A2B0
};
static_assert(sizeof(C_SearchItemDogObjective) == 0xC0,
              "C_SearchItemDogObjective must be 0xC0");
static_assert(offsetof(C_SearchItemDogObjective, m_item) == 0xB8,
              "sniffed Item WUID at +0xB8");

}  // namespace wh::xgenaimodule::activitysystem
