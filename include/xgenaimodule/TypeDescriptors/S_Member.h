#pragma once
#include <cstddef>
#include <cstdint>
#include "../../CryEngine/CryCommon/CryString.h"
#include "../E_ConceptAIWuidType.h"

// -----------------------------------------------
// wh::xgenaimodule::TypeDescriptors::S_Member
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x20. No vtable.
// -----------------------------------------------

namespace wh::xgenaimodule::TypeDescriptors {

struct S_Member {
    CryStringT<char> m_name;                              // +0x00 RTTR "Name"
    CryStringT<char> m_type;                              // +0x08 RTTR "Type"
    CryStringT<char> m_initialValue;                      // +0x10 RTTR "InitialValue"
    wh::xgenaimodule::E_ConceptAIWuidType::Type m_conceptWuidType; // +0x18 RTTR "ConceptWuidType"
    std::uint8_t _pad19[7];                               // +0x19
};

static_assert(offsetof(S_Member, m_name) == 0x00,
              "S_Member::m_name offset mismatch");
static_assert(offsetof(S_Member, m_conceptWuidType) == 0x18,
              "S_Member::m_conceptWuidType offset mismatch");
static_assert(sizeof(S_Member) == 0x20,
              "S_Member size mismatch");

}  // namespace wh::xgenaimodule::TypeDescriptors
