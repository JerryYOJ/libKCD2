#pragma once
#include <cstddef>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::xgenaimodule::S_TreeLocation
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x10. No vtable.
// -----------------------------------------------

namespace wh::xgenaimodule {

struct S_TreeLocation {
    CryStringT<char> m_fileName;                          // +0x00 RTTR "FileName"
    CryStringT<char> m_treeName;                          // +0x08 RTTR "TreeName"
};

static_assert(offsetof(S_TreeLocation, m_fileName) == 0x00,
              "S_TreeLocation::m_fileName offset mismatch");
static_assert(sizeof(S_TreeLocation) == 0x10,
              "S_TreeLocation size mismatch");

}  // namespace wh::xgenaimodule
