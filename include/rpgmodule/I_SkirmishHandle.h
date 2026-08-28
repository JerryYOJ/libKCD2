#pragma once
#include <cstddef>
#include "../framework/C_Signal.h"

namespace wh::rpgmodule {

class I_SkirmishEvent;

class I_SkirmishHandle {
public:
    virtual ~I_SkirmishHandle() = default;                          // [0]
    virtual void Invalidate() = 0;                                  // [1]
    virtual void ConnectInvalidated(
        const wh::shared::S_Delegate<>& delegate) = 0;              // [2]
    virtual void DisconnectInvalidated(
        const wh::shared::S_Delegate<>& delegate) = 0;              // [3]
    virtual void ConnectEvent(
        const wh::shared::S_Delegate<I_SkirmishEvent*>& delegate) = 0; // [4]
    virtual void DisconnectEvent(
        const wh::shared::S_Delegate<I_SkirmishEvent*>& delegate) = 0; // [5]
};

static_assert(sizeof(I_SkirmishHandle) == 0x08,
              "I_SkirmishHandle size mismatch");

} // namespace wh::rpgmodule
