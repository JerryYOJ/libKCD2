#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../framework/C_Signal.h"
#include "../framework/I_ModuleMessageListener.h"
#include "../framework/WUID.h"
#include "C_LinkableObjectExtension.h"
#include "S_AnimalSpawnState.h"

namespace wh::xgenaimodule {

class C_TriggerArea;

class C_AnimalSpawner
    : public C_LinkableObjectExtension,
      public framework::I_ModuleMessageListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_AnimalSpawner;

    ~C_AnimalSpawner() override;                              // primary [0] 0x18096D3AC
    void ProcessEvent(SEntityEvent& event) override;          // primary [1] 0x1814ED634
    void GetMemoryUsage(ICrySizer* sizer) const override;     // primary [6] 0x18328167C
    bool Init(Offsets::IGameObject* gameObject) override;     // primary [7] 0x18096E234
    void PostInit(Offsets::IGameObject* gameObject) override; // primary [8] 0x1816F1760
    void Release() override;                                  // primary [14] 0x18096D1B4
    void FullSerialize(TSerialize serializer) override;       // primary [15] 0x183281058
    bool _vf17() override;                                    // primary [17] 0x183281BEC, role OPEN
    void OnModuleMessage(void* message) override;             // secondary [1] 0x180479D28

    shared::C_Signal<> m_onReturningToPool;         // +0x60, name reconstructed
    std::vector<S_AnimalSpawnState> m_animalStates; // +0x70
    bool m_active;                                  // +0x88
    std::uint8_t _pad89[3];                         // +0x89
    Vec3 m_spawnPosition;                           // +0x8C, name reconstructed
    CryGUID m_soulGuid;                             // +0x98, first initialized by PostInit
    CryStringT<char> m_entityClass;                 // +0xA8
    std::int32_t m_respawnDays;                     // +0xB0, native default 14
    bool m_spawnInFlock;                            // +0xB4, native default true
    std::uint8_t _padB5[3];                         // +0xB5
    framework::WUID m_relationTargetWuid;           // +0xB8, relation index 0x1C; name OPEN
    bool m_triggerAreaRegistered;                   // +0xC0, name reconstructed
    std::uint8_t _padC1[7];                         // +0xC1
    C_TriggerArea* m_pTriggerArea;                  // +0xC8, borrowed
    bool m_daySignalConnected;                      // +0xD0, name reconstructed
    std::uint8_t _padD1[7];                         // +0xD1
    shared::C_Signal<> m_onRespawnReady;            // +0xD8, name reconstructed
};

static_assert(sizeof(C_AnimalSpawner) == 0xE8,
              "C_AnimalSpawner must be 0xE8");
static_assert(offsetof(C_AnimalSpawner, m_onReturningToPool) == 0x60,
              "return-to-pool signal must be at 0x60");
static_assert(offsetof(C_AnimalSpawner, m_animalStates) == 0x70,
              "animal state vector must be at 0x70");
static_assert(offsetof(C_AnimalSpawner, m_active) == 0x88,
              "active flag must be at 0x88");
static_assert(offsetof(C_AnimalSpawner, m_spawnPosition) == 0x8C,
              "spawn position must be at 0x8C");
static_assert(offsetof(C_AnimalSpawner, m_soulGuid) == 0x98,
              "soul GUID must be at 0x98");
static_assert(offsetof(C_AnimalSpawner, m_entityClass) == 0xA8,
              "entity class must be at 0xA8");
static_assert(offsetof(C_AnimalSpawner, m_respawnDays) == 0xB0,
              "respawn days must be at 0xB0");
static_assert(offsetof(C_AnimalSpawner, m_spawnInFlock) == 0xB4,
              "spawn-in-flock flag must be at 0xB4");
static_assert(offsetof(C_AnimalSpawner, m_relationTargetWuid) == 0xB8,
              "relation-target WUID must be at 0xB8");
static_assert(offsetof(C_AnimalSpawner, m_triggerAreaRegistered) == 0xC0,
              "trigger-area registration flag must be at 0xC0");
static_assert(offsetof(C_AnimalSpawner, m_pTriggerArea) == 0xC8,
              "trigger area pointer must be at 0xC8");
static_assert(offsetof(C_AnimalSpawner, m_daySignalConnected) == 0xD0,
              "day-signal flag must be at 0xD0");
static_assert(offsetof(C_AnimalSpawner, m_onRespawnReady) == 0xD8,
              "respawn-ready signal must be at 0xD8");

}  // namespace wh::xgenaimodule
