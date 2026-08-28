#pragma once

#include <cstddef>

#include "../conceptmodule/C_TypedPortRef.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "C_LinkEffectBase.h"

namespace wh::xgenaimodule {

class C_LinkEffectNoData : public C_LinkEffectBase {
public:
    C_LinkEffectNoData();                                                // 0x1816B7D54
    ~C_LinkEffectNoData() override;                                      // [0] 0x181998640
    RTTR_ENABLE(C_LinkEffectBase)                                        // [5..7], vtable 0x183AEB668

    wh::conceptmodule::C_TypedPortRef<CryStringT<char>> m_tag;           // +0x150 RTTR "Tag"
};

static_assert(offsetof(C_LinkEffectNoData, m_tag) == 0x150,
              "C_LinkEffectNoData::m_tag offset mismatch");
static_assert(sizeof(C_LinkEffectNoData) == 0x190,
              "C_LinkEffectNoData size mismatch");

} // namespace wh::xgenaimodule
