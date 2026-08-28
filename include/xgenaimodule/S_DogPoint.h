#pragma once
#include <cstdint>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "E_DogPointType.h"

// -----------------------------------------------
// wh::xgenaimodule::S_DogPoint
// (KCD2 WHGame.dll 1.5.6). sizeof 0x38. 4 slots (dtor + RTTR trio).
// -----------------------------------------------
// RTTI .?AUS_DogPoint@xgenaimodule@wh@@ (struct, not class)
// vtable 0x183A42D20, COL 0x1840DFD20 offset 0 (complete-object, not a subobject).
// CHD nbase=1 (root type, no C++ base).
// Cross-validated across 6 independent leaf dossiers (Mark, FunOnPoint, Dig,
// FunMove, Chase, FunOnSo) with perfect agreement. Embedded by value at
// C_FunOnTargetBaseDogObjective+0x88 (m_requestPoint) -- composition, not MI;
// see C_FunOnTargetBaseDogObjective.h. Dig/FunMove/Chase additionally embed a
// SECOND S_DogPoint of their own past the base's 0xE8 extent.
// RTTR properties (generated Lua + wrappers): Position, Direction, Type, Aux, Guid.

namespace wh::xgenaimodule {

struct S_DogPoint {
public:
    ~S_DogPoint();  // [0] 0x180626404, empty body (no owned resources), optional operator delete
    RTTR_ENABLE()   // [1..3] get_type 0x1832B1248, get_ptr 0x1805F5DA0, get_derived_info 0x1812ADF94

    Vec3                   Position;   // +0x08  init {0,0,0}; Apply copies S_DogObjectiveRequest::m_position
    Vec3                   Direction;  // +0x14  init {0,1,0} (world-Y "up" default before Apply overwrites)
    E_DogPointType::Type   Type;       // +0x20  init 0 (DrinkingSpot); store-width byte
    uint8_t                _pad21[3];
    Vec2_tpl<int>          Aux;        // +0x24  init {-1,-1}; RTTR property Aux, NOT entity ids
    uint32_t               _pad2C;
    uint64_t                Guid;       // +0x30  init 0; RTTR "_K". Lookup key via 0x180A25B44. WUID vs raw uint64 UNVERIFIED
};
static_assert(sizeof(S_DogPoint) == 0x38, "S_DogPoint must be 0x38");
static_assert(offsetof(S_DogPoint, Direction) == 0x14, "Direction follows Position");
static_assert(offsetof(S_DogPoint, Type) == 0x20, "Type at +0x20");
static_assert(offsetof(S_DogPoint, Aux) == 0x24, "Aux at +0x24");
static_assert(offsetof(S_DogPoint, Guid) == 0x30, "Guid 8-aligned at +0x30");

}  // namespace wh::xgenaimodule
