#pragma once
#include <cstddef>
#include "S_TriggerEffectCommandData.h"
#include "CryEngine/CryCommon/E_TriggerEffectMode.h"

struct S_TriggerEffectCommand {
    E_TriggerEffectMode::Type m_mode;                       // +0x00, RTTR "Mode"
    S_TriggerEffectCommandData m_data;                      // +0x01, RTTR "TriggerEffectCommandData"
};

static_assert(offsetof(S_TriggerEffectCommand, m_data) == 0x01,
              "S_TriggerEffectCommand::m_data offset mismatch");
static_assert(sizeof(S_TriggerEffectCommand) == 0x1D,
              "S_TriggerEffectCommand size mismatch");
