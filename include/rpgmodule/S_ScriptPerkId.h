#pragma once
#include <cstddef>
#include "../rttr/rttr_enable.h"
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

namespace wh::rpgmodule {
class S_ScriptPerkId {
public:
    virtual ~S_ScriptPerkId();
    RTTR_ENABLE()  // [1..3]
    CryGUID m_id;  // +0x08
};

static_assert(sizeof(S_ScriptPerkId) == 0x18,
              "S_ScriptPerkId size mismatch");

}  // namespace wh::rpgmodule
