#pragma once
#include <cstdint>
#include <unordered_map>
#include <vector>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../rpgmodule/I_POI.h"
#include "C_DogObjective.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_SearchDogObjective : C_DogObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0x140. 19 slots (no new virtuals vs parent).
// -----------------------------------------------
// RTTI .?AVC_SearchDogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183C122C8, ctor 0x181788904. Embed pack +0x720. GetType Search (POI/chest/corpse).
// Not scent-Track.

namespace wh::xgenaimodule::activitysystem {

class C_SearchDogObjective : public C_DogObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_SearchDogObjective;

    S_ObjectiveScore* ComputeScore(S_ObjectiveScore* out) override;  // [12]
    E_DogObjective::Type GetType() const override;                   // [17] Search

    uint32_t                         m_stashClassId;      // +0x78
    uint32_t                         _pad7C;              // +0x7C
    // keys: I_POI* (tag 2) or IEntity* (tag 3 corpse) by pointer identity; no common
    // base. Tag 1 stash goes to I_DogObjectiveContext[1]()+0x158 (ctx+0x190), not here.
    std::unordered_map<void*, float> m_recent;            // +0x80
    float                            m_phaseTime;         // +0xC0
    uint8_t                          m_fsm;               // +0xC4
    uint8_t                          _padC5[3];           // +0xC5
    float                            m_candidateScore;    // +0xC8
    Vec3                             m_candidatePos;      // +0xCC
    float                            m_candidateRadius;   // +0xD8
    uint32_t                         _padDC;              // +0xDC
    wh::rpgmodule::I_POI*            m_candidatePoi;      // +0xE0
    uint32_t                         m_candidateEntityId; // +0xE8
    uint8_t                          m_candidateTag;      // +0xEC
    uint8_t                          _padED[3];           // +0xED
    int64_t                          m_cooldownDeadline;  // +0xF0
    std::vector<void*>               m_pathObjects;       // +0xF8  element type [U]
    std::vector<Vec3>                m_waypoints;         // +0x110
    float                            m_pathDistance;      // +0x128
    uint32_t                         m_pathId;            // +0x12C
    Vec3                             m_moveDest;          // +0x130
    uint32_t                         _pad13C;             // +0x13C
};
static_assert(sizeof(C_SearchDogObjective) == 0x140,
              "C_SearchDogObjective must be 0x140");
static_assert(offsetof(C_SearchDogObjective, m_recent) == 0x80,
              "recent-target hash at +0x80");
static_assert(offsetof(C_SearchDogObjective, m_candidatePos) == 0xCC,
              "candidate position at +0xCC");
static_assert(offsetof(C_SearchDogObjective, m_moveDest) == 0x130,
              "issued waypoint at +0x130");

}  // namespace wh::xgenaimodule::activitysystem
