#pragma once
#include <cstdint>
#include <cstddef>

// -----------------------------------------------
// wh::entitymodule::S_ActorActionRiderParams -- KCD2 WHGame.dll.  sizeof 8.
// -----------------------------------------------
// C_ParamAction TParams at object +0x50. Serialize keys "horseGUID" and
// "m_Params.m_AdvanceCollision". The 0x38 at +0x70 is Rider runtime, not this.

namespace wh::entitymodule {

struct S_ActorActionRiderParams {
    uint32_t m_horseEntityId;     // +0x00  abs +0x50
    uint8_t  m_flag04;            // +0x04  abs +0x54  Serialize-load writes 1
    uint8_t  m_AdvanceCollision;  // +0x05  abs +0x55
    uint16_t _pad06;              // +0x06
};
static_assert(sizeof(S_ActorActionRiderParams) == 8, "Rider params are 8 bytes");

}  // namespace wh::entitymodule
