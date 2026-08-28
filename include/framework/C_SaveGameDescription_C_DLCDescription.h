#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"
#include "../shared/E_DLC.h"
#include "C_SaveGameDescription.h"

namespace wh::framework {

class C_SaveGameDescription::C_DLCDescription {
public:
    virtual ~C_DLCDescription();                             // [0] 0x18140DFA0
    RTTR_ENABLE()                                             // [1..3]

    wh::shared::E_DLC::Type m_id;                            // +0x08 RTTR "Id"
    CryStringT<char> m_unknown10;                            // +0x10 unreflected
};

static_assert(offsetof(C_SaveGameDescription::C_DLCDescription, m_id) == 0x08,
              "C_DLCDescription::m_id offset mismatch");
static_assert(offsetof(C_SaveGameDescription::C_DLCDescription, m_unknown10) == 0x10,
              "C_DLCDescription::m_unknown10 offset mismatch");
static_assert(sizeof(C_SaveGameDescription::C_DLCDescription) == 0x18,
              "C_DLCDescription size mismatch");

}  // namespace wh::framework
