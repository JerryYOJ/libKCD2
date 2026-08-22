#pragma once
#include <cstdint>
#include <map>
#include <vector>
#include "C_ObjectivePlanner.h"
#include "C_SearchDogObjective.h"
#include "C_SearchItemDogObjective.h"
#include "E_DogObjective.h"

// -----------------------------------------------
// Dog-objective holder embed (KCD2 WHGame.dll 1.5.6). sizeof 0x14D8.
// [SYNTHETIC NAME] — no .?AV complete-object RTTI.
// -----------------------------------------------
// C_DogCompanionContext+0x910. Ctor 0x1809F5960(this, I_DogObjectiveContext*, vector*).
// I_DogObjectiveContext[3] GetObjectivePack 0x1809F6CD0 = context+0x910.
// 26 C_DogObjective leaves are inlined at fixed offsets; registrar 0x1809F5F2C
// inserts GetType() -> this* into m_byType. FindByType 0x1809F6B90 REL::ID 54719
// looks up that map; miss returns the Fail embed at +0x4F8 (not null).
// C_ObjectivePlanner at +0x1480 is in-place constructed by the context ctor.

namespace wh::xgenaimodule::activitysystem {

class I_DogObjectiveContext;

class C_DogObjectivePack {
public:
    C_DogObjective* FindByType(E_DogObjective::Type type);

    std::vector<void*>           m_seed;          // +0x00  8-byte elems copied from ctor a3 [U]
    uint8_t                      _pad18[0x708];   // +0x18  Mark..FollowRider embeds
    C_SearchDogObjective         m_search;        // +0x720  E_DogObjective::Search
    C_SearchItemDogObjective     m_searchItem;    // +0x860  E_DogObjective::SearchItem
    uint8_t                      _pad920[0xB48];  // +0x920  remaining leaves through +0x13D0
    std::map<E_DogObjective::Type, C_DogObjective*> m_byType; // +0x1468
    I_DogObjectiveContext*       m_pContext;      // +0x1478  ctor a2 (context+8)
    C_ObjectivePlanner           m_planner;       // +0x1480  context+0x1D90
};
static_assert(sizeof(C_DogObjectivePack) == 0x14D8,
              "C_DogObjectivePack must be 0x14D8");
static_assert(offsetof(C_DogObjectivePack, m_search) == 0x720,
              "Search embed at +0x720");
static_assert(offsetof(C_DogObjectivePack, m_searchItem) == 0x860,
              "SearchItem embed at +0x860");
static_assert(offsetof(C_DogObjectivePack, m_byType) == 0x1468,
              "type map at +0x1468");
static_assert(offsetof(C_DogObjectivePack, m_pContext) == 0x1478,
              "context back-ref at +0x1478");
static_assert(offsetof(C_DogObjectivePack, m_planner) == 0x1480,
              "planner at +0x1480");

}  // namespace wh::xgenaimodule::activitysystem
