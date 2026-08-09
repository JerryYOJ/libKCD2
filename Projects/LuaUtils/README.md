# LuaUtils

KCSE plugin for KCD2 that extends the vanilla `ItemManager` and `Minigame` Lua tables and publishes new `EquipmentManager` and `AudioManager` globals.

All functions use **dot-call syntax**:

```lua
ItemManager.GetItemEx(itemId)
EquipmentManager.GetEquippedClothing(entityId)
```

Do not call these functions with `:`. Item, inventory, and owner IDs are passed as Lua `ScriptHandle` values so the full 64-bit Warhorse WUID is preserved.

## ItemManager additions

### Queries

| Function | Returns |
| --- | --- |
| `ItemManager.GetItemEx(itemId)` | `{ id, className, type, amount, health, condition, quality, maxQuality, isEquipped, owner, entity }` |
| `ItemManager.IsItemEquipped(itemId)` | `bool` — per-instance equipped flag (`C_Item` flags bit 0) |
| `ItemManager.GetItemCondition(itemId)` | `float 0..1` — effective durability; runtime-data aware for equippables |
| `ItemManager.GetItemQuality(itemId)` | Current integer quality |
| `ItemManager.GetItemMaxQuality(itemId)` | Maximum integer quality |
| `ItemManager.GetItemPrices(itemId)` | `{ unit, stack, newUnit, newStack }`; current and new-condition unit/stack prices |

### Mutators

Mutators return `true` on success and `nil` if resolution or the native operation fails, except `MoveItem`, which returns the surviving item WUID.

| Function | Notes |
| --- | --- |
| `ItemManager.SetItemHealth(itemId, health)` | Native `SetItemHealth`, clamped to `0..1`, with the engine notify path |
| `ItemManager.SetItemCondition(itemId, condition)` | For equippables, maps normalized condition into the current quality tier's raw-health range; for other item types, writes health directly |
| `ItemManager.SetItemQuality(itemId, quality)` | Equippable-type items only |
| `ItemManager.SetItemAmount(itemId, amount)` | Listener-correct amount change; `amount <= 0` deletes a parented stack |
| `ItemManager.SetItemOwner(itemId, ownerId[, stolenFromOwnerId])` | Native owner write and owner-index update; omitted theft-source ID defaults to `ownerId` |
| `ItemManager.WashItem(itemId[, maxEffect])` | Per-item dirt operation; omitted effect performs a full wash |
| `ItemManager.SetItemPhaseId(itemId, phaseId)` | Set the discrete food/torch phase |
| `ItemManager.SetItemPhase(itemId, phase)` | Set normalized phase progress |
| `ItemManager.AdvanceItemPhase(itemId, amount)` | Advance normalized phase progress |
| `ItemManager.MoveItem(itemId, destinationInventoryId[, count])` | Split/merge-aware native move; `count` absent or `0` means the whole stack |

`ownerId` and `stolenFromOwnerId` are WUIDs, not CryEngine entity IDs. Theft state is not reducible to a permanent `ownerId != stolenFromOwnerId` test: the native system also records when the owner mark was set and can age or fade that mark.

## Minigame additions

`userId` here (and throughout the vanilla `Minigame`/per-type scriptbind API) is a CryEngine entity ID, not a multiplayer account — KCD2 resolves it via `IActorSystem::GetActor`. In practice it's always the player's `entity.id`.

| Function | Returns / behavior |
| --- | --- |
| `Minigame.RequestExit(userId)` | Finds the user's live minigame session (any type) and fires the same native exit path the "minigame_exit" key (Esc on keyboard, B/Circle on pad) drives. Not an immediate hard stop: cancels the in-flight action and transitions the session toward exit, deferring briefly if the current action can't be interrupted yet. Returns `true` if a live session was found, `nil` otherwise. |

## EquipmentManager

This is a new global table keyed by CryEngine entity ID.

