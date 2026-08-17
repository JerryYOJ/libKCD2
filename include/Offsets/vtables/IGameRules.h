#pragma once
#include <cstddef>
#include <cstdint>
#include "IGameObjectExtension.h"
#include "XmlNodeRef.h"
#include "../../crysystem/EChatMessageType.h"
#include "../../crysystem/EGameResourceType.h"
#include "../../crysystem/ETextMessageType.h"

typedef unsigned int EntityId;
enum EDisconnectionCause : int;
class IHitListener;
struct EventPhys;
struct HitInfo;
struct INetChannel;

namespace Offsets {

class IActor;

// Current 36-slot KCD2 IGameRules tail. Removed historical vehicle/collision
// callbacks are intentionally absent.
class IGameRules : public IGameObjectExtension {
public:
    virtual bool ShouldKeepClient(int channelId,
                                  EDisconnectionCause cause,
                                  const char* description) const = 0; // [29]
    virtual void PrecacheLevel() = 0; // [30]
    virtual void PrecacheLevelResource(const char* resourceName,
                                       EGameResourceType resourceType) = 0; // [31]
    virtual ::XmlNodeRef FindPrecachedXmlFile(const char* filename) = 0; // [32]
    virtual void OnConnect(INetChannel* netChannel) = 0; // [33]
    virtual void OnDisconnect(EDisconnectionCause cause,
                              const char* description) = 0; // [34]
    virtual bool OnClientConnect(int channelId, bool isReset) = 0; // [35]
    virtual void OnClientDisconnect(int channelId,
                                    EDisconnectionCause cause,
                                    const char* description,
                                    bool keepClient) = 0; // [36]
    virtual bool OnClientEnteredGame(int channelId, bool isReset) = 0; // [37]
    virtual void OnEntitySpawn(IEntity* entity) = 0; // [38]
    virtual void OnEntityRemoved(IEntity* entity) = 0; // [39]
    virtual void OnEntityReused(IEntity* entity,
                                SEntitySpawnParams& params,
                                EntityId previousId) = 0; // [40]
    virtual void SendTextMessage(ETextMessageType type,
                                 const char* message,
                                 std::uint32_t to,
                                 int channelId,
                                 const char* p0,
                                 const char* p1,
                                 const char* p2,
                                 const char* p3) = 0; // [41]
    virtual void SendChatMessage(EChatMessageType type,
                                 EntityId sourceId,
                                 EntityId targetId,
                                 const char* message) = 0; // [42]
    virtual void ClientHit(const HitInfo& hitInfo) = 0; // [43]
    virtual void ServerHit(const HitInfo& hitInfo) = 0; // [44]
    virtual int GetHitTypeIdByName(const char* type) const = 0; // [45]
    virtual int GetHitTypeIdByCrc(std::uint32_t crc) const = 0; // [46]
    virtual const char* GetHitType(int id) const = 0; // [47]
    virtual void CreateEntityRespawnData(EntityId entityId) = 0; // [48]
    virtual bool HasEntityRespawnData(EntityId entityId) const = 0; // [49]
    virtual void ScheduleEntityRespawn(EntityId entityId,
                                       bool unique,
                                       float timer) = 0; // [50]
    virtual void AbortEntityRespawn(EntityId entityId,
                                    bool destroyData) = 0; // [51]
    virtual void ScheduleEntityRemoval(EntityId entityId,
                                       float timer,
                                       bool visibility) = 0; // [52]
    virtual void AbortEntityRemoval(EntityId entityId) = 0; // [53]
    virtual void AddHitListener(IHitListener* listener) = 0; // [54]
    virtual void RemoveHitListener(IHitListener* listener) = 0; // [55]
    virtual bool IsFrozen(EntityId entityId) const = 0; // [56]
    virtual void OnCollision_NotifyAI(const EventPhys* event) = 0; // [57]
    virtual void ShowStatus() = 0; // [58]
    virtual bool IsTimeLimited() const = 0; // [59]
    virtual float GetRemainingGameTime() const = 0; // [60]
    virtual void SetRemainingGameTime(float seconds) = 0; // [61]
    virtual void ClearAllMigratingPlayers() = 0; // [62]
    virtual EntityId SetChannelForMigratingPlayer(
        const char* name,
        std::uint16_t channelId) = 0; // [63]
    virtual void StoreMigratingPlayer(IActor* actor) = 0; // [64]
};
static_assert(sizeof(IGameRules) == 0x40,
              "IGameRules must preserve the 0x40 extension prefix");

}  // namespace Offsets
