#pragma once
#include <cstddef>
#include <cstdint>
#include <optional>
#include <unordered_map>
#include <vector>

#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../conceptmodule/C_ModuleBase.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "../framework/CryDeferrable.h"
#include "../framework/S_TimeSpan.h"
#include "../framework/WUID.h"
#include "S_RandomEventEncounter.h"
#include "S_RandomEventProfileState.h"

namespace wh::playermodule {

class C_RandomEventBase
    : public wh::conceptmodule::C_ModuleBase,
      public UnsafeOp::CryDeferrable<0> {
public:
    C_RandomEventBase();
    ~C_RandomEventBase() override;                         // [0] 0x182ECC870
    RTTR_ENABLE(wh::conceptmodule::C_ModuleBase) // [5..7]
    rttr::variant GetPortValue(
        _smart_ptr<wh::conceptmodule::I_Port> const& port) override; // [12] 0x180453D30
    void Wake(
        std::vector<_smart_ptr<wh::conceptmodule::C_Node>>& changed,
        wh::conceptmodule::E_NodeWakeReason reason) override; // [21] 0x1816B20C4
    void Reset() override;                                  // [37] 0x1817D76FC
    std::uint8_t GetModuleKind() const override;            // [44] 0x181A74A40

    virtual bool CanSpawn() const;                          // [55] true
    virtual bool IsOnCooldown(bool fastTravel) const;       // [56] 0x1804C6B78
    virtual void Start(S_RandomEventEncounter const& encounter); // [57] 0x182ECEAD4
    virtual void ActivateCooldown(
        S_RandomEventEncounter const& encounter);           // [58] 0x182ECD268
    virtual bool CanDespawn() const;                        // [59] false
    virtual bool RequestDespawn();                          // [60] 0x181460A88
    virtual bool IsDespawnRequested() const;                // [61] 0x180533594
    virtual std::uint32_t GetSpawnEntityId() const;         // [62] 0x182ECD8D0
    virtual void unk63();                                   // [63] 0x182ECD37C
    virtual bool HasTag(CryStringT<char> const& tag) const; // [64] false
    virtual void StartInternal(
        S_RandomEventEncounter const& encounter);           // [65] 0x180622050
    virtual void unk66();                                   // [66] null
    virtual Vec3 GetSpawnPosition() const;                  // [67] 0x1809F44F0
    virtual Quat GetSpawnRotation() const;                  // [68] 0x181A9B310
    virtual void OnStarted();                               // [69] 0x180621288
    virtual void Despawn(bool resetCooldown, bool triggerPort); // [70] 0x180ADB774

    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onSpawn;            // +0xA8 RTTR "OnSpawn"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onDespawn;          // +0xE8 RTTR "OnDespawn"
    std::optional<CryStringT<char>> m_profile;              // +0x128 RTTR "Profile"
    std::optional<wh::framework::S_TimeSpan> m_cooldown;   // +0x138 RTTR "Cooldown"
    std::unordered_map<CryStringT<char>, S_RandomEventProfileState>
        m_profileStates;                                    // +0x148
    bool m_spawned;                                         // +0x188
    bool m_unknown189;                                      // +0x189
    bool m_timeSkipListenerRegistered;                      // +0x18A
    bool m_despawnRequested;                                // +0x18B
    std::uint8_t m_padding18C[4];
    S_RandomEventEncounter* m_encounter;                    // +0x190, owned
    std::unordered_map<wh::framework::WUID, CryStringT<char>>
        m_spawnedNpcs;                                      // +0x198, serialized "SpawnedNPCs"
    std::vector<std::uint32_t> m_spawnedEntityIds;          // +0x1D8
};

static_assert(sizeof(C_RandomEventBase) == 0x1F0,
              "C_RandomEventBase size mismatch");
static_assert(offsetof(C_RandomEventBase, m_onSpawn) == 0xA8,
              "C_RandomEventBase spawn port offset mismatch");
static_assert(offsetof(C_RandomEventBase, m_onDespawn) == 0xE8,
              "C_RandomEventBase despawn port offset mismatch");
static_assert(offsetof(C_RandomEventBase, m_profile) == 0x128,
              "C_RandomEventBase profile offset mismatch");
static_assert(offsetof(C_RandomEventBase, m_profileStates) == 0x148,
              "C_RandomEventBase profile states offset mismatch");
static_assert(offsetof(C_RandomEventBase, m_encounter) == 0x190,
              "C_RandomEventBase encounter offset mismatch");
static_assert(offsetof(C_RandomEventBase, m_spawnedNpcs) == 0x198,
              "C_RandomEventBase spawned NPCs offset mismatch");
static_assert(offsetof(C_RandomEventBase, m_spawnedEntityIds) == 0x1D8,
              "C_RandomEventBase spawned entity IDs offset mismatch");

} // namespace wh::playermodule
