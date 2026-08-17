#pragma once
#include <cstddef>
#include <cstdint>
#include <deque>
#include <map>
#include <vector>
#include "../CryEngine/CryAction/IHitListener.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../CryEngine/CryCommon/TimeValue.h"
#include "../Offsets/SmartScriptTable.h"
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IActionListener.h"
#include "../Offsets/vtables/IActor.h"
#include "../Offsets/vtables/IActorSystem.h"
#include "../Offsets/vtables/IEntitySystem.h"
#include "../Offsets/vtables/IGameFramework.h"
#include "../Offsets/vtables/IGameRules.h"
#include "../Offsets/vtables/IScriptSystem.h"
#include "../Offsets/vtables/ISystem.h"
#include "../Offsets/vtables/IViewSystemListener.h"
#include "ExplosionInfo.h"
#include "HitInfo.h"
#include "SCutsceneCameraAudioController.h"
#include "SEntityRemovalData.h"
#include "SEntityRespawn.h"
#include "SEntityRespawnData.h"
#include "SExpandedHitRecord.h"
#include "SGameRulesListener.h"
#include "SGameRulesOpaqueWord.h"
#include "SMinimapEntity.h"

class IEntityClassRegistry;
struct IEntityClass;
struct IAnimSequence;
struct INetChannel;
struct SCameraParams;

