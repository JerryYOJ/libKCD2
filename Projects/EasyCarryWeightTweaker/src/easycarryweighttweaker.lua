-- EasyCarryWeightTweaker -- in-game tuning of carry-weight / encumbrance RPG
-- params through the Mod Configuration Menu.
--
-- Requires (both KCSE plugins):
--   MCM              -- the menu + this Lua API (MCM.* global)
--   ConsoleRpgParam  -- exposes every RPG param as a kcse_rpgparam_* CVar
--
-- The build callback runs on every menu open, so slider defaults are the LIVE
-- CVar values -- whatever the game (or console, or another mod) last set.
-- Changes apply instantly via System.SetCVar; nothing is persisted across
-- restarts by design (RPG params reset to table values on game start).

local MOD_ID   = "easycarryweighttweaker"
local MOD_NAME = "Easy Carry Weight Tweaker"
local PREFIX   = "kcse_rpgparam_"

-- { param, label, min, max, step, suffix, tooltip } -- tooltips are the
-- binary's own param descriptions (S_RpgParamDefs); or { category = "..." }.
local SETTINGS = {
	{ category = "Inventory Capacity" },
	-- the game hard-caps carry weight at 600
	{ "BaseInventoryCapacity", "Base Inventory Capacity", 0, 600, 1, " lb",
	  "base inventory capacity [lb]" },
	{ "MaxBaseInventoryCapacity", "Max Base Inventory Capacity", 0, 600, 1, " lb",
	  "Base maximum of inventory capacity without taking the archetype multiplier into account [lb]" },
	{ "StrengthToInventoryCapacity", "Strength to Inventory Capacity", 0, 100, 1, " lb",
	  "derives the inventory capacity from the strength stat [lb/str]" },
	{ "EquippedWeightSubWithWellWornPerk", "Well Worn Equipped Weight Reduction", 0, 1, 0.05, "",
	  "when player has Well Worn perk, weight of items is lowered when they are equipped; equippedWeight=standardWeight*(1.0 - EquippedWeightSubWithWellWornPerk)" },

	{ category = "Carrying Bodies & Sacks" },
	{ "CarriedBodyWeightCoef", "Carried Body Weight Coef", 0, 2, 0.05, "",
	  "how much of the carried body weight is added to the carried weight of the carrier" },
	{ "CarriedCarriedWeightCoef", "Carried NPC's Carried Weight Coef", 0, 2, 0.05, "",
	  "how much of the carried weight of the carried NPC is added to the carried weight of the carrier" },
	{ "CarriedBodyMaxStamConsumption", "Carried Body Max Stamina Drain", 0, 50, 1, "",
	  "uses encumberence to interpolate from 0 to this" },
	{ "AddedDirtOnCarryItem", "Dirt Added on Carry Item", 0, 100, 1, "%",
	  "Dirt added on player when picking or putting down an item through the carry item action (the sack carrying feature)." },

	{ category = "Encumbrance Effects" },
	{ "HorseMountMaxRelativeEncumberance", "Horse Mount Max Encumbrance", 0, 300, 1, "%",
	  "maximum allowed relative encumberance for player mounting a horse [%]" },
	{ "EncumberedToSpeedSurfaceCoef", "Encumbered Surface Speed Coef", 0, 2, 0.05, "",
	  "Coef that controls terrain/surface influence in encumbered speed mod" },
	{ "EncumberanceForSecondaryModifiers", "Encumbrance for Secondary Modifiers", 0, 2, 0.05, "",
	  "when the buff will activate the secondary group" },

	{ category = "Encumbrance XP" },
	{ "MinEncumberanceXPAwardDistance", "Min XP Award Distance", 0, 1000, 10, " m",
	  "Distance that has to be covered while minimally encumbered to get StatXPStrAndVitPerDistanceEncumbered (linear interpolation with EncumberanceXPAwardDistanceMax)." },
	{ "MaxEncumberanceXPAwardDistance", "Max XP Award Distance", 0, 5000, 50, " m",
	  "Distance that has to be covered while encumbered by at least double of carry weight to get StatXPStrAndVitPerDistanceEncumbered (linear interpolation with EncumberanceXPAwardDistanceMin)." },
	{ "StatXPStrAndVitPerDistanceEncumbered", "Str/Vit XP per Distance", 0, 100, 1, "",
	  "Strength and vitality xp gain after walking EncumberanceXPAwardDistance meters while encumbered" },

	{ category = "Armor Load" },
	{ "ArmorLoadToSprint", "Armor Load to Sprint", 0, 2, 0.05, "",
	  "how armor load coefficient affects sprint" },
	{ "ArmorLoadToRun", "Armor Load to Run Speed", 0, 2, 0.05, "",
	  "how armor load coefficient affects running speed" },
	{ "ArmorLoadToJumpCost", "Armor Load to Jump Cost", 0, 5, 0.1, "",
	  "how armor load coefficient affects the stamina jump cost (times base)" },
	{ "StrToEqwArmorLoad", "Strength to Armor Load", 0, 200, 1, "",
	  "maximal gain on level cap, GDD: 17/218" },
	{ "AgiToEqwArmorLoad", "Agility to Armor Load", 0, 200, 1, "",
	  "maximal gain on level cap, GDD: 17/218" },
	{ "VitToEqwArmorLoad", "Vitality to Armor Load", 0, 200, 1, "",
	  "maximal gain on level cap, GDD: 17/218" },
	{ "ArmorLoadDiffToMax", "Armor Load Diff to Max", 0, 200, 1, "",
	  "GDD: 17/218" },
	{ "MaxArmorLoad", "Max Armor Load", 0, 500, 1, "",
	  "#ArmorLoad" },
	{ "HeavyLightArmorThreshold", "Heavy/Light Armor Threshold", -1, 1, 0.01, "",
	  "should be between -MaxArmorLoad and MaxArmorLoad. #ArmorLoad" },

	{ category = "Combat" },
	{ "DodgeRelArmorLoadThreshold", "Dodge Armor Load Threshold", 0, 1, 0.01, "",
	  "relative armor load threshold for dodge distance computation" },
	{ "DodgeRelDistanceThreshold", "Dodge Distance Threshold", 0, 1, 0.01, "",
	  "relative distance threshold refering to DodgeRelArmorLoadThreshold" },
	{ "HeavyWeaponWeight", "Heavy Weapon Weight", 0, 500, 1, " lb",
	  "used to deduce 'attack weight' [lb]" },
}

