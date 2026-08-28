#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <list>
#include <vector>
#include "../CryEngine/CryCommon/CryString.h"
#include "../entitymodule/C_Inventory.h"
#include "../entitymodule/I_GameObjectLight.h"
#include "../entitymodule/I_ItemCollectionListener.h"
#include "../framework/CryDeferrable.h"
#include "../framework/I_ScheduleUpdatable.h"
#include "../framework/WUID.h"
#include "../rttr/rttr_enable.h"
#include "C_ShopBase.h"

namespace wh::shopmodule {

class C_Shop : public C_ShopBase,
               public wh::entitymodule::I_GameObjectLight,
               public wh::entitymodule::I_ItemCollectionListener,
               public wh::framework::I_ScheduleUpdatable,
               public UnsafeOp::CryDeferrable<0> {
public:
    ~C_Shop() override;                                      // [0] 0x180965328
    float unk_01(void* context) const override;              // [1] 0x1805666B8
    float unk_02(void* context) const override;              // [2] 0x181793A1C
    void unk_03(wh::framework::WUID* result) const override; // [3] 0x1804CCEB0
    const wh::framework::WUID& unk_04() const override;      // [4] 0x180566940
    bool unk_05(const wh::framework::WUID& value) const override; // [5] 0x1813C51BC
    void unk_06(const wh::framework::WUID& value) override;  // [6] 0x180D445C0
    void unk_07(void* a2, void* a3, void* a4) override;      // [7] 0x180C406D8
    wh::entitymodule::C_Item* unk_08(
        wh::entitymodule::C_Item* item,
        std::uint32_t amount) override;                       // [8] 0x1819B8228
    void unk_09(std::uint32_t* result) const override;       // [9] 0x1807D01D8
    RTTR_ENABLE()                                             // [13..15]

    void ProcessEvent(SEntityEvent& event) override;         // light [1] 0x181396DA0
    void _vf11() override;                                   // light [11] 0x18154BBE4

    void ItemCollectionListenerUnk0(wh::entitymodule::C_Item* splitItem) override;
    void ItemCollectionListenerUnk1(wh::entitymodule::C_Item* consumedItem) override;
    void ItemCollectionListenerUnk2(
        wh::entitymodule::S_ItemClass* itemClass,
        std::uint32_t amount,
        wh::framework::WUID itemWuid) override;
    void ItemCollectionListenerUnk3(
        wh::entitymodule::C_Item* item,
        std::int32_t amountDelta,
        std::uint32_t changeMask) override;
    void ItemCollectionListenerUnk4(
        wh::entitymodule::C_ItemCollection* collection) override;
    void ScheduleUpdate(std::int32_t value) override;        // 0x1808F2C7C

    std::uint8_t m_unknownC0[0x10];                          // +0xC0 unreflected
    wh::framework::WUID m_collectionWuid;                    // +0xD0 collection slot [0]
    CryStringT<char> m_name;                                 // +0xD8
    wh::entitymodule::C_Inventory* m_inventory;              // +0xE0
    std::uint8_t m_unknownE8[0x28];                          // +0xE8 unreflected
    std::vector<std::array<std::uint8_t, 0xF8>> m_runtimeItems; // +0x110, element stride 0xF8
    void* m_unknown128;                                      // +0x128
    std::uint8_t m_unknown130[0x18];                         // +0x130 unreflected
    bool m_unknown148;                                       // +0x148 byte writer
    std::uint8_t m_unknown149[7];                            // +0x149
    std::uint8_t m_unknown150[0x18];                         // +0x150 unreflected container
    std::uint8_t m_unknown168[0x18];                         // +0x168 unreflected container
    wh::framework::WUID m_unknownWuid180;                    // +0x180
    wh::framework::WUID m_unknownWuid188;                    // +0x188 slot [4]
    std::list<wh::framework::WUID> m_linkedWuids;            // +0x190
    void* m_unknown1A0;                                      // +0x1A0
    wh::framework::WUID m_shopWuid;                          // +0x1A8 slot [3]
    std::uint32_t m_shopDefinitionId;                        // +0x1B0
    std::uint8_t m_unknown1B4;                               // +0x1B4
    std::uint8_t m_unknown1B5[2];                            // +0x1B5
    std::uint8_t m_unknown1B7;                               // +0x1B7
};

static_assert(offsetof(C_Shop, m_unknownC0) == 0xC0,
              "C_Shop::m_unknownC0 offset mismatch");
static_assert(offsetof(C_Shop, m_collectionWuid) == 0xD0,
              "C_Shop::m_collectionWuid offset mismatch");
static_assert(offsetof(C_Shop, m_inventory) == 0xE0,
              "C_Shop::m_inventory offset mismatch");
static_assert(offsetof(C_Shop, m_runtimeItems) == 0x110,
              "C_Shop::m_runtimeItems offset mismatch");
static_assert(offsetof(C_Shop, m_linkedWuids) == 0x190,
              "C_Shop::m_linkedWuids offset mismatch");
static_assert(offsetof(C_Shop, m_shopWuid) == 0x1A8,
              "C_Shop::m_shopWuid offset mismatch");
static_assert(offsetof(C_Shop, m_shopDefinitionId) == 0x1B0,
              "C_Shop::m_shopDefinitionId offset mismatch");
static_assert(sizeof(C_Shop) == 0x1B8, "C_Shop size mismatch");

}  // namespace wh::shopmodule
