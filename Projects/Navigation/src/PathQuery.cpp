#include "PathQuery.h"

#include "game/S_GameContext.h"
#include "xgenaimodule/C_XGenAIModule.h"
#include "xgenaimodule/navigation/C_Navigation.h"
#include "xgenaimodule/navigation/E_PathFindingMode.h"
#include "xgenaimodule/navigation/I_NavigationElement.h"
#include "xgenaimodule/navigation/S_PathFindingRequestDefault.h"

bool QueryWorldPath(const Vec3& start, const Vec3& target, std::vector<Vec3>& outNodes)
{
    outNodes.clear();
    auto* ctx = wh::game::S_GameContext::GetInstance();
    auto* xgen = ctx ? ctx->m_pXGenAIModule : nullptr;
    auto* nav = xgen ? xgen->m_pNavigation : nullptr;
    if (!nav)
        return false;

    auto* finder = nav->GetPathFinder();
    auto* result = nav->CreatePathResult();
    if (!finder || !result)
    {
        if (result)
            nav->DestroyPathResult(result);
        return false;
    }

    wh::xgenaimodule::navigation::S_PathFindingRequestDefault req;
    req.m_navMeshId = nav->DefaultNavMeshId();
    req.m_pResult = result;
    req.m_onComplete = [](const wh::xgenaimodule::navigation::S_PathFindingResult&) {};
    req.m_start = start;
    req.m_target = target;
    req.m_mode = wh::xgenaimodule::navigation::E_PathFindingMode::Forced;

    const auto status = finder->FindPath(req);
    bool ok = status.m_status == 0;
    if (ok)
    {
        for (auto* el : result->m_elements)
        {
            if (!el)
                continue;
            auto* pts = el->GetPoints();
            if (!pts)
                continue;
            for (const auto& p : *pts)
            {
                if (!outNodes.empty())
                {
                    const auto& last = outNodes.back();
                    if (last.x == p.x && last.y == p.y && last.z == p.z)
                        continue;
                }
                outNodes.push_back(p);
            }
        }
        ok = outNodes.size() >= 2;
    }

    nav->DestroyPathResult(result);
    return ok;
}
