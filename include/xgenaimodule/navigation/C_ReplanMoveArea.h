#pragma once

#include "../I_Area.h"
#include "../../framework/WUID.h"

namespace wh::xgenaimodule::navigation {

class C_ReplanMoveArea : public I_Area {
public:
    framework::WUID m_wuid;       // +0x08
    std::uint8_t _unknown10[0x90];
};
static_assert(sizeof(C_ReplanMoveArea) == 0xA0, "C_ReplanMoveArea must be 0xA0");

}  // namespace wh::xgenaimodule::navigation
