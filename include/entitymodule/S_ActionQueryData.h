#pragma once

#include <cstddef>
#include <cstdint>

#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {

class C_ActionActor;
class C_Actor;

class S_ActionQueryData {
public:
    RTTR_ENABLE()                                           // [0..2]

    std::uint32_t m_stateId;                                // +0x08, initialized -1
    std::uint8_t m_padding0C[4];                            // +0x0C
    bool m_flag10;                                          // +0x10
    std::uint8_t m_padding11[7];                            // +0x11
    C_ActionActor* m_actionActor;                           // +0x18, borrowed
    C_Actor* m_linkedActor;                                 // +0x20, borrowed
};

static_assert(offsetof(S_ActionQueryData, m_stateId) == 0x08,
              "S_ActionQueryData::m_stateId offset mismatch");
static_assert(offsetof(S_ActionQueryData, m_actionActor) == 0x18,
              "S_ActionQueryData::m_actionActor offset mismatch");
static_assert(offsetof(S_ActionQueryData, m_linkedActor) == 0x20,
              "S_ActionQueryData::m_linkedActor offset mismatch");
static_assert(sizeof(S_ActionQueryData) == 0x28,
              "S_ActionQueryData size mismatch");

}  // namespace wh::entitymodule
