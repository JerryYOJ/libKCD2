#pragma once
#include <cstddef>
#include <cstdint>
#include "S_Event.h"

namespace wh::xgenaimodule::BehaviorTree {

struct S_CallbackEvent : S_Event {
    ~S_CallbackEvent() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    void unk_04() override;
    RTTR_ENABLE(S_Event)
    virtual std::uintptr_t unk_08(void* arg1, void* arg2);   // [8] 0x1819E0584

    std::uint8_t m_unknown10[8];                            // +0x10
    void* m_unknown18;                                      // +0x18
    std::uint32_t m_unknown20;                              // +0x20
    std::uint8_t _pad24[4];                                 // +0x24
};

static_assert(offsetof(S_CallbackEvent, m_unknown18) == 0x18,
              "S_CallbackEvent::m_unknown18 offset mismatch");
static_assert(offsetof(S_CallbackEvent, m_unknown20) == 0x20,
              "S_CallbackEvent::m_unknown20 offset mismatch");
static_assert(sizeof(S_CallbackEvent) == 0x28,
              "S_CallbackEvent size mismatch");

}  // namespace wh::xgenaimodule::BehaviorTree
