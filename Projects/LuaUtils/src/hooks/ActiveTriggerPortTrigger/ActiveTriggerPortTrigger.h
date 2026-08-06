#pragma once

#include "REL.h"
#include "conceptmodule/C_ActiveTriggerPort.h"

namespace luautils::hooks {

class ActiveTriggerPortTriggerHook
{
public:
    static bool Install();
    static void Uninstall();

private:
    static void Trigger(wh::conceptmodule::C_ActiveTriggerPort* port);

    inline static REL::Relocation<decltype(&Trigger)> orig;
};

}  // namespace luautils::hooks
