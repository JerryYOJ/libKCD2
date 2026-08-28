#pragma once
#include <cstdint>
#include <vector>

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::S_WaitPhase
// (KCD2 WHGame.dll 1.5.6). sizeof 0x28. SYNTHETIC -- no RTTI, private to C_WaitDogObjective.
// -----------------------------------------------
// Element of C_WaitDogObjective::m_phases. Ctor 0x18099C520; consumed by PickPhase
// 0x1809F40F0 (successor pick + timer arm) and find_if 0x1820980F0 (lookup by id,
// stride 0x28). 4-entry Markov chain installed by the pack ctor:
//   id0 dur=5.0  next={0,2,1} hubLane2=2 allowExtraAction=0
//   id1 dur=11.0 next={1,2}   hubLane2=1 allowExtraAction=1
//   id2 dur=12.0 next={2,3,1} hubLane2=0 allowExtraAction=1
//   id3 dur=15.0 next={0}     hubLane2=0 allowExtraAction=0
// Do not name phases sit/lie/sleep -- the dog-action expansion side keys phases by
// unloaded runtime ids (dword_185323108/10C/110), not by these Markov ids.

namespace wh::xgenaimodule::activitysystem {

struct S_WaitPhase {
    uint8_t              id;                 // +0x00
    uint8_t               _pad01[3];
    float                 duration;           // +0x04  base dwell seconds, 5s jitter (dword_18492F290) applied by the caller
    std::vector<uint8_t>  nextIds;            // +0x08  packed successor id list; PickPhase chooses begin[rand % size]
    uint8_t               hubLane2;           // +0x20  written to hub+0x48 lane index 2 on phase apply
    uint8_t               allowExtraAction;   // +0x21  gates ScheduleExtraAction when remaining time > 3.5s
    uint8_t               _pad22[6];
};
static_assert(sizeof(S_WaitPhase) == 0x28, "S_WaitPhase must be 0x28");
static_assert(offsetof(S_WaitPhase, nextIds) == 0x08, "nextIds at +0x08");
static_assert(offsetof(S_WaitPhase, hubLane2) == 0x20, "hubLane2 at +0x20");

}  // namespace wh::xgenaimodule::activitysystem
