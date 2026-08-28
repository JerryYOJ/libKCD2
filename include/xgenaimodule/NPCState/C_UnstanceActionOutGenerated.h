#pragma once

#include <cstddef>
#include <vector>

#include "C_UnstanceActionOut.h"

namespace wh::xgenaimodule::NPCState {

class C_UnstanceActionOutGenerated : public C_UnstanceActionOut {
public:
    ~C_UnstanceActionOutGenerated() override;
    RTTR_ENABLE(C_UnstanceActionOut)                                         // [24..26], vtable 0x183B908E8

    CryStringT<char> m_fragmentName;                                         // +0x288 RTTR "FragmentName"
    std::vector<CryStringT<char>> m_tags;                                    // +0x290 RTTR "Tags"
};

static_assert(offsetof(C_UnstanceActionOutGenerated, m_fragmentName) == 0x288,
              "C_UnstanceActionOutGenerated::m_fragmentName offset mismatch");
static_assert(sizeof(C_UnstanceActionOutGenerated) == 0x2A8,
              "C_UnstanceActionOutGenerated size mismatch");

} // namespace wh::xgenaimodule::NPCState
