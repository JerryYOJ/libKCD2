#pragma once
#include <cstddef>
#include <cstdint>
#include "../E_AddRemove.h"
#include "C_ElementInitializerBase.h"

namespace wh::xgenaimodule::scheduler {

class C_ElementInitializerChangeAreaLabel : public C_ElementInitializerBase {
public:
    ~C_ElementInitializerChangeAreaLabel() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    RTTR_ENABLE(C_ElementInitializerBase)
    wh::xgenaimodule::E_AddRemove::Type m_operation;      // +0x18 RTTR "Operation"
    std::uint8_t _pad19[7];                               // +0x19 Label accessor
};

static_assert(offsetof(C_ElementInitializerChangeAreaLabel, m_operation) == 0x18,
              "C_ElementInitializerChangeAreaLabel::m_operation offset mismatch");
static_assert(sizeof(C_ElementInitializerChangeAreaLabel) == 0x20,
              "C_ElementInitializerChangeAreaLabel size mismatch");

}  // namespace wh::xgenaimodule::scheduler
