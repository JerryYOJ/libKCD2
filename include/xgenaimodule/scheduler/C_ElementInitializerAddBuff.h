#pragma once
#include <cstddef>
#include "../../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "C_ElementInitializerBase.h"

namespace wh::xgenaimodule::scheduler {

class C_ElementInitializerAddBuff : public C_ElementInitializerBase {
public:
    ~C_ElementInitializerAddBuff() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    RTTR_ENABLE(C_ElementInitializerBase)
    CryGUID m_buffId;                                     // +0x18 RTTR "BuffId"
};

static_assert(offsetof(C_ElementInitializerAddBuff, m_buffId) == 0x18,
              "C_ElementInitializerAddBuff::m_buffId offset mismatch");
static_assert(sizeof(C_ElementInitializerAddBuff) == 0x28,
              "C_ElementInitializerAddBuff size mismatch");

}  // namespace wh::xgenaimodule::scheduler
