#include "LockpickOverhaul.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <unordered_map>

#include "crysystem/CCryAction.h"
#include "entitymodule/C_Actor.h"
#include "game/S_GameContext.h"
#include "guimodule/C_GUIModule.h"
#include "guimodule/C_UIBase.h"
#include "playermodule/C_MinigameManager.h"
#include "playermodule/C_PlayerModule.h"
#include "playermodule/E_MinigameType.h"
#include "rpgmodule/C_RPGModule.h"
#include "rpgmodule/S_RpgParams.h"
#include "mcm.h"

namespace LockpickOverhaul {

Engagement g_eng{};
bool       g_keySwapped = false;

namespace {

constexpr float kAngleTable[5] = { 180.f, 135.f, 90.f, 45.f, 13.f };

// Best round-count reached per lock (EntityId), surviving Teardown so
// re-entering a lock cannot re-farm XP for rounds already won. In-memory only.
std::unordered_map<uint32_t, int> g_bestWins;

}  // namespace

wh::playermodule::C_LockPicking* FindSession()
{
    auto* ctx = wh::game::S_GameContext::GetInstance();
    auto* pm = ctx ? ctx->m_pPlayerModule : nullptr;
    auto* mgr = pm ? pm->m_pMinigameManager : nullptr;
    auto* fw = CCryAction::GetInstance();
    if (!mgr || !fw)
        return nullptr;
    return static_cast<wh::playermodule::C_LockPicking*>(
        mgr->FindOrCreateSession(fw->GetClientActorId(),
                                 wh::playermodule::E_MinigameType::LockPicking,
                                 false, false));
}

wh::rpgmodule::I_RPGMinigames* Minigames()
{
    auto* ctx = wh::game::S_GameContext::GetInstance();
    if (!ctx || !ctx->m_pRPGModule)
        return nullptr;
    return ctx->m_pRPGModule->m_pMinigames;
}

wh::guimodule::C_UIHudMessages* FindHud()
{
    auto* gui = wh::guimodule::C_GUIModule::GetInstance();
    if (!gui)
        return nullptr;
    for (auto& e : gui->m_uiElements) {
        if (auto* hud = kcd_cast<wh::guimodule::C_UIHudMessages*>(e.get()))
            return hud;
    }
    return nullptr;
}

int CalcN(wh::rpgmodule::I_RPGMinigames* rpg, wh::rpgmodule::C_Soul* soul,
          float d0, wh::playermodule::E_InputDeviceClass::Type device)
{
    if (!rpg || !soul)
        return 1;

    float T = 0.f;
    if (rpg->EvalLockpickingSweetSpot(soul, d0, device, &T))
        return 1;

    float base = 0.f, termDiff = 0.f, termSkill = 0.f, thresh = 0.f;
    rpg->EvalLockpickingSweetSpotTerms(soul, d0, device, &base, &termDiff, &termSkill, &thresh);

    auto* defs = wh::rpgmodule::S_RpgParamDefs::Get();
    const bool controller = wh::playermodule::IsController(device);
    const float skillC = controller
        ? defs->ControllerLockPickingToleranceSkillCoef.Value().asFloat
        : defs->LockPickingToleranceSkillCoef.Value().asFloat;
    const float expC = controller
        ? defs->ControllerLockPickingToleranceSkillExpCoef.Value().asFloat
        : defs->LockPickingToleranceSkillExpCoef.Value().asFloat;
    if (skillC <= 0.f || expC <= 0.f)
        return 2;

    const float room = base + termDiff - thresh;
    float gap = 0.f;
    if (room <= 0.f) {
        const float s = (termSkill >= 0.f) ? 0.f : (-std::log((-termSkill) / skillC) / expC);
        gap = std::max(static_cast<float>(defs->SkillCap.Value().asInt) - s, 1.f);
    } else if (room >= skillC) {
        return 1;
    } else {
        const float sEq = -std::log(room / skillC) / expC;
        const float s = (termSkill >= 0.f) ? 0.f : (-std::log((-termSkill) / skillC) / expC);
        gap = std::max(sEq - s, 0.f);
    }

    const float extra = std::max(1.f, std::ceil(g_factor * gap - 1e-12f));
    const int n = 1 + static_cast<int>(extra);
    // Factor 1 tops out at 10; the cap scales with factor so >1 can go higher.
    const int cap = std::max(1, static_cast<int>(std::ceil(10.f * std::max(g_factor, 0.f) - 1e-12f)));
    return n > cap ? cap : n;
}

void CalcDkTk(wh::rpgmodule::I_RPGMinigames* rpg, wh::rpgmodule::C_Soul* soul,
              float d0, wh::playermodule::E_InputDeviceClass::Type device,
              int wins, int n, float* dK, float* tK)
{
    float t = 0.f;
    if (n > 1)
        t = static_cast<float>(wins) / static_cast<float>(n - 1);
    const float ease = t * t * t;
    *dK = d0 * (1.f - 0.5f * ease);

    float Tmin = 0.048f;
    if (rpg && soul) {
        float dummy = 0.f, dummy2 = 0.f, dummy3 = 0.f;
        rpg->EvalLockpickingSweetSpotTerms(soul, d0, device, &dummy, &dummy2, &dummy3, &Tmin);
    }
    const float denom = 1.f - 0.5f * ease;
    const float scale = g_tScale > 0.f ? g_tScale : 1.f;
    const float floorT = (Tmin * scale) / (denom > 1e-6f ? denom : 1e-6f);

    float Traw = 0.f;
    if (rpg && soul)
        rpg->EvalLockpickingSweetSpot(soul, *dK, device, &Traw);
    *tK = std::max(Traw, floorT);
}

float DifficultyFromT(wh::rpgmodule::I_RPGMinigames* rpg, wh::rpgmodule::C_Soul* soul,
                      float t, wh::playermodule::E_InputDeviceClass::Type device)
{
    if (!rpg || !soul)
        return 0.f;

    float base = 0.f, termDiff = 0.f, termSkill = 0.f, thresh = 0.f;
    rpg->EvalLockpickingSweetSpotTerms(soul, 0.f, device, &base, &termDiff, &termSkill, &thresh);
    (void)termDiff;
    (void)thresh;

    auto* defs = wh::rpgmodule::S_RpgParamDefs::Get();
    const float diffC = wh::playermodule::IsController(device)
        ? defs->ControllerLockPickingToleranceDifficultyCoef.Value().asFloat
        : defs->LockPickingToleranceDifficultyCoef.Value().asFloat;
    if (diffC <= 1e-6f)
        return 0.f;

    const float d = (base + termSkill - t) / diffC;
    if (d < 0.f)
        return 0.f;
    if (d > 1.f)
        return 1.f;
    return d;
}

float BandAngle(float d)
{
    int band = 4;
    if (d < 0.2f)
        band = 0;
    else if (d < 0.4f)
        band = 1;
    else if (d < 0.6f)
        band = 2;
    else if (d < 0.8f)
        band = 3;
    return kAngleTable[band];
}

void EnsureEngagement(wh::rpgmodule::I_RPGMinigames* rpg, wh::rpgmodule::C_Soul* soul,
                      float d0, wh::playermodule::E_InputDeviceClass::Type device)
{
    if (g_eng.active)
        return;
    g_eng.d0 = d0;
    g_eng.wins = 0;
    g_eng.n = CalcN(rpg, soul, d0, device);
    g_eng.active = true;
}

void ClearEngagement()
{
    g_eng = {};
}

int BestWins(uint32_t lockEntityId)
{
    auto it = g_bestWins.find(lockEntityId);
    return it != g_bestWins.end() ? it->second : 0;
}

void RecordBestWins(uint32_t lockEntityId, int wins)
{
    int& best = g_bestWins[lockEntityId];
    if (wins > best)
        best = wins;
}

void ForgetLock(uint32_t lockEntityId)
{
    g_bestWins.erase(lockEntityId);
}

void BeginNextRound(wh::playermodule::C_LockPicking* session)
{
    if (!session)
        return;
    auto* rpg = Minigames();
    auto* soul = session->m_pPlayerActor ? session->m_pPlayerActor->m_pSoul : nullptr;
    const auto device = session->m_inputDeviceClass;
    float dK = 0.f, tK = 0.f;
    CalcDkTk(rpg, soul, g_eng.d0, device, g_eng.wins, g_eng.n, &dK, &tK);
    session->m_sweetSpot = tK;
    session->m_startAngle = BandAngle(dK);
    session->ResetPlayFields();
    session->SetLockAngle(session->m_startAngle);
    session->m_state = wh::playermodule::E_LockPickingState::PlayIdle;
    session->RestartPlayActions();
}

void SwapTooHardKey()
{
    auto* hud = FindHud();
    if (!hud || g_keySwapped)
        return;
    hud->m_lockpickingHandleKeys[2] = kTooHardKey;
    g_keySwapped = true;
}

void RestoreTooHardKey()
{
    auto* hud = FindHud();
    if (!hud || !g_keySwapped)
        return;
    hud->m_lockpickingHandleKeys[2] = kVanillaTooHardKey;
    g_keySwapped = false;
}

void ShowProgressToast()
{
    auto* hud = FindHud();
    if (!hud)
        return;

    // ShowInfoText Standardize + Flash split on '|': each @key is localized, other
    // segments stay literal. Spaces next to '|' are stripped, so the space before
    // "(wins/n)" lives in the loc string.
    char buf[160];
    std::snprintf(buf, sizeof buf, "@%s|(%d/%d)", kProgressKey, g_eng.wins, g_eng.n);
    CryStringT<char> text(buf);
    hud->ShowInfoText(text, 0, 0);
}

}  // namespace LockpickOverhaul
