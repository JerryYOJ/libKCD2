#pragma once
#include <cstddef>
#include <cstdint>
#include "C_UIFlashBase.h"
#include "playermodule/I_UIPickpocketing.h"

namespace wh::guimodule {

class C_UIPickpocketing : public C_UIFlashBase,
                          public wh::playermodule::I_UIPickpocketing {
public:
    C_UIPickpocketing();                              // construction path 0x181889428
    ~C_UIPickpocketing() override;                    // primary [0] 0x182BB87E0
    void Init(C_GUIModule* module) override;          // [1] 0x180ED1D04
    void Deinit() override;                           // [2] 0x182BB9300
    RTTR_ENABLE(C_UIBase)                             // primary [7..9], secondary [3..5]
    const char* GetElementName() const override;      // [11] 0x181A71990
    void Open(void* state) override;                  // secondary [1] 0x182BB8AF8
    void SetBoostProgress(
        float progress, float limit,
        std::int32_t state, std::int32_t value) override; // secondary [2] 0x182BBAC78

    std::uint8_t m_runtimeState[0x38];                // +0x60
    void* m_unknown98;                                // +0x98, ctor null
};

static_assert(offsetof(C_UIPickpocketing, m_runtimeState) == 0x60,
              "C_UIPickpocketing::m_runtimeState offset mismatch");
static_assert(offsetof(C_UIPickpocketing, m_unknown98) == 0x98,
              "C_UIPickpocketing::m_unknown98 offset mismatch");
static_assert(sizeof(C_UIPickpocketing) == 0xA0,
              "C_UIPickpocketing size mismatch");

}  // namespace wh::guimodule
