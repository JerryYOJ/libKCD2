#pragma once
#include <cstddef>
#include "C_PhotomodeUIElementBase.h"

namespace wh::game {

class C_PhotomodeSettingChoiceElement : public C_PhotomodeUIElementBase {
public:
    ~C_PhotomodeSettingChoiceElement() override;
    RTTR_ENABLE(C_PhotomodeUIElementBase)
};

static_assert(sizeof(C_PhotomodeSettingChoiceElement) == 0x18,
              "C_PhotomodeSettingChoiceElement size mismatch");

}  // namespace wh::game
