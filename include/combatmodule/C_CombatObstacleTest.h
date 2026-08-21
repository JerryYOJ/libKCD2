#pragma once
#include <cstddef>
#include <unordered_map>
#include "S_SpatialGridJobData.h"
#include "S_SpatialGridKey.h"
#include "S_SpatialGridKeyHash.h"

namespace wh::combatmodule {

class C_CombatActor;

class C_CombatObstacleTest {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatObstacleTest;
    explicit C_CombatObstacleTest(C_CombatActor* pOwner);
    virtual ~C_CombatObstacleTest(); // [0], sole virtual slot

    C_CombatActor* m_pOwner; // +0x08, borrowed
    std::unordered_map<S_SpatialGridKey, S_SpatialGridJobData,
                       S_SpatialGridKeyHash> m_spatialGridJobs; // +0x10, owned
};
static_assert(sizeof(C_CombatObstacleTest) == 0x50);
static_assert(offsetof(C_CombatObstacleTest, m_pOwner) == 0x08);
static_assert(offsetof(C_CombatObstacleTest, m_spatialGridJobs) == 0x10);

}  // namespace wh::combatmodule