local function BuildMenu()
	-- sentinel: ConsoleRpgParam registers its CVars at DataLoaded, well before
	-- the menu can open; missing here means the plugin isn't installed
	if System.GetCVar(PREFIX .. "BaseInventoryCapacity") == nil then
		System.LogAlways("[EasyCarryWeightTweaker] kcse_rpgparam_* CVars missing - is the ConsoleRpgParam KCSE plugin installed?")
		return
	end
	MCM.AddMod(MOD_ID, MOD_NAME)
	for _, s in ipairs(SETTINGS) do
		if s.category then
			MCM.AddCategory(MOD_ID, s.category, "")
		else
			local cur = System.GetCVar(PREFIX .. s[1])
			if cur ~= nil then
				-- the table ranges are educated guesses; the live value wins.
				-- Grow the range to 2x the current value (snapped to step)
				-- whenever the value falls outside.
				local mn, mx, step = s[3], s[4], s[5]
				if cur > mx then
					mx = math.ceil(cur * 2 / step) * step
				end
				if cur < mn then
					if cur < 0 then
						mn = math.floor(cur * 2 / step) * step
					else
						mn = math.floor(cur / step) * step
					end
				end
				MCM.AddSlider(MOD_ID, s[1], s[2], s[7], mn, mx, step, cur, s[6])
			end
		end
	end
end

if MCM == nil then
	System.LogAlways("[EasyCarryWeightTweaker] MCM global missing - install the Mod Configuration Menu (KCSE plugin + mod)")
	return
end

MCM.RegisterBuildSettingsListener(BuildMenu)
MCM.RegisterValueChangeListener(MOD_ID, function(settingId, value)
	System.SetCVar(PREFIX .. settingId, value)
end)

System.LogAlways("[EasyCarryWeightTweaker] MCM listeners registered")
