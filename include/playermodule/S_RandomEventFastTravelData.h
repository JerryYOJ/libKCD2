#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"
#include "../framework/C_LocalizedString.h"
#include "E_RandomEventMapIcon.h"

namespace wh::playermodule {

struct S_RandomEventOptionSet;

struct S_RandomEventFastTravelData {
    E_RandomEventMapIcon::Type m_mapIcon;                   // +0x00 RTTR "MapIcon"
    std::uint8_t _pad01[7];                                 // +0x01
    wh::framework::C_LocalizedString m_caption;             // +0x08 RTTR "Caption"
    wh::framework::C_LocalizedString m_description;         // +0x18 RTTR "Description"
    S_RandomEventOptionSet* m_optionSet;                    // +0x28 accessor backing "OptionSet"
};

static_assert(offsetof(S_RandomEventFastTravelData, m_caption) == 0x08,
              "S_RandomEventFastTravelData::m_caption offset mismatch");
static_assert(offsetof(S_RandomEventFastTravelData, m_description) == 0x18,
              "S_RandomEventFastTravelData::m_description offset mismatch");
static_assert(offsetof(S_RandomEventFastTravelData, m_optionSet) == 0x28,
              "S_RandomEventFastTravelData::m_optionSet offset mismatch");
static_assert(sizeof(S_RandomEventFastTravelData) == 0x30,
              "S_RandomEventFastTravelData size mismatch");

}  // namespace wh::playermodule
