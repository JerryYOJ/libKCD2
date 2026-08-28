#pragma once
#include <cstddef>
#include <cstdint>
#include "C_UIBase.h"
#include "C_UIModalDialogQuestion.h"
#include "C_UIShopCamera.h"
#include "C_UIShopCharacter.h"
#include "C_UIShopInventory.h"
#include "C_UITraderInventory.h"
#include "E_UIShopState.h"
#include "framework/C_ModelProperty.h"
#include "framework/E_UIShopView.h"
#include "framework/I_SourceMonitorListener.h"
#include "framework/I_UIShop.h"
#include "I_UIModalDialogListener.h"

namespace wh::guimodule {

class C_UIShop : public C_UIBase,
                 public wh::framework::I_UIShop,
                 public wh::framework::I_SourceMonitorListener,
                 public I_UIModalDialogListener {
public:
    using ShopState = E_UIShopState::Type;
    using ShopStateProperty = wh::shared::C_ModelProperty<
        ShopState,
        wh::shared::traits::C_StaticDefaultValueTrait<
            ShopState, static_cast<ShopState>(0)>,
        wh::shared::traits::C_SignalWithOldValueTrait<ShopState>,
        wh::shared::traits::C_DebugNoTrace,
        wh::shared::traits::C_NoSaveLoad,
        wh::shared::traits::C_OwnershipEmpty>;
    using ShopView = wh::framework::E_UIShopView::Type;
    using ShopViewProperty = wh::shared::C_ModelProperty<
        ShopView,
        wh::shared::traits::C_StandardDefaultValueTrait<ShopView>,
        wh::shared::traits::C_SignalWithNewValueTrait<ShopView>,
        wh::shared::traits::C_DebugNoTrace,
        wh::shared::traits::C_NoSaveLoad,
        wh::shared::traits::C_OwnershipEmpty>;

    C_UIShop();                                                // 0x180BC8F88
    ~C_UIShop() override;                                     // primary [0] 0x182BA5B98

    void Init(C_GUIModule* module) override;                   // [1] 0x180C41220
    void Deinit() override;                                    // [2] 0x182BA721C
    void OnModuleMessage(void* message) override;              // [3] 0x18085DF5C
    void Update() override;                                    // [4] 0x18056724C
    RTTR_ENABLE(C_UIBase, wh::framework::I_UIShop)             // primary [7..9], interface [10..12]

    void unk_01(const void* parameters) override;              // I_UIShop [1] 0x1808C2A60
    std::uint8_t unk_02() const override;                      // I_UIShop [2] 0x1809E5B38
    void* unk_03() override;                                   // I_UIShop [3] 0x181A7FAB0
    void unk_04() override;                                    // I_UIShop [4] 0x182BA7D38
    void unk_05() override;                                    // I_UIShop [5] 0x182BA7E60
    void unk_06(std::uint8_t state) override;                  // I_UIShop [6] 0x182BA7E10
    void unk_07() override;                                    // I_UIShop [7] 0x182BA7DA4
    void unk_08() override;                                    // I_UIShop [8] 0x182BA7DA4
    void* unk_09() override;                                   // I_UIShop [9] 0x1817301C0
    void OnSourceEvent(void* value, bool active) override;     // I_SourceMonitorListener [0] 0x1808C22F8
    void OnModalOpened() override;                             // I_UIModalDialogListener [0] 0x1808EC484
    void OnModalClosed() override;                             // I_UIModalDialogListener [1] 0x180B5CAA4

    ShopStateProperty m_state;                                // +0x28
    ShopViewProperty m_view;                                  // +0x50
    ShopViewProperty m_previousView;                          // +0x78
    C_UIShopInventory m_inventory;                            // +0xA0
    C_UITraderInventory m_traderInventory;                    // +0x758
    C_UIShopCharacter m_character;                            // +0xE10
    void* m_unknown1218;                                      // +0x1218, ctor null
    C_UIModalDialogQuestion m_question;                       // +0x1220
    void* m_subscription;                                     // +0x1308
    C_UIShopCamera m_camera;                                  // +0x1310
    std::uint32_t m_unknown1438;                              // +0x1438, ctor 0
    bool m_unknown143C;                                       // +0x143C, ctor false
    std::uint8_t m_padding143D[3];
    void* m_unknown1440;                                      // +0x1440, ctor null
};

static_assert(sizeof(C_UIShop::ShopStateProperty) == 0x28,
              "C_UIShop::ShopStateProperty size mismatch");
static_assert(sizeof(C_UIShop::ShopViewProperty) == 0x28,
              "C_UIShop::ShopViewProperty size mismatch");
static_assert(offsetof(C_UIShop, m_inventory) == 0xA0,
              "C_UIShop::m_inventory offset mismatch");
static_assert(offsetof(C_UIShop, m_character) == 0xE10,
              "C_UIShop::m_character offset mismatch");
static_assert(offsetof(C_UIShop, m_camera) == 0x1310,
              "C_UIShop::m_camera offset mismatch");
static_assert(sizeof(C_UIShop) == 0x1448,
              "C_UIShop size mismatch");

}  // namespace wh::guimodule
