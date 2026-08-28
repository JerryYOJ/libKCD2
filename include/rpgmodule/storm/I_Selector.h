#pragma once
#include <cstddef>
#include "../../rttr/rttr_enable.h"

// -----------------------------------------------
// wh::rpgmodule::storm::I_Selector -- per-soul Storm predicate interface
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08; concrete vtables have 5 slots.
// -----------------------------------------------
// Slot [1] receives the C_Soul passed through the Storm rule executor. Its
// original source name and cv-qualification are not encoded, so the virtual
// remains honestly unnamed rather than assigning a behavior-only spelling.

namespace wh::rpgmodule {

class C_Soul;

namespace storm {

class I_Selector {
public:
    virtual ~I_Selector();                        // [0]
    virtual bool unk_01(C_Soul* soul) = 0;       // [1] per-soul predicate
    RTTR_ENABLE()                                 // [2..4]
};

static_assert(sizeof(I_Selector) == 0x08,
              "I_Selector size mismatch");

}  // namespace storm
}  // namespace wh::rpgmodule
