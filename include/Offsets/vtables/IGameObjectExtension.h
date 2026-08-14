#pragma once
#include <cstddef>
#include <cstdint>
#include "IComponent.h"
#include "../../CryEngine/CryAction/GameObjectTypes.h"
#include "../../CryEngine/CryCommon/SerializeFwd.h"

class ICrySizer;
template <class T>
class _smart_ptr;
struct ISerializableInfo;
using ISerializableInfoPtr = _smart_ptr<ISerializableInfo>;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;

namespace Offsets {

struct IGameObject;

// KCD2 binary-facing CryEngine game-object extension base. Slot 17 is a
// Warhorse addition; its exact source name remains open.
class IGameObjectExtension : public IComponent {
public:
    virtual void GetMemoryUsage(ICrySizer* sizer) const = 0;             // [6]
    virtual bool Init(IGameObject* gameObject) = 0;                     // [7]
    virtual void PostInit(IGameObject* gameObject) = 0;                 // [8]
    virtual void InitClient(int channelId) = 0;                         // [9]
    virtual void PostInitClient(int channelId) = 0;                     // [10]
    virtual bool ReloadExtension(IGameObject* gameObject,
                                 const SEntitySpawnParams& params) = 0; // [11]
    virtual void PostReloadExtension(IGameObject* gameObject,
                                     const SEntitySpawnParams& params) = 0; // [12]
    virtual bool GetEntityPoolSignature(TSerialize signature) = 0;     // [13]
    virtual void Release() = 0;                                        // [14]
    virtual void FullSerialize(TSerialize serializer) = 0;             // [15]
    virtual bool NetSerialize(TSerialize serializer,
                              EEntityAspects aspect,
                              std::uint8_t profile,
                              int flags) = 0;                           // [16]
    virtual bool _vf17() = 0;                                          // [17], name/role OPEN
    virtual NetworkAspectType GetNetSerializeAspects() = 0;            // [18]
    virtual void PostSerialize() = 0;                                  // [19]
    virtual void SerializeSpawnInfo(TSerialize serializer) = 0;        // [20]
    virtual ISerializableInfoPtr GetSpawnInfo() = 0;                   // [21]
    virtual void Update(SEntityUpdateContext& context, int updateSlot) = 0; // [22]
    virtual void HandleEvent(const SGameObjectEvent& event) = 0;       // [23]
    virtual void SetChannelId(std::uint16_t id) = 0;                   // [24]
    virtual void SetAuthority(bool authoritative) = 0;                 // [25]
    virtual const void* GetRMIBase() const = 0;                        // [26]
    virtual void PostUpdate(float frameTime) = 0;                      // [27]
    virtual void PostRemoteSpawn() = 0;                                // [28]

    IGameObject* m_pGameObject; // +0x28, borrowed
    std::uint32_t m_entityId;   // +0x30
    std::uint32_t _pad34;       // +0x34
    IEntity* m_pEntity;         // +0x38, borrowed
};
static_assert(sizeof(IGameObjectExtension) == 0x40,
              "IGameObjectExtension must be 0x40");
static_assert(offsetof(IGameObjectExtension, m_pGameObject) == 0x28,
              "game object must be at 0x28");
static_assert(offsetof(IGameObjectExtension, m_pEntity) == 0x38,
              "entity must be at 0x38");

}  // namespace Offsets
