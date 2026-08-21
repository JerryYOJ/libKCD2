#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "C_CombatActorUpdatedObject.h"
#include "C_CombatObstacleTest.h"
#include "C_CombatSpatialTest.h"
#include "I_CombatEnvironmentManager.h"
#include "S_CombatObstacleTestParams.h"

namespace wh::combatmodule {

class C_CombatActor;
class C_SpatialGrid;

class C_CombatEnvironmentManager final
    : public C_CombatActorUpdatedObject
    , public I_CombatEnvironmentManager {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CombatEnvironmentManager;
    explicit C_CombatEnvironmentManager(C_CombatActor* pOwner);
    ~C_CombatEnvironmentManager() override;

    void Reset() override;
    E_CombatSubsystem GetSubsystemId() const override {
        return E_CombatSubsystem::ENV_MANAGER;
    }
    const char* GetName() const override { return "CombatEnvironmentManager"; }
    void UpdatePhase1() override;

    bool TestSpatialGrid(const C_SpatialGrid* pGrid) const override;
    std::unique_ptr<C_SpatialGrid> CreateSpatialGrid() override;
    bool TestObstacle(std::int32_t testType,
                      const S_CombatObstacleTestParams& params) override;

    C_CombatSpatialTest  m_spatialTest;  // +0x20, embedded/owned
    C_CombatObstacleTest m_obstacleTest; // +0x50, embedded/owned
};
static_assert(sizeof(C_CombatEnvironmentManager) == 0xA0);
static_assert(offsetof(C_CombatEnvironmentManager, m_spatialTest) == 0x20);
static_assert(offsetof(C_CombatEnvironmentManager, m_obstacleTest) == 0x50);

}  // namespace wh::combatmodule
