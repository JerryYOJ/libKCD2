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
#include "Offsets/vtables/ILog.h"
#include "Offsets/vtables/ISystem.h"
#include "Offsets/vtables/IEntity.h"
#include "Offsets/vtables/IGameFramework.h"
#include "Offsets/vtables/IActor.h"
#include "Offsets/vtables/IGame.h"
#include "Offsets/vtables/IGameStartup.h"

// ---- RE'd concrete engine classes (real members; use SDK/std types). These are OUR
//      reverse-engineered definitions, kept in crysystem/ (NOT the stock CryCommon SDK folder). ----
#include "crysystem/CScriptTable.h"
#include "crysystem/CScriptSystem.h"
#include "crysystem/CXConsole.h"
#include "crysystem/CSystem.h"
#include "crysystem/CEntity.h"
#include "crysystem/CEntitySystem.h"
#include "crysystem/CCryAction.h"
#include "entitymodule/C_Actor.h"
#include "game/C_Game.h"
#include "game/C_GameStartup.h"

// ---- Round 1: engine/globals foundation (gEnv, camera, movie, rpg params, game context) ----
#include "crysystem/SSystemGlobalEnvironment.h"   // gEnv
#include "crysystem/SCameraParams.h"
#include "crysystem/CMovieSystem.h"
#include "rpgmodule/S_RpgParams.h"
#include "game/S_GameContext.h"
#include "playermodule/C_PlayerModule.h"
#include "combatmodule/C_CombatActor.h"

// ---- Tranche 1: foundation (actor hierarchy + signal + module message) ----
#include "framework/C_Signal.h"
#include "framework/S_WuidSlot.h"       // generation-counted registry slot (0x10)
#include "framework/HashPrimitives.h"   // FNV-1a/FNV-1 + S_DefaultHash for std:: unordered keys
#include "framework/InplaceVector.h"    // std::vector with inline small-buffer storage
#include "framework/C_Listeners.h"      // C_Listeners<L,N> / C_DependentListeners<L,K,N> registries
#include "framework/C_ModuleMessage.h"
#include "framework/CryDeferrable.h"
#include "entitymodule/I_ItemAttachmentListener.h"
#include "entitymodule/I_EquipmentManagerListener.h"
#include "entitymodule/C_Actor.h"
#include "entitymodule/C_Human.h"
#include "entitymodule/C_Animal.h"
#include "entitymodule/C_Horse.h"
#include "entitymodule/C_Player.h"

// ---- Tranche 2: item / inventory ----
#include "entitymodule/C_Item.h"
#include "entitymodule/C_Inventory.h"
#include "entitymodule/C_WorldInventory.h"
#include "entitymodule/C_EquipmentManager.h"
#include "entitymodule/C_InventoryManager.h"
#include "entitymodule/C_ItemManager.h"

// ---- Tranche 3: combat subsystems (model-property family + per-actor combat state) ----
#include "framework/ModelPropertyTraits.h"
#include "combatmodule/CombatModelTraits.h"
#include "framework/C_ModelProperty.h"
#include "framework/C_ModelRefProperty.h"
#include "framework/C_ModelContextProperty.h"
#include "framework/C_ModelSetProperty.h"
#include "framework/C_ModelArrayProperty.h"
#include "combatmodule/S_CombatActorState.h"
#include "combatmodule/C_CombatActorObject.h"
#include "combatmodule/C_CombatActorUpdatedObject.h"
#include "combatmodule/I_CombatComboManager.h"
#include "combatmodule/C_CombatComboManager.h"
#include "combatmodule/C_CombatActorOpponentManager.h"
#include "combatmodule/I_CombatActorHuntAttack.h"
#include "combatmodule/C_CombatActorHuntAttack.h"
#include "combatmodule/C_CombatActorActionManager.h"
#include "framework/C_ActionDirector.h"
#include "combatmodule/C_CombatActorDirector.h"
#include "combatmodule/C_CombatAutomationAction.h"
#include "combatmodule/C_CombatAutomationDirector.h"
#include "combatmodule/C_CombatAutomationBattlement.h"
#include "combatmodule/C_CombatAutomationAttack.h"
#include "combatmodule/C_CombatAutomationCombo.h"
#include "combatmodule/C_CombatAutomationMissile.h"
#include "combatmodule/C_CombatAutomationZoneChange.h"
#include "combatmodule/C_CombatAutomationGuard.h"
#include "game/I_EntitySideEffectCallback.h"
#include "combatmodule/C_CombatAutomationWeapons.h"
#include "combatmodule/S_CombatAutomationModels.h"
#include "combatmodule/C_CombatAutomationDefense.h"
#include "combatmodule/C_CombatAutomationRiposte.h"
#include "combatmodule/C_CombatTemporaryAutomationGuardStarter.h"
#include "combatmodule/I_CombatAutomation.h"
#include "combatmodule/C_CombatAutomation.h"

// ---- Tranche 4: C_Actor / C_Player embedded sub-structs ----
#include "entitymodule/C_AuxLightAttachment.h"
#include "entitymodule/C_PlayerMaterialEffects.h"
#include "entitymodule/C_MissileWeaponPlayerController.h"
#include "framework/CStateMachine.h"
#include "entitymodule/C_PhysicsIgnoreLists.h"
#include "entitymodule/C_BoneSlotSystem.h"
#include "animationmodule/C_LookAimIK.h"
#include "entitymodule/C_IdleState.h"
#include "entitymodule/C_StanceState.h"
#include "entitymodule/C_ActorMoveParams.h"
#include "entitymodule/C_ActorBounds.h"
#include "entitymodule/S_MountAnimState.h"

