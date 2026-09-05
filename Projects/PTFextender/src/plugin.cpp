// Hook sites:
//   defaultActionHelp.xml    write_call<5> @ REL::ID 65542 + 0x48 wrapping C_ActionSets::ParseActionHelp_180A13558
//                            (caller 0x180C3D5B4 is an I_ActionSets vfunc: it loads the XML and
//                            calls the parser with this-8 = the complete C_ActionSets object)
//   keybindSuperactions.xml  write_call<5> @ REL::ID 33537 + 0x73 wrapping C_Keybinds::ParseKeybindsXml_1808FB4CC
//   defaultProfile.xml       MinHook on CActionMapManager::LoadFromXML_180A13E3C (REL::ID 55292,
//                            IActionMapManager slot [7]). Two verified invokers:
//                            C_Game::LoadConfigXml_18173CB3C (stock profile path, overridable)
//                            and InitActionMaps_183573BFC (arbitrary file, but it records it
//                            via SetLoadFromXMLPath first) — so the detour keys the patch by
//                            GetLoadFromXMLPath() and falls back to the stock path when unset.
//                            Controller layouts and user rebinds go through the separate
//                            LoadRebindDataFromXML slot [8] and are never touched.

#include <MinHook.h>

#include "KCSE/KCSEAPI.h"
#include "REL.h"
#include "crysystem/SSystemGlobalEnvironment.h"
#include "Offsets/vtables/IActionMapManager.h"
#include "Offsets/vtables/ICryPak.h"
#include "Offsets/vtables/ILog.h"
#include "Offsets/vtables/ISystem.h"
#include "Offsets/vtables/IXmlNode.h"
#include "Offsets/vtables/IXmlUtils.h"
#include "playermodule/C_ActionSets.h"
#include "playermodule/C_Keybinds.h"
#include "mod_index.h"
#include "ptf_families.h"

#include <windows.h>

#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using Offsets::IXmlNode;

// --------------------------------------------------------------- PTF merge ---

