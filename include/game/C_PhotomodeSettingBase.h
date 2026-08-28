#pragma once
#include <cstddef>
#include <cstdint>
#include "C_PhotomodeUIElementBase.h"
#include "E_PhotomodeParameterSourceType.h"
#include "E_PhotomodeParameterType.h"

namespace wh::game {

class C_PhotomodeSettingBase : public C_PhotomodeUIElementBase {
public:
    ~C_PhotomodeSettingBase() override;                     // [0]
    RTTR_ENABLE(C_PhotomodeUIElementBase)                   // [1..3]

    E_PhotomodeParameterType::Type m_parameterType;         // +0x18
    std::uint8_t _pad19[7];                                 // +0x19
    CryStringT<char> m_parameterId;                         // +0x20 RTTR "ParameterId"
    E_PhotomodeParameterSourceType::Type m_parameterSourceType; // +0x28
    std::uint8_t _pad29[7];                                 // +0x29
    CryStringT<char> m_converterParameters;                 // +0x30 RTTR "ConverterParameters"
    bool m_useDefault;                                      // +0x38 RTTR "UseDefault"
    bool m_resetOnEnter;                                    // +0x39 RTTR "ResetOnEnter"
    std::uint8_t _pad3A[6];                                 // +0x3A
};

static_assert(offsetof(C_PhotomodeSettingBase, m_parameterType) == 0x18,
              "C_PhotomodeSettingBase::m_parameterType offset mismatch");
static_assert(offsetof(C_PhotomodeSettingBase, m_parameterId) == 0x20,
              "C_PhotomodeSettingBase::m_parameterId offset mismatch");
static_assert(offsetof(C_PhotomodeSettingBase, m_converterParameters) == 0x30,
              "C_PhotomodeSettingBase::m_converterParameters offset mismatch");
static_assert(sizeof(C_PhotomodeSettingBase) == 0x40,
              "C_PhotomodeSettingBase size mismatch");

}  // namespace wh::game
