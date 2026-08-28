#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../../wh/S_DeltaMovementComputerParams.h"
#include "S_DeltaMovementParamsNode.h"
#include "S_DeltaMovementPartialSurroundingRequirements.h"
#include "S_DeltaMovementSurroundingDef.h"

namespace wh::xgenaimodule::navigation {

struct S_DeltaMovementParamsEntityClassNode {
    wh::S_DeltaMovementComputerParams m_computerParams;                      // +0x00
    std::vector<S_DeltaMovementParamsNode> m_logicalSpeedParams;             // +0x10 RTTR "LogicalSpeedParams"
    CryStringT<char> m_entityClassName;                                      // +0x28 RTTR "EntityClassName"
    std::uint8_t m_unknown30[8];                                             // +0x30
    S_DeltaMovementSurroundingDef m_surroundingDef;                          // +0x38 RTTR "SurroundingDef"
    std::vector<S_DeltaMovementPartialSurroundingRequirements>
        m_surroundingRequirements;                                           // +0x58 RTTR "SurroundingRequirements"
};

static_assert(offsetof(S_DeltaMovementParamsEntityClassNode,
                       m_logicalSpeedParams) == 0x10,
              "S_DeltaMovementParamsEntityClassNode::m_logicalSpeedParams offset mismatch");
static_assert(offsetof(S_DeltaMovementParamsEntityClassNode, m_entityClassName) ==
                  0x28,
              "S_DeltaMovementParamsEntityClassNode::m_entityClassName offset mismatch");
static_assert(offsetof(S_DeltaMovementParamsEntityClassNode, m_surroundingDef) ==
                  0x38,
              "S_DeltaMovementParamsEntityClassNode::m_surroundingDef offset mismatch");
static_assert(sizeof(S_DeltaMovementParamsEntityClassNode) == 0x70,
              "S_DeltaMovementParamsEntityClassNode size mismatch");

} // namespace wh::xgenaimodule::navigation
