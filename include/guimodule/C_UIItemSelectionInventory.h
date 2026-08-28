#pragma once
#include <cstddef>
#include <cstdint>
#include "C_UIInventoryBase.h"
#include "entitymodule/C_ItemIndexer.h"

namespace wh::guimodule {

class C_UIItemSelectionInventory : public C_UIInventoryBase {
public:
    C_UIItemSelectionInventory();                         // 0x1816F6950
    ~C_UIItemSelectionInventory() override;               // [0] 0x182B8BFBC

    void _vf10() override;                                // [10] 0x1806C1C14
    void _vf15() override;                                // [15] 0x1808F4CEC
    void _vf18() override;                                // [18] 0x181F78B80

    void _vf1() override;                                 // I_UIItemContext [1] 0x182B8D570
    void _vf2() override;                                 // I_UIItemContext [2] 0x1808C5694
    void _vf3() override;                                 // I_UIItemContext [3] 0x1808F4CDC
    void _vf4() override;                                 // I_UIItemContext [4] 0x1808C4E78

    wh::shared::C_Signal<> m_signal5D0;                   // +0x5D0
    std::uint64_t m_unknown5E0;                           // +0x5E0
    wh::entitymodule::C_ItemIndexer m_indexer;            // +0x5E8
    wh::shared::C_Signal<> m_signal678;                   // +0x678
    std::uint8_t m_runtimeState688[0xD8];                 // +0x688
};

static_assert(offsetof(C_UIItemSelectionInventory, m_indexer) == 0x5E8,
              "C_UIItemSelectionInventory::m_indexer offset mismatch");
static_assert(sizeof(C_UIItemSelectionInventory) == 0x760,
              "C_UIItemSelectionInventory size mismatch");

}  // namespace wh::guimodule
