#pragma once

// -----------------------------------------------
// ::IEntitySystemSink -- entity-system spawn/remove/event callback interface (CryEngine stock plus
// KCD2's appended name query). sizeof 0x08 (vtable-only), 8 slots.
// -----------------------------------------------
// Declared here because the stock CryCommon IEntitySystem.h declaration lacks KCD2's final GetName
// slot, cannot compile in this build env (its IComponent.h requires boost), and would redefine
// IEntityEventListener against crysystem/EntityEventListenerWithCleanup.h in the same TU. Do NOT
// also include the stock IEntitySystem.h in a TU using this.
//
// The first seven source contracts retain the stock order. KCD2 appends GetName at slot 7; concrete
// eight-slot sink tables independently return their class identity from that slot.
// Used as a base of wh::combatmodule::C_CombatScene (@+0x10, vtable 0x183A6C7F0).

struct IEntity;
struct SEntitySpawnParams;
struct SEntityEvent;
class ICrySizer;

struct IEntitySystemSink {
    virtual ~IEntitySystemSink() {}
    virtual bool OnBeforeSpawn(SEntitySpawnParams& params) = 0;
    virtual void OnSpawn(IEntity* pEntity, SEntitySpawnParams& params) = 0;
    virtual bool OnRemove(IEntity* pEntity) = 0;
    virtual void OnReused(IEntity* pEntity, SEntitySpawnParams& params) = 0;
    virtual void OnEvent(IEntity* pEntity, SEntityEvent& event) = 0;
    virtual void GetMemoryUsage(ICrySizer* pSizer) const {}
    virtual const char* GetName() const = 0; // [7], KCD2 addition
};
static_assert(sizeof(IEntitySystemSink) == 0x08, "IEntitySystemSink is vtable-only");
