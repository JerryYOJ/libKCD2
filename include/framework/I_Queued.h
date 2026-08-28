#pragma once

#include <cstddef>

namespace wh::framework {

class I_Queued {
public:
    virtual void unk_0() = 0;                                                // [0]
    virtual void unk_1() = 0;                                                // [1]
};

static_assert(sizeof(I_Queued) == 0x08, "I_Queued size mismatch");

} // namespace wh::framework
