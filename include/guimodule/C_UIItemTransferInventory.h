#pragma once
#include <cstddef>
#include <cstdint>
#include "C_UIInventoryBase.h"

namespace wh::guimodule {

class C_UIItemTransferInventory : public C_UIInventoryBase {
public:
    C_UIItemTransferInventory(std::uint32_t side, void* context); // 0x180BC6CD0
    ~C_UIItemTransferInventory() override;                        // [0] 0x182B8C024

    void _vf10() override;                                        // [10] 0x1808C1578
    void _vf20() override;                                        // [20] 0x1819C7BDC
    void _vf23() override;                                        // [23] 0x1819C1BD4
    void _vf24() override;                                        // [24] 0x1812B3FF4

    wh::shared::C_Signal<> m_changed;                             // +0x5D0
    void* m_unknown5E0;                                           // +0x5E0
    bool m_unknown5E8;                                            // +0x5E8
    std::uint8_t m_padding5E9[7];
    void* m_context;                                              // +0x5F0
};

static_assert(offsetof(C_UIItemTransferInventory, m_changed) == 0x5D0,
              "C_UIItemTransferInventory::m_changed offset mismatch");
static_assert(sizeof(C_UIItemTransferInventory) == 0x5F8,
              "C_UIItemTransferInventory size mismatch");

}  // namespace wh::guimodule
