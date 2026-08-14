#pragma once
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <vector>
#include "S_PickableAreaInstance.h"

// -----------------------------------------------
// wh::environmentmodule::C_PickableAreaInstanceGrid -- pickable-instance spatial grid
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x58. [SYNTHETIC NAME]
// -----------------------------------------------
// Constructors sub_180B6C7A0/sub_180B6C834 initialize the scalar grid geometry and
// the cell map. Each flattened cell owns a vector of 0x30 pickable-area instances.

namespace wh::environmentmodule {

class C_PickableAreaInstanceGrid {
public:
    int32_t m_axisCellCount;       // +0x00
    int32_t m_totalCellCount;      // +0x04
    float   m_axisCellCountFloat;  // +0x08
    float   m_worldToCellScaleX;   // +0x0C
    float   m_worldToCellScaleY;   // +0x10
    uint32_t _pad14;               // +0x14
    std::unordered_map<int32_t, std::vector<S_PickableAreaInstance>> m_cells; // +0x18
};
static_assert(sizeof(C_PickableAreaInstanceGrid) == 0x58,
              "C_PickableAreaInstanceGrid must match the 0x58 allocation");
static_assert(offsetof(C_PickableAreaInstanceGrid, m_cells) == 0x18,
              "pickable-instance cell map must begin at +0x18");

}  // namespace wh::environmentmodule
