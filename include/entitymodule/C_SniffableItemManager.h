#pragma once
#include <unordered_map>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "I_SniffableItemManager.h"
#include "S_SniffableItemData.h"

// -----------------------------------------------
// wh::entitymodule::C_SniffableItemManager : I_SniffableItemManager
// (KCD2 WHGame.dll 1.5.6). sizeof 0x48.
// -----------------------------------------------
// Meyers singleton getter 0x18055E9A4 → 0x1855DBDD0. Ctor 0x181540804. No extra
// virtuals. Map key is S_ItemClass::m_guid (CryGUID, std::hash XOR of two FNV-1a-64).

namespace wh::entitymodule {

class C_SniffableItemManager : public I_SniffableItemManager {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_SniffableItemManager;

    static C_SniffableItemManager* GetInstance();  // 0x18055E9A4

    std::unordered_map<CryGUID, S_SniffableItemData> m_map;  // +0x08  MSVC _Hash 0x40
};
static_assert(sizeof(C_SniffableItemManager) == 0x48,
              "C_SniffableItemManager is vptr + unordered_map 0x40");
static_assert(offsetof(C_SniffableItemManager, m_map) == 0x08,
              "hash begins immediately after the interface vptr");

}  // namespace wh::entitymodule
