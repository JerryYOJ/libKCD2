#pragma once

#include <cstddef>
#include <cstdint>

#include "C_UnstanceActionOut.h"

namespace wh::xgenaimodule::NPCState {

class C_UnstanceActionOutStatic : public C_UnstanceActionOut {
public:
    ~C_UnstanceActionOutStatic() override;
    RTTR_ENABLE(C_UnstanceActionOut)                                         // [24..26], vtable 0x183B7A638

    bool m_hasSingleOption;                                                  // +0x288 RTTR "HasSingleOption"
    std::uint8_t m_padding289[7];                                            // +0x289
};

static_assert(offsetof(C_UnstanceActionOutStatic, m_hasSingleOption) == 0x288,
              "C_UnstanceActionOutStatic::m_hasSingleOption offset mismatch");
static_assert(sizeof(C_UnstanceActionOutStatic) == 0x290,
              "C_UnstanceActionOutStatic size mismatch");

} // namespace wh::xgenaimodule::NPCState