| Function | Returns / behavior |
| --- | --- |
| `EquipmentManager.GetEquippedItems(entityId)` | Dense array of materialized equipped item WUIDs |
| `EquipmentManager.GetEquippedClothing(entityId)` | `{ [equipmentSlotId] = itemId }` for data-driven clothing slots |
| `EquipmentManager.GetHandSlots(entityId)` | Sparse `{ [1..8] = itemId }` using the fixed native weapon-equip mapping below; empty entries are absent |
| `EquipmentManager.GetItemInSlot(entityId, slotId)` | Item WUID in a data-driven clothing slot, or `nil`; does not query weapon or QAM slots |
| `EquipmentManager.GetEquipWeights(entityId)` | `{ total, worn }` |
| `EquipmentManager.GetInventoryEx(entityId)` | Dense array of `GetItemEx`-shaped item tables |
| `EquipmentManager.GetInventoryId(entityId)` | Inventory WUID usable with `MoveItem` |
| `EquipmentManager.SetItemEquipped(entityId, itemId, equip)` | Equip/unequip through the entity's inventory soul, preserving native visuals and bookkeeping |
| `EquipmentManager.GetWeaponQuickSlots(entityId[, outfitId])` | Four weapon-pair records: `{ outfitId, [1..4] = { usable, main?, off? } }` |
| `EquipmentManager.SetWeaponQuickSlot(entityId, quickSlot, itemId[, outfitId])` | Assign to pair `1..4`; returns the actual flattened main/off slot `1..8` selected by the native item classification |
| `EquipmentManager.ClearWeaponQuickSlot(entityId, quickSlot, offHand[, outfitId])` | Clear the main (`false`) or off (`true`) side of weapon pair `1..4` |
| `EquipmentManager.GetConsumableQuickSlots(entityId[, outfitId])` | Four records: `{ outfitId, [1..4] = { usable, item? } }` |
| `EquipmentManager.SetConsumableQuickSlot(entityId, slotId, itemId[, outfitId])` | Assign a consumable to slot `1..4`; returns `nil` when that pouch-controlled slot is not usable |
| `EquipmentManager.ClearConsumableQuickSlot(entityId, slotId[, outfitId])` | Clear consumable slot `1..4` |

For every QAM function, omitted `outfitId` selects the actor's current outfit. Explicit native outfit IDs are `0 = A`, `1 = B`, and `2 = C`.

### `GetHandSlots` mapping

Despite its compatibility name, `GetHandSlots` exposes the complete fixed `E_WeaponEquipSlot` array, not only literal hands:

| Lua key | Native value | `E_WeaponEquipSlot` |
| ---: | ---: | --- |
| `1` | `0` | `PrimaryMainHand` |
| `2` | `1` | `PrimaryOffHand` |
| `3` | `2` | `SecondaryMainHand` |
| `4` | `3` | `SecondaryOffHand` |
| `5` | `4` | `Oversized` |
| `6` | `5` | `OversizedOff` |
| `7` | `6` | `Torch` |
| `8` | `7` | `Dagger` |

## Clothing slots, weapon slots, and QAM are separate

KCD2 has three independent slot systems:

1. **Clothing `EquipmentSlotId`** — a data-driven 32-bit database ID. `GetEquippedClothing` and `GetItemInSlot` use this system.
2. **`E_WeaponEquipSlot`** — the fixed eight-entry native array exposed by `GetHandSlots`.
3. **Player QAM assignments** — outfit-specific quick-access assignments held by the player inventory soul. They are not entries in either table above.

The fixed four-byte `S_EquipmentSlotIdWrapper` does not make clothing slots a compiled enum. Only the wrapper ABI is fixed; valid IDs and names come from the `equipment_slot` database.

### Belt and pouch

| Identifier domain | Belt | Pouch |
| --- | ---: | ---: |
| Clothing `EquipmentSlotId` | `44` | `45` |
| `ArmorType` | `76` | `77` |
| `ArmorArchetypeId` used by QAM capacity logic | `103` | `104` |

The equipped container items can therefore be queried as clothing:

```lua
local beltItem = EquipmentManager.GetItemInSlot(entityId, 44)
local pouchItem = EquipmentManager.GetItemInSlot(entityId, 45)
```

Those calls return the **belt or pouch item**, not the weapon, potion, food, or consumable assigned to quick access.

- An equipped belt controls the usable weapon-QAM pair count. The native no-belt baseline is one weapon pair.
- An equipped pouch controls the usable food/consumable-QAM slot count. The native no-pouch baseline is zero food slots.
- QAM assignments are stored separately for outfits A, B, and C in player-specific outfit managers.

Weapon QAM consists of four pairs. Each pair stores a main and off item, but assignment targets the pair rather than forcing a side: the native manager classifies the item and chooses main or off. `SetWeaponQuickSlot` therefore returns the actual flattened side (`1=Main_1`, `2=Off_1`, ..., `8=Off_4`).

Consumable QAM has four independent slots and uses each pair record's main item. Belt and pouch capacity is enforced before mutation, so records can exist while reporting `usable = false`. `GetHandSlots` remains a separate physical weapon-equip query and is not a QAM alias.

## Examples

