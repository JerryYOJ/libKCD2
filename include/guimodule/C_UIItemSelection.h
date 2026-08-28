#pragma once
#include <cstddef>
#include <cstdint>
#include "C_UIFlashBase.h"
#include "C_UIItemSelectionInventory.h"
#include "C_UIModalDialogInfo.h"
#include "framework/I_SourceMonitorListener.h"
#include "framework/I_UIItemSelection.h"

namespace wh::guimodule {

class C_UIItemSelection : public C_UIFlashBase,
                          public wh::framework::I_UIItemSelection,
                          public wh::framework::I_SourceMonitorListener {
public:
    C_UIItemSelection();                                      // 0x1816F6830
    ~C_UIItemSelection() override;                            // primary [0] 0x182B8BF88

    void Init(C_GUIModule* module) override;                  // [1] 0x180C3BCF8
    void Deinit() override;                                   // [2] 0x182B8D2AC
    void OnModuleMessage(void* message) override;             // [3] 0x18085DD24
    void Update() override;                                   // [4] 0x180533C50
    RTTR_ENABLE(C_UIBase, wh::framework::I_UIItemSelection)   // primary [7..9], interface [4..6]
    const char* GetElementName() const override;              // [11] 0x181A719D0

    bool unk_01(const void* parameters) override;             // I_UIItemSelection [1] 0x1806C134C
    bool unk_02(std::uint8_t reason) override;                // I_UIItemSelection [2] 0x1806C2598
    std::uint8_t unk_03() const override;                     // I_UIItemSelection [3] 0x181A731E0
    void OnSourceEvent(void* value, bool active) override;    // I_SourceMonitorListener [0] 0x1816F68EC

    std::uint16_t m_unknown68;                                // +0x68, ctor 0
    std::uint8_t m_unknown6A;                                 // +0x6A, ctor 0
    std::uint8_t m_runtimeState6B[0x3D];                      // +0x6B
    void* m_unknownA8;                                        // +0xA8, ctor null
    C_UIItemSelectionInventory m_inventory;                   // +0xB0
    void* m_unknown810;                                       // +0x810, ctor null
    void* m_unknown818;                                       // +0x818, ctor null
    C_UIModalDialogInfo m_dialog;                             // +0x820
    void* m_subscription;                                     // +0x8C8
    bool m_unknown8D0;                                        // +0x8D0, ctor false
    std::uint8_t m_padding8D1[7];
};

static_assert(offsetof(C_UIItemSelection, m_inventory) == 0xB0,
              "C_UIItemSelection::m_inventory offset mismatch");
static_assert(offsetof(C_UIItemSelection, m_dialog) == 0x820,
              "C_UIItemSelection::m_dialog offset mismatch");
static_assert(sizeof(C_UIItemSelection) == 0x8D8,
              "C_UIItemSelection size mismatch");

}  // namespace wh::guimodule
