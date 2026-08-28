#pragma once
#include <cstddef>
#include <cstdint>
#include "C_ElementInitializerBase.h"

// Binary spelling C_ElementInitiazerEnableBehaviorForNPC (missing 'l') is preserved.

namespace wh::xgenaimodule::scheduler {

class C_ElementInitiazerEnableBehaviorForNPC : public C_ElementInitializerBase {
public:
    ~C_ElementInitiazerEnableBehaviorForNPC() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    RTTR_ENABLE(C_ElementInitializerBase)
    std::uint8_t m_unknown18[8];                          // +0x18 Behavior accessor
};

static_assert(sizeof(C_ElementInitiazerEnableBehaviorForNPC) == 0x20,
              "C_ElementInitiazerEnableBehaviorForNPC size mismatch");

}  // namespace wh::xgenaimodule::scheduler
