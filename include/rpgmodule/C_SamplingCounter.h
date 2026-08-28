#pragma once
#include <cstddef>
#include <cstdint>
#include <functional>
#include "C_Counter.h"

namespace wh::rpgmodule {

class C_SamplingCounter : public C_Counter {
public:
    ~C_SamplingCounter() override;
    void unk_19() override;                                  // [19] 0x181A94F60, clear sample state
    void unk_20() override;                                  // [20] 0x1809D9AAC, dispatch policy update
    virtual void SetCallback(std::function<void()> callback); // [22] 0x1818451EC
    virtual void unk_23() = 0;                               // [23], policy update
    virtual void unk_24() = 0;                               // [24], policy reset

    std::function<void()> m_callback;                         // +0x20
    bool m_initialized;                                       // +0x60
    std::uint8_t m_padding61[7];
    std::int64_t m_lastTime;                                  // +0x68
    std::int64_t m_accumulatedTime;                           // +0x70
    float m_cachedHours;                                      // +0x78
    std::uint8_t m_padding7C[4];
};

static_assert(offsetof(C_SamplingCounter, m_callback) == 0x20,
              "C_SamplingCounter::m_callback offset mismatch");
static_assert(offsetof(C_SamplingCounter, m_initialized) == 0x60,
              "C_SamplingCounter::m_initialized offset mismatch");
static_assert(sizeof(C_SamplingCounter) == 0x80,
              "C_SamplingCounter size mismatch");

}  // namespace wh::rpgmodule
