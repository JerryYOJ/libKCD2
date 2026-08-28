#pragma once
#include <cstddef>
#include <memory>
#include <vector>
#include "I_Selector.h"

// -----------------------------------------------
// wh::rpgmodule::storm::C_CompositeSelector : I_Selector
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x20.
// -----------------------------------------------
// The direct zero-adjustment base is certified by the C_CustomSelector MSVC
// preorder and RTTR base builder. The child vector is an exact RTTR member at
// +0x08; duplicate registrations describe the same physical member.

namespace wh::rpgmodule::storm {

class C_CompositeSelector : public I_Selector {
public:
    std::vector<std::shared_ptr<I_Selector>> m_selectors; // +0x08 RTTR "selectors"
};

static_assert(offsetof(C_CompositeSelector, m_selectors) == 0x08,
              "C_CompositeSelector::m_selectors offset mismatch");
static_assert(sizeof(C_CompositeSelector) == 0x20,
              "C_CompositeSelector size mismatch");

}  // namespace wh::rpgmodule::storm
