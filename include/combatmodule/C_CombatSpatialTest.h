#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::combatmodule {

class C_CombatActor;
class C_SpatialGrid;

class C_CombatSpatialTest {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatSpatialTest;
    explicit C_CombatSpatialTest(C_CombatActor* pOwner);
    virtual ~C_CombatSpatialTest(); // [0], sole virtual slot

    C_CombatActor* m_pOwner;                  // +0x08, borrowed
    std::unique_ptr<C_SpatialGrid> m_pSpatialGrid; // +0x10, owned
    float m_refreshElapsed;                   // +0x18, init FLT_MAX
    bool m_hasValidGrid;                      // +0x1C
    bool m_refreshResultLatched;              // +0x1D
    std::uint8_t _pad1E[2];                   // +0x1E
    float m_cachedSpatialGridRadius;          // +0x20
    std::uint32_t _pad24;                     // +0x24
    CryStringT<char> m_cachedDissectionString;// +0x28, owned
};
static_assert(sizeof(C_CombatSpatialTest) == 0x30);
static_assert(offsetof(C_CombatSpatialTest, m_pOwner) == 0x08);
static_assert(offsetof(C_CombatSpatialTest, m_pSpatialGrid) == 0x10);
static_assert(offsetof(C_CombatSpatialTest, m_refreshElapsed) == 0x18);
static_assert(offsetof(C_CombatSpatialTest, m_hasValidGrid) == 0x1C);
static_assert(offsetof(C_CombatSpatialTest, m_cachedSpatialGridRadius) == 0x20);
static_assert(offsetof(C_CombatSpatialTest, m_cachedDissectionString) == 0x28);

}  // namespace wh::combatmodule
