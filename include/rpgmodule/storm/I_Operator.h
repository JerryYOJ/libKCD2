#pragma once
#include <cstddef>
#include "E_TaskClass.h"

namespace wh {
class C_DebugDraw;
}

namespace wh::rpgmodule {

class C_Soul;

namespace storm {

class C_Rule;

class I_Operator {
public:
    virtual ~I_Operator();                                        // [0]
    virtual void unk_01(C_Soul* soul, C_Rule* rule) = 0;          // [1] Storm apply
    virtual bool unk_02() = 0;                                    // [2]
    virtual E_TaskClass unk_03() = 0;                             // [3] task-class mask
    virtual void DebugDraw(wh::C_DebugDraw& draw) const = 0;      // [4] RTTR "DebugDraw"
};

static_assert(sizeof(I_Operator) == 0x08,
              "I_Operator size mismatch");

}  // namespace storm
}  // namespace wh::rpgmodule
