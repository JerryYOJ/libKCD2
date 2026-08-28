#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "C_DebugReputationLog.h"
#include "E_ReputationPropagationKind.h"

namespace wh::rpgmodule {

struct C_DebugReputationLog::S_LogEntry {
    S_LogEntry(
        const std::shared_ptr<const I_ReputationLog::S_RepChangeRec>& request,
        float contribution,
        int targetMemberCount,
        E_ReputationPropagationKind::Type propagationKind);
    S_LogEntry(const S_LogEntry& other);
    ~S_LogEntry();
    RTTR_ENABLE() // [0..2]

    const std::weak_ptr<const I_ReputationLog::S_RepChangeRec>&
        GetChangeRequest() const;

    std::weak_ptr<const I_ReputationLog::S_RepChangeRec> m_changeRequest; // +0x08
    std::uint64_t m_seqId;                                      // +0x18
    float m_contribution;                                       // +0x20
    float m_propagationFactor;                                  // +0x24
    E_ReputationPropagationKind::Type m_propagationKind;        // +0x28
    std::uint8_t m_padding29[7];                               // +0x29
};

static_assert(sizeof(C_DebugReputationLog::S_LogEntry) == 0x30,
              "C_DebugReputationLog::S_LogEntry size mismatch");
static_assert(offsetof(C_DebugReputationLog::S_LogEntry, m_changeRequest) == 0x08,
              "C_DebugReputationLog::S_LogEntry request offset mismatch");
static_assert(offsetof(C_DebugReputationLog::S_LogEntry, m_seqId) == 0x18,
              "C_DebugReputationLog::S_LogEntry sequence offset mismatch");
static_assert(offsetof(C_DebugReputationLog::S_LogEntry, m_propagationKind) == 0x28,
              "C_DebugReputationLog::S_LogEntry kind offset mismatch");

} // namespace wh::rpgmodule
