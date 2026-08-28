#pragma once
#include <cstddef>
#include <cstdint>
#include "C_UIFlashBase.h"
#include "playermodule/I_UISkipTime.h"

namespace wh::guimodule {

class C_UISkiptime : public C_UIFlashBase,
                     public wh::playermodule::I_UISkipTime {
public:
    C_UISkiptime();                                   // 0x180B5CD04
    ~C_UISkiptime() override;                         // primary [0] 0x182BB88B4
    void Init(C_GUIModule* module) override;          // [1] 0x1817769F4
    void Deinit() override;                           // [2] 0x182BB9448
    RTTR_ENABLE(C_UIBase)                             // primary [7..9], secondary [7..9]
    const char* GetElementName() const override;      // [11] 0x181A8F4E0

    void StartAction() override;                      // secondary [1] 0x182BBB96C
    void SetInterval(float interval) override;        // [2] 0x180C44B48
    void SetTime(float time) override;                // [3] 0x180C44BA4
    void ShowDialog() override;                       // [4] 0x180F49338
    void HideDialog() override;                       // [5] 0x1819C339C
    void RemoveDialog() override;                     // [6] 0x180B5CD84

    std::uint8_t m_runtimeState0[0x38];               // +0x60
    void* m_unknown98;                                // +0x98, ctor null
    std::uint8_t m_runtimeState1[0x38];               // +0xA0
    void* m_unknownD8;                                // +0xD8, ctor null
    void* m_unknownE0;                                // +0xE0, ctor null
    std::int32_t m_unknownE8;                         // +0xE8, ctor -1
    float m_interval;                                 // +0xEC
    std::uint16_t m_unknownF0;                        // +0xF0
    bool m_dialogVisible;                             // +0xF2
    std::uint8_t m_unknownF3;
    std::uint32_t m_unknownF4;                        // +0xF4
    float m_unknownF8[4];                             // +0xF8
    std::uint32_t m_unknown108;                       // +0x108
    std::uint8_t m_unknown10C[4];
};

static_assert(offsetof(C_UISkiptime, m_runtimeState0) == 0x60,
              "C_UISkiptime::m_runtimeState0 offset mismatch");
static_assert(offsetof(C_UISkiptime, m_interval) == 0xEC,
              "C_UISkiptime::m_interval offset mismatch");
static_assert(offsetof(C_UISkiptime, m_dialogVisible) == 0xF2,
              "C_UISkiptime::m_dialogVisible offset mismatch");
static_assert(sizeof(C_UISkiptime) == 0x110,
              "C_UISkiptime size mismatch");

}  // namespace wh::guimodule
