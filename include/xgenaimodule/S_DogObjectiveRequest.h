#pragma once
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../framework/WUID.h"

// -----------------------------------------------
// 0x30 dog-objective apply/request POD (KCD2 WHGame.dll 1.5.6).
// [SYNTHETIC NAME] — no RTTI.
// -----------------------------------------------
// Ctor 0x180C589B4 / heap new 0x180C58950. DestCommit writes m_position + m_hasPosition.
// SearchItem submit writes m_item (Item WUID, tag 2) + m_hasItem.
// NOT C_ObjectivePlanner::S_Request (real polymorphic queue entry : I_ObjectivePlannerRunnable,
// vtable 0x183A8A940, ctor 0x180C58B90) — that wrapper carries this POD, distinct type.

namespace wh::xgenaimodule::activitysystem {

struct S_DogObjectiveRequest {
    Vec3                m_position;      // +0x00
    Vec3                m_direction;     // +0x0C
    wh::framework::WUID m_target;        // +0x18
    wh::framework::WUID m_item;          // +0x20  SearchItem only
    bool                m_hasPosition;   // +0x28
    bool                m_hasDirection;  // +0x29
    bool                m_hasTarget;     // +0x2A
    bool                m_hasItem;       // +0x2B
    uint8_t             _pad2C[4];       // +0x2C
};
static_assert(sizeof(S_DogObjectiveRequest) == 0x30,
              "S_DogObjectiveRequest must be 0x30 (operator new(48))");
static_assert(offsetof(S_DogObjectiveRequest, m_item) == 0x20,
              "SearchItem WUID at +0x20");
static_assert(offsetof(S_DogObjectiveRequest, m_hasItem) == 0x2B,
              "SearchItem accept reads +0x2B");

}  // namespace wh::xgenaimodule::activitysystem
