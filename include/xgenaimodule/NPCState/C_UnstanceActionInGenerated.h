#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../../entitymodule/E_StanceCategory.h"
#include "C_UnstanceActionIn.h"

namespace wh::xgenaimodule::NPCState {

class C_UnstanceActionInGenerated : public C_UnstanceActionIn {
public:
    ~C_UnstanceActionInGenerated() override;
    RTTR_ENABLE(C_UnstanceActionIn)                                          // [24..26], vtable 0x183B91080

    CryStringT<char> m_fragmentName;                                         // +0x218 RTTR "FragmentName"
    std::vector<CryStringT<char>> m_tags;                                    // +0x220 RTTR "Tags"
    wh::entitymodule::E_StanceCategory::Type m_targetStance;                 // +0x238 RTTR "TargetStance"
    std::uint8_t m_padding23C[4];                                            // +0x23C
};

static_assert(offsetof(C_UnstanceActionInGenerated, m_fragmentName) == 0x218,
              "C_UnstanceActionInGenerated::m_fragmentName offset mismatch");
static_assert(offsetof(C_UnstanceActionInGenerated, m_targetStance) == 0x238,
              "C_UnstanceActionInGenerated::m_targetStance offset mismatch");
static_assert(sizeof(C_UnstanceActionInGenerated) == 0x240,
              "C_UnstanceActionInGenerated size mismatch");

} // namespace wh::xgenaimodule::NPCState
