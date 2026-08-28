#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "../CryEngine/CryCommon/CryString.h"
#include "S_ItemManipulationAnim.h"
#include "S_ItemTransformation.h"

namespace wh::entitymodule {

struct S_ItemManipulationVariation {
    int m_unknown00;                                         // +0x00 duplicate owner label
    std::uint32_t m_unknown04;                               // +0x04
    CryStringT<char> m_slotTag;                              // +0x08 RTTR "SlotTag"
    std::shared_ptr<S_ItemManipulationAnim> m_pickUpAnimation; // +0x10 RTTR "PickUpAnimation"
    std::shared_ptr<S_ItemManipulationAnim> m_placeAnimation; // +0x20 RTTR "PlaceAnimation"
    std::shared_ptr<S_ItemTransformation> m_itemTransformation; // +0x30 RTTR "ItemTransformation"
};

static_assert(offsetof(S_ItemManipulationVariation, m_slotTag) == 0x08,
              "S_ItemManipulationVariation::m_slotTag offset mismatch");
static_assert(offsetof(S_ItemManipulationVariation, m_pickUpAnimation) == 0x10,
              "S_ItemManipulationVariation::m_pickUpAnimation offset mismatch");
static_assert(offsetof(S_ItemManipulationVariation, m_itemTransformation) == 0x30,
              "S_ItemManipulationVariation::m_itemTransformation offset mismatch");
static_assert(sizeof(S_ItemManipulationVariation) == 0x40,
              "S_ItemManipulationVariation size mismatch");

}  // namespace wh::entitymodule
