#pragma once
#include <cstddef>
#include "C_SumCounter.h"

namespace wh::rpgmodule {

class C_ScriptCounter : public C_SumCounter<int> {
public:
    ~C_ScriptCounter() override;
    RTTR_ENABLE(C_SumCounter<int>)
};

static_assert(sizeof(C_ScriptCounter) == 0x28,
              "C_ScriptCounter size mismatch");

}  // namespace wh::rpgmodule
