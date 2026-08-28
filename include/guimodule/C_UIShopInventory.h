#pragma once
#include <cstddef>
#include <cstdint>
#include "C_UIInventoryBase.h"
#include "entitymodule/C_ItemIndexer.h"

namespace wh::guimodule {

class C_UIShop;

class C_UIShopInventory : public C_UIInventoryBase {
public:
    C_UIShopInventory(
        C_UIShop* owner,
        CryStringT<char> elementName,
        CryStringT<char> listName,
        CryStringT<char> infoName,
        bool trader);                                             // 0x180BC8DD4
    ~C_UIShopInventory() override;                                // [0] 0x182BA5C6C

    void Init(C_GUIModule* module) override;                      // [1] 0x180C41CD8
    void Deinit() override;                                       // [2] 0x182BA739C
    void _vf12() override;                                        // [12] 0x1806C22C8
    void _vf13() override;                                        // [13] 0x181F8C370
    void _vf14() override;                                        // [14] 0x181F8D5B0
    void _vf15() override;                                        // [15] 0x1816E0634
    void _vf16() override;                                        // [16] 0x182BA76D8
    void _vf25() override;                                        // [25] 0x180565444
    virtual void _vf26();                                         // [26] 0x1817F1868
    virtual void _vf27();                                         // [27] 0x1808C42DC
    virtual void _vf28();                                         // [28] 0x1817F1964

    void _vf0() override;                                         // I_UIItemContext [0] 0x180566844
    void _vf3() override;                                         // I_UIItemContext [3] 0x1808F344C
    void _vf4() override;                                         // I_UIItemContext [4] 0x182BA7AA0

    wh::shared::C_Signal<> m_signal5D0;                           // +0x5D0
    wh::shared::C_Signal<> m_signal5E0;                           // +0x5E0
    C_UIShop* m_owner;                                            // +0x5F0
    wh::entitymodule::C_ItemIndexer m_indexer;                    // +0x5F8
    wh::shared::C_Signal<> m_signal688;                           // +0x688
    CryStringT<char> m_elementName;                               // +0x698
    CryStringT<char> m_listName;                                  // +0x6A0
    CryStringT<char> m_infoName;                                  // +0x6A8
    bool m_trader;                                                // +0x6B0
    std::uint8_t m_padding6B1[7];
};

static_assert(offsetof(C_UIShopInventory, m_indexer) == 0x5F8,
              "C_UIShopInventory::m_indexer offset mismatch");
static_assert(sizeof(C_UIShopInventory) == 0x6B8,
              "C_UIShopInventory size mismatch");

}  // namespace wh::guimodule
