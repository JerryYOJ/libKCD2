#pragma once
#include <cstddef>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "S_WorldStateToggleId.h"

namespace wh::musicmodule {

class C_SkaldBoxProbe : public wh::conceptmodule::C_Effect {
public:
    ~C_SkaldBoxProbe() override;                               // [0] 0x1815A52CC
    RTTR_ENABLE(wh::conceptmodule::C_Effect)                   // [5..7]
    void OnEffectActivate() override;                          // [43] 0x182F2A3DC
    void OnEffectDeactivate() override;                        // [44] 0x182F2A41C
    virtual const char* unk_46();                              // [46] 0x181A9CDB0 returns "C_SkaldBoxProbe"

    wh::conceptmodule::C_TypedPortRef<S_WorldStateToggleId> m_toggle; // +0x88 RTTR "Toggle"
};

static_assert(offsetof(C_SkaldBoxProbe, m_toggle) == 0x88,
              "C_SkaldBoxProbe::m_toggle offset mismatch");
static_assert(sizeof(C_SkaldBoxProbe) == 0xC8,
              "C_SkaldBoxProbe size mismatch");

}  // namespace wh::musicmodule
