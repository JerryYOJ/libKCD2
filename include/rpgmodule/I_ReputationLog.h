#pragma once
#include <cstddef>

namespace wh::rpgmodule {

struct S_ReputationChangeRequest;

class I_ReputationLog {
public:
    struct S_RepChangeRec;

    virtual ~I_ReputationLog() = default;                       // [0]
    virtual float GetPlayerReputation(
        bool includeExpired,
        bool useCurrentState) const = 0;                        // [1]
    virtual float GetPlayerRenown() const = 0;                  // [2]
    virtual void AddChangeRequest(
        const S_ReputationChangeRequest& request) = 0;          // [3]
    virtual void ProcessChanges() = 0;                          // [4]
    virtual void Update() = 0;                                  // [5]
    virtual void WriteState(void* context) const = 0;           // [6]
    virtual void ReadState(void* context) = 0;                  // [7]
    virtual void Clear() = 0;                                   // [8]
};

static_assert(sizeof(I_ReputationLog) == 0x08,
              "I_ReputationLog size mismatch");

} // namespace wh::rpgmodule

#include "I_ReputationLog_S_RepChangeRec.h"
