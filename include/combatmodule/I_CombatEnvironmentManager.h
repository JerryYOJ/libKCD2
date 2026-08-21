#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>

namespace wh::combatmodule {

class C_SpatialGrid;
struct S_CombatObstacleTestParams;

class I_CombatEnvironmentManager {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_CombatEnvironmentManager;
    // No virtual destructor in the retail three-slot interface.
    virtual bool TestSpatialGrid(const C_SpatialGrid* pGrid) const = 0; // [0]
    virtual std::unique_ptr<C_SpatialGrid> CreateSpatialGrid() = 0;      // [1]
    virtual bool TestObstacle(std::int32_t testType,
                              const S_CombatObstacleTestParams& params) = 0; // [2]
};
static_assert(sizeof(I_CombatEnvironmentManager) == 0x08);

}  // namespace wh::combatmodule
