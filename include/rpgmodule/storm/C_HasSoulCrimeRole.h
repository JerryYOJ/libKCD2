#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Selector.h"
#include "../E_SoulCrimeRole.h"

namespace wh::rpgmodule::storm {
class C_HasSoulCrimeRole : public I_Selector {
public:
    ~C_HasSoulCrimeRole() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
    E_SoulCrimeRole::Type m_id;  // +0x8 RTTR "ID"
    std::uint8_t m_unknown0C[0x4];                  // +0xC
};

static_assert(offsetof(C_HasSoulCrimeRole, m_id) == 0x8, "C_HasSoulCrimeRole::m_id offset mismatch");
static_assert(sizeof(C_HasSoulCrimeRole) == 0x10, "C_HasSoulCrimeRole size mismatch");

}  // namespace wh::rpgmodule::storm
