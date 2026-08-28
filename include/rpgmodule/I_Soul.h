#pragma once
#include <cstddef>
#include "../framework/WUID.h"

// -----------------------------------------------
// wh::rpgmodule::I_Soul -- KCD2 WHGame.dll 1.5.6. Pure interface.
// -----------------------------------------------
// C_Soul primary slot 0 target 0x181A749E0 returns this+0x30, exactly
// C_Soul::m_selfWuid. Callers throughout the skirmish subsystem use this slot
// as an eight-byte WUID key; it is not a virtual destructor.

namespace wh::rpgmodule {

class I_Soul {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_Soul;
    virtual const wh::framework::WUID& GetWuid() const = 0;        // [0]
};

static_assert(sizeof(I_Soul) == 0x08, "I_Soul size mismatch");

} // namespace wh::rpgmodule
