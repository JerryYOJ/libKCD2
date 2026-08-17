#include "FastTravel.h"

#include <vector>

#include "Overlay.h"
#include "PathQuery.h"
#include "PathParticles.h"
#include "KCSE/KCSEAPI.h"
#include "crysystem/SSystemGlobalEnvironment.h"
#include "crysystem/CCryAction.h"
#include "Offsets/vtables/I3DEngine.h"
#include "Offsets/vtables/IEntity.h"
#include "game/S_GameContext.h"
#include "playermodule/C_PlayerModule.h"
#include "playermodule/C_FastTravel.h"
#include "guimodule/C_UIMap.h"
#include "guimodule/C_UIApse.h"
#include "framework/E_UIApseView.h"

using wh::playermodule::C_FastTravel;
using wh::guimodule::C_UIMap;
using wh::framework::E_UIApseView;

#define NAV_LOG(fmt, ...) SSystemGlobalEnvironment::GetInstance()->pLog->LogAlways("[Navigation] " fmt, ##__VA_ARGS__)

static Vec3 g_armedDest = {0, 0, 0};
static std::vector<Vec3> g_previewNodes;
static bool g_armed = false;

static bool RecalcAndPush(const Vec3& dest)
{
    auto* fw = CCryAction::GetInstance();
    auto* ent = fw ? fw->GetClientEntity() : nullptr;
    if (!ent)
        return false;
    Vec3 start;
    ent->GetWorldPos(start);
    if (!QueryWorldPath(start, dest, g_previewNodes))
    {
        NAV_LOG("FindPath failed dest=(%.1f %.1f %.1f)", dest.x, dest.y, dest.z);
        g_previewNodes.clear();
        return false;
    }
    Overlay::PushPath(g_previewNodes);
    PathParticles::Sync(g_previewNodes);
    return true;
}

C_FastTravel* FastTravel::Get()
{
    auto* ctx = wh::game::S_GameContext::GetInstance();
    if (!ctx || !ctx->m_pPlayerModule)
        return nullptr;
    return ctx->m_pPlayerModule->m_pFastTravel;
}

bool FastTravel::RandomEventPromptOpen()
{
    auto* map = C_UIMap::GetInstance();
    return map && map->m_randomEventDialog.m_isOpen;
}

void FastTravel::TryCancel()
{
    auto* ft = Get();
    if (ft && ft->IsFastTraveling() && !RandomEventPromptOpen())
    {
        NAV_LOG("CancelFastTravel()");
        ft->CancelFastTravel();
    }
}

bool FastTravel::RouteArmedTo(const Vec3& dest)
{
    return g_armed && g_armedDest.x == dest.x && g_armedDest.y == dest.y && g_previewNodes.size() >= 2;
}

bool FastTravel::IsArmed()
{
    return g_armed;
}

void FastTravel::HideLine(C_UIMap* map)
{
    (void)map;
    if (!g_armed && g_previewNodes.empty())
        return;
    g_armed = false;
    g_previewNodes.clear();
    Overlay::ClearPath();
    PathParticles::Clear();
}

void FastTravel::ClearIfCheckpointGone()
{
    if (!g_armed)
        return;
    auto* map = C_UIMap::GetInstance();
    auto* el = map ? map->m_content.m_pElement : nullptr;
    if (!el || !el->IsVisible())
        return;
    Vec2 mark;
    map->GetCheckpointMarkPos(mark);
    if (mark.x == 0.0f && mark.y == 0.0f)
        HideLine(map);
}

void FastTravel::RestoreOnInit()
{
    if (!g_armed)
        return;
    RecalcAndPush(g_armedDest);
}

void FastTravel::RepathArmed()
{
    if (!g_armed)
        return;
    auto* fw = CCryAction::GetInstance();
    auto* ent = fw ? fw->GetClientEntity() : nullptr;
    if (!ent)
        return;
    Vec3 start;
    ent->GetWorldPos(start);
    std::vector<Vec3> nodes;
    if (!QueryWorldPath(start, g_armedDest, nodes))
        return;
    g_previewNodes = std::move(nodes);
    Overlay::PushPath(g_previewNodes);
    PathParticles::Sync(g_previewNodes);
}

bool FastTravel::OnConfirmPressed()
{
    auto* map = C_UIMap::GetInstance();
    if (!map || map->m_modalDialog.m_isOpen)
        return false;
    auto* el = map->m_content.m_pElement;
    if (!el || !el->IsVisible() || !Overlay::CheckpointHovered())
        return false;

    Vec2 mark;
    map->GetCheckpointMarkPos(mark);
    if (mark.x == 0.0f && mark.y == 0.0f)
        return false;
    auto* env = SSystemGlobalEnvironment::GetInstance();
    if (!env || !env->p3DEngine)
        return false;
    const Vec3 dest = { mark.x, mark.y, env->p3DEngine->GetTerrainElevation(mark.x, mark.y) };

    if (!RouteArmedTo(dest))
    {
        if (!RecalcAndPush(dest))
            return true;
        g_armed = true;
        g_armedDest = dest;
        NAV_LOG("arm: dest=(%.1f %.1f %.1f) nodes=%zu", dest.x, dest.y, dest.z, g_previewNodes.size());
        return true;
    }

    NAV_LOG("confirm: opening dialog");
    map->RemoveCheckpointMark();
    map->m_modalDialog.Open(
        CryStringT<char>("@ui_dlg_fasttravel_confirm"),
        nullptr,
        [dest] {
            auto* f = Get();
            auto* m = C_UIMap::GetInstance();
            if (!f || !m)
                return;
            NAV_LOG("confirm: yes -> StartTravel");
            m->SetDestination(dest, false, false);
            f->StartTravel();
            m->m_ftPathPending = false;
            HideLine(m);
            if (auto* apse = m->m_pApse)
                apse->SetApseView(E_UIApseView::Map, 1, 0);
        },
        [] {
            NAV_LOG("confirm: no");
            if (auto* m = C_UIMap::GetInstance())
                HideLine(m);
        },
        CryStringT<char>("ui_Yes"),
        CryStringT<char>("ui_No"));
    return true;
}

bool FastTravel::OnCancelPressed(int keyId)
{
    auto* ft = Get();
    if (ft && ft->IsFastTraveling() && !RandomEventPromptOpen())
    {
        NAV_LOG("cancel requested (key %d)", keyId);
        KCSE::GetTaskInterface()->AddTask(TryCancel);
        return true;
    }
    return false;
}
