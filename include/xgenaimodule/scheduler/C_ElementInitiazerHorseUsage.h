#pragma once
#include <cstddef>
#include "C_ElementInitializerBase.h"

// Binary spelling C_ElementInitiazerHorseUsage (missing 'l') is preserved.

namespace wh::xgenaimodule::scheduler {

class C_ElementInitiazerHorseUsage : public C_ElementInitializerBase {
public:
    ~C_ElementInitiazerHorseUsage() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    RTTR_ENABLE(C_ElementInitializerBase)
};

static_assert(sizeof(C_ElementInitiazerHorseUsage) == 0x18,
              "C_ElementInitiazerHorseUsage size mismatch");

}  // namespace wh::xgenaimodule::scheduler
