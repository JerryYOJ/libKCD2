# `libKCD2`

Reverse-engineered headers and runtime library for **Kingdom Come: Deliverance 2**
(Warhorse-evolved CryEngine 3 fork). Sibling to [`libKCD1`](../../KCD1/RE), sharing the
same SKSE-style architecture: a `REL::ID` abstract-address library, a KASL address
database, `kcd_cast` RTTI, and the KCSE `dinput8.dll` proxy loader.

> Status: **foundation stage.** The KCD2 engine is a re-target of libKCD1, not a rewrite
> (~75% of RE'd class names survive by exact `Class@module` match), but every concrete
> offset / vtable slot / size must be re-measured against the KCD2 binary. See
> [../MIGRATION_ASSESSMENT.md](../MIGRATION_ASSESSMENT.md) for the full plan.

## Target build

| | |
|---|---|
| Game version | **1.5.6** (branch `release_1_5`, assembly `15693`) |
| `WHGame.dll` md5 | `170a55fe1ef804b4a9ac6fbf9f6843e5` |
| Image base | `0x180000000`, ~95 MB, 360,206 functions |
| Binary dir | `Bin\Win64MasterMasterSteamPGO` (Steam) — exe + WHGame.dll |
| Renderer | DX12 (+ D3D11 fallback), DLSS / FSR2 |
| Anti-tamper | none on the DLL (imports: ntdll, BugSplat64, WS2_32) |

## What is ported so far

- **`REL/` runtime** — `ID`, `Offset`, `Relocation`, `IDDatabase` (KASL loader),
  `BranchTrampoline` copied verbatim from libKCD1 (version-agnostic).
- **`REL::Module`** — adapted for KCD2: `build_code()` reads `whdlversions.json`
  (`<Branch.Name>-<Assembly.Id>`, e.g. `release_1_5-15693`) instead of the KCD1
  `whdlversions.txt`; `release()` still reads `system.cfg` `wh_sys_version`;
  `resolve_game_root()` and `detect_distribution()` are unchanged (strip-depth 3 still
  lands on the game root; Steam/GOG/Epic markers still present).
- **`Offsets/RTTI.h`** — `kcd_cast` (version-independent) copied verbatim.
- **`KCSE/Trampoline.h`** — copied verbatim.

## Not yet regenerated (blocking, see MIGRATION_ASSESSMENT.md)

- KCD2 KASL address library (`kcd_addresslib_steam_release_1_5-15693.bin`) + ID registry
  — **brand-new ID namespace; do not reuse KCD1 IDs**.
- `Offsets_RTTI.h` / `Offsets_VTABLE.h` and all `Offsets/vtables/*.h` (interfuscator
  reshuffles vtable order — every slot re-verified).
- Warhorse module headers (`rpgmodule`, `entitymodule`, `combatmodule`, plus new
  `conceptmodule`, `xbehaviormodule`, `musicmodule`) — layouts re-measured per class.
- `CrySDKStubs.cpp` (needs `Offsets.h` + the malloc/free thunk IDs) — re-enabled in the
  build once the address library lands.