```lua
-- Which of the bandit's duplicate mailles is actually equipped?
local bandit = System.GetEntityByName("bandit_01")
for _, item in ipairs(EquipmentManager.GetInventoryEx(bandit.id) or {}) do
    if item.className == "maille_long" then
        System.LogAlways(tostring(item.id) .. " equipped=" .. tostring(item.isEquipped))
    end
end

-- Which clothing item occupies each merchant equipment slot?
local merchant = System.GetEntityByName("merchant_01")
local worn = EquipmentManager.GetEquippedClothing(merchant.id)

-- Query the player's equipped belt and pouch container items.
local belt = EquipmentManager.GetItemInSlot(player.id, 44)
local pouch = EquipmentManager.GetItemInSlot(player.id, 45)

-- Read current-outfit QAM, then explicitly read outfit B.
local currentWeapons = EquipmentManager.GetWeaponQuickSlots(player.id)
local outfitBConsumables = EquipmentManager.GetConsumableQuickSlots(player.id, 1)

-- Repair and clean the player's current main-hand item.
local itemId = player.human:GetItemInHand(0)
ItemManager.SetItemHealth(itemId, 1.0)
ItemManager.WashItem(itemId)

-- Kick the player out of whatever minigame they're currently in.
Minigame.RequestExit(player.id)
```

## Resolution caveats

- Distant or unstreamed NPCs may not yet have their worn items materialized as `C_Item` instances. Queries can therefore return less than the NPC conceptually owns; interact with or approach the NPC first.
- Some souls have no inventory or equipment manager. All query functions are nil-graceful instead of raising Lua errors.
- Direct stat writes use the engine's notify paths, but some UI screens refresh only after being reopened.
- `SetItemQuality` returns `nil` for non-equippable item types.

## AudioManager

`AudioManager` is a new direct-audio global. It complements the vanilla `Sound` table rather than replacing CryEngine ATL triggers or entity audio proxies.

All custom audio assets are loaded through **CryPak virtual paths**. The API does not accept absolute disk paths and does not use the Windows filesystem directly. Put assets in a mounted mod PAK under a unique path such as:

```text
Libs/Audio/MyMod/my_events.bank
Libs/Audio/MyMod/hit.ogg
```

Do not put direct-loaded banks under `Sounds/fmod/Build/PC/`; Warhorse's startup bank enumerator also scans that directory for native ATL/FSW registration.

### Return convention

Audio handles are opaque generation-checked `ScriptHandle` values. Never convert them to Lua numbers.

- Success returns one value. Mutators return `true`.
- Failure returns `nil, errorString`.
- `IsReady` always returns a Boolean.
- `GetStatus` always returns a table.
- Event handles automatically become stale after the event reaches `stopped` and the frame tick releases it.
- Core sound-instance handles become stale after explicit stop or natural completion.

```lua
local sound, err = AudioManager.LoadSound("Libs/Audio/MyMod/hit.ogg")
if not sound then
    System.LogAlways(err)
    return
end
```

### System and resources

| Function | Returns / behavior |
| --- | --- |
| `AudioManager.IsReady()` | Whether the game-owned FMOD Studio/Core systems are available and version-compatible |
| `AudioManager.GetStatus()` | Readiness, wrapper state/result, runtime version, backend epoch, resource counts, and latest asynchronous error |
| `AudioManager.GetLoadedBanks()` | Dense array of loaded-bank info tables |
| `AudioManager.GetLoadedSounds()` | Dense array of loaded loose-sound info tables |
| `AudioManager.LoadBank(path[, options])` | Load an FMOD Studio bank from CryPak memory; `{ sampleData = true }` optionally requests sample data |
| `AudioManager.UnloadBank(bankHandle[, force])` | Drop one logical reference; final normal unload refuses active events, while force stops owned events first |
| `AudioManager.LoadBankSampleData(bankHandle)` | Request bank sample data |
| `AudioManager.UnloadBankSampleData(bankHandle)` | Release bank sample data |
| `AudioManager.GetBankInfo(bankHandle)` | Path, references, active instances, event count, and sample loading state |
| `AudioManager.GetBankEvents(bankHandle)` | Dense array of raw `event:/...` paths contained in the bank |
| `AudioManager.LoadSound(path)` | Load and synchronously decode a CryPak-visible `.wav` or `.ogg`; compressed input is capped at 256 MiB |
| `AudioManager.UnloadSound(soundHandle[, force])` | Drop one logical reference; final normal unload refuses active channels |
| `AudioManager.GetSoundInfo(soundHandle)` | Path, references, active channels, duration, codec/container, channels, and bit depth |

