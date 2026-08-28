#pragma once

#include <cstddef>

namespace wh::xgenaimodule::NPCState {

class I_QueueableAction {
public:
    virtual void unk_0() = 0;                                                // [0]
};

static_assert(sizeof(I_QueueableAction) == 0x08,
              "I_QueueableAction size mismatch");

} // namespace wh::xgenaimodule::NPCState
