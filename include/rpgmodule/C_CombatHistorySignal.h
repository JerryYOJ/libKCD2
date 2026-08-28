#pragma once
#include <cstddef>
#include <cstdint>
#include "../framework/C_Signal.h"
#include "I_SkirmishListener.h"

namespace wh::rpgmodule {

class I_SkirmishHandleProvider;
class I_Soul;

class C_CombatHistorySignal : public I_SkirmishListener {
public:
    C_CombatHistorySignal();
    ~C_CombatHistorySignal() override;                             // [0]
    void OnSkirmishStarted(
        I_SkirmishHandleProvider* skirmish,
        std::uint32_t matchFlag) override;                         // [1]
    void OnSkirmishEnded() override;                              // [2]

    wh::shared::C_Signal<> m_onCombatHistoryBegins;               // +0x08
    bool m_registered;                                            // +0x18
    std::uint8_t m_padding19[7];                                 // +0x19
    I_Soul* m_soul1;                                              // +0x20
    I_Soul* m_soul2;                                              // +0x28
};

static_assert(sizeof(C_CombatHistorySignal) == 0x30,
              "C_CombatHistorySignal size mismatch");
static_assert(offsetof(C_CombatHistorySignal, m_onCombatHistoryBegins) == 0x08,
              "C_CombatHistorySignal signal offset mismatch");
static_assert(offsetof(C_CombatHistorySignal, m_soul1) == 0x20,
              "C_CombatHistorySignal Soul1 offset mismatch");

} // namespace wh::rpgmodule