Loading the same normalized CryPak path repeatedly returns the same handle and increments its logical reference count. Match those loads with normal unload calls, or use `force=true` to discard all references and owned instances.

### Studio events

| Function | Returns / behavior |
| --- | --- |
| `AudioManager.GetEventInfo(eventPath)` | Authored 2D/3D, oneshot, snapshot, stream, length, and distance metadata |
| `AudioManager.PlayEvent(eventPath[, options])` | Start a raw Studio event and return an event-instance handle |
| `AudioManager.StopEvent(eventHandle[, immediate])` | Request fadeout or immediate stop; handle remains valid while FMOD reports `stopping` |
| `AudioManager.SetEventPaused(eventHandle, paused)` | Pause/unpause |
| `AudioManager.SetEventParameter(eventHandle, name, value[, ignoreSeekSpeed])` | Set a named authored parameter |
| `AudioManager.SetEventVolume(eventHandle, volume)` | Set nonnegative instance volume |
| `AudioManager.SetEventPitch(eventHandle, pitch)` | Set positive instance pitch |
| `AudioManager.SetEventPosition(eventHandle, position[, velocity])` | Move a static 3D event; attached events must be detached first |
| `AudioManager.AttachEventToEntity(eventHandle, entityId[, offset])` | Follow an entity using its world transform |
| `AudioManager.DetachEvent(eventHandle)` | Freeze the last transform and zero velocity |
| `AudioManager.GetEventState(eventHandle)` | Playback state, pause, attachment, volume, and pitch |

`PlayEvent` options:

```lua
{
    position = { x = 1, y = 2, z = 3 },
    velocity = { x = 0, y = 0, z = 0 },

    -- Use entityId instead of position for attachment.
    entityId = entity.id,
    offset = { x = 0, y = 0, z = 1 },

    -- Optional static-position orientation; supply both together.
    forward = { x = 0, y = 1, z = 0 },
    up = { x = 0, y = 0, z = 1 },

    volume = 1.0,
    pitch = 1.0,
    paused = false,
    parameters = { ParameterName = 0.5 },
    ignoreSeekSpeed = false
}
```

Authored 3D events require `position` or `entityId`. Authored 2D events reject spatial fields. `position` and `entityId` are mutually exclusive.

### Loose WAV/OGG playback

| Function | Returns / behavior |
| --- | --- |
| `AudioManager.PlaySound(soundHandle[, options])` | Play a loaded sound through a KCD2 Studio bus and return a channel-instance handle |
| `AudioManager.StopSound(instanceHandle)` | Stop and invalidate the channel handle |
| `AudioManager.SetSoundPaused(instanceHandle, paused)` | Pause/unpause |
| `AudioManager.SetSoundVolume(instanceHandle, volume)` | Set nonnegative channel volume |
| `AudioManager.SetSoundPitch(instanceHandle, pitch)` | Set positive channel pitch |
| `AudioManager.SetSoundLooping(instanceHandle, loop)` | Switch loop-off/loop-normal for that channel only |
| `AudioManager.SetSoundPosition(instanceHandle, position[, velocity])` | Move a static 3D channel |
| `AudioManager.AttachSoundToEntity(instanceHandle, entityId[, offset])` | Follow an entity |
| `AudioManager.DetachSound(instanceHandle)` | Freeze the last position and zero velocity |
| `AudioManager.GetSoundState(instanceHandle)` | Bus, playback/pause/loop state, attachment, volume, pitch, and distance range |

`PlaySound` options:

```lua
{
    bus = "bus:/dieg/w_obj",
    loop = false,
    paused = false,
    volume = 1.0,
    pitch = 1.0,

    position = { x = 1, y = 2, z = 3 },
    velocity = { x = 0, y = 0, z = 0 },

    -- Use entityId instead of position for attachment.
    entityId = entity.id,
    offset = { x = 0, y = 0, z = 1 },

    minDistance = 1.0,
    maxDistance = 100.0
}
```

No spatial fields means 2D playback. `position` or `entityId` selects 3D playback. One loaded sound resource can back multiple simultaneous channels with independent loop, volume, pitch, bus, and position settings.

### Audio examples

```lua
-- Play a CryPak OGG as a UI/non-spatial effect.
local sound, err = AudioManager.LoadSound("Libs/Audio/MyMod/notify.ogg")
if sound then
    local channel
    channel, err = AudioManager.PlaySound(sound, {
        bus = "bus:/dieg/w_obj",
        volume = 0.7
    })
end

-- Attach the same resource to an entity as a looping 3D sound.
local attached, attachErr = AudioManager.PlaySound(sound, {
    entityId = player.id,
    offset = { x = 0, y = 0, z = 1.5 },
    loop = true,
    minDistance = 1,
    maxDistance = 30
})

-- Inspect and play a raw authored event.
local eventInfo, eventErr = AudioManager.GetEventInfo(
    "event:/animals/raven/raven_whistling")
local event, playErr = AudioManager.PlayEvent(
    "event:/animals/raven/raven_whistling",
    { entityId = player.id, volume = 0.25 })
```

