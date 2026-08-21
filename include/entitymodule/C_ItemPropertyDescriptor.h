#pragma once
#include <cstddef>
#include <cstdint>
#include "C_HomogenousItemDescriptor.h"
#include "E_ItemFilterType.h"

// -----------------------------------------------
// wh::entitymodule::C_ItemPropertyDescriptor -- property-range item filter (KCD2 1.5.6, kd7u).
// sizeof 0x38.
// -----------------------------------------------
// RTTI .?AVC_ItemPropertyDescriptor@entitymodule@wh@@ (RTTR "ItemPropertyDescriptor",
// type_data 0x1817F7CF0, sizeof 0x38). Vtable 0x183A3D590. Matcher vf[4] 0x18096F50C tests,
// in order: Equipped (C_Item flags bit0) / Quest (bit1; quest-bit identity UNVERIFIED) /
// Stolen (0x180469828), health [min,max] xor negate, price via GetNewUnitPrice 0x18096F68C,
// quality via GetQuality 0x180469A70 (fail code 9), condition via GetCondition 0x18096F7D4
// (fail code 0xA). Fields packed by CreateItemClassDescriptor impl 0x180517508.

namespace wh::entitymodule {

class C_ItemPropertyDescriptor : public C_HomogenousItemDescriptor {
public:
    std::int32_t           m_amount;             // +0x08  RTTR param "Amount"; -1 = unlimited (vf[9])
    E_ItemFilterType::Type m_equippedFilter;     // +0x0C  "EquippedFilter" vs C_Item flags bit0
    E_ItemFilterType::Type m_questFilter;        // +0x0D  "QuestFilter"    vs C_Item flags bit1
    E_ItemFilterType::Type m_stolenFilter;       // +0x0E  "StolenFilter"   vs stolen predicate 0x180469828
    std::uint8_t           _pad0F;               // +0x0F
    float                  m_minimumHealth;      // +0x10  "MinimumHealth"
    float                  m_maximumHealth;      // +0x14  "MaximumHealth"
    bool                   m_negateHealth;       // +0x18  "NegateHealth"
    std::uint8_t           _pad19[3];            // +0x19
    std::uint32_t          m_minNewUnitPrice;    // +0x1C  "MinNewUnitPrice"
    std::uint32_t          m_maxNewUnitPrice;    // +0x20  "MaxNewUnitPrice"
    bool                   m_negatePrice;        // +0x24  "NegatePrice"
    std::uint8_t           _pad25[3];            // +0x25
    std::uint32_t          m_minQuality;         // +0x28  "MinQuality"
    std::uint32_t          m_maxQuality;         // +0x2C  "MaxQuality"
    float                  m_minCondition;       // +0x30  "MinCondition"
    float                  m_maxCondition;       // +0x34  "MaxCondition"
};
static_assert(sizeof(C_ItemPropertyDescriptor) == 0x38, "C_ItemPropertyDescriptor must be 0x38 (RTTR sizeof)");
static_assert(offsetof(C_ItemPropertyDescriptor, m_amount) == 0x08, "amount at 0x08 (vf[9])");
static_assert(offsetof(C_ItemPropertyDescriptor, m_minCondition) == 0x30, "condition range ends the 0x38 base");

}  // namespace wh::entitymodule
