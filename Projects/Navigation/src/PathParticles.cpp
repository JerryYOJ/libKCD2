#include "PathParticles.h"

#include <cmath>
#include <cstring>

#include "FastTravel.h"
#include "crysystem/SSystemGlobalEnvironment.h"
#include "crysystem/CCryAction.h"
#include "cry3dengine/CParticleEmitter.h"
#include "Offsets/vtables/IEntity.h"
#include "Offsets/vtables/IParticleEffect.h"
#include "Offsets/vtables/IParticleEmitter.h"
#include "Offsets/vtables/IParticleManager.h"
#include "Offsets/vtables/ITimer.h"
#include "Offsets/vtables/ILog.h"

#define NAV_LOG(fmt, ...)                                                                 \
    do                                                                                    \
    {                                                                                     \
        auto* _env = SSystemGlobalEnvironment::GetInstance();                             \
        if (_env && _env->pLog)                                                           \
            _env->pLog->LogAlways("[Navigation] " fmt, ##__VA_ARGS__);                    \
    } while (0)

namespace {

constexpr int kPool = 5;
constexpr float kLateralGuard = 5.f;
constexpr float kOffEnter = 10.f;
constexpr float kOffExit = 5.f;
constexpr int kOffFrames = 3;
constexpr float kRepathCooldown = 1.5f;

// Fixed pool: all kPool emitters are spawned when a path is SET (Sync) and
// killed+released only on Clear or the next Sync. Walking just SetLocations the
// recycled rear emitter to the window front; a slot whose sample index ran past
// the path end is parked with Activate(false) (it can never re-enter this
// path's window). Spawn hands its one reference to the particle manager, which
// retires not-alive emitters (update 0x1805D5C04 -> 0x1820DCFC0) -- so we
// AddRef everything we hold; a parked emitter may be unlinked by the engine
// but cannot be freed under us.
Offsets::IParticleEmitter* g_pool[kPool] = {};
std::vector<Vec3> g_samples;
std::vector<float> g_s;
float g_progress = 0.f;
size_t g_head = 0;
int g_offStreak = 0;
bool g_off = false;
float g_lastRepath = -1000.f;

Offsets::IParticleEffect* Effect()
{
    static Offsets::IParticleEffect* fx = nullptr;
    if (fx)
        return fx;
    auto* env = SSystemGlobalEnvironment::GetInstance();
    if (!env || !env->pParticleManager)
    {
        NAV_LOG("Effect: no pParticleManager env=%p", env);
        return nullptr;
    }
    fx = env->pParticleManager->FindEffect("navigation.distant_light", "Navigation", true);
    if (!fx)
        NAV_LOG("Effect: FindEffect navigation.distant_light failed");
    return fx;
}

bool PlayerPos(Vec3& out)
{
    auto* fw = CCryAction::GetInstance();
    auto* ent = fw ? fw->GetClientEntity() : nullptr;
    if (!ent)
        return false;
    ent->GetWorldPos(out);
    return true;
}

constexpr float kZOffset = 0.f;  // lift blobs above the nav mesh

QuatTS Loc(const Vec3& pos)
{
    return QuatTS(Quat(IDENTITY), Vec3(pos.x, pos.y, pos.z + kZOffset), 1.f);
}

void ReleaseSlot(int slot)
{
    auto* e = g_pool[slot];
    if (!e)
        return;
    g_pool[slot] = nullptr;
    e->Kill();
    static_cast<CParticleEmitter*>(e)->Release();
}

void ReleasePool()
{
    for (int i = 0; i < kPool; ++i)
        ReleaseSlot(i);
}

void SpawnSlot(int slot, const Vec3& pos)
{
    auto* fx = Effect();
    if (!fx)
    {
        NAV_LOG("SpawnSlot FAIL no fx slot=%d", slot);
        return;
    }
    auto* e = fx->Spawn(Loc(pos), 0);
    if (!e)
    {
        NAV_LOG("SpawnSlot FAIL Spawn returned null slot=%d pos=(%.1f %.1f %.1f)",
                slot, pos.x, pos.y, pos.z);
        return;
    }
    static_cast<CParticleEmitter*>(e)->AddRef();  // our ref; Spawn's ref belongs to the manager
    g_pool[slot] = e;
}

void RebuildArc()
{
    const size_t n = g_samples.size();
    g_s.resize(n);
    if (n == 0)
        return;
    g_s[0] = 0.f;
    for (size_t i = 1; i < n; ++i)
    {
        const float dx = g_samples[i].x - g_samples[i - 1].x;
        const float dy = g_samples[i].y - g_samples[i - 1].y;
        g_s[i] = g_s[i - 1] + sqrtf(dx * dx + dy * dy);
    }
}

struct Snap
{
    float dist = 1.0e30f;
    float s = 0.f;
};

// Distance to the remaining polyline INCLUDING the segment the player is on
// (from the last passed vertex), otherwise the measure jumps to the next
// vertex the instant one is passed and falsely reads as off-trail.
Snap ClosestRemaining(const Vec3& pos)
{
    Snap best;
    const size_t n = g_samples.size();
    if (n == 0)
        return best;
    const size_t first = g_head > 0 ? g_head - 1 : 0;
    if (first + 1 >= n)
    {
        const float dx = pos.x - g_samples[n - 1].x;
        const float dy = pos.y - g_samples[n - 1].y;
        best.dist = sqrtf(dx * dx + dy * dy);
        best.s = g_s[n - 1];
        return best;
    }
    best.s = g_s[first];
    for (size_t i = first; i + 1 < n; ++i)
    {
        const Vec3& a = g_samples[i];
        const Vec3& b = g_samples[i + 1];
        const float abx = b.x - a.x;
        const float aby = b.y - a.y;
        const float ab2 = abx * abx + aby * aby;
        float t = 0.f;
        if (ab2 > 1.0e-8f)
        {
            t = ((pos.x - a.x) * abx + (pos.y - a.y) * aby) / ab2;
            if (t < 0.f)
                t = 0.f;
            else if (t > 1.f)
                t = 1.f;
        }
        const float px = a.x + abx * t;
        const float py = a.y + aby * t;
        const float dx = pos.x - px;
        const float dy = pos.y - py;
        const float d = sqrtf(dx * dx + dy * dy);
        if (d < best.dist)
        {
            best.dist = d;
            best.s = g_s[i] + t * sqrtf(ab2);
        }
    }
    return best;
}

// Passed crumb: recycle the rear emitter to the new front of the window. Pure
// SetLocation on a normal walk; past the path end the emitter is parked.
void RecycleOne()
{
    auto* passed = g_pool[0];
    memmove(&g_pool[0], &g_pool[1], sizeof(g_pool[0]) * (kPool - 1));
    g_pool[kPool - 1] = passed;
    const size_t front = g_head + static_cast<size_t>(kPool - 1);
    if (!passed)
        return;
    if (front < g_samples.size())
        passed->SetLocation(Loc(g_samples[front]));
    else
        passed->Activate(false);
}

void AdvanceHead()
{
    while (g_head < g_samples.size() && g_s[g_head] <= g_progress)
    {
        ++g_head;
        RecycleOne();
    }
}

float Now()
{
    auto* env = SSystemGlobalEnvironment::GetInstance();
    if (!env || !env->pTimer)
        return 0.f;
    return env->pTimer->GetCurrTime();
}

}  // namespace

void PathParticles::Sync(const std::vector<Vec3>& nodes)
{
    ReleasePool();
    // Keep every 2nd nav node (0, 2, 4, ...) plus the final one so the trail
    // still ends on the destination.
    g_samples.clear();
    g_samples.reserve(nodes.size() / 2 + 2);
    for (size_t i = 0; i < nodes.size(); i += 2)
        g_samples.push_back(nodes[i]);
    if (!nodes.empty() && (nodes.size() - 1) % 2 != 0)
        g_samples.push_back(nodes.back());
    RebuildArc();
    g_progress = 0.f;
    g_head = 0;
    g_off = false;
    g_offStreak = 0;

    Vec3 pos;
    if (PlayerPos(pos) && g_samples.size() >= 2)
    {
        const Snap snap = ClosestRemaining(pos);
        if (snap.dist < kLateralGuard)
            g_progress = snap.s;
        while (g_head < g_samples.size() && g_s[g_head] <= g_progress)
            ++g_head;
    }
    for (int i = 0; i < kPool; ++i)
    {
        const size_t idx = g_head + static_cast<size_t>(i);
        if (idx < g_samples.size())
            SpawnSlot(i, g_samples[idx]);
    }
}

void PathParticles::Clear()
{
    ReleasePool();
    g_samples.clear();
    g_s.clear();
    g_progress = 0.f;
    g_head = 0;
    g_off = false;
    g_offStreak = 0;
}

void PathParticles::Tick()
{
    if (g_samples.size() < 2)
        return;
    Vec3 pos;
    if (!PlayerPos(pos))
        return;

    const Snap snap = ClosestRemaining(pos);
    if (snap.dist < kLateralGuard)
        g_progress = (snap.s > g_progress) ? snap.s : g_progress;

    AdvanceHead();

    if (snap.dist > kOffEnter)
    {
        if (g_offStreak < kOffFrames)
            ++g_offStreak;
        if (g_offStreak >= kOffFrames && !g_off)
        {
            g_off = true;
            const float t = Now();
            if (t - g_lastRepath >= kRepathCooldown)
            {
                g_lastRepath = t;
                FastTravel::RepathArmed();
            }
        }
    }
    else if (snap.dist < kOffExit)
    {
        g_off = false;
        g_offStreak = 0;
    }
    else
    {
        g_offStreak = 0;
    }
}
