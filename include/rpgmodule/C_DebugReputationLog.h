#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>
#include "I_ReputationLog.h"

namespace wh::rpgmodule {

class C_FactionBase;

class C_DebugReputationLog : public I_ReputationLog {
public:
    struct S_LogEntry;

    explicit C_DebugReputationLog(C_FactionBase* owner);
    ~C_DebugReputationLog() override;                           // [0]
    float GetPlayerReputation(
        bool includeExpired,
        bool useCurrentState) const override;                   // [1]
    float GetPlayerRenown() const override;                     // [2]
    void AddChangeRequest(
        const S_ReputationChangeRequest& request) override;     // [3]
    void ProcessChanges() override;                             // [4]
    void Update() override;                                     // [5]
    void WriteState(void* context) const override;              // [6]
    void ReadState(void* context) override;                     // [7]
    void Clear() override;                                      // [8]
    RTTR_ENABLE(I_ReputationLog) // [9..11]

    std::vector<std::shared_ptr<S_RepChangeRec>> m_changeRecords; // +0x08
    std::vector<S_LogEntry> m_logEntries;                       // +0x20
    C_FactionBase* m_owner;                                     // +0x38
    float m_playerRenown;                                       // +0x40
    std::uint8_t m_padding44[4];                               // +0x44
};

static_assert(sizeof(C_DebugReputationLog) == 0x48,
              "C_DebugReputationLog size mismatch");
static_assert(offsetof(C_DebugReputationLog, m_changeRecords) == 0x08,
              "C_DebugReputationLog record offset mismatch");
static_assert(offsetof(C_DebugReputationLog, m_logEntries) == 0x20,
              "C_DebugReputationLog entry offset mismatch");
static_assert(offsetof(C_DebugReputationLog, m_owner) == 0x38,
              "C_DebugReputationLog owner offset mismatch");
static_assert(offsetof(C_DebugReputationLog, m_playerRenown) == 0x40,
              "C_DebugReputationLog renown offset mismatch");

} // namespace wh::rpgmodule

#include "C_DebugReputationLog_S_LogEntry.h"
