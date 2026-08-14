#pragma once
#include <cstddef>
#include <cstdint>
#include <functional>
#include "../Offsets/SmartScriptTable.h"
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IItem.h"
#include "../Offsets/vtables/IGameObjectProfileManager.h"
#include "../cry3dengine/I_MaterialInstance.h"
#include "../framework/C_Signal.h"
#include "../framework/CryDeferrable.h"

// -----------------------------------------------
// wh::entitymodule::C_PickableItem -- base world-item extension
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0xD8.
// -----------------------------------------------
// Primary vtable 0x183EC85E0 has exactly 130 slots [0..129]; secondary
// IGameObjectProfileManager vtable 0x183EC85A8 has six slots. Ctor 0x1803F08EC,
// complete dtor 0x1808DFF78, allocation witness 0x180705E60 (0xD8).
// Class-owned slots [85..129] are all present below. Signatures on indexed OPEN
// slots are conservative replicas; do not call them until their parameter types are certified.

namespace wh::entitymodule {

class C_Item;

class C_PickableItem
    : public Offsets::CGameObjectExtensionHelper<
          C_PickableItem,
          Offsets::IItem,
          64>
    , public Offsets::IGameObjectProfileManager
    , public UnsafeOp::CryDeferrable<0> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PickableItem;

    ~C_PickableItem() override;                                      // [0] 0x1808DFEBC
    void ProcessEvent(SEntityEvent& event) override;                 // [1] 0x180EC4330
    bool _vf2() override;                                            // [2] 0x180838AE0
    int GetEventPriority(int eventId) override;                      // [3] 0x181A74280
    void _vf4() override;                                            // [4] nullsub_1
    Offsets::IEntity* GetEntity() override;                          // [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;            // [6] nullsub_1
    bool Init(Offsets::IGameObject* gameObject) override;            // [7] 0x180706048
    void PostInit(Offsets::IGameObject* gameObject) override;        // [8] nullsub_1
    void InitClient(int channelId) override;                         // [9] nullsub_1
    void PostInitClient(int channelId) override;                     // [10] nullsub_1
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override; // [11] 0x180838AE0
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12] nullsub_1
    bool GetEntityPoolSignature(TSerialize signature) override;     // [13] 0x180838AE0
    void Release() override;                                        // [14] 0x1803A5684
    void FullSerialize(TSerialize serializer) override;             // [15] 0x182A89A88
    bool NetSerialize(TSerialize serializer,
                      EEntityAspects aspect,
                      std::uint8_t profile,
                      int flags) override;                           // [16] 0x180838AE0
    bool _vf17() override;                                           // [17] 0x180838AE0
    NetworkAspectType GetNetSerializeAspects() override;             // [18] 0x181A72600
    void PostSerialize() override;                                   // [19] nullsub_1
    void SerializeSpawnInfo(TSerialize serializer) override;        // [20] nullsub_1
    ISerializableInfoPtr GetSpawnInfo() override;                    // [21] 0x1823CA690
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22] 0x182A8B978
    void HandleEvent(const SGameObjectEvent& event) override;        // [23] nullsub_1
    void SetChannelId(std::uint16_t id) override;                    // [24] nullsub_1
    void SetAuthority(bool authoritative) override;                  // [25] nullsub_1
    void PostUpdate(float frameTime) override;                       // [27] nullsub_1
    void PostRemoteSpawn() override;                                 // [28] nullsub_1

    const char* GetType() const override;                            // [29] 0x181A8AD50
    EntityId GetOwnerId() const override;                            // [30] 0x18066CD10
    void SetOwnerId(EntityId ownerId) override;                      // [31] nullsub_1
    void EnableUpdate(bool enable, int slot) override;               // [32] nullsub_1
    void RequireUpdate(int slot) override;                           // [33] nullsub_1
    void ForcePendingActions(std::uint8_t blockedActions) override;  // [34] nullsub_1
    void OnAction(EntityId actorId,
                  const Offsets::ActionId& actionId,
                  int activationMode,
                  float value) override;                             // [35] 0x182A8A640
    void OnParentSelect(bool select) override;                       // [36] nullsub_1
    void OnAttach(bool attach) override;                             // [37] nullsub_1
    void OnPickedUp(EntityId actorId, bool destroyed) override;      // [38] nullsub_1
    void OnHit(float damage, int hitType) override;                  // [39] nullsub_1
    void Select(bool select) override;                               // [40] 0x1814666C4
    bool IsSelected() const override;                                // [41] 0x182A69E88
    bool CanSelect() const override;                                 // [42] 0x18041A6A0
    bool CanDeselect() const override;                               // [43] 0x18041A6A0
    void RemoveOwnerAttachedAccessories() override;                  // [44] nullsub_1
    void Physicalize(bool enable, bool rigid) override;              // [45] 0x181F1BF20
    bool CanDrop() const override;                                   // [46] 0x18041A6A0
    void Drop(float impulseScale, bool selectNext, bool byDeath) override; // [47] 0x181466464
    void UpdateFPView(float frameTime) override;                     // [48] nullsub_1
    Vec3 GetMountedAngleLimits() const override;                     // [49] 0x1809F44F0
    void PickUp(EntityId picker,
                bool sound,
                bool select,
                bool keepHistory,
                const char* setup) override;                         // [50] 0x18143DCDC
    void MountAtEntity(EntityId entityId,
                       const Vec3& pos,
                       const Ang3& angles) override;                 // [51] nullsub_1
    bool FilterView(SViewParams& viewParams) override;               // [52] 0x18041A6A0
    void RemoveAllAccessories() override;                            // [53] nullsub_1
    void DetachAllAccessories() override;                            // [54] nullsub_1
    void AttachAccessory(IEntityClass* entityClass,
                         bool attach,
                         bool noAnimation,
                         bool force,
                         bool firstTimeAttached,
                         bool initialLoadoutSetup) override;          // [55] nullsub_1
    void SetCurrentActionController(IActionController* actionController) override; // [56] nullsub_1
    void UpdateCurrentActionController() override;                   // [57] nullsub_1
    CryStringT<char> GetAttachedAccessoriesString() override;        // [58] 0x1808D2480
    void SetHand(int hand) override;                                 // [59] nullsub_1
    void StartUse(EntityId userId) override;                         // [60] 0x1808DFF58
    void StopUse(EntityId userId) override;                          // [61] 0x181466644
    void SetBusy(bool busy) override;                                // [62] nullsub_1
    bool IsBusy() const override;                                    // [63] 0x180838AE0
    bool CanUse(EntityId userId) const override;                     // [64] 0x18143DC80
    bool IsUsed() const override;                                    // [65] 0x1823D09D8
    void Use(EntityId userId) override;                              // [66] 0x182A8BFD0
    bool AttachToHand(bool attach, bool checkAttachment) override;   // [67] 0x18041A6A0
    bool AttachToBack(bool attach) override;                         // [68] 0x18041A6A0
    bool _vf69(Offsets::IEntity* entity, std::uint16_t slot) override; // [69] 0x182A87DF8
    bool IsModifying() const override;                               // [70] 0x180838AE0
    bool CheckAmmoRestrictions(IInventory* inventory) override;      // [71] 0x180838AE0
    void Reset() override;                                           // [72] 0x180708B30
    bool ResetParams() override;                                     // [73] 0x18041A6A0
    void PreResetParams() override;                                  // [74] nullsub_1
    bool GivesAmmo() override;                                       // [75] 0x180838AE0
    const char* GetDisplayName() const override;                     // [76] 0x181A8AD00
    void HideItem(bool hide) override;                               // [77] nullsub_1
    void SetSubContextID(int tagContext) override;                   // [78] nullsub_1
    int GetSubContextID() override;                                  // [79] 0x18066CD10
    const IWeapon* GetIWeaponConst() const override;                 // [80] 0x18066CD10
    IWeapon* GetIWeaponMutable() override;                           // [81] 0x18066CD10
    bool IsAccessory() override;                                     // [82] 0x180838AE0
    void SerializeLTL(TSerialize serializer) override;               // [83] nullsub_1
    Vec3 GetMountedDir() const override;                             // [84] 0x18046B830

    virtual void _vf85();                                            // [85] nullsub_1, signature OPEN
    virtual void _vf86(bool enabled);                                // [86] 0x1808D037C
    virtual bool OnUsed(EntityId userId);                            // [87] 0x182A8A838
    virtual void _vf88(EntityId entityId, void* object, bool flag);  // [88] 0x181466538, object/flag roles OPEN
    virtual std::uint64_t _vf89();                                  // [89] 0x18066CD10, return identity OPEN
    virtual void _vf90();                                            // [90] nullsub_1, signature OPEN
    virtual bool CanSteal(EntityId userId);                          // [91] 0x182A88404
    virtual void OnSteal(EntityId userId);                          // [92] 0x182A8A7EC
    virtual bool _vf93(EntityId userId);                            // [93] 0x182A8B478, role OPEN
    virtual bool _vf94();                                            // [94] 0x182A8B534, role OPEN
    virtual void _vf95();                                            // [95] 0x1808E00CC, role OPEN
    virtual bool _vf96();                                            // [96] 0x180838AE0, signature OPEN
    virtual void _vf97();                                            // [97] nullsub_1, signature OPEN
    virtual std::uint64_t _vf98();                                  // [98] 0x18066CD10, return identity OPEN
    virtual std::uint64_t _vf99();                                  // [99] 0x18066CD10, return identity OPEN
    virtual std::uint64_t _vf100();                                 // [100] 0x18066CD10, return identity OPEN
    virtual void _vf101();                                           // [101] nullsub_1, signature OPEN
    virtual void _vf102();                                           // [102] nullsub_1, signature OPEN
    virtual bool _vf103();                                           // [103] 0x180838AE0, signature OPEN
    virtual bool _vf104();                                           // [104] 0x180838AE0, signature OPEN
    virtual bool _vf105();                                           // [105] 0x180838AE0, signature OPEN
    virtual void _vf106();                                           // [106] nullsub_1, signature OPEN
    virtual std::uint64_t _vf107();                                 // [107] 0x18066CD10, return identity OPEN
    virtual void _vf108();                                           // [108] 0x180708B78
    virtual void _vf109();                                           // [109] nullsub_1, signature OPEN
    virtual void _vf110();                                           // [110] nullsub_1, signature OPEN
    virtual void _vf111();                                           // [111] nullsub_1, signature OPEN
    virtual void _vf112();                                           // [112] nullsub_1, signature OPEN
    virtual void _vf113();                                           // [113] nullsub_1, signature OPEN
    virtual void _vf114();                                           // [114] nullsub_1, signature OPEN
    virtual void _vf115();                                           // [115] 0x180708B70
    virtual void _vf116();                                           // [116] nullsub_1
    virtual CryStringT<char> _vf117();                               // [117] 0x1808D2480, role OPEN
    virtual bool IsDestroyed();                                      // [118] 0x180838AE0
    virtual bool _vf119();                                           // [119] 0x18143DDC8
    virtual void _vf120(bool enabled);                               // [120] 0x18143DD80
    virtual bool _vf121(EntityId entityId);                          // [121] 0x18143DD9C, role OPEN
    virtual bool CanPickUp(EntityId userId);                         // [122] 0x18041A6A0
    virtual void _vf123();                                           // [123] nullsub_1, signature OPEN
    virtual void _vf124();                                           // [124] nullsub_1, signature OPEN
    virtual void _vf125();                                           // [125] nullsub_1, signature OPEN
    virtual void _vf126();                                           // [126] nullsub_1, signature OPEN
    virtual void _vf127();                                           // [127] nullsub_1, signature OPEN
    virtual C_Item* GetItem();                                       // [128] 0x181A7F820, returns m_pItem
    virtual std::uint32_t _vf129() const;                            // [129] 0x18066CD10, leaf discriminator (Pickable=0)

    bool SetAspectProfile(EEntityAspects aspect,
                          std::uint8_t profile) override;             // secondary [1] 0x180A5619C
    std::uint8_t GetDefaultProfile(EEntityAspects aspect) override;  // secondary [2] 0x182A89B64
    bool ProfileManagerUnk3() override;                              // secondary [3] 0x180838AE0
    void ConnectProfileChanged(
        const Offsets::S_ProfileChangedDelegate& delegate) override; // secondary [4] 0x18295D160
    void DisconnectProfileChanged(
        const Offsets::S_ProfileChangedDelegate& delegate) override; // secondary [5] 0x18295D7E4

    wh::shared::C_Signal<
        Offsets::IEntity*,
        EEntityAspects,
        std::uint8_t,
        std::uint8_t> m_profileSignal;                  // +0x48
    C_Item* m_pItem;                                    // +0x58, borrowed
    std::uint32_t m_itemStateFlags;                     // +0x60, bit names OPEN
    std::uint32_t m_activeUseToken;                     // +0x64, exact alias OPEN
    Offsets::SmartScriptTable m_scriptTable;            // +0x68
    std::uint32_t m_scriptState;                        // +0x70, enum identity OPEN
    std::uint8_t m_unk74;                               // +0x74, not proven padding
    bool m_profileDirty;                                // +0x75
    std::int16_t m_profileGuardCount;                   // +0x76
    std::uint32_t m_requestedProfile;                   // +0x78, exact profile type OPEN
    std::uint32_t m_appliedProfile;                     // +0x7C, exact profile type OPEN
    std::function<void(C_PickableItem&)> m_profileCallback; // +0x80
    std::uint32_t m_auxCleanupState;                    // +0xC0, exact role OPEN
    std::uint32_t _padC4;                               // +0xC4, alignment gap
    CryStringT<char> m_auxEntityName;                   // +0xC8, role OPEN
    _smart_ptr<wh::I_MaterialInstance> m_pMaterialInstance; // +0xD0
};
static_assert(sizeof(C_PickableItem) == 0xD8,
              "C_PickableItem must be 0xD8");
static_assert(offsetof(C_PickableItem, m_profileSignal) == 0x48,
              "profile signal must overlap the empty base at 0x48");
static_assert(offsetof(C_PickableItem, m_pItem) == 0x58,
              "backing item must be at 0x58");
static_assert(offsetof(C_PickableItem, m_profileCallback) == 0x80,
              "profile callback must be at 0x80");
static_assert(offsetof(C_PickableItem, m_pMaterialInstance) == 0xD0,
              "material instance must be at 0xD0");

}  // namespace wh::entitymodule