// ---- Tranche 5: RPG core (souls / buffs / factions / module) ----
#include "framework/C_ParallelModuleUpdater.h"
#include "databasemodule/I_DatabaseListener.h"
// soul stack
#include "rpgmodule/I_Soul.h"
#include "rpgmodule/I_SoulResolver.h"
#include "rpgmodule/S_ModifierNode.h"
#include "rpgmodule/C_SoulPropertyNotifier.h"
#include "rpgmodule/C_CombatSoul.h"
#include "rpgmodule/C_InventorySoul.h"
#include "rpgmodule/C_CompanionManager.h"
#include "rpgmodule/C_PerkList.h"
#include "rpgmodule/S_SoulStatBlock.h"
#include "rpgmodule/C_SoulRPGStats.h"
#include "rpgmodule/S_SoulRegistry.h"
#include "rpgmodule/C_SoulBuffList.h"
#include "rpgmodule/C_Soul.h"
#include "rpgmodule/C_StormProgram.h"
#include "rpgmodule/C_SoulList.h"
// buff stack
#include "rpgmodule/I_BuffManager.h"
#include "rpgmodule/C_BuffInstanceBase.h"
#include "rpgmodule/C_BuffInstance.h"
#include "rpgmodule/C_SoulBuffInstance.h"
#include "rpgmodule/C_TimedSoulBuffInstance.h"
#include "rpgmodule/C_BuffManager.h"
// faction stack
#include "rpgmodule/I_FactionManager.h"
#include "rpgmodule/S_FactionDefinitionID.h"
#include "framework/S_BoostOptional.h"
#include "rpgmodule/S_LocationId.h"
#include "rpgmodule/S_FactionNeighbor.h"
#include "rpgmodule/C_FactionAngriness.h"
#include "rpgmodule/C_FactionRelation.h"
#include "rpgmodule/C_FactionBase.h"
#include "rpgmodule/C_Faction.h"
#include "rpgmodule/C_FactionManager.h"
// module
#include "rpgmodule/S_RPGCVars.h"
#include "rpgmodule/C_RPGModule.h"

// ---- Tranche 6: Lua ScriptBind surface + item runtime data + RPG value enums ----
// enums (index the S_SoulStatBlock arrays / GetDerivedStat string codes)
#include "rpgmodule/E_SoulStat.h"
#include "rpgmodule/E_SoulSkill.h"
#include "rpgmodule/E_DerivedStat.h"
#include "rpgmodule/E_SoulCondition.h"
// ScriptBind surface (the Lua cheat entry points; fn tables documented per header)
#include "crysystem/CScriptableBase.h"
#include "rpgmodule/C_ScriptBindSoul.h"
#include "rpgmodule/C_FactionScriptBind.h"
#include "rpgmodule/C_LocationScriptBind.h"
#include "rpgmodule/C_ScriptBindRPGModule.h"
#include "entitymodule/C_ScriptBindActor.h"
#include "entitymodule/C_ScriptBindPlayer.h"
#include "entitymodule/C_ScriptBindHorse.h"
#include "entitymodule/C_ScriptBindHuman.h"
#include "entitymodule/C_ScriptBindInventory.h"
#include "entitymodule/C_ScriptBindItemManager.h"
#include "shopmodule/C_ScriptBindShop.h"
// item runtime-data family (C_Item+0x58 pointee hierarchy)
#include "entitymodule/I_ItemRuntimeData.h"
#include "entitymodule/C_ConsumableRuntimeData.h"
#include "entitymodule/C_KeyRuntimeData.h"
#include "entitymodule/C_EquippableItemRuntimeData.h"
#include "entitymodule/C_ArmorRuntimeData.h"
#include "entitymodule/C_WeaponEquipRuntimeData.h"
#include "entitymodule/C_AmmoRuntimeData.h"
#include "entitymodule/C_WeaponRuntimeData.h"
#include "entitymodule/C_MeleeWeaponRuntimeData.h"
#include "entitymodule/C_MissileWeaponRuntimeData.h"

// ---- Tranche 7: buff instance leaves + buff init-params + save-game stack ----
// buff leaves (below the C_SoulBuffInstance / C_TimedSoulBuffInstance anchors)
#include "rpgmodule/C_ConstantSoulBuffInstance.h"
#include "rpgmodule/C_ConstantContextCheckingSoulBuffInstance.h"
#include "rpgmodule/C_CombatContextSoulBuffInstance.h"
#include "rpgmodule/C_InstantSoulBuffInstance.h"
#include "rpgmodule/C_TwoStateSoulBuffInstance.h"
#include "rpgmodule/C_TwoStateWithActivationSoulBuffInstance.h"
#include "rpgmodule/C_WantedBuff.h"
#include "rpgmodule/C_ModifiableTimedBuff.h"
#include "rpgmodule/C_WorldTimeTimedBuff.h"
#include "rpgmodule/C_BleedingBuffInstance.h"
// buff init-params family
#include "rpgmodule/I_BuffInitParams.h"
#include "rpgmodule/C_BuffInitParamsDefault.h"
#include "rpgmodule/C_ItemBuffInitParams.h"
// save-game stack (framework; owner C_PlayerProfileWHManager not yet RE'd)
#include "framework/E_SaveGameType.h"
#include "framework/I_ReadinessDebuggable.h"
#include "framework/I_ReadinessTask.h"
#include "framework/C_ReadinessObserver.h"
#include "framework/C_CrySaveGameHelper.h"
#include "framework/C_CryLoadGameHelper.h"
#include "framework/C_SaveGameDescription.h"
#include "framework/S_SaveGameTypeSlot.h"
#include "framework/S_SaveBuildStamp.h"
#include "framework/C_SaveGameManager.h"
// fast travel (playermodule; owned at C_PlayerModule+0x28)
#include "playermodule/S_FastTravelConfig.h"
#include "playermodule/C_FastTravel.h"
