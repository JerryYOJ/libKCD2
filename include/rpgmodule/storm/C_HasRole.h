#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Selector.h"
#include "../S_RoleId.h"

namespace wh::rpgmodule::storm {
class C_HasRole : public I_Selector {
public:
    ~C_HasRole() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
    S_RoleId m_name;  // +0x8 RTTR "name"
    std::uint8_t m_unknown0A[0x6];                  // +0xA
};

static_assert(offsetof(C_HasRole, m_name) == 0x8, "C_HasRole::m_name offset mismatch");
static_assert(sizeof(C_HasRole) == 0x10, "C_HasRole size mismatch");

}  // namespace wh::rpgmodule::storm