namespace {

// IXmlNode::getAttr [33] returns the engine's static "" when absent (never
// NULL); the guard is belt-and-suspenders.
const char* AttrOrEmpty(IXmlNode* node, const char* key)
{
    const char* v = node->getAttr(key);
    return v ? v : "";
}

void CopyAttributes(IXmlNode* dst, IXmlNode* src)
{
    const int n = src->getNumAttributes();
    for (int i = 0; i < n; ++i) {
        const char* key = nullptr;
        const char* val = nullptr;
        if (src->getAttributeByIndex(i, &key, &val) && key && val)
            dst->setAttr(key, val);
    }
}

// The text of a direct child element -- `<GameProfile><Name>x</Name>`, which an attribute-only
// identity cannot express. [49] getContent, VERIFIED: it is the trivial getter of the content
// member, and returns the shared static empty string rather than NULL when a node has no text.
const char* ChildText(IXmlNode* node, const char* tag)
{
    IXmlNode* c = nullptr;
    node->findChild(&c, tag);
    if (!c)
        return "";
    const char* t = c->getContent();
    // the caller compares immediately; the string is interned in the node's own table and outlives
    // this reference for as long as the tree does
    c->Release();
    return t ? t : "";
}

// Row identity, from the FAMILY DESCRIPTOR rather than a fixed attribute list.
//
// WHY A DESCRIPTOR. The shipped rule compares seven hardcoded attribute names, which happens to
// span the three keybind files it was written for. It cannot express the families a content mod
// actually claims: `whdata_1` keys on a CHILD ELEMENT, `waitinglinks` on a PAIR of attributes plus
// a child, and an arbitrary `Libs\Tables` row on that table's primary key. Worse, a fixed list is
// silently wrong rather than absent -- measured, `skill_check_difficulty.xml` carries none of the
// seven, so every row keys identically and rows pair by POSITION.
//
// `spec` is the identity string from the generated table: `attr:X`, `attr:X+attr:Y`, `child:X`, or
// any combination. Absent parts compare as "" on both sides, so a row missing the key still matches
// only another row missing it.
bool IdentityMatches(IXmlNode* a, IXmlNode* b, const char* spec)
{
    if (std::strcmp(a->getTag(), b->getTag()) != 0)
        return false;
    if (!spec || !*spec) {
        // No descriptor: fall back to the shipped seven-attribute key. That is the behaviour the
        // three config files have always had, and it stays exactly as it was for them.
        static const char* const kIdAttrs[] = { "name", "actionmap", "action", "alternative",
                                                "map", "input", "controller" };
        for (const char* key : kIdAttrs)
            if (std::strcmp(AttrOrEmpty(a, key), AttrOrEmpty(b, key)) != 0)
                return false;
        return true;
    }
    const char* p = spec;
    while (*p) {
        const char* plus = std::strchr(p, '+');
        const std::string term(p, plus ? static_cast<size_t>(plus - p) : std::strlen(p));
        const size_t colon = term.find(':');
        if (colon != std::string::npos) {
            const std::string kind = term.substr(0, colon);
            const std::string key = term.substr(colon + 1);
            if (kind == "attr") {
                if (std::strcmp(AttrOrEmpty(a, key.c_str()), AttrOrEmpty(b, key.c_str())) != 0)
                    return false;
            } else if (kind == "child") {
                if (std::strcmp(ChildText(a, key.c_str()), ChildText(b, key.c_str())) != 0)
                    return false;
            }
        }
        if (!plus)
            break;
        p = plus + 1;
    }
    return true;
}

// Glob match where `*` NEVER CROSSES A SEPARATOR.
//
// `fnmatch`-style matching lets `*` swallow `/`, and that is not a nicety here: the rule written for
// a graph NODE then also catches every EDGE inside it, the edges key on an attribute they do not
// carry, and a contested rewiring comes out silently applied. Measured on the Python side before
// this was written.
bool GlobMatch(const char* pat, const char* str)
{
    if (*pat == '\0')
        return *str == '\0';
    if (*pat == '*') {
        for (const char* s = str;; ++s) {
            if (GlobMatch(pat + 1, s))
                return true;
            if (*s == '\0' || *s == '/' || *s == '\\')
                return false;                   // the wildcard stops at a separator
        }
    }
    if (*str == '\0')
        return false;
    const char a = static_cast<char>(::tolower(static_cast<unsigned char>(*pat)));
    const char b = static_cast<char>(::tolower(static_cast<unsigned char>(*str)));
    const bool same = (a == b) || ((a == '/' || a == '\\') && (b == '/' || b == '\\'));
    return same && GlobMatch(pat + 1, str + 1);
}

// The path a family glob is matched against.
//
// SPELLING VARIES BY CALLER, measured from a launch-load-quit that logged all 28,019 paths the
// engine asked for:
//
//     levels/kutnohorsko/LevelData.xml            mixed case, no prefix
//     levels/kutnohorsko/Objects_Mission0.xml
//     levels/kutnohorsko/whdata_1                 no extension at all
//     data/levels/kutnohorsko/WaitingLinks.xml    ...and this one carries `data/`
//
// A glob written one way would silently miss three of the four. Lowercase, forward slashes, and a
// leading `data/` removed -- CryPak is rooted there, so the two spellings name one file. The
// ORIGINAL string is still what FindFirst is given, because that is what the engine resolved.
std::string NormalisePath(const char* p)
{
    std::string v(p ? p : "");
    for (char& c : v) {
        if (c == '\\')
            c = '/';
        else
            c = static_cast<char>(::tolower(static_cast<unsigned char>(c)));
    }
    if (v.compare(0, 5, "data/") == 0)
        v.erase(0, 5);
    return v;
}

// Which family, if any, describes this virtual path.
const ptf::Family* FamilyFor(const char* vpath)
{
    if (!vpath)
        return nullptr;
    const std::string v = NormalisePath(vpath);
    for (std::size_t i = 0; i < ptf::kFamilyCount; ++i)
        if (GlobMatch(ptf::kFamilies[i].glob, v.c_str()))
            return &ptf::kFamilies[i];
    return nullptr;
}

// The identity rule in force for the children of `parentPath`, or nullptr when no family describes
// it -- in which case `IdentityMatches` uses the shipped seven-attribute key, unchanged.
const char* IdentityFor(const ptf::Family* fam, const std::string& parentPath)
{
    if (!fam)
        return nullptr;
    for (std::size_t i = 0; i < fam->ruleCount; ++i) {
        const std::string rule(fam->rules[i].path);
        // the rule names the ROW path; we are asked about its parent
        const size_t slash = rule.find_last_of('/');
        if (slash != std::string::npos && rule.substr(0, slash) == parentPath)
            return fam->rules[i].identity;
    }
    return nullptr;
}

int FindChildIndex(IXmlNode* base, IXmlNode* like, const char* idSpec)
{
    const int n = base->getChildCount();
    for (int i = 0; i < n; ++i) {
        IXmlNode* c = nullptr;
        base->getChild(&c, i);
        if (!c)
            continue;
        const bool match = IdentityMatches(c, like, idSpec);
        c->Release();
        if (match)
            return i;
    }
    return -1;
}

struct S_MergeStats {
    int added = 0;      // appended nodes (no key match in base), any depth
    int modified = 0;   // replaced leaves + attr-updated containers, any depth
};

// Stock row-merge, transplanted to XML: keyed replace-or-append, recursing into
// containers so a mod can patch a single <action> without restating the whole
// actionmap. Patch subtrees are shared into the base document — the same
// technique the stock XMLPatcher uses (insertChild/replaceChild AddRef the node).
void MergeChildren(IXmlNode* base, IXmlNode* patch, S_MergeStats& stats,
                   const ptf::Family* fam = nullptr, const std::string& path = std::string())
{
    // The element path is carried down so each level of the recursion can ask the descriptor which
    // rule governs ITS children. Without it a family could only describe rows at one depth.
    const std::string here = path + "/" + base->getTag();
    const char* idSpec = IdentityFor(fam, here);

    const int n = patch->getChildCount();
    for (int i = 0; i < n; ++i) {
        IXmlNode* p = nullptr;
        patch->getChild(&p, i);
        if (!p)
            continue;

        const int at = FindChildIndex(base, p, idSpec);
        if (at < 0) {
            IXmlNode* add = nullptr;                         // clone: p may be read-only
            p->clone(&add, false);
            if (add) {
                base->insertChild(base->getChildCount(), &add);  // added
                add->Release();
                ++stats.added;
            }
        } else {
            IXmlNode* b = nullptr;
            base->getChild(&b, at);
            if (b) {
                if (p->getChildCount() == 0 && b->getChildCount() == 0) {
                    IXmlNode* repl = nullptr;
                    p->clone(&repl, false);
                    if (repl) {
                        base->replaceChild(at, &repl);       // modified (leaf row)
                        repl->Release();
                        ++stats.modified;
                    }
                } else {
                    // container (either side has children): never replace — a
                    // patch leaf must not wipe the base node's subtree
                    if (p->getNumAttributes() > 0) {
                        CopyAttributes(b, p);                // modified (attrs)
                        ++stats.modified;
                    }
                    MergeChildren(b, p, stats, fam, here);   // recurse, carrying the path
                }
                b->Release();
            }
        }
        p->Release();
    }
}

// The provenance map, built once. See mod_index.h: the find record carries no pak field, so a
// patch's ORIGIN cannot be read off the enumeration and has to be indexed from the mod paks.
ptf::ModIndex g_mods;
bool          g_modsBuilt = false;

const ptf::ModIndex& Mods()
{
    if (!g_modsBuilt) {
        g_modsBuilt = true;
        char exe[MAX_PATH] = {0};
        ::GetModuleFileNameA(nullptr, exe, MAX_PATH);
        // <game>\Bin\Win64MasterMasterSteamPGO\KingdomCome.exe -> <game>
        std::string root(exe);
        for (int up = 0; up < 3; ++up) {
            const size_t slash = root.find_last_of("/\\");
            if (slash == std::string::npos)
                break;
            root.erase(slash);
        }
        g_mods.Build(root);
        auto* env = SSystemGlobalEnvironment::GetInstance();
        if (env && env->pLog)
            env->pLog->LogAlways("[PTFextender] mod index: %zu enabled mod(s), %zu pak(s), "
                                 "%zu file name(s) -- a part is eligible only if a MOD ships it",
                                 g_mods.Mods(), g_mods.Paks(), g_mods.Files());
    }
    return g_mods;
}

// One candidate patch: the file the enumeration returned, and the position that decides when it
// applies relative to the others.
struct Candidate {
    int         rank;
    std::string name;
    std::string modid;
    bool operator<(const Candidate& o) const { return rank < o.rank; }
};

// The suffix after the LAST `__`, which is the modid by convention.
//
// SPLIT FROM THE RIGHT, NEVER THE LEFT. Base files already contain `__` -- e.g.
// `konec_sluzby__komplet_vsechno.xml` -- so a part of one is
// `konec_sluzby__komplet_vsechno__<modid>.xml`, and a first-`__` split reads the modid as
// `komplet_vsechno__<modid>`, matches no enabled mod, and drops the part silently.
std::string SuffixOf(const std::string& fileName)
{
    std::string stem(fileName);
    const size_t slash = stem.find_last_of("/\\");
    if (slash != std::string::npos)
        stem = stem.substr(slash + 1);
    const size_t dot = stem.rfind('.');
    if (dot != std::string::npos)
        stem = stem.substr(0, dot);
    const size_t sep = stem.rfind("__");
    return (sep == std::string::npos) ? std::string() : stem.substr(sep + 2);
}

// Merge every <stem>__<modid><ext> patch the pak FS has for basePath into the
// tree at *ppBaseRoot. The base tree is a read-only pooled one, so patches land
// in a mutable deep clone and *ppBaseRoot is swapped to it (old ref released).
// Returns the number of patch files applied.
int ApplyPtfPatches(const char* basePath, IXmlNode** ppBaseRoot)
{
    if (!basePath || !ppBaseRoot || !*ppBaseRoot)
        return 0;

    // The descriptor for this file, or nullptr -- in which case every rule below behaves exactly as
    // the shipped plugin did. Adding a family cannot change how an undescribed file merges.
    const ptf::Family* fam = FamilyFor(basePath);

    auto* env = SSystemGlobalEnvironment::GetInstance();
    if (!env || !env->pCryPak || !env->pSystem)
        return 0;

    // "libs/config/foo.xml" -> "libs/config/foo__*.xml"
    //
    // AND AN EXTENSION-LESS BASE PATH GETS `__*` APPENDED. `rfind('.')` returning npos used to mean
    // "give up", which quietly excluded every file without a dot -- `levels\<lvl>\whdata_1` among
    // them, the registry that says which profile streams a layer. A file cannot be unpatchable
    // because of how it is spelled.
    std::string wildcard(basePath);
    const size_t dot = wildcard.rfind('.');
    if (dot == std::string::npos)
        wildcard += "__*";
    else
        wildcard.insert(dot, "__*");

    // find records carry bare file names; keep the directory for reloading
    const size_t slash = wildcard.find_last_of("/\\");
    const std::string dir =
        (slash == std::string::npos) ? std::string() : wildcard.substr(0, slash + 1);

    // ---- COLLECT FIRST, then decide. Two rules cannot be applied while enumerating: eligibility
    // needs the mod index, and ORDER needs every candidate in hand.
    Offsets::SCryPakFindData fd{};
    const intptr_t h = env->pCryPak->FindFirst(wildcard.c_str(), &fd);
    if (h == -1)
        return 0;

    const ptf::ModIndex& mods = Mods();
    std::vector<Candidate> queue;
    int rejectedBase = 0, rejectedUnlisted = 0;
    do {
        const std::string name(fd.name);
        // ELIGIBILITY IS PROVENANCE **AND** NAME.
        //   provenance: the file must come from a mod pak. The base game ships 5,902 files carrying
        //     a `__<suffix>` in the directories mods patch, so a name-only rule merges Warhorse's
        //     own build fixtures the moment a player installs a mod called `muz` or `autotests`.
        //   name: the suffix must be an ENABLED mod, so a disabled mod's leftovers stay inert.
        const char* owner = mods.Owner(name);
        if (!owner) {
            ++rejectedBase;
            continue;
        }
        const std::string suffix = SuffixOf(name);
        const int rank = suffix.empty() ? -1 : mods.Rank(suffix);
        if (rank < 0) {
            ++rejectedUnlisted;
            continue;
        }
        queue.push_back(Candidate{rank, name, suffix});
    } while (env->pCryPak->FindNext(h, &fd) >= 0);
    env->pCryPak->FindClose(h);

    if (queue.empty()) {
        if ((rejectedBase || rejectedUnlisted) && env->pLog)
            env->pLog->LogAlways("[PTFextender] '%s': no eligible patch (%d base-game, %d not in "
                                 "mod_order)", basePath, rejectedBase, rejectedUnlisted);
        return 0;
    }

    // ORDER IS mod_order.txt, NOT ENUMERATION ORDER. `FindFirst` returns names in whatever order the
    // pak filesystem holds them, so two mods touching one row would resolve differently on two
    // machines -- and differently from what the player's load order says. Stable sort, so two parts
    // from one mod keep their enumeration order relative to each other.
    std::stable_sort(queue.begin(), queue.end());

    IXmlNode* merged = nullptr;
    (*ppBaseRoot)->clone(&merged, false);
    if (!merged)
        return 0;

    int applied = 0;
    for (const Candidate& c : queue) {
        const std::string patchPath = dir + c.name;
        IXmlNode* patchRoot = nullptr;
        // same call shape as the three stock config loaders: (&out, path, 0, 1, 1)
        env->pSystem->LoadXmlFromFile(&patchRoot, patchPath.c_str(), 0, 1, 1);
        if (!patchRoot) {
            if (env->pLog)
                env->pLog->LogAlways("[PTFextender] Failed to load patch '%s'", patchPath.c_str());
            continue;
        }
        S_MergeStats stats;
        MergeChildren(merged, patchRoot, stats, fam);
        patchRoot->Release();
        ++applied;
        if (env->pLog)
            env->pLog->LogAlways("[PTFextender] '%s' is patched by '%s' (mod '%s', #%d of %zu), "
                                 "nodes added: %d, modified: %d",
                                 basePath, c.name.c_str(), c.modid.c_str(), c.rank + 1,
                                 mods.Mods(), stats.added, stats.modified);
    }
    if (rejectedBase && env->pLog)
        env->pLog->LogAlways("[PTFextender] '%s': %d base-game part(s) rejected -- not shipped by "
                             "any enabled mod", basePath, rejectedBase);

    if (applied > 0) {
        (*ppBaseRoot)->Release();
        *ppBaseRoot = merged;      // caller's XmlNodeRef now owns the merged tree
    } else {
        merged->Release();
    }
    return applied;
}

}  // namespace

