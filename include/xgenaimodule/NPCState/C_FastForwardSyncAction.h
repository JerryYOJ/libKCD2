#pragma once

#include <cstddef>

#include "C_FastForwardHandlingAction.h"

namespace wh::xgenaimodule::NPCState {

class C_FastForwardSyncAction : public C_FastForwardHandlingAction {
public:
    ~C_FastForwardSyncAction() override;                                     // [0] 0x181940BA4
    RTTR_ENABLE(C_FastForwardHandlingAction)                                 // [24..26], vtable 0x183FFA850
};

static_assert(sizeof(C_FastForwardSyncAction) == 0xC8,
              "C_FastForwardSyncAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
