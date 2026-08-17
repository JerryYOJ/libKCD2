#pragma once
#include <cstddef>
#include <cstdint>

struct SPredictedCharacterStates {
    float m_motionParameter[6];   // +0x00
    std::uint8_t m_motionParameterID[6]; // +0x18
    std::uint8_t m_numParams;     // +0x1E
    std::uint8_t _pad1F;          // +0x1F
};
static_assert(sizeof(SPredictedCharacterStates) == 0x20,
              "SPredictedCharacterStates must be 0x20");
static_assert(offsetof(SPredictedCharacterStates, m_motionParameterID) == 0x18);
static_assert(offsetof(SPredictedCharacterStates, m_numParams) == 0x1E);
