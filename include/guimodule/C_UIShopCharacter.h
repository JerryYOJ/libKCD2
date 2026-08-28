#pragma once
#include <cstddef>
#include "C_UICharacterBase.h"

namespace wh::guimodule {

class C_UIShop;

class C_UIShopCharacter : public C_UICharacterBase {
public:
    explicit C_UIShopCharacter(C_UIShop* owner);                  // 0x18146CFA8
    ~C_UIShopCharacter() override;                                // [0] 0x182BA5C00

    void Init(C_GUIModule* module) override;                      // [1] 0x180ED1FC0
    void Deinit() override;                                       // [2] 0x182BA7350
    void _vf10() override;                                        // [10] 0x1819DB2B8
    void _vf14() override;                                        // [14] 0x1819EC6E8
    void _vf15() override;                                        // [15] 0x181F8D240
    void _vf16() override;                                        // [16] 0x18146BF14
    void _vf18() override;                                        // [18] 0x1819C67B0
    void _vf19() override;                                        // [19] 0x18146CBF0
    void _vf20() override;                                        // [20] 0x1819C6828
    void _vf21() override;                                        // [21] 0x180C41BC8
    void _vf22() override;                                        // [22] 0x180C41C50
    void _vf26() override;                                        // [26] 0x1819D243C
    void _vf29() override;                                        // [29] 0x1819A2A90
    void _vf30() override;                                        // [30] 0x1819A2A90
    void _vf31() override;                                        // [31] 0x182BA91D0
    void _vf33() override;                                        // [33] 0x1808ED9A8
    void _vf34() override;                                        // [34] 0x182BA7750
    void _vf35() override;                                        // [35] 0x1808EF45C
    void _vf36() override;                                        // [36] nullsub_1
    void _vf37() override;                                        // [37] nullsub_1

    void OnAction(
        Offsets::SActionId const& action,
        int activationMode,
        float value) override;                                    // IActionListener [1] 0x18167E614
    void OnHardwareMouseEvent(
        int x,
        int y,
        EHARDWAREMOUSEEVENT event,
        int wheelDelta) override;                                 // IHardwareMouseEventListener [1] 0x181045B6C

    C_UIShop* m_owner;                                            // +0x3F8
    void* m_unknown400;                                           // +0x400
};

static_assert(offsetof(C_UIShopCharacter, m_owner) == 0x3F8,
              "C_UIShopCharacter::m_owner offset mismatch");
static_assert(sizeof(C_UIShopCharacter) == 0x408,
              "C_UIShopCharacter size mismatch");

}  // namespace wh::guimodule
