#pragma once
#include <cstddef>
#include "../../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "C_FilteringConditionHandContentBase.h"

namespace wh::xgenaimodule::NPCState {

class C_FilteringConditionIsItemClass : public C_FilteringConditionHandContentBase {
public:
    ~C_FilteringConditionIsItemClass() override;
    RTTR_ENABLE(C_FilteringConditionHandContentBase)
    bool unk_09() override;
    CryGUID m_itemClass;                                  // +0x18 RTTR "ItemClass"
};

static_assert(offsetof(C_FilteringConditionIsItemClass, m_itemClass) == 0x18,
              "C_FilteringConditionIsItemClass::m_itemClass offset mismatch");
static_assert(sizeof(C_FilteringConditionIsItemClass) == 0x28,
              "C_FilteringConditionIsItemClass size mismatch");

}  // namespace wh::xgenaimodule::NPCState
