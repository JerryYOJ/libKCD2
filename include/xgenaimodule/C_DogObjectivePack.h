#pragma once
#include <cstdint>
#include <map>
#include <vector>
#include "C_MarkDogObjective.h"
#include "C_BarkDogObjective.h"
#include "C_FunOnPointDogObjective.h"
#include "C_DigDogObjective.h"
#include "C_DistractDogObjective.h"
#include "C_FollowDogObjective.h"
#include "C_WaitDogObjective.h"
#include "C_FollowHeelDogObjective.h"
#include "C_FollowRiderDogObjective.h"
#include "C_SearchDogObjective.h"
#include "C_SearchItemDogObjective.h"
#include "C_MeleeCombatDogObjective.h"
#include "C_FetchDogObjective.h"
#include "C_RunawayDogObjective.h"
#include "C_AlarmDogObjective.h"
#include "C_HuntDogObjective.h"
#include "C_FailDogObjective.h"
#include "C_MoveDogObjective.h"
#include "C_FunMoveDogObjective.h"
#include "C_FunOnSoDogObjective.h"
#include "C_ChaseDogObjective.h"
#include "C_EatDogObjective.h"
#include "C_ShakeOutDogObjective.h"
#include "C_PetDogObjective.h"
#include "C_TeleportDogObjective.h"
#include "E_DogObjective.h"

// -----------------------------------------------
// Dog-objective holder embed (KCD2 WHGame.dll 1.5.6). sizeof 0x1480.
// [SYNTHETIC NAME] -- no .?AV complete-object RTTI.
// -----------------------------------------------
// C_DogCompanionContext+0x910. Ctor 0x1809F5960(this, I_DogObjectiveContext*, vector*).
// I_DogObjectiveContext[3] GetObjectivePack 0x1809F6CD0 = context+0x910.
// 25 C_DogObjective leaves are inlined at fixed offsets (ctor-order table below); registrar
// 0x1809F5F2C inserts GetType() -> this* into m_byType for each one. FindByType 0x1809F6B90
// (REL::ID 54719) looks up that map; on miss it returns &m_wait (E_DogObjective::Wait, +0x4F8),
// NOT Fail -- C_FailDogObjective is its own distinct leaf at +0xD58 (E_DogObjective::Fail = 13).
//
// C_ObjectivePlanner is NOT a member of this pack. An earlier pass wrongly nested it at a
// synthetic +0x1480, inflating this class's believed sizeof to 0x14D8; the planner is in fact a
// SIBLING field of C_DogCompanionContext at +0x1D90, constructed by the context ctor
// 0x180BC9D10 AFTER this pack's own ctor returns (the pack ctor/dtor never touch that region) --
// see C_ObjectivePlanner.h and KCD2/analysis/dogpack_re/planner_deep.md / AUDIT3_enum_bijection.md.
//
// Embed offset chain is exactly gapless, +0x00 through +0x1480 (25 leaves + m_byType + m_pContext),
// derived from the pack ctor's own sequence of dedicated-ctor calls / vtable installs.

namespace wh::xgenaimodule::activitysystem {

class I_DogObjectiveContext;

class C_DogObjectivePack {
public:
    C_DogObjective* FindByType(E_DogObjective::Type type);  // 0x1809F6B90  map lookup into m_byType; miss returns &m_wait

