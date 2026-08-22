#pragma once
#include <cstdint>
#include "C_ActivityObjective.h"
#include "E_DogObjective.h"
#include "I_DogObjectiveContext.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_DogObjective : C_ActivityObjective
// (KCD2 WHGame.dll 1.5.6). sizeof 0x78. 19 slots.
// -----------------------------------------------
// RTTI .?AVC_DogObjective@activitysystem@xgenaimodule@wh@@
// vtable 0x183A42DF8, ctor 0x1806265D8(this, I_DogObjectiveContext*).
// Abstract: ComputeScore [12] and GetType [17] are _purecall.

namespace wh::xgenaimodule::activitysystem {

class C_DogObjective : public C_ActivityObjective {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_DogObjective;

    virtual E_DogObjective::Type GetType() const = 0;   // [17] 0x181D93E5D
    virtual void unk_18();                              // [18] 0x181AA6870

    C_DogObjective* FindByType(E_DogObjective::Type type) const;

    bool                    m_selfRunning;  // +0x68
    bool                    m_bound;        // +0x69
    uint8_t                 _pad6A[6];      // +0x6A
    I_DogObjectiveContext*  m_pContext;     // +0x70
};
static_assert(sizeof(C_DogObjective) == 0x78,
              "C_DogObjective must be 0x78 (leaves start at +0x78)");
static_assert(offsetof(C_DogObjective, m_pContext) == 0x70,
              "factory context at +0x70");

}  // namespace wh::xgenaimodule::activitysystem
