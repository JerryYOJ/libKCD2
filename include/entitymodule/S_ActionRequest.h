#pragma once
#include <cstddef>
#include <cstdint>
#include <functional>
#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {

struct S_ActionRequest {
    virtual ~S_ActionRequest();                                // [0] 0x182895510
    virtual bool unk_01(void* output) const = 0;               // [1], writes request type data
    virtual std::uint32_t unk_02() const = 0;                  // [2]
    virtual std::uint8_t unk_03() const = 0;                   // [3]
    RTTR_ENABLE()                                               // [4..6]

    std::function<void()> m_callback;                          // +0x08, callable signature OPEN
};

static_assert(offsetof(S_ActionRequest, m_callback) == 0x08,
              "S_ActionRequest::m_callback offset mismatch");
static_assert(sizeof(S_ActionRequest) == 0x48,
              "S_ActionRequest size mismatch");

}  // namespace wh::entitymodule
