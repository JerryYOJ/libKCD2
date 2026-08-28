#pragma once
#include <cstddef>
#include <cstdint>

#include "../rttr/rttr_enable.h"
#include "E_StanceBy.h"
#include "E_StanceCategory.h"
#include "E_StanceOn.h"
#include "E_StanceSide.h"

namespace wh::entitymodule {

class C_ActorStanceGroupData {
public:
    virtual bool HasName() const;                       // [0] 0x180681B98
    virtual CryStringT<char> GetName() const;           // [1] 0x1808592EC
    virtual const CryStringT<char>& GetNameRef() const; // [2] 0x181A71D30
    virtual void unk_03();                              // [3] 0x1828B372C; 0x18 tag-state return signature OPEN
    virtual E_StanceCategory::Type GetStance() const;   // [4] 0x181A72C80
    virtual E_StanceOn::Type GetStanceOn() const;       // [5] 0x181A83590
    virtual E_StanceBy::Type GetStanceBy() const;       // [6] 0x181A83580
    virtual E_StanceSide::Type GetStanceSide() const;   // [7] 0x181A72850
    RTTR_ENABLE()                                       // [8..10]

    CryStringT<char> m_name;             // +0x08 RTTR "Name"
    E_StanceCategory::Type m_stance;      // +0x10 RTTR "Stance"
    E_StanceOn::Type m_stanceOn;          // +0x14 RTTR "StanceOn"
    E_StanceBy::Type m_stanceBy;          // +0x15 RTTR "StanceBy"
    std::uint8_t m_padding16[2];          // +0x16
    E_StanceSide::Type m_stanceSide;      // +0x18 RTTR "StanceSide"
    std::uint32_t m_padding1C;            // +0x1C
};

static_assert(offsetof(C_ActorStanceGroupData, m_name) == 0x08,
              "C_ActorStanceGroupData::m_name offset mismatch");
static_assert(offsetof(C_ActorStanceGroupData, m_stance) == 0x10,
              "C_ActorStanceGroupData::m_stance offset mismatch");
static_assert(offsetof(C_ActorStanceGroupData, m_stanceOn) == 0x14,
              "C_ActorStanceGroupData::m_stanceOn offset mismatch");
static_assert(offsetof(C_ActorStanceGroupData, m_stanceSide) == 0x18,
              "C_ActorStanceGroupData::m_stanceSide offset mismatch");
static_assert(sizeof(C_ActorStanceGroupData) == 0x20,
              "C_ActorStanceGroupData size mismatch");

} // namespace wh::entitymodule
