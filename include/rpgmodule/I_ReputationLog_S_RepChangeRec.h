#pragma once
#include <cstddef>
#include <cstdint>
#include "../framework/T_TimeoutTimer.h"
#include "I_ReputationLog.h"
#include "S_ReputationChangeRequest.h"

namespace wh::rpgmodule {

struct T_GameWorldPausedInFullUITimePolicy;

struct I_ReputationLog::S_RepChangeRec {
    S_RepChangeRec();
    ~S_RepChangeRec();
    RTTR_ENABLE() // [0..2]

    std::uint64_t m_seqId;                                      // +0x08
    wh::framework::T_TimeoutTimer<
        T_GameWorldPausedInFullUITimePolicy> m_timeout;         // +0x10
    S_ReputationChangeRequest m_changeRequest;                  // +0x38
    std::uint64_t m_sourceMemberCount;                          // +0x60
    bool m_expired;                                             // +0x68
    bool m_processed;                                           // +0x69
    std::uint8_t m_padding6A[6];                               // +0x6A
};

static_assert(sizeof(I_ReputationLog::S_RepChangeRec) == 0x70,
              "I_ReputationLog::S_RepChangeRec size mismatch");
static_assert(offsetof(I_ReputationLog::S_RepChangeRec, m_seqId) == 0x08,
              "I_ReputationLog::S_RepChangeRec sequence offset mismatch");
static_assert(offsetof(I_ReputationLog::S_RepChangeRec, m_changeRequest) == 0x38,
              "I_ReputationLog::S_RepChangeRec request offset mismatch");
static_assert(offsetof(I_ReputationLog::S_RepChangeRec, m_sourceMemberCount) == 0x60,
              "I_ReputationLog::S_RepChangeRec member-count offset mismatch");

} // namespace wh::rpgmodule
