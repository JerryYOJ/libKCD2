#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "I_InventoryListener.h"
#include "S_CarryItemPileGeom.h"
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IGameObjectExtension.h"
#include "../framework/C_Signal.h"
#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {

class C_ActorModel;
class C_Inventory;
class C_Item;

#pragma pack(push, 4)
class C_CarryItemPile
    : public Offsets::CGameObjectExtensionHelper<
          C_CarryItemPile,
          Offsets::IGameObjectExtension,
          64>
    , public I_InventoryListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CarryItemPile;

    ~C_CarryItemPile() override;                                    // [0] 0x18152CCF0
    void ProcessEvent(SEntityEvent& event) override;                 // [1] nullsub_1
    bool _vf2() override;                                            // [2] 0x180838AE0
    int GetEventPriority(int eventId) override;                      // [3] 0x181A74280
    void _vf4() override;                                            // [4] nullsub_1
    Offsets::IEntity* GetEntity() override;                          // [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;            // [6] 0x1828D92C0
    bool Init(Offsets::IGameObject* gameObject) override;            // [7] 0x18152CD34
    void PostInit(Offsets::IGameObject* gameObject) override;        // [8] 0x1819DCFE4
    void InitClient(int channelId) override;                         // [9] nullsub_1
    void PostInitClient(int channelId) override;                     // [10] nullsub_1
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override; // [11] 0x1827D22E8
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12] nullsub_1
    bool GetEntityPoolSignature(TSerialize signature) override;     // [13] 0x1828D86C8
    void Release() override;                                        // [14] 0x18152CCAC
    void FullSerialize(TSerialize serializer) override;             // [15] nullsub_1
    bool NetSerialize(TSerialize serializer,
                      EEntityAspects aspect,
                      std::uint8_t profile,
                      int flags) override;                           // [16] 0x180838AE0
    bool _vf17() override;                                           // [17] 0x180838AE0, role OPEN
    NetworkAspectType GetNetSerializeAspects() override;             // [18] 0x181A72600
    void PostSerialize() override;                                   // [19] nullsub_1
    void SerializeSpawnInfo(TSerialize serializer) override;        // [20] nullsub_1
    ISerializableInfoPtr GetSpawnInfo() override;                    // [21] 0x1823CA690
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22] nullsub_1
    void HandleEvent(const SGameObjectEvent& event) override;        // [23] nullsub_1
    void SetChannelId(std::uint16_t id) override;                    // [24] nullsub_1
    void SetAuthority(bool authoritative) override;                  // [25] nullsub_1
    void PostUpdate(float frameTime) override;                       // [27] 0x1807F1D3C
    void PostRemoteSpawn() override;                                 // [28] nullsub_1

    RTTR_ENABLE() // [29..31]

    void InventoryListenerUnk0(C_Item* item,
                               std::uint32_t amount) override;       // listener [0] 0x180D7C61C
    void InventoryListenerUnk1(C_Item* item,
                               std::uint32_t amount) override;       // listener [1] 0x1808D58A0
    void InventoryListenerUnk2(S_ItemClass* itemClass,
                               std::uint32_t amount,
                               framework::WUID itemWuid) override;   // listener [2] 0x180D7CAB0

    wh::shared::C_Signal<> m_onPickup;                       // +0x48, name reconstructed
    wh::shared::C_Signal<> m_onBecameEmpty;                  // +0x58, name reconstructed
    wh::shared::C_Signal<> m_onContentChanged;               // +0x68, name reconstructed
    wh::shared::C_Signal<> m_onBecameFull;                   // +0x78, name reconstructed
    wh::shared::C_Signal<C_CarryItemPile*> m_onRemoving;     // +0x88, name reconstructed
    CryStringT<char> m_pickupAnimTag;                        // +0x98
    CryStringT<char> m_depositAnimTag;                       // +0xA0
    CryStringT<char> m_materialOverride;                     // +0xA8
    std::int32_t m_capacity;                                 // +0xB0
    std::int32_t m_initialNumberOfItems;                     // +0xB4
    bool m_pickupActive;                                     // +0xB8, name reconstructed
    bool m_depositActive;                                    // +0xB9, name reconstructed
    std::uint8_t _padBA[2];                                  // +0xBA
    CryGUID m_itemClassId;                                   // +0xBC
    std::uint8_t _padCC[4];                                  // +0xCC
    C_Inventory* m_pInventory;                               // +0xD0, borrowed
    C_Item* m_pCurrentItem;                                  // +0xD8, borrowed
    C_ActorModel* m_pPickupActorModel;                       // +0xE0, borrowed; name reconstructed
    C_ActorModel* m_pDepositActorModel;                      // +0xE8, borrowed; name reconstructed
    std::vector<CryGUID> m_savedItemInstanceGuids;           // +0xF0, transient restore queue
    S_CarryItemPileGeom* m_pGeometry;                        // +0x108, borrowed database definition
    bool m_hasUnpackedModel;                                 // +0x110, name reconstructed
    std::uint8_t _pad111[3];                                 // +0x111
    CryGUID m_geometryId;                                    // +0x114
    std::uint8_t _pad124[4];                                 // +0x124
    CryStringT<char> m_packAudioSwitchState;                 // +0x128
};
#pragma pack(pop)

static_assert(sizeof(C_CarryItemPile) == 0x130,
              "C_CarryItemPile must be 0x130");
static_assert(offsetof(C_CarryItemPile, m_onPickup) == 0x48,
              "first CarryItemPile signal must be at 0x48");
static_assert(offsetof(C_CarryItemPile, m_pickupAnimTag) == 0x98,
              "pickup animation tag must be at 0x98");
static_assert(offsetof(C_CarryItemPile, m_itemClassId) == 0xBC,
              "item-class GUID must be at 0xBC");
static_assert(offsetof(C_CarryItemPile, m_pInventory) == 0xD0,
              "inventory pointer must be at 0xD0");
static_assert(offsetof(C_CarryItemPile, m_savedItemInstanceGuids) == 0xF0,
              "saved item GUID vector must be at 0xF0");
static_assert(offsetof(C_CarryItemPile, m_pGeometry) == 0x108,
              "geometry pointer must be at 0x108");
static_assert(offsetof(C_CarryItemPile, m_geometryId) == 0x114,
              "geometry GUID must be at 0x114");
static_assert(offsetof(C_CarryItemPile, m_packAudioSwitchState) == 0x128,
              "pack audio switch state must be at 0x128");

}  // namespace wh::entitymodule
