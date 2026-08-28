#pragma once

#include <cstddef>
#include <cstdint>

#include "C_FastForwardSyncAction.h"

namespace wh::xgenaimodule::NPCState {

class C_TeleportFastForwardSyncAction : public C_FastForwardSyncAction {
public:
    ~C_TeleportFastForwardSyncAction() override;
    RTTR_ENABLE(C_FastForwardSyncAction)                                     // [24..26], vtable 0x183FFD940

    std::uint8_t m_unknownC8[0x30];                                          // +0xC8
};

static_assert(sizeof(C_TeleportFastForwardSyncAction) == 0xF8,
              "C_TeleportFastForwardSyncAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
