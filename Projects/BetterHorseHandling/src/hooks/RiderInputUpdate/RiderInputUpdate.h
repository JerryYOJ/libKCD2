#pragma once

#include "REL.h"
#include "entitymodule/C_RiderPlayerInput.h"
#include "entitymodule/S_HorseData.h"

namespace hooks {

// C_RiderPlayerInput::Update, REL::ID 56411.
class RiderInputUpdateHook {
public:
    static bool Install();
    static void Uninstall();

private:
    static void Update(wh::entitymodule::C_RiderPlayerInput* self,
                       wh::entitymodule::S_HorseData* data, float dt);

    inline static REL::Relocation<decltype(&Update)> orig;
};

}  // namespace hooks
