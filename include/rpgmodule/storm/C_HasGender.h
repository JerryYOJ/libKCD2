#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Selector.h"
#include "../../entitymodule/E_ActorGender.h"

namespace wh::rpgmodule::storm {
class C_HasGender : public I_Selector {
public:
    ~C_HasGender() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
    wh::entitymodule::E_ActorGender m_gender;  // +0x8 RTTR "name"
    std::uint8_t m_unknown09[0x7];                  // +0x9
};

static_assert(offsetof(C_HasGender, m_gender) == 0x8, "C_HasGender::m_gender offset mismatch");
static_assert(sizeof(C_HasGender) == 0x10, "C_HasGender size mismatch");

}  // namespace wh::rpgmodule::storm
