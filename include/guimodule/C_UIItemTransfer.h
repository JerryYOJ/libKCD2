#pragma once
#include <cstddef>
#include <cstdint>
#include "C_UIFlashBase.h"
#include "C_UIItemTransferInventory.h"
#include "framework/I_SourceMonitorListener.h"
#include "framework/I_UIItemTransfer.h"

namespace wh::guimodule {

class C_UIItemTransfer : public C_UIFlashBase,
                         public wh::framework::I_UIItemTransfer,
                         public wh::framework::I_SourceMonitorListener {
public:
    C_UIItemTransfer();                                      // 0x180BC6C14
    ~C_UIItemTransfer() override;                            // primary [0] 0x182B8BFF0

    void Init(C_GUIModule* module) override;                 // [1] 0x180C41398
    void Deinit() override;                                  // [2] 0x182B8D320
    void OnModuleMessage(void* message) override;            // [3] 0x18085DDF8
    void Update() override;                                  // [4] 0x1805336E0
    RTTR_ENABLE(C_UIBase, wh::framework::I_UIItemTransfer)   // primary [7..9], interface [7..9]
    const char* GetElementName() const override;             // [11] 0x181A719C0

    bool unk_01(const void* parameters) override;            // I_UIItemTransfer [1] 0x180C4179C
    bool unk_02(std::uint8_t reason) override;               // I_UIItemTransfer [2] 0x180C424F4
    bool unk_03(const void* object) const override;          // I_UIItemTransfer [3] 0x182B8DDAC
    void* unk_04() override;                                 // I_UIItemTransfer [4] 0x182B8D670
    std::uint8_t unk_05() const override;                    // I_UIItemTransfer [5] 0x181A731E0
    bool unk_06() const override;                            // I_UIItemTransfer [6] 0x182B8DD94
    void OnSourceEvent(void* value, bool active) override;   // I_SourceMonitorListener [0] 0x181738700

    std::uint16_t m_unknown68;                               // +0x68, ctor 0
    std::uint8_t m_runtimeState6A[0x3E];                     // +0x6A
    void* m_unknownA8;                                       // +0xA8, ctor null
    bool m_unknownB0;                                        // +0xB0, ctor false
    std::uint8_t m_paddingB1[7];
    C_UIItemTransferInventory m_inventories[2];              // +0xB8
    void* m_subscription;                                    // +0xCA8
    void* m_unknownCB0;                                      // +0xCB0, ctor null
    std::uint64_t m_unknownCB8;                              // +0xCB8
};

static_assert(offsetof(C_UIItemTransfer, m_inventories) == 0xB8,
              "C_UIItemTransfer::m_inventories offset mismatch");
static_assert(offsetof(C_UIItemTransfer, m_subscription) == 0xCA8,
              "C_UIItemTransfer::m_subscription offset mismatch");
static_assert(sizeof(C_UIItemTransfer) == 0xCC0,
              "C_UIItemTransfer size mismatch");

}  // namespace wh::guimodule
