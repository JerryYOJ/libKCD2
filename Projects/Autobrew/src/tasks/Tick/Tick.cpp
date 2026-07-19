#include "tasks/Tick/Tick.h"

#include "KCSE/KCSEAPI.h"

#include <cstring>

#include "crysystem/SSystemGlobalEnvironment.h"
#include "entitymodule/C_Actor.h"
#include "entitymodule/C_Inventory.h"
#include "playermodule/C_ActionSets.h"
#include "playermodule/I_ActionSets.h"
#include "playermodule/C_Alchemy.h"
#include "playermodule/C_AlchemyRecipeDatabase.h"
#include "playermodule/C_AlchemyResource.h"

#include "core/Executor.h"
#include "mcm.h"

namespace Autobrew {

using namespace wh::playermodule;

void Tick()
{
    if (g_executor)
        g_executor->Tick();
    KCSE::GetTaskInterface()->AddTask(&Tick);
}

// The whole driver state machine.  This is the ONLY place game state is sampled, intents are
// consumed and phases transition; everything called from here is a pure query or a gate-free
// worker.
void Executor::Tick()
{
    auto* alc = m_pAlchemy;
    auto& bs = alc->m_brewState;

    // ---- world snapshot ----
    const char* context   = alc->m_currentContext.c_str();
    const bool inReading  = std::strcmp(context, "alchemy_reading") == 0;
    const bool atTable    = std::strcmp(context, "alchemy") == 0;
    const bool brewing    = bs.m_mode == E_AlchemyMode::Brewing;
    const bool bookLanded = bs.m_mode == E_AlchemyMode::Reading;   // open montage done -- the
                                                                   //   vanilla light-up instant
    const bool verbBusy   = alc->m_director.IsSlotOccupied(E_AlchemyDirectorSlot::Verb);
    const bool tableIdle  = alc->GetEffectiveState() == E_AlchemyState::Idle;
    const uint32_t openRecipeId = GetOpenRecipeId();

    // ---- intents (recorded by the action-row callbacks between our frames) ----
    const bool pressedAutobrew = m_autobrewPressed;
    const bool pressedStop     = m_stopPressed;
    m_autobrewPressed = false;
    m_stopPressed = false;

    // ---- book prompt: lit only while pressing would work (vanilla read_* timing) ----
    // MCM main switch folds into visibility AND the light (all three row properties false/empty
    // = the helpbar uninstalls the row entirely).
    bool lit = g_enableAutobrew && m_phase == E_Phase::Idle && inReading && bookLanded
               && openRecipeId != 0;
    bool missingIngredients = false;
    if (lit) {
        // Availability folds into the light, exactly like vanilla greys read_select when
        // ingredients are missing.  Only evaluated while a recipe page is up.
        auto* recipe = C_AlchemyRecipeDatabase::GetRecipeById(openRecipeId);
        auto* actor = alc->m_pPlayerActor;
        auto* inventory = actor ? actor->GetInventory() : nullptr;
        lit = recipe && inventory && recipe->CanBrewFrom(inventory);
        missingIngredients = !lit;
    }

    GetActionSets()->SetActionVisible("alchemy_reading", "alch_autobrew", g_enableAutobrew != 0, 1);

    GetActionSets()->SetActionEnabled("alchemy_reading", "alch_autobrew", lit, 1);

    GetActionSets()->SetActionDisableReason("alchemy_reading", "alch_autobrew",
        g_enableAutobrew && missingIngredients ? "dlg_alch_not_all_ingredients" : "", 1);

    // ---- stop cancels any phase (the row dispatches even while hidden) ----
    // The MCM main switch is a START gate only (folded into `lit`): flipping it off
    // mid-run lets the running batch finish on its own.
    if (pressedStop && m_phase != E_Phase::Idle) {
        ReturnToIdle();
        return;
    }

    switch (m_phase) {
    case E_Phase::Idle: {
        if (!pressedAutobrew || !lit)
            break;   // lit already embeds page validity AND ingredient availability
        m_pendingRecipeId = openRecipeId;
        m_phase = E_Phase::Arming;
        // Auto-close the book.  Dispatching from the tick task is the same execution context
        // the deferred read_back task used -- outside any action-row invoke.
        static_cast<C_ActionSets*>(GetActionSets())->TriggerAction("read_back");
        break;
    }
    case E_Phase::Arming: {
        // verbBusy for blocking reset while pouring into phial
        if (!atTable || !brewing || !tableIdle || verbBusy)
            break;   // book closing / walking back / finish flow of the previous batch
        
        if (IsWorkspaceDirty())
            alc->Reset();
        

        auto* recipe = C_AlchemyRecipeDatabase::GetRecipeById(m_pendingRecipeId);
        auto* actor = alc->m_pPlayerActor;
        auto* inventory = actor ? actor->GetInventory() : nullptr;
        if (recipe && inventory && recipe->CanBrewFrom(inventory)
            && StockStations(recipe) && BuildPlan(m_pendingRecipeId))
            BeginCooking();
        else
            ReturnToIdle();   // unsupported recipe / ingredients ran out -> loop ends
        break;
    }
    case E_Phase::Cooking: {
        if (m_planCursor >= m_plan.size()) {
            // Brew complete -> chain the next batch: back to Arming with the SAME recipe.
            // Its gate waits out the finish montage (grade+Reset run inside it, leaving a
            // clean Idle workspace) and re-stocks; when the ingredients run out the arming
            // check fails and ReturnToIdle ends the loop (restoring the result popup).
            // Looping off = single brew: back to Idle BEFORE the verdict lands, so
            // HandleBrewResult passes it through and the vanilla result popup shows.
            if (g_enableLooping)
                m_phase = E_Phase::Arming;
            else
                ReturnToIdle();
            break;
        }
        if (!brewing) {
            ++m_op.stallFrames;
            if (m_op.stallFrames > kStallAbortFrames)
                ReturnToIdle();
            break;
        }
        {
            const S_PlanOp& op = m_plan[m_planCursor];
            // Boil ops keep running DURING verb montages: they only monitor accrual and feed
            // the input buffer (the continuous-bellows chain depends on it); every dispatching
            // op still waits the Verb slot out.
            const bool boilOp = op.kind == S_PlanOp::BoilWeak || op.kind == S_PlanOp::BoilStrong;
            if (verbBusy && !boilOp) {   // a verb action is playing
                m_op.stallFrames = 0;
                break;
            }
            bool advanced = false;
            switch (op.kind) {
            case S_PlanOp::DoVerb:
                if (alc->CanPerformVerb(op.verb)) {
                    alc->PerformVerb(op.verb);
                    advanced = true;
                }
                break;
            case S_PlanOp::TakeIngredient: {
                const auto verb = FindIngredientVerb(op.guid);
                if (verb != E_AlchemyVerb::None && alc->CanPerformVerb(verb)) {
                    alc->PerformVerb(verb);
                    advanced = true;
                }
                break;
            }
            case S_PlanOp::EnsureHoldPot: {
                const auto st = alc->GetEffectiveState();
                if (st == E_AlchemyState::HoldingPot) {
                    advanced = true;
                } else if (st == E_AlchemyState::Idle
                           && alc->CanPerformVerb(E_AlchemyVerb::TakePot)) {
                    alc->PerformVerb(E_AlchemyVerb::TakePot);
                    advanced = true;
                }
                break;
            }
            case S_PlanOp::SetPotOnFire:
            case S_PlanOp::TakePotOffFire: {
                const bool wantFire = op.kind == S_PlanOp::SetPotOnFire;
                if (bs.m_potMoving)
                    break;   // swing in flight; m_potOnFire flips on its "done" anim event
                if (bs.m_potOnFire == wantFire) {
                    advanced = true;
                    break;
                }
                // Verb 20 is the halter-toggle input (delegate #6) -- position-agnostic, one
                // swing per dispatch.  Advance only once the position byte reads back.
                if (alc->CanPerformVerb(E_AlchemyVerb::MovePotBack)) {
                    alc->PerformVerb(E_AlchemyVerb::MovePotBack);
                    m_op.stallFrames = 0;
                }
                break;
            }
            case S_PlanOp::BoilWeak:
            case S_PlanOp::BoilStrong: {
                const bool strong = op.kind == S_PlanOp::BoilStrong;
                // Progress in raw SECONDS off the pot's base-liquid record: the accrual writer
                // adds the same dt to EVERY pot record, so the base's delta since this op
                // started IS the boil time this stage has added.
                const C_AlchemyResource* base = FindPotBaseRecord();
                if (!base)
                    break;   // no base liquid in the pot -> wedged; the stall abort takes over
                const float accrued = strong ? base->m_strongBoilSeconds : base->m_weakBoilSeconds;
                if (!m_op.baselineTaken) {
                    m_op.baselineTaken = true;
                    m_op.boilBaseline = accrued;
                }
                if (accrued - m_op.boilBaseline >= op.targetSeconds) {
                    if (strong && alc->m_pendingVerb == E_AlchemyVerb::UseBellows)
                        alc->m_pendingVerb = E_AlchemyVerb::None;   // un-press: no trailing pull
                    advanced = true;
                    break;
                }
                if (!bs.m_potOnFire && !bs.m_potMoving)
                    break;   // pot left the fire mid-window -> wedged; the stall abort takes over
                

                if (strong) {
                    const float remaining = op.targetSeconds - (accrued - m_op.boilBaseline);
                    const float charge = (bs.m_fireIntensity - 1.0f) * kSecondsPerIntensity;
                    if (remaining > charge)
                        alc->m_pendingVerb = E_AlchemyVerb::UseBellows;
                    else if (alc->m_pendingVerb == E_AlchemyVerb::UseBellows)
                        alc->m_pendingVerb = E_AlchemyVerb::None;
                }
                m_op.stallFrames = 0;   // waiting on wall-clock accrual IS progress...
                if (++m_op.boilFrames > static_cast<int>(120.0f * op.targetSeconds) + 3600)
                    m_op.stallFrames = kStallAbortFrames + 1;   // ...unless 2x the window + 60 s pass
                break;
            }
            }
            if (advanced) {
                ++m_planCursor;
                m_op = {};
            } else {
                ++m_op.stallFrames;
            }
        }
        // Wedge diagnostics: a state snapshot to kcd.log every ~2 s of no progress, so a stall
        // in the field pins the exact op + gate instead of guessing.
        if (m_op.stallFrames > 0 && m_op.stallFrames % 240 == 0) {
            if (auto* env = SSystemGlobalEnvironment::GetInstance(); env && env->pLog) {
                const S_PlanOp& op = m_plan[m_planCursor];
                env->pLog->LogAlways(
                    "[Autobrew] stalled %d frames: op %zu/%zu kind %d verb %d canPerform %d "
                    "state %d verbBusy %d potFire %d potMoving %d X %.2f pending %d mode %d",
                    m_op.stallFrames, m_planCursor, m_plan.size(), int(op.kind), int(op.verb),
                    int(alc->CanPerformVerb(op.verb)), int(alc->GetEffectiveState()),
                    int(verbBusy), int(bs.m_potOnFire), int(bs.m_potMoving),
                    bs.m_fireIntensity, int(alc->m_pendingVerb), int(bs.m_mode));
            }
        }
        if (m_op.stallFrames > kStallAbortFrames)   // wedged (missing herb, blocked verb...)
            ReturnToIdle();
        break;
    }
    }
}

}  // namespace Autobrew
