#pragma once
#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include "../Offsets/vtables/IEntity.h"
#include "../framework/I_WUIDMappingProvider.h"
#include "../framework/S_MulticastDelegateStorage.h"

namespace wh::xgenaimodule {

class C_AreaUnion;

// AreaUnion registry and WUID provider. Both maps are non-owning indexes; each
// C_AreaUnionExtension controls the lifetime of its runtime object.
class C_AreaUnionManager : public framework::I_WUIDMappingProvider {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_AreaUnionManager;

    static C_AreaUnionManager* GetInstance();
    C_AreaUnion* Create(Offsets::IEntity* entity);

    framework::WUID GetWuidForKey(const CryGUID& key) const override; // [0] 0x183281B60
    CryGUID GetValueForWuid(framework::WUID wuid) const override;     // [1] 0x183281B18
    virtual ~C_AreaUnionManager();                                    // [2] 0x1832805C8
    virtual C_AreaUnion* FindByWuid(const framework::WUID& wuid);     // [3] 0x18154CF4C

    shared::S_MulticastDelegateStorage m_removalObservers;            // +0x08
    std::uint64_t m_currentIdentity;                                  // +0x18
    std::uint64_t m_reservedIdentity;                                 // +0x20, exact source role OPEN
    bool m_skipReservedIdentity;                                      // +0x28
    std::uint8_t _pad29[7];                                           // +0x29
    std::unordered_map<framework::WUID, C_AreaUnion*> m_byWuid;       // +0x30, non-owning
    std::unordered_map<EntityGUID, C_AreaUnion*> m_byEntityGuid;      // +0x70, non-owning
};
static_assert(sizeof(C_AreaUnionManager) == 0xB0,
              "C_AreaUnionManager must be 0xB0");
static_assert(offsetof(C_AreaUnionManager, m_removalObservers) == 0x08,
              "removal observers must be at 0x08");
static_assert(offsetof(C_AreaUnionManager, m_currentIdentity) == 0x18,
              "AreaUnion identity counter must be at 0x18");
static_assert(offsetof(C_AreaUnionManager, m_byWuid) == 0x30,
              "WUID index must be at 0x30");
static_assert(offsetof(C_AreaUnionManager, m_byEntityGuid) == 0x70,
              "EntityGUID index must be at 0x70");

}  // namespace wh::xgenaimodule
