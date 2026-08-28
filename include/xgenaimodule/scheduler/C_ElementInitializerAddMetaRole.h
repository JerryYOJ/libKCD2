#pragma once
#include <cstddef>
#include "../../CryEngine/CryCommon/CryString.h"
#include "C_ElementInitializerBase.h"

namespace wh::xgenaimodule::scheduler {

class C_ElementInitializerAddMetaRole : public C_ElementInitializerBase {
public:
    ~C_ElementInitializerAddMetaRole() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    RTTR_ENABLE(C_ElementInitializerBase)
    CryStringT<char> m_enabledMetaRole;                   // +0x18 RTTR "EnabledMetaRole"
};

static_assert(offsetof(C_ElementInitializerAddMetaRole, m_enabledMetaRole) == 0x18,
              "C_ElementInitializerAddMetaRole::m_enabledMetaRole offset mismatch");
static_assert(sizeof(C_ElementInitializerAddMetaRole) == 0x20,
              "C_ElementInitializerAddMetaRole size mismatch");

}  // namespace wh::xgenaimodule::scheduler
