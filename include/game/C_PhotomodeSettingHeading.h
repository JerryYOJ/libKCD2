#pragma once
#include <cstddef>
#include "C_PhotomodeUIElementBase.h"

namespace wh::game {

class C_PhotomodeSettingHeading : public C_PhotomodeUIElementBase {
public:
    ~C_PhotomodeSettingHeading() override;
    RTTR_ENABLE(C_PhotomodeUIElementBase)
};

static_assert(sizeof(C_PhotomodeSettingHeading) == 0x18,
              "C_PhotomodeSettingHeading size mismatch");

}  // namespace wh::game