### Audio limitations

- The plugin reuses KCD2's existing FMOD 2.2.21 systems; it does not create or ship another FMOD runtime.
- Direct-loaded banks bypass Warhorse's `FSW_BANK`/`FSW_EVENT_DESCRIPTION` registry. Their events are available through raw `AudioManager` paths, not automatically through vanilla ATL triggers, entity audio proxies, SKALD, or FlowGraph.
- Compatible event banks must target FMOD Studio 2.2.21 and normally require a KCD-derived authoring project. Banks from unrelated FMOD projects may reference incompatible mixer/bus GUIDs.
- Loose effects are fully buffered and decoded; use a Studio bank for large or streaming content.
- `AudioManager` performs no obstruction, occlusion, environment, or ATL-proxy processing for direct instances.
- The implementation is release-build verified. Live in-game CryPak bank/effect playback remains to be tested with a mounted test PAK and a compatible event-bearing bank.

## RTTR bridge

LuaUtils exposes KCD2's reflected (rttr) surface — the same registry used by SKALD — through generated source-facing wrappers under the public `wh` namespace. Everything below targets KCD2 Steam 1.5.6; the coverage ground truth is `KCD2/analysis/rttr/rttr_lua_manifest.json` and its report.

### Native bootstrap API (exactly seven functions, dot-call)

LuaUtils publishes an uppercase `RTTR` table during KCSE `PreDataLoaded`, before KCD2 executes the mod's PAK-owned Lua bootstrap:

| Function | Behavior |
| --- | --- |
| `RTTR.CallGlobal(name, ...)` | Invoke a reflected global function by its exact registered name (`"wh::rpgmodule::GetGameMode"`). |
| `RTTR.CallMethod(handle, declaringType, name, ...)` | Invoke a reflected member on a live object token. `declaringType` is the registered source type (`"wh::entitymodule::Inventory"`). |
| `RTTR.GetProperty(handle, declaringType, name)` | Read a reflected read-only property. |
| `RTTR.GetEnum(enumType, valueName)` | Look up a reflected enum value (`"E_GameMode"`, `"hardcore"`) and return a typed token. |
| `RTTR.GetTypeName(handle)` | Return the exact reflected type name of a live token. |
| `RTTR.Release(handle)` | Destroy one stored value; the token becomes permanently stale. |
| `RTTR.Clear()` | Destroy every stored value (also happens automatically on LoadGame/NewGame). |

Every generated chunk captures this table in a local upvalue. `generated/all.lua` verifies the complete public tree, while the uppercase `RTTR` bridge remains visible. Normal mod scripts should use `wh`; direct `RTTR` calls remain available for low-level diagnostics and native validation.

All native failures return `nil, errorString`; a successful reflected `void` call returns `true`. Object, pointer, smart-pointer, reference-wrapper, and enum results are retained as plugin-owned `rttr::variant`s behind monotonic `ScriptHandle` tokens. Releasing or clearing a token permanently invalidates it. Lua's source-facing wrapper does not change the stored variant: for example, an exact `std::shared_ptr<wh::entitymodule::I_ItemDescriptor>` remains that exact native type while Lua sees `wh.entitymodule.ItemDescriptor`.

Arguments convert against the **exact** reflected parameter type: booleans, 8/16/32-bit integers (range-checked), floats, `std::string` from Lua strings, `ScriptHandle` payloads for 64-bit arithmetic parameters, registry tokens for enum/class/pointer parameters, and reflected defaults for omitted trailing arguments. Releasing the source Lua wrapper does not change an already-cloned native argument variant. Containers, `wchar_t`, raw `const char*`, property writes, constructors, and SKALD node/TLS-dependent callables remain blocked with specific errors. SKALD-native functions such as `Inventory::GetMoney` are not RTTR methods and are intentionally absent from this layer.

### Public generated wrappers

The Python generators and their fixture tests are dev-time tooling, not shipped project sources: they live under `KCD2/analysis/luautils/tools/` and `KCD2/analysis/luautils/tests/`, outside this project directory. Only their output (`lua/`) and the native plugin (`src/`) ship with LuaUtils.

