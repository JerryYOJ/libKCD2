#pragma once
#include "C_UIShopInventory.h"

namespace wh::guimodule {

class C_UITraderInventory : public C_UIShopInventory {
public:
    C_UITraderInventory(
        C_UIShop* owner,
        CryStringT<char> elementName,
        CryStringT<char> listName,
        CryStringT<char> infoName);                               // 0x1819A7824
    ~C_UITraderInventory() override;                              // [0] 0x182BA5C6C

    void _vf12() override;                                       // [12] 0x1806C21BC
    void _vf15() override;                                       // [15] 0x1808F4F44
    void _vf25() override;                                       // [25] 0x1805653F0
    void _vf26() override;                                       // [26] 0x1817F17E4
    void _vf27() override;                                       // [27] 0x1808C4258
    void _vf28() override;                                       // [28] 0x1817F19D8
    void _vf3() override;                                        // I_UIItemContext [3] 0x1808F33F0
};

static_assert(sizeof(C_UITraderInventory) == 0x6B8,
              "C_UITraderInventory size mismatch");

}  // namespace wh::guimodule
