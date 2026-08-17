#pragma once
#include <cstdint>
#include <vector>
#include "I_NavigationElement.h"

// -----------------------------------------------
// wh::xgenaimodule::navigation::S_PathFindingResult -- FindPath output container
// (KCD2 WHGame.dll 1.5.6).  sizeof 0x18. RTTI spelling from functor mangles
// (`AEBUS_PathFindingResult`); no standalone TypeDescriptor / vtable.
// -----------------------------------------------
// I_Navigation::CreatePathResult [34] (sub_1834100E8) allocates 0x18 and zeroes
// it. DestroyPathResult [35] (sub_183410238) calls each element's vf[0](1) then
// frees the block. Walk m_elements and I_NavigationElement::GetPoints/GetLength
// — do not wrap the game's flatten/sum helpers.

namespace wh::xgenaimodule::navigation {

struct S_PathFindingResult {
    std::vector<I_NavigationElement*> m_elements;           // +0x00
};
static_assert(sizeof(S_PathFindingResult) == 0x18, "S_PathFindingResult is one pointer vector");

}  // namespace wh::xgenaimodule::navigation
