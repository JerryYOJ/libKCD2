#pragma once
#include <cstddef>
#include <vector>
#include <boost/optional.hpp>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "S_CIPilePhase.h"

namespace wh::entitymodule {

struct S_CarryItemPileGeom {
    CryStringT<char> m_name;                       // +0x00
    CryGUID m_id;                                  // +0x08
    boost::optional<CryStringT<char>> m_unpacked; // +0x18
    CryStringT<char> m_defaultModel;               // +0x28
    std::vector<S_CIPilePhase> m_phases;           // +0x30
    CryStringT<char> m_pickupAnimTag;              // +0x48
    CryStringT<char> m_depositAnimTag;             // +0x50
    CryStringT<char> m_packAudioSwitchState;       // +0x58

    void AfterDeserialization(); // 0x1812998D8
};
static_assert(sizeof(S_CarryItemPileGeom) == 0x60,
              "S_CarryItemPileGeom must be 0x60");
static_assert(offsetof(S_CarryItemPileGeom, m_unpacked) == 0x18,
              "unpacked model must be at 0x18");
static_assert(offsetof(S_CarryItemPileGeom, m_phases) == 0x30,
              "pile phases must be at 0x30");
static_assert(offsetof(S_CarryItemPileGeom, m_packAudioSwitchState) == 0x58,
              "pack audio state must be at 0x58");

}  // namespace wh::entitymodule