    std::vector<void*>           m_seed;         // +0x00  8-byte trivial POD snapshot of C_ActivitySystemContext+0x5D8 (I_ActivityDebugDrawContext[2] 0x1809048E0). Source is empty-forever after ctor zero; pack never reads begin/end. T unnameable (not C_DogObjective* -- those live in m_byType). See pack_seed_vector.md.
    C_MarkDogObjective            m_mark;         // +0x18    E_DogObjective::Mark = 1
    C_BarkDogObjective            m_bark;         // +0x100   E_DogObjective::Bark = 2
    C_FunOnPointDogObjective      m_funOnPoint;   // +0x190   E_DogObjective::FunOnPoint = 17
    C_DigDogObjective             m_dig;          // +0x280   E_DogObjective::Dig = 3
    C_DistractDogObjective        m_distract;     // +0x3A0   E_DogObjective::Distract = 21
    C_FollowDogObjective          m_follow;       // +0x448   E_DogObjective::Follow = 4
    C_WaitDogObjective            m_wait;         // +0x4F8   E_DogObjective::Wait = 0; FindByType lookup-miss target
    C_FollowHeelDogObjective      m_followHeel;   // +0x5D8   E_DogObjective::FollowHeel = 5
    C_FollowRiderDogObjective     m_followRider;  // +0x698   E_DogObjective::FollowRider = 6
    C_SearchDogObjective          m_search;       // +0x720   E_DogObjective::Search = 7
    C_SearchItemDogObjective      m_searchItem;   // +0x860   E_DogObjective::SearchItem = 23
    C_MeleeCombatDogObjective     m_meleeCombat;  // +0x920   E_DogObjective::MeleeCombat = 8
    C_FetchDogObjective           m_fetch;        // +0xA10   E_DogObjective::Fetch = 9
    C_RunawayDogObjective         m_runaway;      // +0xAA8   E_DogObjective::Runaway = 11
    C_AlarmDogObjective           m_alarm;        // +0xB58   E_DogObjective::Alarm = 12
    C_HuntDogObjective            m_hunt;         // +0xC48   E_DogObjective::Hunt = 10
    C_FailDogObjective            m_fail;         // +0xD58   E_DogObjective::Fail = 13
    C_MoveDogObjective            m_move;         // +0xDD8   E_DogObjective::Move = 14
    C_FunMoveDogObjective         m_funMove;      // +0xE60   E_DogObjective::FunMove = 15
    C_FunOnSoDogObjective         m_funOnSo;      // +0xF88   E_DogObjective::FunOnSo = 16
    C_ChaseDogObjective           m_chase;        // +0x1090  E_DogObjective::Chase = 18
    C_EatDogObjective             m_eat;          // +0x11C0  E_DogObjective::Eat = 19
    C_ShakeOutDogObjective        m_shakeOut;     // +0x1278  E_DogObjective::ShakeOut = 20
    C_PetDogObjective             m_pet;          // +0x1318  E_DogObjective::Pet = 22
    C_TeleportDogObjective        m_teleport;     // +0x13D0  E_DogObjective::Teleport = 24
    std::map<E_DogObjective::Type, C_DogObjective*> m_byType;  // +0x1468  populated by registrar 0x1809F5F2C, one insert per embed above
    I_DogObjectiveContext*        m_pContext;     // +0x1478  ctor a2 (context+8)
};
static_assert(sizeof(C_DogObjectivePack) == 0x1480,
              "C_DogObjectivePack must be 0x1480 (planner is NOT a member -- see C_ObjectivePlanner.h)");
static_assert(offsetof(C_DogObjectivePack, m_mark) == 0x18, "Mark embed at +0x18");
static_assert(offsetof(C_DogObjectivePack, m_bark) == 0x100, "Bark embed at +0x100");
static_assert(offsetof(C_DogObjectivePack, m_funOnPoint) == 0x190, "FunOnPoint embed at +0x190");
static_assert(offsetof(C_DogObjectivePack, m_dig) == 0x280, "Dig embed at +0x280");
static_assert(offsetof(C_DogObjectivePack, m_distract) == 0x3A0, "Distract embed at +0x3A0");
static_assert(offsetof(C_DogObjectivePack, m_follow) == 0x448, "Follow embed at +0x448");
static_assert(offsetof(C_DogObjectivePack, m_wait) == 0x4F8, "Wait embed at +0x4F8");
static_assert(offsetof(C_DogObjectivePack, m_followHeel) == 0x5D8, "FollowHeel embed at +0x5D8");
static_assert(offsetof(C_DogObjectivePack, m_followRider) == 0x698, "FollowRider embed at +0x698");
static_assert(offsetof(C_DogObjectivePack, m_search) == 0x720, "Search embed at +0x720");
static_assert(offsetof(C_DogObjectivePack, m_searchItem) == 0x860, "SearchItem embed at +0x860");
static_assert(offsetof(C_DogObjectivePack, m_meleeCombat) == 0x920, "MeleeCombat embed at +0x920");
static_assert(offsetof(C_DogObjectivePack, m_fetch) == 0xA10, "Fetch embed at +0xA10");
static_assert(offsetof(C_DogObjectivePack, m_runaway) == 0xAA8, "Runaway embed at +0xAA8");
static_assert(offsetof(C_DogObjectivePack, m_alarm) == 0xB58, "Alarm embed at +0xB58");
static_assert(offsetof(C_DogObjectivePack, m_hunt) == 0xC48, "Hunt embed at +0xC48");
static_assert(offsetof(C_DogObjectivePack, m_fail) == 0xD58, "Fail embed at +0xD58");
static_assert(offsetof(C_DogObjectivePack, m_move) == 0xDD8, "Move embed at +0xDD8");
static_assert(offsetof(C_DogObjectivePack, m_funMove) == 0xE60, "FunMove embed at +0xE60");
static_assert(offsetof(C_DogObjectivePack, m_funOnSo) == 0xF88, "FunOnSo embed at +0xF88");
static_assert(offsetof(C_DogObjectivePack, m_chase) == 0x1090, "Chase embed at +0x1090");
static_assert(offsetof(C_DogObjectivePack, m_eat) == 0x11C0, "Eat embed at +0x11C0");
static_assert(offsetof(C_DogObjectivePack, m_shakeOut) == 0x1278, "ShakeOut embed at +0x1278");
static_assert(offsetof(C_DogObjectivePack, m_pet) == 0x1318, "Pet embed at +0x1318");
static_assert(offsetof(C_DogObjectivePack, m_teleport) == 0x13D0, "Teleport embed at +0x13D0");
static_assert(offsetof(C_DogObjectivePack, m_byType) == 0x1468, "type map at +0x1468");
static_assert(offsetof(C_DogObjectivePack, m_pContext) == 0x1478, "context back-ref at +0x1478");

}  // namespace wh::xgenaimodule::activitysystem
