#pragma once
#include <cstdint>

enum EColliderModeLayer : std::int32_t {
    eColliderModeLayer_AnimGraph = 0,
    eColliderModeLayer_Game,
    eColliderModeLayer_Script,
    eColliderModeLayer_FlowGraph,
    eColliderModeLayer_Animation,
    eColliderModeLayer_ForceSleep,
    eColliderModeLayer_Debug,
    eColliderModeLayer_COUNT,
    eColliderModeLayer_FF = 0xFF,
};
static_assert(sizeof(EColliderModeLayer) == 0x04,
              "EColliderModeLayer must be 0x04");
