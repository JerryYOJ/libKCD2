#pragma once

#include "C_ItemCollection.h"
#include "../framework/C_BaseModule.h"

namespace wh::entitymodule {

class C_InventoryManager;
class C_ItemIndexerManager;

// Recovered prefix through the two item-collection registry owners at +0xE0/+0xE8.
class C_EntityModule : public framework::C_BaseModule {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_EntityModule;
    static C_EntityModule* GetInstance();
    C_ItemCollection* FindItemCollectionByWuid(framework::WUID wuid);

    std::uint8_t _unknown10[0xD0];
    C_ItemIndexerManager* m_pItemIndexerManager; // +0xE0
    C_InventoryManager* m_pInventoryManager;     // +0xE8
};

}  // namespace wh::entitymodule
