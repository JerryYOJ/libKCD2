#pragma once
#include <cstddef>
#include <cstdint>
#include "C_ElementInitializerBase.h"

namespace wh::xgenaimodule::scheduler {

class C_ElementInitializerAddContext : public C_ElementInitializerBase {
public:
    ~C_ElementInitializerAddContext() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    RTTR_ENABLE(C_ElementInitializerBase)
    std::uint8_t m_unknown18[8];                          // +0x18 Context accessor
    bool m_invert;                                        // +0x20 RTTR "Invert"
    std::uint8_t _pad21[7];                               // +0x21
};

static_assert(offsetof(C_ElementInitializerAddContext, m_invert) == 0x20,
              "C_ElementInitializerAddContext::m_invert offset mismatch");
static_assert(sizeof(C_ElementInitializerAddContext) == 0x28,
              "C_ElementInitializerAddContext size mismatch");

}  // namespace wh::xgenaimodule::scheduler
