#pragma once

#include <cstddef>
#include <cstdint>

#include "I_CallbackEventSource.h"
#include "S_BaseNodeContext.h"
#include "S_BaseNodeContextGeneratedAttributes.h"

namespace wh::xgenaimodule::BehaviorTree {

struct S_InstantFireCallbackContext
    : S_BaseNodeContextGeneratedAttributes<S_BaseNodeContext>,
      I_CallbackEventSource {
    void unk_0() override;
    std::uint8_t m_unknown20[0x38];                                          // +0x20
};

static_assert(sizeof(S_InstantFireCallbackContext) == 0x58,
              "S_InstantFireCallbackContext size mismatch");

} // namespace wh::xgenaimodule::BehaviorTree
