#pragma once
#include <cstddef>
#include <cstdint>
#include "../rttr/rttr_enable.h"

namespace wh::playermodule {
class S_PlayerId {
public:
    virtual ~S_PlayerId();
    RTTR_ENABLE()  // [1..3]
    std::int32_t m_playerId;  // +0x8 RTTR "PlayerId"
    std::uint8_t m_unknown0C[0x4];                  // +0xC
};

static_assert(offsetof(S_PlayerId, m_playerId) == 0x8, "S_PlayerId::m_playerId offset mismatch");
static_assert(sizeof(S_PlayerId) == 0x10, "S_PlayerId size mismatch");

}  // namespace wh::playermodule
