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
// PickDestination override 0x18330F310 REL::ID(406230). Parent [26] 0x18330F304 is a
// complete-1 stub; the 0xC gap is int3 padding, not a thunk. Never hook 406231
// (0x18330F528, the next function). Picker writes nothing on this before Commit/Fail.

namespace wh::xgenaimodule::activitysystem {

class C_SearchItemDogObjective : public C_PlayerSynchroAnimBaseDogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_SearchItemDogObjective;

    E_DogObjective::Type GetType() const override;  // [17] SearchItem
    void unk_19() override;                         // [19]
    void unk_20() override;                         // [20]
    void unk_21() override;                         // [21]

    int64_t CommitDestination(const Vec3& pos);  // 0x18330EF7C
    int64_t Fail();                              // 0x18330B484

    wh::framework::WUID m_item;  // +0xB8  Item WUID; invalid sentinel qword_18533A2B0
};
static_assert(sizeof(C_SearchItemDogObjective) == 0xC0,
              "C_SearchItemDogObjective must be 0xC0");
static_assert(offsetof(C_SearchItemDogObjective, m_item) == 0xB8,
              "sniffed Item WUID at +0xB8");

}  // namespace wh::xgenaimodule::activitysystem
