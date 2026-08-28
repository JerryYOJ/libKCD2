#pragma once
#include <cstddef>
#include <cstdint>
#include <string>

struct S_TriggerEffectCommandData {
    std::string GetStrengthArray() const;                  // 0x1825ED1DC, reads +0x08..+0x11
    void SetStrengthArray(std::string value);              // 0x1825ED1BC, writes +0x08..+0x11
    std::string GetAmplitudeArray() const;                 // 0x1825EC74C, reads +0x12..+0x1B
    void SetAmplitudeArray(std::string value);             // 0x1825EC72C, writes +0x12..+0x1B

    std::uint8_t m_position;                               // +0x00, RTTR "Position"
    std::uint8_t m_startPosition;                          // +0x01, RTTR "StartPosition"
    std::uint8_t m_endPosition;                            // +0x02, RTTR "EndPosition"
    std::uint8_t m_amplitude;                              // +0x03, RTTR "Amplitude"
    std::uint8_t m_frequency;                              // +0x04, RTTR "Frequency"
    std::uint8_t m_strength;                               // +0x05, RTTR "Strength"
    std::uint8_t m_proxyNames;                             // +0x06, RTTR "ProxyNames"
    std::uint8_t m_endStrength;                            // +0x07, RTTR "EndStrength"
    std::uint8_t m_strengthArray[10];                      // +0x08, accessor-backed
    std::uint8_t m_amplitudeArray[10];                     // +0x12, accessor-backed
};

static_assert(offsetof(S_TriggerEffectCommandData, m_strengthArray) == 0x08,
              "S_TriggerEffectCommandData::m_strengthArray offset mismatch");
static_assert(offsetof(S_TriggerEffectCommandData, m_amplitudeArray) == 0x12,
              "S_TriggerEffectCommandData::m_amplitudeArray offset mismatch");
static_assert(sizeof(S_TriggerEffectCommandData) == 0x1C,
              "S_TriggerEffectCommandData size mismatch");
