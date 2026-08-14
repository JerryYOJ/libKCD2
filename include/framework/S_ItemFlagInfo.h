#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::framework::S_ItemFlagInfo -- KCD2 WHGame.dll 1.5.6 (kd7u). sizeof 0x28.
// -----------------------------------------------
// Value published by C_PlayerInteractor and consumed by C_UIHudHints::ShowItemHint.
// ctor sub_1809ECFF4; copy helper sub_1809ECC3C. The HUD converts m_priceTenths
// to display currency with *0.1f; the remaining fields are forwarded in declaration order.

namespace wh::framework {

struct S_ItemFlagInfo {
    CryStringT<char> m_name;          // +0x00
    int32_t          m_amount;        // +0x08
    float            m_mainStat;      // +0x0C
    float            m_health;        // +0x10
    float            m_weight;        // +0x14
    int32_t          m_quality;       // +0x18
    bool             m_isRepainted;   // +0x1C
    uint8_t          _pad1D[3];       // +0x1D
    int32_t          m_priceTenths;   // +0x20
};

static_assert(sizeof(S_ItemFlagInfo) == 0x28, "S_ItemFlagInfo must be 0x28");
static_assert(offsetof(S_ItemFlagInfo, m_priceTenths) == 0x20, "m_priceTenths must be at 0x20");

}  // namespace wh::framework