// ------------------------------------------------ hook: defaultActionHelp ---

class {
public:
    static bool Install() {
        orig = REL::Relocation<>{ REL::ID(65542), 0x48 }.write_call<5>(ParseActionHelp);
        return orig.address();
    }

protected:
    static void ParseActionHelp(wh::playermodule::C_ActionSets* pThis, IXmlNode** ppXml) {
        if (ppXml && *ppXml)
            ApplyPtfPatches("libs/config/defaultActionHelp.xml", ppXml);
        orig(pThis, ppXml);
    }

    static inline REL::Relocation<decltype(&ParseActionHelp)> orig;
} hkParseActionHelp;

// ---------------------------------------------- hook: keybindSuperactions ---

class {
public:
    static bool Install() {
        orig = REL::Relocation<>{ REL::ID(33537), 0x73 }.write_call<5>(ParseKeybindsXml);
        return orig.address();
    }

protected:
    static void ParseKeybindsXml(wh::playermodule::C_Keybinds* pThis, IXmlNode** ppXml) {
        if (ppXml && *ppXml)
            ApplyPtfPatches("libs/config/keybindSuperactions.xml", ppXml);
        orig(pThis, ppXml);
    }

    static inline REL::Relocation<decltype(&ParseKeybindsXml)> orig;
} hkParseKeybindsXml;

