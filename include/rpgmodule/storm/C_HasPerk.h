#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Selector.h"
#include "../../CryEngine/CryCommon/CryExtension/CryGUID.h"

namespace wh::rpgmodule::storm {
class C_HasPerk : public I_Selector {
public:
    ~C_HasPerk() override;
    bool unk_01(C_Soul* soul) override;
    RTTR_ENABLE(I_Selector)
    CryGUID m_id;  // +0x8 RTTR "ID"
};

static_assert(offsetof(C_HasPerk, m_id) == 0x8, "C_HasPerk::m_id offset mismatch");
static_assert(sizeof(C_HasPerk) == 0x18, "C_HasPerk size mismatch");

}  // namespace wh::rpgmodule::storm