class CGameRules
    : public Offsets::CGameObjectExtensionHelper<
          CGameRules,
          Offsets::IGameRules,
          64>
    , public Offsets::IActionListener
    , public Offsets::IViewSystemListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_CGameRules;

    CGameRules();
    ~CGameRules() override; // [0]
    void ProcessEvent(SEntityEvent& event) override; // [1]
    bool _vf2() override; // [2]
    int GetEventPriority(int eventId) override; // [3]
    void _vf4() override; // [4]
    Offsets::IEntity* GetEntity() override; // [5]
    void GetMemoryUsage(ICrySizer* sizer) const override; // [6]
    bool Init(Offsets::IGameObject* gameObject) override; // [7]
    void PostInit(Offsets::IGameObject* gameObject) override; // [8]
    void InitClient(int channelId) override; // [9]
    void PostInitClient(int channelId) override; // [10]
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override; // [11]
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12]
    bool GetEntityPoolSignature(TSerialize signature) override; // [13]
    void Release() override; // [14]
    void FullSerialize(TSerialize serializer) override; // [15]
    bool NetSerialize(TSerialize serializer,
                      EEntityAspects aspect,
                      std::uint8_t profile,
                      int flags) override; // [16]
    bool _vf17() override; // [17]
    NetworkAspectType GetNetSerializeAspects() override; // [18]
    void PostSerialize() override; // [19]
    void SerializeSpawnInfo(TSerialize serializer) override; // [20]
    ISerializableInfoPtr GetSpawnInfo() override; // [21]
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22]
    void HandleEvent(const SGameObjectEvent& event) override; // [23]
    void SetChannelId(std::uint16_t id) override; // [24]
    void SetAuthority(bool authoritative) override; // [25]
    const void* GetRMIBase() const override; // [26]
    void PostUpdate(float frameTime) override; // [27]
    void PostRemoteSpawn() override; // [28]

    bool ShouldKeepClient(int channelId,
                          EDisconnectionCause cause,
                          const char* description) const override; // [29]
    void PrecacheLevel() override; // [30]
    void PrecacheLevelResource(const char* resourceName,
                               EGameResourceType resourceType) override; // [31]
    XmlNodeRef FindPrecachedXmlFile(const char* filename) override; // [32]
    void OnConnect(INetChannel* netChannel) override; // [33]
    void OnDisconnect(EDisconnectionCause cause,
                      const char* description) override; // [34]
    bool OnClientConnect(int channelId, bool isReset) override; // [35]
    void OnClientDisconnect(int channelId,
                            EDisconnectionCause cause,
                            const char* description,
                            bool keepClient) override; // [36]
    bool OnClientEnteredGame(int channelId, bool isReset) override; // [37]
    void OnEntitySpawn(Offsets::IEntity* entity) override; // [38]
    void OnEntityRemoved(Offsets::IEntity* entity) override; // [39]
    void OnEntityReused(Offsets::IEntity* entity,
                        SEntitySpawnParams& params,
                        EntityId previousId) override; // [40]
    void SendTextMessage(ETextMessageType type,
                         const char* message,
                         std::uint32_t to,
                         int channelId,
                         const char* p0,
                         const char* p1,
                         const char* p2,
                         const char* p3) override; // [41]
    void SendChatMessage(EChatMessageType type,
                         EntityId sourceId,
                         EntityId targetId,
                         const char* message) override; // [42]
    void ClientHit(const HitInfo& hitInfo) override; // [43]
    void ServerHit(const HitInfo& hitInfo) override; // [44]
    int GetHitTypeIdByName(const char* type) const override; // [45]
    int GetHitTypeIdByCrc(std::uint32_t crc) const override; // [46]
    const char* GetHitType(int id) const override; // [47]
    void CreateEntityRespawnData(EntityId entityId) override; // [48]
    bool HasEntityRespawnData(EntityId entityId) const override; // [49]
    void ScheduleEntityRespawn(EntityId entityId,
                               bool unique,
                               float timer) override; // [50]
    void AbortEntityRespawn(EntityId entityId,
                            bool destroyData) override; // [51]
    void ScheduleEntityRemoval(EntityId entityId,
                               float timer,
                               bool visibility) override; // [52]
    void AbortEntityRemoval(EntityId entityId) override; // [53]
    void AddHitListener(IHitListener* listener) override; // [54]
    void RemoveHitListener(IHitListener* listener) override; // [55]
    bool IsFrozen(EntityId entityId) const override; // [56]
    void OnCollision_NotifyAI(const EventPhys* event) override; // [57]
    void ShowStatus() override; // [58]
    bool IsTimeLimited() const override; // [59]
    float GetRemainingGameTime() const override; // [60]
    void SetRemainingGameTime(float seconds) override; // [61]
    void ClearAllMigratingPlayers() override; // [62]
    EntityId SetChannelForMigratingPlayer(
        const char* name,
        std::uint16_t channelId) override; // [63]
    void StoreMigratingPlayer(Offsets::IActor* actor) override; // [64]

    virtual const char* GetTeamName(std::int32_t teamId) const; // [65]
    virtual void OnItemDropped(EntityId actorId, EntityId itemId); // [66]
    virtual void OnItemPickedUp(EntityId actorId, EntityId itemId); // [67]
    virtual bool unk_68(std::uintptr_t unusedRdx,
                        EntityId first,
                        EntityId second); // [68]
    virtual void unk_69_LAYOUT_ONLY(); // [69], arguments/return role OPEN
    virtual void ResetGameTime(); // [70]
    virtual bool unk_71_LAYOUT_ONLY(); // [71], scalar return class OPEN
    virtual void ResetRoundTime(); // [72]
    virtual float GetRemainingRoundTime() const; // [73]
    virtual bool IsRoundTimeLimited() const; // [74]
    virtual void ResetPreRoundTime(); // [75]
    virtual float GetRemainingPreRoundTime() const; // [76]
    virtual void ResetReviveCycleTime(); // [77]
    virtual float GetRemainingReviveCycleTime() const; // [78]
    virtual void ResetGameStartTimer(float seconds); // [79]
    virtual float GetRemainingStartTimer() const; // [80]
    virtual void RegisterConsoleCommands(); // [81]
    virtual void UnregisterConsoleCommands(); // [82]
    virtual void unk_83_LAYOUT_ONLY(); // [83]
    virtual void unk_84_LAYOUT_ONLY(); // [84], script revive dispatch; arity OPEN
    virtual void unk_85_LAYOUT_ONLY(); // [85], script kill dispatch; arity OPEN
    virtual void OnTextMessage(ETextMessageType type,
                               const char* message); // [86]
    virtual void unk_87_LAYOUT_ONLY(); // [87]
    virtual Offsets::IActor* GetActorByChannelId(std::uint16_t channelId); // [88]
    virtual Offsets::IActor* GetActorByEntityId(EntityId entityId); // [89]
    virtual EntityId ResolveActorEntityId(EntityId entityId) const; // [90]
    virtual EntityId GetActorEntityId(Offsets::IActor* actor) const; // [91]
    virtual std::uint16_t GetChannelId(EntityId entityId) const; // [92]
    virtual Offsets::IActor* SpawnPlayer(std::uint16_t channelId,
                                         const char* requestedName,
                                         const char* className,
                                         const Vec3& position,
                                         const Ang3& angles); // [93]
    virtual Offsets::IActor* ChangePlayerClass(std::uint16_t channelId,
                                               const char* className); // [94]
    virtual void RevivePlayer(Offsets::IActor* actor,
                              const Vec3& position,
                              const Ang3& angles,
                              std::int32_t teamId,
                              bool clearInventory); // [95]
    virtual void RenamePlayer(Offsets::IActor* actor,
                              const char* requestedName); // [96]
    virtual CryStringT<char> VerifyName(const char* name,
                                        Offsets::IEntity* excludedEntity); // [97]
    virtual bool IsNameTaken(const char* name,
                             Offsets::IEntity* excludedEntity) const; // [98]
    virtual void unk_99(Offsets::IActor* actor,
                        std::uintptr_t unusedR8,
                        bool doRagdoll,
                        std::uintptr_t unusedStack28,
                        EntityId entityId); // [99]
    virtual void MovePlayer(Offsets::IActor* actor,
                            const Vec3& position,
                            const Quat& orientation); // [100]
    virtual void ChangeTeamByName(Offsets::IActor* actor,
                                  const char* teamName); // [101]
    virtual void DispatchChangeTeam(Offsets::IActor* actor,
                                    std::int32_t teamId); // [102]
    virtual void OnAddTaggedEntity(EntityId entityId,
                                   std::int32_t tag); // [103]
    virtual std::int32_t GetPlayerCount(bool inGameOnly) const; // [104]
    virtual EntityId GetPlayerByIndex(std::int32_t index) const; // [105]
    virtual void GetPlayers(std::vector<EntityId>& out) const; // [106]
    virtual bool IsPlayerInGame(EntityId playerId) const; // [107]
    virtual bool IsPlayerActivelyPlaying(EntityId playerId,
                                         bool mustBeAlive) const; // [108]
    virtual bool IsChannelInGame(std::uint16_t channelId) const; // [109]
    virtual std::int32_t CreateTeam(const char* name); // [110]
    virtual void RemoveTeam(std::int32_t teamId); // [111]
    virtual std::int32_t GetTeamId(const char* name) const; // [112]
    virtual std::int32_t GetTeamCount() const; // [113]
    virtual std::int32_t GetTeamPlayerCount(std::int32_t teamId,
                                            bool inGameOnly) const; // [114]
    virtual std::int32_t GetTeamChannelCount(std::int32_t teamId,
                                             bool inGameOnly) const; // [115]
    virtual EntityId GetTeamPlayerByIndex(std::int32_t teamId,
                                          std::int32_t index) const; // [116]
    virtual void GetTeamPlayers(std::int32_t teamId,
                                std::vector<EntityId>& out) const; // [117]
    virtual void SetTeam(std::int32_t teamId, EntityId entityId); // [118]
    virtual std::int32_t GetTeam(EntityId entityId) const; // [119]
    virtual std::int32_t GetChannelTeam(std::int32_t channelId) const; // [120]
    virtual std::int32_t AddSpawnGroup(const char* entityClassName); // [121]
    virtual std::int32_t GetSpawnGroupId(
        const char* entityClassName) const; // [122]
    virtual IEntityClass* GetSpawnGroupEntityClass(
        std::int32_t spawnGroupId) const; // [123]
    virtual std::int32_t GetSpawnGroupIdByEntityClassId(
        std::uint16_t classId) const; // [124]
    virtual void ClearSpawnGroups(); // [125]
    virtual std::int32_t RegisterHitType(const char* name); // [126]
    virtual void ClearHitTypes(); // [127]
    virtual void AddSpawnLocation(EntityId entityId); // [128]
    virtual void RemoveSpawnLocation(EntityId entityId); // [129]
    virtual std::int32_t GetSpawnLocationCount() const; // [130]
    virtual EntityId GetSpawnLocation(EntityId playerId,
                                      bool ignoreTeam,
                                      bool includeNeutral,
                                      EntityId groupId,
                                      float minimumDistance,
                                      const Vec3* referencePosition,
                                      float* outFallbackValue); // [131]
    virtual EntityId GetSpawnLocationByIdx(std::int32_t index) const; // [132]
    virtual void GetSpawnLocations(std::vector<EntityId>& out) const; // [133]
    virtual bool unk_134(EntityId playerId,
                         EntityId spawnLocationId,
                         float radius,
                         bool unusedFilter,
                         float secondaryDistance); // [134]
    virtual bool unk_135(EntityId locationId,
                         float minimumDistance,
                         const Vec3* referencePosition); // [135]
    virtual bool unk_136(EntityId spawnLocationId,
                         EntityId ignoredEntityId,
                         float verticalOffset,
                         float rayLength); // [136]
    virtual EntityId GetFirstSpawnLocation(std::int32_t teamId,
                                           std::int32_t groupId) const; // [137]
    virtual void AddSpawnLocationGroup(std::int32_t groupId); // [138]
    virtual void AddSpawnLocationToSpawnGroup(std::int32_t groupId,
                                              EntityId locationId); // [139]
    virtual void RemoveSpawnLocationFromSpawnGroup(std::int32_t groupId,
                                                   EntityId locationId); // [140]
    virtual void RemoveSpawnLocationGroup(std::int32_t groupId); // [141]
    virtual std::int32_t GetSpawnLocationGroup(EntityId locationId) const; // [142]
    virtual std::int32_t GetSpawnGroupCount() const; // [143]
    virtual std::int32_t GetSpawnGroupByIdx(std::int32_t index) const; // [144]
    virtual void GetSpawnGroups(std::vector<std::int32_t>& out) const; // [145]
    virtual bool IsSpawnGroup(std::int32_t groupId) const; // [146]
    virtual void RequestSpawnGroup(std::int32_t groupId); // [147]
    virtual void DispatchSetPlayerSpawnGroup(std::int32_t first,
                                             std::int32_t second); // [148]
    virtual std::int32_t DispatchGetPlayerSpawnGroup(
        Offsets::IActor* actor); // [149]
    virtual void SetPlayerSpawnGroup(EntityId playerId,
                                     std::int32_t spawnGroupId); // [150]
    virtual std::int32_t GetPlayerSpawnGroup(EntityId playerId) const; // [151]
    virtual void OnSpawnGroupInvalid(std::int32_t spawnGroupId); // [152]
    virtual void ResetMinimap(); // [153]
    virtual void UpdateMinimap(float frameTime); // [154]
    virtual void AddMinimapEntity(EntityId entityId,
                                  std::int32_t type,
                                  float lifetime); // [155]
    virtual void RemoveMinimapEntity(EntityId entityId); // [156]
    virtual const std::vector<SMinimapEntity>& GetMinimapEntities() const; // [157]
    virtual void Restart(); // [158]
    virtual void Reset(); // [159]
    virtual void ActivateGameModeScriptState_OPEN(); // [160]
    virtual void EnteredGame(); // [161]
    virtual void GameOver(std::int32_t localWinner); // [162]
    virtual void EndGameNear(EntityId id); // [163]
    virtual void ProcessHit(const HitInfo& hitInfo); // [164]
    virtual void AddExpandedHitRecord(const SExpandedHitRecord& record); // [165]
    virtual void UpdateEntityRespawnAndRemoval(float frameTime); // [166]
    virtual void unk_167_LAYOUT_ONLY(); // [167]
    virtual void ClearKeyState(); // [168]
    virtual bool unk_169_LAYOUT_ONLY(); // [169]
    virtual void unk_170_LAYOUT_ONLY(); // [170]
    virtual void AddGameRulesListener(SGameRulesListener* listener); // [171]
    virtual void RemoveGameRulesListener(SGameRulesListener* listener); // [172]
    virtual void HitInfoToScriptTable(Offsets::SmartScriptTable& table,
                                      const HitInfo& hitInfo); // [173]
    virtual void ExpandedHitRecordToScriptTable(
        Offsets::SmartScriptTable& table,
        const SExpandedHitRecord& record); // [174]
    virtual void ScriptTableToHitInfo(Offsets::SmartScriptTable& table,
                                      HitInfo& hitInfo); // [175]

    void OnAction(const Offsets::SActionId& action,
                  int activationMode,
                  float value) override; // action [1]
    bool OnBeginCutScene(IAnimSequence* sequence, bool resetFx) override; // view [1]
    bool OnEndCutScene(IAnimSequence* sequence) override; // view [2]
    bool OnCameraChange(const SCameraParams& cameraParams) override; // view [3]

    Offsets::IGameFramework* m_pGameFramework; // +0x050, borrowed
    Offsets::ISystem* m_pSystem; // +0x058, borrowed
    Offsets::IActorSystem* m_pActorSystem; // +0x060, borrowed
    Offsets::IEntitySystem* m_pEntitySystem; // +0x068, borrowed
    Offsets::IScriptSystem* m_pScriptSystem; // +0x070, borrowed
    IEntityClassRegistry* m_pEntityClassRegistry; // +0x078, borrowed
    Offsets::SmartScriptTable m_script; // +0x080
    Offsets::SmartScriptTable m_clientScript; // +0x088
    Offsets::SmartScriptTable m_serverScript; // +0x090
    Offsets::SmartScriptTable m_clientScriptCache; // +0x098
    Offsets::SmartScriptTable m_serverScriptCache; // +0x0A0
    HSCRIPTFUNCTION m_onCollision; // +0x0A8
    Offsets::SmartScriptTable m_scratchTable; // +0x0B0
    Offsets::SmartScriptTable m_openB8; // +0x0B8
    Offsets::SmartScriptTable m_openC0; // +0x0C0
    INetChannel* m_pNetChannel; // +0x0C8, borrowed
    std::vector<EntityId> m_players; // +0x0D0
    std::map<CryStringT<char>, std::int32_t> m_teamNameToId; // +0x0E8
    std::map<EntityId, std::int32_t> m_entityToTeam; // +0x0F8
    std::map<EntityId, std::int32_t> m_entityToSpawnGroup; // +0x108
    std::map<std::int32_t, std::vector<EntityId>> m_teamPlayers; // +0x118
    std::map<std::int32_t, std::int32_t> m_channelToTeam; // +0x128
    std::int32_t m_nextTeamId; // +0x138
    std::map<std::int32_t, std::uint16_t> m_spawnGroupClasses; // +0x140
    std::int32_t m_nextSpawnGroupId; // +0x150
    std::map<std::int32_t, CryStringT<char>> m_hitTypes; // +0x158
    std::int32_t m_nextHitTypeId; // +0x168
    Offsets::SmartScriptTable m_hitScriptTable; // +0x170
    Offsets::SmartScriptTable m_explosionScriptTable; // +0x178
    std::deque<ExplosionInfo> m_explosions; // +0x180
    std::deque<HitInfo> m_queuedHits; // +0x1A8
    std::int32_t m_hitProcessingDepth; // +0x1D0
    std::vector<SExpandedHitRecord> m_expandedHitHistory; // +0x1D8
    std::map<EntityId, SEntityRespawnData> m_respawnData; // +0x1F0
    std::map<EntityId, SScheduledRespawn> m_scheduledRespawns; // +0x200
    std::map<EntityId, SScheduledRemoval> m_scheduledRemovals; // +0x210
    std::vector<SMinimapEntity> m_minimapEntities; // +0x220
    std::map<std::int32_t,
             std::map<CryStringT<char>, std::int32_t>> m_open238; // +0x238
    std::vector<EntityId> m_defaultSpawnLocations; // +0x248
    std::map<std::int32_t,
             std::vector<EntityId>> m_spawnGroupLocations; // +0x260
    std::vector<SGameRulesOpaqueWord> m_open270; // +0x270
    std::uint32_t m_eventPayload25; // +0x288
    std::vector<IHitListener*> m_hitListeners; // +0x290, borrowed elements
    CTimeValue m_gameDeadline; // +0x2A8
    CTimeValue m_roundDeadline; // +0x2B0
    CTimeValue m_preRoundDeadline; // +0x2B8
    CTimeValue m_reviveCycleDeadline; // +0x2C0
    CTimeValue m_gameStartDeadline; // +0x2C8
    std::vector<SGameRulesListener*> m_gameRulesListeners; // +0x2D0, borrowed elements
    std::uint32_t m_open2E8; // +0x2E8
    bool m_netSerializeFirstSend; // +0x2EC
    bool m_isOutsideCutscene; // +0x2ED
    std::byte m_pad2EE[0x02]; // +0x2EE
    SCutsceneCameraAudioController m_cutsceneController; // +0x2F0
};
static_assert(sizeof(CGameRules) == 0x348,
              "CGameRules must be 0x348");
static_assert(offsetof(CGameRules, m_pGameFramework) == 0x50,
              "game-rules services must begin at 0x50");
static_assert(offsetof(CGameRules, m_script) == 0x80,
              "game-rules script table must be at 0x80");
static_assert(offsetof(CGameRules, m_players) == 0xD0,
              "game-rules players must be at 0xD0");
static_assert(offsetof(CGameRules, m_hitScriptTable) == 0x170,
              "game-rules hit script table must be at 0x170");
static_assert(offsetof(CGameRules, m_expandedHitHistory) == 0x1D8,
              "game-rules expanded-hit history must be at 0x1D8");
static_assert(offsetof(CGameRules, m_minimapEntities) == 0x220,
              "game-rules minimap entities must be at 0x220");
static_assert(offsetof(CGameRules, m_hitListeners) == 0x290,
              "game-rules hit listeners must be at 0x290");
static_assert(offsetof(CGameRules, m_gameRulesListeners) == 0x2D0,
              "game-rules listeners must be at 0x2D0");
static_assert(offsetof(CGameRules, m_cutsceneController) == 0x2F0,
              "game-rules cutscene controller must be at 0x2F0");
