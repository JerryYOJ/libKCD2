#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>
#include "C_PhotomodeSettingBase.h"
#include "C_PhotomodeSettingChoiceElement.h"

namespace wh::game {

class C_PhotomodeSettingChoice : public C_PhotomodeSettingBase {
public:
    ~C_PhotomodeSettingChoice() override;
    RTTR_ENABLE(C_PhotomodeSettingBase)

    int m_unknown40;                                        // +0x40 RTTR duplicate owner label
    std::uint8_t _pad44[4];                                 // +0x44
    std::vector<std::shared_ptr<C_PhotomodeSettingChoiceElement>> m_choices; // +0x48 RTTR duplicate owner label
};

static_assert(offsetof(C_PhotomodeSettingChoice, m_unknown40) == 0x40,
              "C_PhotomodeSettingChoice::m_unknown40 offset mismatch");
static_assert(offsetof(C_PhotomodeSettingChoice, m_choices) == 0x48,
              "C_PhotomodeSettingChoice::m_choices offset mismatch");
static_assert(sizeof(C_PhotomodeSettingChoice) == 0x60,
              "C_PhotomodeSettingChoice size mismatch");

}  // namespace wh::game
