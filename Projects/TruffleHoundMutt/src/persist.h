#pragma once

// TruffleHoundMutt's own config persistence -- self-contained and deliberately MCM-ONLY:
// HandleMcmMessage (mcm.h) calls PersistSetting for every menu edit; console edits of the
// kcse_trufflehoundmutt_* cvars apply for the session but are NOT recorded.
//
// Write side (ours): PersistSetting rewrites Mods/TruffleHoundMutt/mod.cfg.
// Read side (the engine's): WHGame evals Mods/<mod>/mod.cfg at startup (same path as
// user.cfg), and the console HOLDS values for not-yet-registered cvars, applying them
// when RegisterCVar* runs at DataLoaded -- the round trip needs no load code at all.

namespace TruffleHoundMutt {

// Seed the entry map from last session's mod.cfg so a rewrite never forgets settings that
// weren't re-edited this session.  Call once at plugin load.
void LoadPersistedEdits();

// Record one MCM edit (cvar line in mod.cfg) and rewrite the file.  No-ops when the value
// matches what is already persisted.
void PersistSetting(const char* cvarName, double value, bool isFloat);

}  // namespace TruffleHoundMutt
