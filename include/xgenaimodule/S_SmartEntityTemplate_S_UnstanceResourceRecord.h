#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"
#include "S_SmartEntityTemplate.h"

namespace wh::xgenaimodule {

struct S_SmartEntityTemplate::S_UnstanceResourceRecord {
    CryStringT<char> m_unstance;                            // +0x00 RTTR "Unstance"
    CryStringT<char> m_resource;                            // +0x08 RTTR "Resource"
};

static_assert(offsetof(S_SmartEntityTemplate::S_UnstanceResourceRecord, m_resource) == 0x08,
              "S_UnstanceResourceRecord::m_resource offset mismatch");
static_assert(sizeof(S_SmartEntityTemplate::S_UnstanceResourceRecord) == 0x10,
              "S_UnstanceResourceRecord size mismatch");

}  // namespace wh::xgenaimodule
