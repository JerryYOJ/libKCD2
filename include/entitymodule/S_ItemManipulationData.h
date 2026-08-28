#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

#include "S_ItemManipulationVariation.h"

namespace wh::entitymodule {

struct S_ItemManipulationData {
    enum Flag : std::uint32_t {
        AllowRunFlag = 0x02,
        AllowSprintFlag = 0x04,
        UsesBothHandsFlag = 0x08,
    };

    bool AllowRun() const;                       // 0x181C5C040
    void SetAllowRun(bool enabled);              // 0x18133C178
    bool AllowSprint() const;                    // 0x182A89B10
    void SetAllowSprint(bool enabled);           // 0x18133C15C
    bool UsesBothHands() const;                  // 0x182A89FA4
    void SetUsesBothHands(bool enabled);         // 0x18133C374

    std::int32_t m_id;                           // +0x00 RTTR "Id"
    std::uint32_t m_padding04;
    CryStringT<char> m_tag;                      // +0x08 RTTR "Tag"
    CryStringT<char> m_sharpeningAnim;           // +0x10 RTTR "SharpeningAnim"
    std::uint32_t m_flags;                       // +0x18 accessor-backed
    std::uint32_t m_padding1C;
    std::vector<S_ItemManipulationVariation> m_variations; // +0x20 RTTR "Variations"
};

static_assert(offsetof(S_ItemManipulationData, m_flags) == 0x18,
              "S_ItemManipulationData::m_flags offset mismatch");
static_assert(offsetof(S_ItemManipulationData, m_variations) == 0x20,
              "S_ItemManipulationData::m_variations offset mismatch");
static_assert(sizeof(S_ItemManipulationData) == 0x38,
              "S_ItemManipulationData size mismatch");

} // namespace wh::entitymodule
