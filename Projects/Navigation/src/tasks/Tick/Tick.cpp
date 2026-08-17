#include "tasks/Tick/Tick.h"

#include "Overlay.h"
#include "FastTravel.h"
#include "PathParticles.h"
#include "input/MapInput/MapInput.h"
#include "KCSE/KCSEAPI.h"
#include "game/S_GameContext.h"
#include "playermodule/C_PlayerModule.h"
#include "playermodule/I_ActionSets.h"

// -1 = not applied yet. PTF rows start visible; the first tick must write
// even when want==0 or Navigate sits on the bar with no hover.
// 0 = none, 1 = Navigate (unarmed hover), 2 = Travel (armed hover).
static int g_chip = -1;

static bool SetChip(const char* action, bool on)
{
    auto* ctx = wh::game::S_GameContext::GetInstance();
    auto* sets = (ctx && ctx->m_pPlayerModule) ? ctx->m_pPlayerModule->m_pActionSets : nullptr;
    if (!sets)
        return false;
    const char vis = on ? 1 : 0;
    sets->SetActionVisible("apse_map_interaction", action, vis, 1);
    sets->SetActionEnabled("apse_map_interaction", action, on, 1);
    return true;
}

static void SetNavTravelChip(bool hover)
{
    const int want = !hover ? 0 : (FastTravel::IsArmed() ? 2 : 1);
    if (want == g_chip)
        return;
    // Map close/open rebuilds the live action rows without our functor. Re-bind
    // before we enable a chip or Use fires a hollow row.
    if (want != 0 && !MapInput::BindConfirm())
        return;
    if (!SetChip("nav_travel", want == 1) || !SetChip("nav_confirm", want == 2))
        return;
    g_chip = want;
}

void NavigationTick()
{
    FastTravel::ClearIfCheckpointGone();
    PathParticles::Tick();
    SetNavTravelChip(Overlay::CheckpointHovered());
    KCSE::GetTaskInterface()->AddTask(&NavigationTick);
}
