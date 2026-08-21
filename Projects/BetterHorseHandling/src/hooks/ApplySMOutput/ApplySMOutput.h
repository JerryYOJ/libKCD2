#pragma once

#include "REL.h"
#include "entitymodule/C_RiderPlayerInput.h"
#include "entitymodule/S_HorseData.h"
#include "entitymodule/S_RiderMoveRequest.h"
#include "entitymodule/S_RiderSMOutput.h"

namespace hooks {

// C_RiderPlayerInput::ApplySMOutput, REL::ID 56418.
class ApplySMOutputHook {
public:
    static bool Install();
    static void Uninstall();

private:
    static char ApplySMOutput(wh::entitymodule::C_RiderPlayerInput* self,
                              wh::entitymodule::S_RiderSMOutput* smOut,
                              wh::entitymodule::S_RiderMoveRequest* request,
                              wh::entitymodule::S_HorseData* data, float dt);

    inline static REL::Relocation<decltype(&ApplySMOutput)> orig;
};

}  // namespace hooks
