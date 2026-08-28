#pragma once
#include <cstddef>
#include <cstdint>
#include "C_ElementInitializerBase.h"

namespace wh::xgenaimodule::scheduler {

class C_ElementInitializerEnableRoleOnHub : public C_ElementInitializerBase {
public:
    ~C_ElementInitializerEnableRoleOnHub() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    RTTR_ENABLE(C_ElementInitializerBase)
    std::uint8_t m_unknown18[8];                          // +0x18 EnabledRole accessor
};

static_assert(sizeof(C_ElementInitializerEnableRoleOnHub) == 0x20,
              "C_ElementInitializerEnableRoleOnHub size mismatch");

}  // namespace wh::xgenaimodule::scheduler
