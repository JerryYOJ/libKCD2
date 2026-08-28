#pragma once
#include <cstddef>
#include <cstdint>
#include "S_TriggerEffectCommand.h"
#include "CryEngine/CryCommon/CryString.h"
#include "CryEngine/CryCommon/E_TriggerEffectType.h"

struct S_TriggerEffect {
    std::uint8_t m_unknown00;                              // +0x00, unreflected
    S_TriggerEffectCommand m_command;                      // +0x01, RTTR "TriggerEffectCommand"
    std::uint8_t m_padding1E[2];
    CryStringT<char> m_action;                             // +0x20, RTTR "Action"
    bool m_requiresActivation;                             // +0x28, RTTR "RequiresActivation"
    E_TriggerEffectType::Type m_effectType;                // +0x29, RTTR "EffectType"
    std::uint8_t m_padding2A[6];
};

static_assert(offsetof(S_TriggerEffect, m_command) == 0x01,
              "S_TriggerEffect::m_command offset mismatch");
static_assert(offsetof(S_TriggerEffect, m_action) == 0x20,
              "S_TriggerEffect::m_action offset mismatch");
static_assert(sizeof(S_TriggerEffect) == 0x30,
              "S_TriggerEffect size mismatch");
