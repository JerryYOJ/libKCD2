#pragma once

#include <cstddef>
#include <cstdint>

#include "C_ChangeUnstanceAction.h"

namespace wh::xgenaimodule::NPCState {

class C_UnstanceActionOut : public C_ChangeUnstanceAction {
public:
    ~C_UnstanceActionOut() override;
    RTTR_ENABLE(C_ChangeUnstanceAction)                                      // [24..26], vtable 0x183A44758

    std::uint8_t m_unknown218[0x70];                                         // +0x218
};

static_assert(sizeof(C_UnstanceActionOut) == 0x288,
              "C_UnstanceActionOut size mismatch");

} // namespace wh::xgenaimodule::NPCState
