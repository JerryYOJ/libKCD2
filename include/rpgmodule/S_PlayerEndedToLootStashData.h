#pragma once
#include <cstdint>
#include <unordered_map>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

// -----------------------------------------------
// wh::rpgmodule::S_PlayerEndedToLootStashData -- payload of C_PlayerEndedToLootStashCause
// (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// sizeof 0x50 (PROVEN: ctor sub_182CDE9A8 tracked-alloc 88, += 0x58; dword *a2 @+0,
// qword *(a2+8) @+8, then a 0x40 std::unordered_map copy via sub_180B5EED0 @+16).
// The map key is S_ItemClass::m_guid; the value is the signed C_Item::m_amount delta.

namespace wh::rpgmodule {

struct S_PlayerEndedToLootStashData {
    std::int32_t m_stashEntityId; // +0x00
    std::uint8_t _pad04[4];       // +0x04
    std::uint64_t m_stashHandle;  // +0x08, exact handle type OPEN
    std::unordered_map<CryGUID, std::int32_t>
        m_itemCountDeltas;         // +0x10, item-class GUID -> signed stack-count delta
};
static_assert(sizeof(S_PlayerEndedToLootStashData) == 0x50, "S_PlayerEndedToLootStashData must be 0x50");

}  // namespace wh::rpgmodule