`KCD2/analysis/luautils/tools/generate_rttr_lua.py` renders the certified manifest into `lua/rttr/`; `--check` verifies byte-for-byte freshness. The current tree contains 1,940 source-like class modules, 226 enum modules, and 24 global namespaces. Base classes and namespace-owning parent classes load before derived and nested types. Native transport records (`std`, `boost`, `rttr`, raw pointers, `_smart_ptr`, and reference wrappers) do not receive a public class tree.

```lua
-- typed enum values
local hardcore = wh.game.E_GameMode.hardcore()

-- reflected globals return source-class wrappers
local timeOfDay = wh.rpgmodule.GetTimeOfDay()  -- wh.framework.TimeOfDay

-- class wrappers use registered source names
local Inventory = wh.entitymodule.Inventory
local ItemDescriptor = wh.entitymodule.ItemDescriptor

local mode, err = wh.rpgmodule.GetGameMode()
if mode then mode:Release() end
```

Class modules carry LuaLS annotations (`---@class wh.entitymodule.Inventory : wh.entitymodule.C_ItemHolder`), retain the exact C++ identity and registered declaring type privately, unwrap wrapper arguments before native calls, wrap object results through the projected source type, inherit through metatables, and invalidate themselves after `:Release()`. Every represented source-like class receives a full module, including memberless classes. Objects enter this V1 wrapper layer only through reflected returns; it does not add constructors or object resolvers.

Members whose signatures cannot cross the bridge stay visible and return their specific blocker. Same-name overloads generate only the proven name-first winner, with shadowed signatures documented. Compatible duplicate property registrations are merged deterministically. Incompatible same-name registrations are never guessed: 57 groups are emitted as blocked accessors and documented with exact types and anchors in `generated/ambiguous_properties.txt`.

Regenerate after a manifest rebuild with `python KCD2/analysis/luautils/tools/generate_rttr_lua.py`; freshness check: `python KCD2/analysis/luautils/tools/generate_rttr_lua.py --check`. Smoke tests: `KCD2/analysis/luautils/tests/rttr_native_smoke.lua`, `KCD2/analysis/luautils/tests/rttr_wrappers_smoke.lua`, and the offline fixture `KCD2/analysis/luautils/tests/test_generate_rttr_lua.py`.

## SKALD bridge

SKALD is KCD2's native node-graph ("concept") system — the same runtime that drives quest logic, environment triggers, and supporting AI nodes. This bridge builds, wires, and drives SKALD node graphs directly from Lua: create a node, bind its outputs, pulse its inputs, tear it down — without an authored graph asset. Coverage ground truth is `KCD2/analysis/skald/skald_lua_manifest.json`; the full RE writeup is `KCD2/analysis/skald/skald_live_verification_2026-08-07.md`.

### Native bootstrap API (eleven functions, dot-call)

LuaUtils publishes an uppercase `SKALD` table during KCSE `PreDataLoaded`, alongside `RTTR`:

