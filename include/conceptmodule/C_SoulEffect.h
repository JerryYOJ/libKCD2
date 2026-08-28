#pragma once
#include <vector>
#include "C_Effect.h"

namespace wh::rpgmodule { class I_Soul; }

// -----------------------------------------------
// wh::conceptmodule::C_SoulEffect -- soul-targeted concept effect (KCD2 WHGame.dll 1.5.6, kd7u).
// -----------------------------------------------
// Ctor sub_181E2E290: C_Effect chain then own vftable only -- adds NO data (derived
// rpgmodule::C_BuffEffect members start at +0x88 = sizeof(C_Effect)).

namespace wh::conceptmodule {

class C_SoulEffect : public C_Effect {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_conceptmodule_C_SoulEffect;
    virtual void RegisterSoulRemovalListeners();                    // [46] 0x181E2EA00
    virtual void UnregisterSoulRemovalListeners();                  // [47] 0x181E2EA90
    virtual void OnSoulRemoved(wh::rpgmodule::I_Soul* soul) = 0;   // [48]
    virtual std::vector<wh::rpgmodule::I_Soul*>
        GetAffectedSouls() const = 0;                               // [49]
};
static_assert(sizeof(C_SoulEffect) == 0x88, "conceptmodule::C_SoulEffect must be 0x88");

}  // namespace wh::conceptmodule
