#pragma once
#include <cstddef>
#include "../../rttr/rttr_enable.h"

namespace wh::xgenaimodule::NPCState {

class I_Effect {
public:
    virtual ~I_Effect();                                  // [0] 0x183320D7C
    virtual void unk_01() = 0;                            // [1]
    virtual void unk_02() = 0;                            // [2]
    virtual void unk_03() = 0;                            // [3]
    virtual bool unk_04() = 0;                            // [4] C_EffectBase writes true thunk
    virtual bool unk_05() = 0;                            // [5]
    virtual bool unk_06() = 0;                            // [6] C_EffectBase writes false thunk
    virtual bool unk_07() = 0;                            // [7]
    virtual bool unk_08() = 0;                            // [8]
    virtual bool unk_09() = 0;                            // [9]
    RTTR_ENABLE()                                         // [10..12]
};

static_assert(sizeof(I_Effect) == 0x08,
              "I_Effect size mismatch");

}  // namespace wh::xgenaimodule::NPCState
