// ModIndex -- which MOD, if any, ships a given file.
//
// WHY A PART'S NAME IS NOT ENOUGH TO TRUST IT.
//
// `ApplyPtfPatches` merges every `<stem>__*<ext>` the pak filesystem returns. The pak filesystem is
// the BASE GAME plus every mod, flattened, and the base game ships a great many files that already
// carry a `__<suffix>`: build-time table parts, per-quest dialogue variants, per-role barks.
// Counted from a retail 1.5.6 install, restricted to the directories a content mod patches:
//
//     5,902 files carrying a __<suffix>, across 3,245 distinct suffixes
//     muz 411 files   zena 371   kuman 200   bandita 96   straz 68   autotests 20
//
// Warhorse publish these as RESERVED MODIDS for exactly this reason. But "reject a list of names"
// is the wrong shape of fix: the list goes stale at every game patch, it cannot be derived by a
// plugin at runtime, and it answers a question about NAMES when the real question is about ORIGIN.
// A player who installs a mod called `muz` should not thereby merge 411 of Warhorse's own fixtures
// into their tables.
//
// PROVENANCE ANSWERS IT EXACTLY: a part is eligible when the file came from a MOD pak. That needs
// no list, cannot go stale, and is what a reserved-name list is a proxy for.
//
// WHY THIS CLASS EXISTS RATHER THAN A FLAG ON THE FIND RECORD. Measured in game, 2026-09-05:
// `ICryPak::FindFirst` fills `attrib / times / size / name` and no pak field, and `attrib` is
// `0x80000001` (in-pak | readonly) for all 184 hits tested across the base game and three separate
// mods. The enumeration separates pak from loose and nothing finer, so the plugin has to build the
// map itself.
//
// HOW: read `Mods\mod_order.txt`, then walk each ENABLED mod's own `.pak` files and record which
// names each one contains. A pak is a zip; only its central directory is read, which is a few
// hundred KB even for a large mod and needs no external library.
//
// COST, measured on an 89-mod install: 1.4 GB of mod paks, of which the central directories are a
// small fraction, read once at startup.

#pragma once

#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>

namespace ptf {

class ModIndex {
public:
    // `gameRoot` is the install directory -- the parent of `Mods\`. Safe to call twice; the second
    // call rebuilds. Returns false only when `Mods\mod_order.txt` cannot be read, which means no
    // mod is enabled and no part can be eligible.
    bool Build(const std::string& gameRoot);

    // Load order position of a modid, or -1 when it is not enabled. Comparison is case-insensitive
    // because mod_order.txt is hand-edited as often as it is generated.
    int Rank(const std::string& modid) const;

    // The modid that ships `fileName` (a BARE name, as the find record carries), or nullptr when no
    // enabled mod does -- which for a file the pak filesystem just returned means the BASE GAME.
    //
    // Last enabled mod wins, matching the load order: if two mods ship the same name, the one the
    // engine actually reads is the later one, and that is the one whose provenance applies.
    const char* Owner(const std::string& fileName) const;

    std::size_t Mods() const { return m_order.size(); }
    std::size_t Files() const { return m_owner.size(); }
    std::size_t Paks() const { return m_paks; }

    // The whole map, so an independent implementation can be diffed against it. `kcdlib\vfs.py`
    // builds the same relation in Python; two implementations agreeing on ~1,900 names is a far
    // stronger claim than either one passing its own spot checks.
    const std::unordered_map<std::string, std::string>& Dump() const { return m_owner; }

private:
    void IndexPak(const std::string& pakPath, const std::string& modid);

    std::vector<std::string>                     m_order;   // as listed, original spelling
    std::unordered_map<std::string, int>         m_rank;    // lowercased modid -> position
    std::unordered_map<std::string, std::string> m_owner;   // lowercased bare name -> modid
    std::size_t                                  m_paks = 0;
};

}  // namespace ptf
