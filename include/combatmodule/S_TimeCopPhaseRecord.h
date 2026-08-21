#pragma once
#include <cstddef>
#include <cstdint>
#include "E_TimeCopPhaseKind.h"

namespace wh::combatmodule {

struct S_TimeCopPhaseRecord {
    E_TimeCopPhaseKind m_kind;           // +0x00
    std::uint8_t       _pad01[3];        // +0x01
    float              m_dilatedTarget;  // +0x04
    float              m_referenceTarget;// +0x08
    float              m_dilatedLeft;    // +0x0C
    float              m_referenceLeft;  // +0x10
};
static_assert(sizeof(S_TimeCopPhaseRecord) == 0x14);
static_assert(offsetof(S_TimeCopPhaseRecord, m_kind) == 0x00);
static_assert(offsetof(S_TimeCopPhaseRecord, m_dilatedTarget) == 0x04);
static_assert(offsetof(S_TimeCopPhaseRecord, m_referenceLeft) == 0x10);

}  // namespace wh::combatmodule
