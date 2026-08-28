#pragma once
#include <cstddef>
#include <cstdint>
#include "I_SkirmishListener.h"

namespace wh::rpgmodule {

class C_SoulSkirmishTrigger;
class I_SkirmishHandle;
class I_SkirmishHandleProvider;
class I_Soul;

class C_SkirmishSoulTriggerListener : public I_SkirmishListener {
public:
    C_SkirmishSoulTriggerListener(
        I_Soul* soul,
        C_SoulSkirmishTrigger* trigger);
    ~C_SkirmishSoulTriggerListener() override;                      // [0]
    void OnSkirmishStarted(
        I_SkirmishHandleProvider* skirmish,
        std::uint32_t matchFlag) override;                          // [1]
    void OnSkirmishEnded() override;                               // [2]

    C_SoulSkirmishTrigger* m_trigger;                              // +0x08
    I_Soul* m_soul;                                                // +0x10
    bool m_listenerRegistered;                                    // +0x18
    std::uint8_t m_padding19[7];                                  // +0x19
    I_SkirmishHandle* m_skirmishHandle;                           // +0x20
};

static_assert(sizeof(C_SkirmishSoulTriggerListener) == 0x28,
              "C_SkirmishSoulTriggerListener size mismatch");
static_assert(offsetof(C_SkirmishSoulTriggerListener, m_trigger) == 0x08,
              "C_SkirmishSoulTriggerListener trigger offset mismatch");
static_assert(offsetof(C_SkirmishSoulTriggerListener, m_skirmishHandle) == 0x20,
              "C_SkirmishSoulTriggerListener handle offset mismatch");

} // namespace wh::rpgmodule
