#pragma once
#include <cstddef>
#include <cstdint>
#include "../E_HandType.h"
#include "C_ElementInitializerBase.h"
#include "E_InitializationMode.h"

namespace wh::xgenaimodule::scheduler {

class C_ElementInitializerHandContent : public C_ElementInitializerBase {
public:
    ~C_ElementInitializerHandContent() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    RTTR_ENABLE(C_ElementInitializerBase)
    E_InitializationMode::Type m_initMode;                // +0x18 RTTR "InitMode"
    std::uint8_t _pad19[3];                               // +0x19
    wh::xgenaimodule::E_HandType::Type m_usedHand;        // +0x1C RTTR "UsedHand"
    std::uint8_t m_unknown20[8];                          // +0x20
};

static_assert(offsetof(C_ElementInitializerHandContent, m_initMode) == 0x18,
              "C_ElementInitializerHandContent::m_initMode offset mismatch");
static_assert(offsetof(C_ElementInitializerHandContent, m_usedHand) == 0x1C,
              "C_ElementInitializerHandContent::m_usedHand offset mismatch");
static_assert(sizeof(C_ElementInitializerHandContent) == 0x28,
              "C_ElementInitializerHandContent size mismatch");

}  // namespace wh::xgenaimodule::scheduler
