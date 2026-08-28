#pragma once
#include <cstddef>
#include <cstdint>
#include "C_UIFlashBase.h"
#include "framework/I_SourceMonitorListener.h"
#include "Offsets/vtables/IActionListener.h"

namespace wh::guimodule {

class C_UICredits : public C_UIFlashBase,
                    public wh::framework::I_SourceMonitorListener,
                    public Offsets::IActionListener {
public:
    C_UICredits();                                    // 0x181899BC8
    ~C_UICredits() override;                          // primary [0] 0x182BA5A14
    void Init(C_GUIModule* module) override;          // [1] 0x180C3B850
    void Deinit() override;                           // [2] 0x182BA6F40
    void Update() override;                           // [4] 0x181F8DEB0
    RTTR_ENABLE(C_UIBase)                             // [7..9]
    const char* GetElementName() const override;      // [11] 0x181A8F230
    void OnSourceEvent(void* source, bool active) override; // secondary +0x58 [0] 0x182BA7ECC
    void OnAction(
        Offsets::SActionId const& action,
        int activationMode, float value) override;    // secondary +0x60 [1] 0x182BA7F1C

    std::uint16_t m_unknown68;                        // +0x68, ctor 0
    std::uint8_t m_unknown6A[6];
    void* m_unknown70;                                // +0x70, ctor null
    std::uint8_t m_unknown78[0x1C];
    float m_colorR;                                   // +0x94, ctor 1.0
    float m_colorG;                                   // +0x98, ctor 1.0
    float m_colorB;                                   // +0x9C, ctor 1.0
};

static_assert(offsetof(C_UICredits, m_unknown68) == 0x68,
              "C_UICredits::m_unknown68 offset mismatch");
static_assert(offsetof(C_UICredits, m_colorR) == 0x94,
              "C_UICredits::m_colorR offset mismatch");
static_assert(sizeof(C_UICredits) == 0xA0,
              "C_UICredits size mismatch");

}  // namespace wh::guimodule
