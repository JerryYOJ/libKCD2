#include "input/MapInput/MapInput.h"

#include "FastTravel.h"
#include "crysystem/SSystemGlobalEnvironment.h"
#include "game/S_GameContext.h"
#include "playermodule/C_PlayerModule.h"
#include "playermodule/I_ActionSets.h"
#include "Offsets/vtables/IInput.h"
#include "CryEngine/CryCommon/SInputEvent.h"

MapInput MapInput::s_listener;
bool MapInput::s_registered = false;

static wh::playermodule::I_ActionSets* ActionSets()
{
    auto* ctx = wh::game::S_GameContext::GetInstance();
    auto* pm = ctx ? ctx->m_pPlayerModule : nullptr;
    return pm ? pm->m_pActionSets : nullptr;
}

bool MapInput::BindConfirm()
{
    auto* sets = ActionSets();
    if (!sets)
        return false;
    const auto confirm = [] { FastTravel::OnConfirmPressed(); };
    sets->RegisterAction("apse_map_interaction", "nav_travel", confirm, 1);
    sets->RegisterAction("apse_map_interaction", "nav_confirm", confirm, 1);
    s_registered = true;
    return true;
}

bool MapInput::Install()
{
    if (!BindConfirm())
        return false;

    // Cancel-during-travel is not a map chip; still a raw listener for Esc/B.
    auto* env = SSystemGlobalEnvironment::GetInstance();
    if (env && env->pInput)
        env->pInput->AddEventListener(&s_listener);
    return true;
}

void MapInput::Uninstall()
{
    if (s_registered)
    {
        if (auto* sets = ActionSets())
        {
            sets->UnregisterAction("apse_map_interaction", "nav_travel", 1);
            sets->UnregisterAction("apse_map_interaction", "nav_confirm", 1);
        }
        s_registered = false;
    }
    auto* env = SSystemGlobalEnvironment::GetInstance();
    if (env && env->pInput)
        env->pInput->RemoveEventListener(&s_listener);
}

bool MapInput::OnInputEvent(const Offsets::SInputEvent& e)
{
    if (!(e.state & Offsets::eIS_Pressed))
        return false;
    if (e.keyId == Offsets::eKI_Escape || e.keyId == Offsets::eKI_XI_B)
        return FastTravel::OnCancelPressed(static_cast<int>(e.keyId));
    return false;
}
