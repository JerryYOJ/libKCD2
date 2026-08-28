#pragma once

#include <cstddef>
#include <cstdint>
#include "../../CryEngine/CryCommon/CryString.h"

namespace wh::xgenaimodule::NPCState {

struct S_UnstanceTransitionData {
    CryStringT<char> m_sourceUnstanceName;                                   // +0x00 RTTR "SourceUnstanceName"
    CryStringT<char> m_targetUnstanceName;                                   // +0x08 RTTR "TargetUnstanceName"
    CryStringT<char> m_fragment;                                             // +0x10 RTTR "Fragment"
    std::uint8_t m_unknown18[0x18];                                          // +0x18 accessor Tags
    bool m_ignoreItemRelatedStateInSimulationCompare;                        // +0x30 RTTR "IgnoreItemRelatedStateInSimulationCompare"
    std::uint8_t m_padding31[0xF];                                           // +0x31
};

static_assert(offsetof(S_UnstanceTransitionData, m_sourceUnstanceName) == 0x00,
              "S_UnstanceTransitionData::m_sourceUnstanceName offset mismatch");
static_assert(offsetof(S_UnstanceTransitionData, m_fragment) == 0x10,
              "S_UnstanceTransitionData::m_fragment offset mismatch");
static_assert(
    offsetof(S_UnstanceTransitionData,
             m_ignoreItemRelatedStateInSimulationCompare) == 0x30,
    "S_UnstanceTransitionData::m_ignoreItemRelatedStateInSimulationCompare offset mismatch");
static_assert(sizeof(S_UnstanceTransitionData) == 0x40,
              "S_UnstanceTransitionData size mismatch");

} // namespace wh::xgenaimodule::NPCState
