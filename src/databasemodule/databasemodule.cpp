#include "databasemodule/C_ObjectDatabaseManager.h"
#include "databasemodule/C_DatabaseModule.h"
#include "rpgmodule/C_ReputationChangeDatabase.h"
#include "rpgmodule/C_PerkDatabase.h"
#include "rpgmodule/C_SoulArchetypeDatabase.h"
#include "rpgmodule/C_SocialClassDatabase.h"
#include "rpgmodule/C_PerkBuffDatabase.h"
#include "rpgmodule/C_PerkScriptDatabase.h"
#include "rpgmodule/C_PerkSoulAbilityDatabase.h"
#include "rpgmodule/C_PerkRecipeDatabase.h"
#include "rpgmodule/C_PerkCombatTechniqueDatabase.h"
#include "rpgmodule/C_PerkCompanionDatabase.h"
#include "rpgmodule/C_PerkCodexDatabase.h"
#include "rpgmodule/C_Perk2PerkExclusivityDatabase.h"
#include "rpgmodule/C_ReputationConditionDatabase.h"
#include "rpgmodule/C_ReputationNotificationDatabase.h"
#include "rpgmodule/C_Location2PerkDatabase.h"
#include "rpgmodule/C_POIType2PerkDatabase.h"
#include "rpgmodule/C_PerkBuffOverrideDatabase.h"
#include "rpgmodule/C_PerkRPGParamOverrideDatabase.h"
#include "rpgmodule/C_DocumentRewardPerkDatabase.h"
#include "rpgmodule/C_SoulStateEffectContextDatabase.h"
#include "Offsets/Offsets.h"

namespace wh::databasemodule {

C_ObjectDatabaseManager* C_ObjectDatabaseManager::GetInstance()
{
    using Fn = C_ObjectDatabaseManager* (__fastcall*)();
    static REL::Relocation<Fn> fn{ REL::ID(39) };
    return fn();
}

bool C_ObjectDatabaseManager::LoadAll(bool force)
{
    using Fn = bool (__fastcall*)(C_ObjectDatabaseManager*, bool);
    static REL::Relocation<Fn> fn{ REL::ID(328564) };
    return fn(this, force);
}

void C_DynamicEnumManager::Register(const char* tableName,
                                    I_DynamicEnum* provider)
{
    using Fn = void (__fastcall*)(C_DynamicEnumManager*, const char*, I_DynamicEnum*);
    static REL::Relocation<Fn> fn{ REL::ID(76162) };
    fn(this, tableName, provider);
}

void C_DynamicEnumManager::Unregister(const char* tableName)
{
    using Fn = void (__fastcall*)(C_DynamicEnumManager*, const char*);
    static REL::Relocation<Fn> fn{ REL::ID(328474) };
    fn(this, tableName);
}

C_DatabaseModule* C_DatabaseModule::GetInstance()
{
    static REL::Relocation<C_DatabaseModule**> instance{ REL::ID(2325) };
    return *instance;
}

}  // namespace wh::databasemodule

namespace wh::rpgmodule {

C_ReputationChangeDatabase* C_ReputationChangeDatabase::GetInstance()
{
    static REL::Relocation<C_ReputationChangeDatabase*> instance{ REL::ID(2343) };
    return instance.get();
}

C_PerkDatabase* C_PerkDatabase::GetInstance()
{
    static REL::Relocation<C_PerkDatabase*> instance{ REL::ID(2338) };
    return instance.get();
}

C_SoulArchetypeDatabase* C_SoulArchetypeDatabase::GetInstance()
{
    static REL::Relocation<C_SoulArchetypeDatabase*> instance{ REL::ID(2347) };
    return instance.get();
}

C_SocialClassDatabase* C_SocialClassDatabase::GetInstance()
{
    static REL::Relocation<C_SocialClassDatabase*> instance{ REL::ID(2346) };
    return instance.get();
}

C_PerkBuffDatabase* C_PerkBuffDatabase::GetInstance()
{
    static REL::Relocation<C_PerkBuffDatabase*> instance{ REL::ID(2333) };
    return instance.get();
}

C_PerkScriptDatabase* C_PerkScriptDatabase::GetInstance()
{
    static REL::Relocation<C_PerkScriptDatabase*> instance{ REL::ID(2341) };
    return instance.get();
}

C_PerkSoulAbilityDatabase* C_PerkSoulAbilityDatabase::GetInstance()
{
    static REL::Relocation<C_PerkSoulAbilityDatabase*> instance{ REL::ID(2342) };
    return instance.get();
}

C_PerkRecipeDatabase* C_PerkRecipeDatabase::GetInstance()
{
    static REL::Relocation<C_PerkRecipeDatabase*> instance{ REL::ID(2340) };
    return instance.get();
}

C_PerkCombatTechniqueDatabase* C_PerkCombatTechniqueDatabase::GetInstance()
{
    static REL::Relocation<C_PerkCombatTechniqueDatabase*> instance{ REL::ID(2336) };
    return instance.get();
}

C_PerkCompanionDatabase* C_PerkCompanionDatabase::GetInstance()
{
    static REL::Relocation<C_PerkCompanionDatabase*> instance{ REL::ID(2337) };
    return instance.get();
}

C_PerkCodexDatabase* C_PerkCodexDatabase::GetInstance()
{
    static REL::Relocation<C_PerkCodexDatabase*> instance{ REL::ID(2335) };
    return instance.get();
}

C_Perk2PerkExclusivityDatabase* C_Perk2PerkExclusivityDatabase::GetInstance()
{
    static REL::Relocation<C_Perk2PerkExclusivityDatabase*> instance{ REL::ID(2332) };
    return instance.get();
}

C_ReputationConditionDatabase* C_ReputationConditionDatabase::GetInstance()
{
    static REL::Relocation<C_ReputationConditionDatabase*> instance{ REL::ID(2345) };
    return instance.get();
}

C_ReputationNotificationDatabase* C_ReputationNotificationDatabase::GetInstance()
{
    static REL::Relocation<C_ReputationNotificationDatabase*> instance{ REL::ID(2344) };
    return instance.get();
}

C_Location2PerkDatabase* C_Location2PerkDatabase::GetInstance()
{
    static REL::Relocation<C_Location2PerkDatabase*> instance{ REL::ID(2330) };
    return instance.get();
}

C_POIType2PerkDatabase* C_POIType2PerkDatabase::GetInstance()
{
    static REL::Relocation<C_POIType2PerkDatabase*> instance{ REL::ID(2331) };
    return instance.get();
}

C_PerkBuffOverrideDatabase* C_PerkBuffOverrideDatabase::GetInstance()
{
    static REL::Relocation<C_PerkBuffOverrideDatabase*> instance{ REL::ID(2334) };
    return instance.get();
}

C_PerkRPGParamOverrideDatabase* C_PerkRPGParamOverrideDatabase::GetInstance()
{
    static REL::Relocation<C_PerkRPGParamOverrideDatabase*> instance{ REL::ID(2339) };
    return instance.get();
}

C_DocumentRewardPerkDatabase* C_DocumentRewardPerkDatabase::GetInstance()
{
    static REL::Relocation<C_DocumentRewardPerkDatabase*> instance{ REL::ID(2329) };
    return instance.get();
}

C_SoulStateEffectContextDatabase* C_SoulStateEffectContextDatabase::GetInstance()
{
    static REL::Relocation<C_SoulStateEffectContextDatabase*> instance{ REL::ID(2348) };
    return instance.get();
}

}  // namespace wh::rpgmodule
