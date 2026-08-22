#pragma once
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/TimeValue.h"
#include "C_DogObjective.h"
#include "S_ObjectiveScore.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_PlayerSynchroAnimBaseDogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0xB8. 27 slots.
// -----------------------------------------------
// RTTI .?AVC_PlayerSynchroAnimBaseDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183C39218, ctor 0x18192C680. Immediate parent of SearchItem / Pet.
// Abstract GetType [17] and synchro pures [19][20][21].

namespace wh::xgenaimodule::activitysystem {

class C_PlayerSynchroAnimBaseDogObjective : public C_DogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PlayerSynchroAnimBaseDogObjective;

    void BeginWork() override;                                    // [8] 0x18330CD60
    void Tick() override;                                         // [10] 0x18330E2B4
    void unk_11() override;                                       // [11] 0x18330D404
    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override; // [12] 0x18330B318
    virtual void unk_19() = 0;                                    // [19] 0x181D93E5D
    virtual void unk_20() = 0;                                    // [20] 0x181D93E5D
    virtual void unk_21() = 0;                                    // [21] 0x181D93E5D
    virtual Vec3 GetMasterAimPos();                               // [22] 0x18330BB64
    virtual Vec3 GetMasterFacing();                               // [23] 0x18330BA68
    virtual float GetHeightTolerance() const;                     // [24] 0x181A7E430
    virtual void OnSynchroFail();                                 // [25] 0x1803931E8
    virtual void PickDestination();                               // [26] 0x18330F304 complete-1 stub; SearchItem overrides 0x18330F310

    bool        m_playerCbHooked;  // +0x78
    uint8_t     _pad79[7];         // +0x79
    CTimeValue  m_timeout;         // +0x80
    CTimeValue  m_repathTimer;     // +0x88
    Vec3        m_posA;            // +0x90
    Vec3        m_posB;            // +0x9C
    Vec3        m_localOffset;     // +0xA8
    uint8_t     m_synchroState;    // +0xB4
    uint8_t     _padB5[3];         // +0xB5
};
static_assert(sizeof(C_PlayerSynchroAnimBaseDogObjective) == 0xB8,
              "synchro base must be 0xB8");
static_assert(offsetof(C_PlayerSynchroAnimBaseDogObjective, m_timeout) == 0x80,
              "timeout CTimeValue at +0x80");
static_assert(offsetof(C_PlayerSynchroAnimBaseDogObjective, m_synchroState) == 0xB4,
              "synchro FSM byte at +0xB4");

}  // namespace wh::xgenaimodule::activitysystem
