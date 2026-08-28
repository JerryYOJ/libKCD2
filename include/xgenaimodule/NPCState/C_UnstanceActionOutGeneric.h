#pragma once

#include <cstddef>
#include <cstdint>

#include "C_UnstanceActionOut.h"

namespace wh::xgenaimodule::NPCState {

class C_UnstanceActionOutGeneric : public C_UnstanceActionOut {
public:
    ~C_UnstanceActionOutGeneric() override;
    RTTR_ENABLE(C_UnstanceActionOut)                                         // [24..26], vtable 0x183C71528

    CryStringT<char> m_fragmentName;                                         // +0x288 RTTR "FragmentName"
    std::uint8_t m_padding290[8];                                            // +0x290
};

static_assert(offsetof(C_UnstanceActionOutGeneric, m_fragmentName) == 0x288,
              "C_UnstanceActionOutGeneric::m_fragmentName offset mismatch");
static_assert(sizeof(C_UnstanceActionOutGeneric) == 0x298,
              "C_UnstanceActionOutGeneric size mismatch");

} // namespace wh::xgenaimodule::NPCState
