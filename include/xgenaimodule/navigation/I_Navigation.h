#pragma once
#include <cstdint>
#include "I_PathFinder.h"
#include "S_PathFindingResult.h"

// -----------------------------------------------
// wh::xgenaimodule::navigation::I_Navigation -- navmesh system contract
// (KCD2 WHGame.dll 1.5.6).  sizeof 0x08.
// -----------------------------------------------
// RTTI .?AVI_Navigation@navigation@xgenaimodule@wh@@.  Interface vtable
// 0x18400C5D0, 42 slots (0-41; slot 42 is the next COL). C_Navigation implements
// this as its primary base. Only the path-query cluster is named.

namespace wh::xgenaimodule::navigation {

class C_PathManager;
class C_ReplanMoveAreaRegistry;

class I_Navigation {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_Navigation;
    virtual ~I_Navigation() = default;                      // [0]
    virtual C_PathManager* GetPathManager() = 0;            // [1] 0x181A76BE0  this+0x148
    virtual void unk_2() = 0;
    virtual void unk_3() = 0;
    virtual void unk_4() = 0;
    virtual void unk_5() = 0;
    virtual void unk_6() = 0;
    virtual I_PathFinder* GetPathFinder() = 0;              // [7]  C_Navigation: 0x181A77FC0  this+0x150
    virtual void unk_8() = 0;
    virtual void unk_9() = 0;
    virtual void unk_10() = 0;
    virtual void unk_11() = 0;
    virtual C_ReplanMoveAreaRegistry* GetReplanMoveAreaRegistry() = 0;         // [12] 0x181A77FA0  this+0x178
    virtual void unk_13() = 0;
    virtual void unk_14() = 0;
    virtual void unk_15() = 0;
    virtual void unk_16() = 0;
    virtual void unk_17() = 0;
    virtual void unk_18() = 0;
    virtual void unk_19() = 0;
    virtual void unk_20() = 0;
    virtual void unk_21() = 0;
    virtual void unk_22() = 0;
    virtual void unk_23() = 0;
    // Writes *id = m_defaultNavMeshId (+0x88) and returns id.  C_Navigation: 0x180813390.
    virtual uint32_t* GetDefaultNavMeshId(uint32_t* id) const = 0;            // [24]
    virtual void unk_25() = 0;
    virtual void unk_26() = 0;
    virtual void unk_27() = 0;
    virtual void unk_28() = 0;
    virtual void unk_29() = 0;
    virtual void unk_30() = 0;
    virtual void unk_31() = 0;
    virtual void unk_32() = 0;
    virtual void unk_33() = 0;
    virtual S_PathFindingResult* CreatePathResult() = 0;    // [34] 0x1834100E8  alloc 0x18, zeroed
    virtual void DestroyPathResult(S_PathFindingResult* result) = 0;          // [35] 0x183410238
    virtual void unk_36() = 0;
    virtual void unk_37() = 0;
    virtual void unk_38() = 0;
    virtual void unk_39() = 0;
    virtual void unk_40() = 0;
    virtual void unk_41() = 0;
};
static_assert(sizeof(I_Navigation) == 0x08, "I_Navigation is a vptr-only interface");

}  // namespace wh::xgenaimodule::navigation
