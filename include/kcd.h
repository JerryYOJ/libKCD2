#pragma once
// libKCD2 umbrella (mirrors libKCD1's analysis/gen_kcd.py output).
// Force-included via the PCH so every RE'd header sees the real SDK types AND the rest of
// the RE surface, exactly like libKCD1. Order: std -> CryEngine SDK types -> Offsets ->
// RE'd vtable bases -> concrete classes.

// ---- std ----
#include <cstdint>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <cstddef>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <functional>
#include <string>

// ---- CryEngine SDK types (stock; the real Vec3/Quat/Matrix34/CryStringT/DynArray) ----
#include "CryEngine/CryCommon/BaseTypes.h"
#include "CryEngine/CryCommon/CryString.h"   // CryStringT<char>
#include "CryEngine/CryCommon/Cry_Math.h"    // Vec3 / Vec2 / Quat / QuatT / Matrix34 (self-includes platform.h)
#include "CryEngine/CryCommon/CryArray.h"    // DynArray

// ---- RE'd vtable bases (KCD2 binary slot orders) ----
#include "Offsets/vtables/IScriptTable.h"
#include "Offsets/vtables/IScriptSystem.h"
#include "Offsets/vtables/IConsole.h"
#include "Offsets/vtables/ISystem.h"
#include "Offsets/vtables/IEntity.h"
#include "Offsets/vtables/IGameFramework.h"
#include "Offsets/vtables/IActor.h"
#include "Offsets/vtables/IGame.h"
#include "Offsets/vtables/IGameStartup.h"

// ---- RE'd concrete classes (real members; use SDK/std types) ----
#include "CryEngine/CryCommon/CScriptTable.h"
#include "CryEngine/CryCommon/CScriptSystem.h"
#include "CryEngine/CryCommon/CXConsole.h"
#include "CryEngine/CryCommon/CSystem.h"
#include "CryEngine/CryCommon/CEntity.h"
#include "CryEngine/CryCommon/CEntitySystem.h"
#include "CryEngine/CryCommon/CCryAction.h"
#include "entitymodule/C_Actor.h"
#include "game/C_Game.h"
#include "game/C_GameStartup.h"

// ---- Round 1: classes to recreate the 3 easiest plugins (ConsoleRpgParam / AutoSave / LetterboxRemoverNG) ----
#include "crysystem/SSystemGlobalEnvironment.h"   // gEnv
#include "crysystem/SCameraParams.h"
#include "crysystem/CMovieSystem.h"
#include "rpgmodule/S_RpgParams.h"
#include "game/S_GameContext.h"
#include "playermodule/C_PlayerModule.h"
#include "combatmodule/C_CombatActor.h"
