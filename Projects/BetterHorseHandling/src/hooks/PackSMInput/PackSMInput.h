#pragma once

#include <cstdint>

#include "REL.h"
#include "entitymodule/C_RiderPlayerInput.h"
#include "entitymodule/S_HorseData.h"
#include "entitymodule/S_RiderSMPackedInput.h"

namespace hooks {

// C_RiderPlayerInput::PackSMInput, REL::ID 56419.
class PackSMInputHook {
public:
    static bool Install();
    static void Uninstall();

private:
    static int64_t PackSMInput(wh::entitymodule::C_RiderPlayerInput* self,
                               wh::entitymodule::S_RiderSMPackedInput* packed,
                               wh::entitymodule::S_HorseData* data);

    inline static REL::Relocation<decltype(&PackSMInput)> orig;
};

}  // namespace hooks
