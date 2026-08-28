#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Selector.h"

namespace wh::rpgmodule::storm {
class C_HasSocialClass : public I_Selector {
public:
    ~C_HasSocialClass() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
    std::int32_t m_id;  // +0x8 RTTR "ID"
    std::uint8_t m_unknown0C[0x4];                  // +0xC
};

static_assert(offsetof(C_HasSocialClass, m_id) == 0x8, "C_HasSocialClass::m_id offset mismatch");
static_assert(sizeof(C_HasSocialClass) == 0x10, "C_HasSocialClass size mismatch");

}  // namespace wh::rpgmodule::storm
