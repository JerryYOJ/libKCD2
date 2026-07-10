#include <MinHook.h>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "KCSE/KCSEAPI.h"
#include "REL.h"
#include "guimodule/C_UICompass.h"
#include "guimodule/C_UIQuestLog.h"
#include "guimodule/C_GUIModule.h"
#include "guimodule/C_CompassMark.h"
#include "guimodule/E_MarkType.h"
#include "questmodule/C_Objective.h"
#include "questmodule/C_Quest.h"
#include "framework/C_LocalizedString.h"
#include "CryEngine/CryCommon/CFlashUIElement.h"
#include "CryEngine/CryCommon/CFlashPlayer.h"
#include "Offsets/vtables/IFlashVariableObject.h"

namespace gm = wh::guimodule;
namespace qm = wh::questmodule;

namespace {

    std::map<std::string, std::string> g_objectiveNames;   // "marker<id>" -> localized objective name

    void PushTable(Offsets::IFlashPlayer* fp, const char* path,
                   const std::map<std::string, std::string>& table) {
        std::vector<const char*> flat;
        flat.reserve(table.size() * 2);
        for (const auto& [k, v] : table) {
            flat.push_back(k.c_str());
            flat.push_back(v.c_str());
        }
        fp->SetVariableArray(Offsets::IFlashPlayer::FVAT_ConstStrPtr, path, 0,
            flat.data(), static_cast<unsigned int>(flat.size()));
    }

    void PushObjectiveNames(gm::C_UICompass* compass) {
        if (auto fp = compass->m_pElement->GetFlashPlayer())
            PushTable(fp.get(), "_root.compassOverlay.co_names", g_objectiveNames);
    }

    void PushTypeNames(gm::C_UICompass* compass) {
        auto fp = compass->m_pElement->GetFlashPlayer();
        if (!fp) return;

        static const std::map<std::string, std::string> kKeySuffixOverride = {
            { "HorseTrader",     "horse_trader" },
            { "ArcheryArena",    "archery_arena" },
            { "FistFight",       "fist_fight" },
            { "HuntingSpot",     "hunting_spot" },
            { "HuntingSpotBoar", "hunting_spot_boar" },
            { "HuntingSpotRoe",  "hunting_spot_roe_deer" },
            { "HuntingSpotWolf", "hunting_spot_wolf" },
            { "ForestGarden",    "forest_garden" },
            { "CampEnemy",       "camp_enemy" },
            { "ConcCross",       "conc_cross" },
            { "GeneralPoi",      "general_poi" },
            { "VegetableShop",   "vegetable_shop" },
            { "FastTravelLevel", "fasttravel_level" },
            { "FastTravelSedlec","fasttravel_sedlec" },
        };

        std::map<std::string, std::string> table;
        for (int t = 0; t <= gm::E_MarkType::FastTravelSedlec; ++t) {
            const char* name = gm::GetMarkTypeName(static_cast<gm::E_MarkType::Type>(t));
            if (!name || !*name || (name[0] == '?' && !name[1])) continue;

            auto it = kKeySuffixOverride.find(name);
            std::string key = "ui_maplegend_" + (it != kKeySuffixOverride.end() ? it->second : std::string(name));
            CryStringT<char> loc = wh::framework::C_LocalizedString::Resolve(key.c_str());
            if (loc.empty() || key == loc.c_str()) continue;   // no loc entry -> hide
            table[name] = loc.c_str();
        }
        PushTable(fp.get(), "_root.compassOverlay.co_typeNames", table);
    }

    class{
    public:
        static bool Install() {
            void* target = reinterpret_cast<void*>(REL::Offset(0xDC5F24).address());
            if (MH_CreateHook(target, reinterpret_cast<void*>(&thunk),
                reinterpret_cast<void**>(&orig)) != MH_OK)
                return false;

            return MH_EnableHook(target) == MH_OK;
        }

        static void Uninstall() {
            void* target = reinterpret_cast<void*>(REL::Offset(0xDC5F24).address());
            MH_RemoveHook(target);
        }

    protected:
        static void thunk(gm::C_UIQuestLog* self, qm::C_Objective* obj, qm::C_Quest* quest) {
            auto* compass = self->m_pModule ? self->m_pModule->GetUICompass() : nullptr;
            const size_t before = compass ? compass->m_marks.size() : 0;

            orig(self, obj, quest);

            if (!compass || !obj) return;
            CryStringT<char> name = wh::framework::C_LocalizedString::Resolve(obj->m_locText.m_text);
            if (name.empty()) return;
            bool added = false;
            
            for (size_t i = before; i < compass->m_marks.size(); ++i) {
                const auto& mark = compass->m_marks[i];
                if (!mark) continue;
                g_objectiveNames["marker" + std::string(mark->m_id.c_str())] = name.c_str();
                added = true;
            }
            if (added) PushObjectiveNames(compass);
        }

        static inline REL::Relocation<decltype(&thunk)> orig;
    }hkAddObjectiveCompassMarkers;

    class{
    public:
        static bool Install() {
            void* target = reinterpret_cast<void*>(REL::Offset(0xC3D0A8).address());
            if (MH_CreateHook(target, reinterpret_cast<void*>(&thunk),
                reinterpret_cast<void**>(&orig)) != MH_OK)
                return false;

            return MH_EnableHook(target) == MH_OK;
        }

        static void Uninstall() {
            void* target = reinterpret_cast<void*>(REL::Offset(0xC3D0A8).address());
            MH_RemoveHook(target);
        }

    protected:
        static void thunk(gm::C_UICompass* self, void* pModule) {
            orig(self, pModule);

            auto* hud = static_cast<CFlashUIElement*>(self->m_pElement);
            if (!hud) return;
            auto fp = hud->GetFlashPlayer();
            if (!fp || fp->IsAvailable("_root.compassOverlay")) return;

            Offsets::FlashVarPtr root, mc;
            if (!fp->GetVariable("_root", root.put()) || !root) return;
            if (!root->CreateEmptyMovieClip(mc.put(), "compassOverlay") || !mc) return;

            SFlashVarValue url("compass.gfx");   // resolved relative to the parent movie dir "Libs/UI/"
            if (!mc->Invoke("loadMovie", &url, 1, nullptr)) return;

            // The stopped HUD timeline only drains its load queue on a frame-step,
            // so service our late-added entry now (see GFxMovieRoot.h).
            if (auto* movie = static_cast<CFlashPlayer*>(fp.get())->GetMovieRoot())
                movie->ProcessLoadQueue();

            PushObjectiveNames(self);
            PushTypeNames(self);
        }

        static inline REL::Relocation<decltype(&thunk)> orig;
    }hkCompassInit;

}  // namespace

bool InstallHooks() {
    if (MH_Initialize() != MH_OK)
        return false;

    return hkAddObjectiveCompassMarkers.Install()
        && hkCompassInit.Install();
}

KCSE_PLUGIN_INFO("CompassOverhaul", "JerryYOJ", 1);
KCSE_PLUGIN_LOAD(kcse)
{
    return InstallHooks();
}