// -------------------------------------------------- hook: defaultProfile ---

class {
public:
    static bool Install() {
        void* target = reinterpret_cast<void*>(REL::ID(55292).address());
        if (MH_CreateHook(target, reinterpret_cast<void*>(&LoadFromXML),
                          reinterpret_cast<void**>(&orig)) != MH_OK)
            return false;

        return MH_EnableHook(target) == MH_OK;
    }

protected:
    static char LoadFromXML(Offsets::IActionMapManager* pThis, IXmlNode** ppXml) {
        if (ppXml && *ppXml) {
            // InitActionMaps records its source file (SetLoadFromXMLPath) before
            // invoking this parser; the C_Game::LoadConfigXml path does not, so
            // an empty path means the stock profile file.
            const char* path = pThis->GetLoadFromXMLPath();
            if (!path || !*path)
                path = "libs/config/defaultProfile.xml";
            ApplyPtfPatches(path, ppXml);
        }
        return orig(pThis, ppXml);
    }

    static inline REL::Relocation<decltype(&LoadFromXML)> orig;
} hkLoadFromXML;

// ------------------------------------------------------ hook: LEVEL FILES ---
//
// ONE HOOK REACHES ALL OF THEM. Measured: 37,768 calls over 28,019 distinct paths in a single
// launch-load-quit, and every file family a level-content mod claims comes through
// `IXmlUtils::LoadXmlFromFile` -- leveldata, objects_mission0, waitinglinks and whdata_1 alike.
// So this is a hook plus a path lookup, and every future family is a descriptor rather than a
// reverse-engineering job.
//
// IXmlUtils SLOT [1], NOT ISystem [131]. The latter is a thin forwarder into the former, so hooking
// IXmlUtils catches both routes and no direct caller slips past. The target is read out of the live
// vtable via `gEnv->pSystem->GetXmlUtils()`, which is why this one installs on a KCSE message
// rather than at plugin load: the pointer does not exist yet when the DLL is loaded.
//
// `patching=1` on all 37,768 calls -- the stock XML patcher already runs inside this function, on
// every file. A merge placed here sits exactly where the engine already expects one.
namespace {

using LoadXmlFn = IXmlNode** (*)(Offsets::IXmlUtils*, IXmlNode**, const char*, bool, bool, bool,
                                 bool);
LoadXmlFn g_origLoadXml = nullptr;

// RE-ENTRANCY. ApplyPtfPatches loads each part through this very function, so without a guard the
// first patched file recurses until the stack ends. Thread-local because XML loading is not
// single-threaded here -- two loader threads were observed interleaving in the same session.
thread_local int t_inPatchLoad = 0;

struct PatchLoadGuard {
    PatchLoadGuard() { ++t_inPatchLoad; }
    ~PatchLoadGuard() { --t_inPatchLoad; }
};

IXmlNode** LoadXmlDetour(Offsets::IXmlUtils* pThis, IXmlNode** out, const char* sFilename,
                         bool bEnablePatching, bool b5, bool b6, bool b7)
{
    IXmlNode** r = g_origLoadXml(pThis, out, sFilename, bEnablePatching, b5, b6, b7);
    if (t_inPatchLoad || !out || !*out || !sFilename)
        return r;
    if (!FamilyFor(sFilename))
        return r;                    // not a described file: the engine's own result, untouched
    PatchLoadGuard guard;
    ApplyPtfPatches(sFilename, out);
    return r;
}

bool InstallLevelHook()
{
    auto* env = SSystemGlobalEnvironment::GetInstance();
    if (!env || !env->pSystem)
        return false;
    auto* utils = reinterpret_cast<Offsets::IXmlUtils*>(env->pSystem->GetXmlUtils());
    if (!utils)
        return false;
    void** vtbl = *reinterpret_cast<void***>(utils);
    void*  target = vtbl[1];
    if (MH_CreateHook(target, reinterpret_cast<void*>(&LoadXmlDetour),
                      reinterpret_cast<void**>(&g_origLoadXml)) != MH_OK)
        return false;
    if (MH_EnableHook(target) != MH_OK)
        return false;
    if (env->pLog)
        env->pLog->LogAlways("[PTFextender] level families armed on IXmlUtils::LoadXmlFromFile "
                             "at %p -- %zu family descriptor(s)", target, ptf::kFamilyCount);
    return true;
}

bool g_levelHookArmed = false;

void OnKcseMessage(KCSE::Message* msg)
{
    if (g_levelHookArmed || !msg)
        return;
    // PreDataLoaded is the earliest point gEnv->pSystem is usable; DataLoaded is the fallback.
    if (msg->type == KCSE::IMessagingInterface::kMessage_PreDataLoaded ||
        msg->type == KCSE::IMessagingInterface::kMessage_DataLoaded)
        g_levelHookArmed = InstallLevelHook();
}

}  // namespace

// ---------------------------------------------------------------- install ---

static bool InstallHooks()
{
    if (MH_Initialize() != MH_OK)
        return false;

    return hkParseActionHelp.Install()
        && hkParseKeybindsXml.Install()
        && hkLoadFromXML.Install();
}

// -------------------------------------------------------------- KCSE glue ---

KCSE_PLUGIN_INFO("PTF Extender", "JerryYOJ", 1);

KCSE_PLUGIN_LOAD(kcse)
{
    KCSE::AllocTrampoline(1 << 10);

    if (!InstallHooks())
        return false;
    // The level hook needs gEnv->pSystem, which does not exist yet -- arm it on the first message.
    auto* msg = kcse->GetMessagingInterface();
    return msg && msg->RegisterListener(&OnKcseMessage);
}