| Function | Behavior |
| --- | --- |
| `SKALD.CreateNode(cppType, arguments)` | Construct a node from its registered factory tag plus a Lua table of creation arguments. Returns `(nodeHandle, rttrHandle)`, or `(nil, error)`. |
| `SKALD.GetPortDefinitions(cppType[, typeParameter])` | Build a node, apply `TypeT` if given, read its live port list, then discard it without attaching or activating anything. Returns a dense array of `{name, valueType, direction, isTrigger}`. |
| `SKALD.DestroyNode(nodeHandle)` | Destroy a live node and detach it from its host module. Destroying an active effect force-deactivates it (the native teardown's falling edge), so effects never leak past their node. |
| `SKALD.QueueDestroy(nodeHandle)` | Enqueue a destroy for the next frame-tick drain. This is the generated GC finalizers' path — safe from any context because it never tears down inline. Mod scripts normally never call it. |
| `SKALD.BindTriggerOutput(nodeHandle, outputName, callback)` | Subscribe a Lua function to a trigger output; fires whenever the native graph pulses it, including synchronously within the same call chain (e.g. one trigger cascading into another). Returns a connection handle. |
| `SKALD.BindDataOutput(nodeHandle, outputName)` | Bind a data output and return `(bindingHandle, currentValue)`. The binding stays live until unbound. |
| `SKALD.UnbindDataOutput(bindingHandle)` | Release a data-output binding. |
| `SKALD.Disconnect(connectionHandle)` | Release a trigger-output connection. |
| `SKALD.TriggerInput(nodeHandle, triggerName)` | Pulse an action-trigger input. Returns an updates table for any bound outputs the pulse changed. |
| `SKALD.SetActivation(nodeHandle, active)` | Activate/deactivate an effect node: drives the native `OnEffectActivate`/`OnEffectDeactivate` edge directly (RTTI-verified against `C_Effect`). This is the **only** working activation lever — see below. Returns an updates table like `TriggerInput`. |
| `SKALD.SetUpdateDispatcher(dispatcher)` | Wire the function that receives output updates the native graph pushes asynchronously — not only as a side effect of a Lua-driven call. LuaUtils calls this once during bootstrap; mod scripts never call it directly. |

`cppType` here is the node's registered **factory tag** — the short authored-XML identifier the native factory resolves (`"If"`, `"BuffEffect"`, `"Length"`, ...), recovered and certified per node class, not necessarily the fully-qualified C++ type name. Every generated `Create()` below already passes the correct tag for its node. Normal mod scripts should use the `wh.<module>.<Node>` wrappers; direct `SKALD` calls remain available for low-level diagnostics — `SKALD.GetPortDefinitions` in particular is safe to call on a live game to introspect a node class without touching the running graph.

### Public generated node wrappers

Every supported node gets a `wh.<module>.<Node>` class alongside its RTTR wrapper:

```lua
-- Fixed-shape node: build a live wh.conceptmodule.If, react to both branches.
local branch, err = wh.conceptmodule.If.Create{ Condition = true }
if not branch then error(err) end

local trueConn = branch:BindOutput("True", function()
    System.LogAlways("condition was true")
end)
local falseConn = branch:BindOutput("False", function()
    System.LogAlways("condition was false")
end)
branch:TriggerInput("Exec")   -- pulses whichever branch Condition selects

trueConn:Disconnect()
falseConn:Disconnect()
branch:Destroy()
```

```lua
-- Effect-style node: wh.rpgmodule.C_PauseWorldTime. Effects do NOTHING at
-- creation -- the input pins are just values. Activate() applies the effect,
-- Deactivate() reverts it (live-verified via IsWorldTimePaused()).
local pause, err = wh.rpgmodule.C_PauseWorldTime.Create{ IsActive = true }
if not pause then error(err) end
pause:Activate()      -- world time is now frozen
pause:Deactivate()    -- and running again
pause:Destroy()
```

`Class.Create(args)` validates argument names (and required ones) against the certified port list before ever calling the native layer, unwraps `wh.*` object arguments to their raw handle, and marshals plain Lua array tables (see Arrays below). `Class.Outputs` lists bindable output names; `node:BindOutput(name[, callback])` returns a `Skald.OutputConnection` for trigger outputs (needs a callback) or a `Skald.OutputValue<T>` for data outputs. A connection exposes `:Disconnect()`; a value holder exposes `.value` (refreshes automatically — including asynchronously, whenever the native graph produces a new value for that output), `:Take()` (read and release ownership), and `:Release()`. `.value` is typed by the port: primitive outputs (`bool`, the int/float families, strings) deliver **raw Lua values**, object/enum outputs deliver `wh.*` wrappers owning their registry handle. `Class.Triggers` lists action-trigger names for `node:TriggerInput(name)`. `node:Destroy()` tears down the native node and invalidates every output/connection/binding it owns; `node:Release()` (inherited from the RTTR wrapper) redirects to `Destroy()` for live SKALD nodes.

**Effect activation.** Every supported node deriving the native `C_Effect` base — 122 of the 154 — gets `node:Activate()` / `node:Deactivate()`, and they are the *only* way to switch the effect on and off. Passing `IsActive = true` at creation sets the pin value but applies nothing, and there is deliberately **no `Commit`**: the native `Set<X>` companion pulses are a live-proven no-op outside authored graphs (the effect latch only reacts to executes sourced from the pin itself — an attribution that requires real graph wiring), so the wrappers don't offer a lever that cannot work. `Activate`/`Deactivate` drive the same `OnEffectActivate`/`OnEffectDeactivate` virtuals a genuine graph edge would.

**Node lifetime is GC-owned.** Every created node carries a finalizer: if the Lua wrapper is collected without an explicit `Destroy()`, the native node is queued for destruction and dies at the next frame tick — active effects included, which revert on teardown (verified: a collected, still-active `C_PauseWorldTime` unfroze world time). Keep a reference (a global, your mod's state table) for anything that must outlive the current scope; call `Destroy()` deliberately when done. Explicit `Destroy()` remains immediate and returns a verifiable result.

`wh.conceptmodule.ObjectProperties` bridges a live object's reflected state onto SKALD outputs (`DeclaringType` + a **required** `Object` — reading its outputs with no object wired faults natively, so `Create` demands it up front, making that failure mode unreachable by construction).

### Arrays

`wh.conceptmodule.Length`, `ElementAt`, and `ContainsElement` take a plain Lua table directly on their `Array` input — no native array-builder node is needed:

```lua
local strings = { "aa", "bb", "cc" }
local len = wh.conceptmodule.Length.Create{ Array = strings }        -- TypeT defaults to 'Strings'
local size = len:BindOutput("Length").value                          -- 3

local at1 = wh.conceptmodule.ElementAt.Create{ Array = strings, Index = 1 }
local value = at1:BindOutput("Value").value                          -- "bb"

local has = wh.conceptmodule.ContainsElement.Create{ Array = strings, Value = "bb" }
local found = has:BindOutput("Result").value                         -- true
```

`TypeT` accepts either a certified string (`'Strings'`, `'wh::rpgmodule::Souls'`) or the element's generated RTTR class table (`wh.rpgmodule.I_Soul`/`wh.rpgmodule.C_Soul`, aliased to `Souls`); it defaults to `'Strings'`. Elements are RTTR handles/wrappers (unwrapped automatically) for object-typed arrays, or plain Lua strings for `Strings` arrays. The same plain-table marshalling backs fixed array-alias inputs on other nodes (e.g. `BuffEffect.Souls`, always `wh::rpgmodule::Souls` regardless of `TypeT`) — the annotation on each generated `CreateArgs` field says which form a given input takes.

**`wh.conceptmodule.MakeArray` does not exist and should not be used.** The native factory refuses to construct it at all (a live-verified, unidentified-cause failure, not a Lua-side restriction); plain Lua tables on the inputs above supersede it entirely and are not limited to the 26-element cap that node's old variadic-pin design had.

Regenerate after a manifest rebuild with `python KCD2/analysis/luautils/tools/generate_skald_manifest.py` (writes `skald_lua_manifest.json`; `--check` verifies freshness), then `python KCD2/analysis/luautils/tools/generate_skald_lua.py` (writes `lua/skald/`; `--check` verifies freshness). The current manifest covers 154 of 195 swept native node classes; unsupported nodes stay listed with their specific blocker rather than being dropped silently — see `generated/coverage.txt`. Fixture test: `KCD2/analysis/luautils/tests/test_generate_skald_manifest.py` and `KCD2/analysis/luautils/tests/test_generate_skald_lua.py`.

## Game-native Lua packaging

Generated Lua is not loaded from loose files beside the plugin DLL. KCD2 mounts `Data/luautils.pak` and automatically executes `Scripts/Mods/luautils.lua`, selected by `<modid>luautils</modid>` in `mod.manifest`.

KCSE publishes the native bridges before that entry point runs:

```text
KCSE PreDataLoaded
  -> publish RTTR and SKALD
KCD2 CompleteInit
  -> Scripts/main.lua
  -> Scripts/Mods/luautils.lua
       -> ordered RTTR modules
       -> ordered SKALD modules
```

The bootstrap uses explicit `Script.ReloadScript` calls generated from the two `generated/files.txt` manifests. It does not use `ScriptLoader.LoadFolder`, whose directory enumeration order is not certified for RTTR's base-before-derived requirement.

Build or verify the PAK explicitly; CMake does not invoke Python or package assets:

```text
python KCD2/analysis/luautils/tools/build_scripts_pak.py --output KCD2/RE/.buildenv/build-release/LuaUtils/luautils.pak
python KCD2/analysis/luautils/tools/build_scripts_pak.py --output KCD2/RE/.buildenv/build-release/LuaUtils/luautils.pak --check
python KCD2/analysis/luautils/tests/test_build_scripts_pak.py
```

Deployment layout:

```text
mods/LuaUtils/
  mod.manifest
  Data/luautils.pak
  KCSE/Plugins/LuaUtils.dll
  KCSE/Plugins/LuaUtils.pdb
```

The DLL/PDB remain loose because KCSE loads physical plugin DLLs with `LoadLibraryA`. The RTTR and SKALD Lua trees exist only inside `Data/luautils.pak`; do not deploy `KCSE/Plugins/LuaUtils/rttr` or `KCSE/Plugins/LuaUtils/skald` directories.

## Build

LuaUtils is part of the KCD2 RE workspace. CMake compiles and links native code only. Build the `release` preset from `KCD2/RE/.buildenv`; the DLL and PDB are emitted under `build-release/LuaUtils/`. Run the standalone packaging command above afterward to create `luautils.pak`.
