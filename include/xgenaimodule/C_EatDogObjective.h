#pragma once
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../framework/WUID.h"
#include "C_DogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_EatDogObjective : C_DogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0xB8. 19 slots, 0 new.
// -----------------------------------------------
// RTTI .?AVC_EatDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183C40FD0, COL 0x1840DD930 offset 0, CHD 0x184562BB0 nbase=4 (single inheritance).
// ctor 0x18194BF20(this, I_DogObjectiveContext*), dtor 0x183300004.
// Pack embed C_DogObjectivePack+0x11C0. E_DogObjective::Eat = 19.
//
// Walks to a world food item, waits for it to come to rest, plays out EatingTime seconds, then
// consumes it and fires entityModule:onDogFed when the target came from an explicit request
// (m_fromRequest); ComputeScore can also auto-pick an untracked food entity id without setting
// m_fromRequest. Accept/Apply resolve the request's target WUID to a C_Item and gate on
// S_FoodItemClass::m_type in {2,5}. Virtual Complete [15] (inherited) is the FAIL path only --
// success completes go directly through the shared helper 0x1809F62F4(this,1) from OnMoveArrived.

namespace wh::xgenaimodule::activitysystem {

class C_EatDogObjective : public C_DogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_EatDogObjective;

    void  StopIfRunning() override;                                        // [4]  0x1818A2060  parent body, then disconnect arrive cb + item-watch
    bool  Accept(const S_DogObjectiveRequest*) override;                    // [6]  0x1833004A0  m_hasTarget && resolved item passes IsEatableItem
    void  Apply(const S_DogObjectiveRequest*) override;                      // [7]  0x183302914  same resolve+gate; on success m_entityId/m_item/m_fromRequest=true
    void  BeginWork() override;                                              // [8]  0x183302084  GetEntity(m_entityId); snapshot master pos, occupy physics bit, Connect arrive cb
    void  Tick() override;                                                    // [10] 0x183302F28  drift-abort check, at-rest gait/eat-timer logic, EatingTime expiry -> consume
    void  unk_11() override;                                                  // [11] 0x183302618  EndWork: release physics occupy, unhook face/arrive cbs, clear target fields
    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override;          // [12] 0x180729448  30.0 if m_fromRequest, 30.001 if auto-picked+held, else auto-pick or -1.0
    E_DogObjective::Type GetType() const override;                         // [17] 0x181AA68A0  return 0x13 (Eat)

    bool     m_itemWatchHooked;    // +0x78
    bool     m_arriveCbHooked;     // +0x79
    uint8_t  _pad7A[2];            // +0x7A
    float    m_eatStartTime;       // +0x7C  sentinel -1.0f; ITimer seconds
    float    m_approachStartDist;  // +0x80  length of the dog-expansion pose vector at BeginWork
    bool     m_physFlagSet;        // +0x84
    uint8_t  _pad85[3];            // +0x85
    Vec3     m_moveDest;           // +0x88
    Vec3     m_masterPosAtBegin;   // +0x94
    bool     m_issuingMove;        // +0xA0
    bool     m_faceCbHooked;       // +0xA1
    uint8_t  _padA2[2];            // +0xA2
    uint32_t m_entityId;           // +0xA4  Cry EntityId (typedef unsigned int)
    wh::framework::WUID m_item;    // +0xA8  Item tag; invalid sentinel qword_18533A260
    bool     m_fromRequest;        // +0xB0
    uint8_t  _padB1[7];            // +0xB1
};
static_assert(sizeof(C_EatDogObjective) == 0xB8, "C_EatDogObjective must be 0xB8");
static_assert(offsetof(C_EatDogObjective, m_eatStartTime) == 0x7C, "m_eatStartTime at +0x7C");
static_assert(offsetof(C_EatDogObjective, m_item) == 0xA8, "m_item at +0xA8");
static_assert(offsetof(C_EatDogObjective, m_fromRequest) == 0xB0, "m_fromRequest at +0xB0");

// unk_11 keeps the C_ActivityObjective-declared spelling (source name UNVERIFIED); EndWork
// describes behavior only. ComputeScore's auto-pick path (no request target) never sets
// m_fromRequest or m_item -- only the explicit-request path (Apply) does.

}  // namespace wh::xgenaimodule::activitysystem
