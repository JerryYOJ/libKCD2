#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Selector.h"
#include "../S_LocationId.h"

namespace wh::rpgmodule::storm {
class C_HasLocation : public I_Selector {
public:
    ~C_HasLocation() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
    S_LocationId m_id;  // +0x8 RTTR "ID"
};

static_assert(offsetof(C_HasLocation, m_id) == 0x8, "C_HasLocation::m_id offset mismatch");
static_assert(sizeof(C_HasLocation) == 0x18, "C_HasLocation size mismatch");

}  // namespace wh::rpgmodule::storm
