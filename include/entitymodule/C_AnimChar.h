#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../Offsets/Offsets_RTTI.h"
#include "C_ArmorRuntimeData.h"
#include "C_ItemVectorHolder.h"
#include "I_AnimChar.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {

class C_ClothingAttachmentOwnerAnimChar;
class I_ClothingAttachmentManager;

class C_AnimChar
    : public Offsets::CGameObjectExtensionHelper<C_AnimChar, I_AnimChar, 64> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_AnimChar;

    ~C_AnimChar() override;                                            // [0] 0x1828C1AF8
    void ProcessEvent(SEntityEvent& event) override;                   // [1] 0x1828C54A0
    bool _vf2() override;                                               // [2] false stub
    int GetEventPriority(int eventId) override;                        // [3] 0x1819B465C
    void _vf4() override;                                               // [4] nullsub
    Offsets::IEntity* GetEntity() override;                            // [5] 0x180602360
    void GetMemoryUsage(ICrySizer* sizer) const override;              // [6] 0x1828C4AF4
    bool Init(Offsets::IGameObject* gameObject) override;              // [7] 0x1816EB5A0
    void PostInit(Offsets::IGameObject* gameObject) override;          // [8] 0x1828C5468
    void InitClient(int channelId) override;                           // [9] nullsub
    void PostInitClient(int channelId) override;                       // [10] nullsub
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override;   // [11] 0x1827D22E8
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12] nullsub
    bool GetEntityPoolSignature(TSerialize signature) override;       // [13] 0x1828C4978
    void Release() override;                                           // [14] 0x1803A5684
    void FullSerialize(TSerialize serializer) override;               // [15] nullsub
    bool NetSerialize(TSerialize serializer, EEntityAspects aspect,
                      std::uint8_t profile, int flags) override;       // [16] true stub
    bool _vf17() override;                                              // [17] false stub
    NetworkAspectType GetNetSerializeAspects() override;               // [18] 0x181A72600
    void PostSerialize() override;                                     // [19] nullsub
    void SerializeSpawnInfo(TSerialize serializer) override;          // [20] nullsub
    ISerializableInfoPtr GetSpawnInfo() override;                      // [21] 0x1823CA690
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22] nullsub
    void HandleEvent(const SGameObjectEvent& event) override;          // [23] nullsub
    void SetChannelId(std::uint16_t id) override;                      // [24] nullsub
    void SetAuthority(bool authoritative) override;                    // [25] nullsub
    const void* GetRMIBase() const override;                           // [26] 0x181A83AA0
    void PostUpdate(float frameTime) override;                         // [27] nullsub
    void PostRemoteSpawn() override;                                   // [28] nullsub
    void _vf29() override;                                              // [29] 0x1828C4F00
    void _vf30() override;                                              // [30] 0x1828C5004

    RTTR_ENABLE() // [31..33]

    C_ClothingAttachmentOwnerAnimChar* m_pClothingAttachmentOwner; // +0x40, owned
    I_ClothingAttachmentManager* m_pClothingAttachmentManager;     // +0x48, managed interface
    std::array<CryStringT<char>, 5> m_animationNames;               // +0x50, exact fixed array; roles OPEN
    C_ItemVectorHolder m_items78;                                   // +0x78
    C_ItemVectorHolder m_items98;                                   // +0x98
    std::vector<std::uint32_t> m_managerHandles;                    // +0xB8, opaque 32-bit handles
    C_ArmorRuntimeData m_armorRuntimeData;                          // +0xD0, ctor parameter 7
};
static_assert(sizeof(C_AnimChar) == 0x190,
              "C_AnimChar must be 0x190");
static_assert(offsetof(C_AnimChar, m_pClothingAttachmentOwner) == 0x40,
              "AnimChar clothing owner must be at 0x40");
static_assert(offsetof(C_AnimChar, m_animationNames) == 0x50,
              "AnimChar animation names must be at 0x50");
static_assert(offsetof(C_AnimChar, m_items78) == 0x78,
              "first AnimChar item holder must be at 0x78");
static_assert(offsetof(C_AnimChar, m_items98) == 0x98,
              "second AnimChar item holder must be at 0x98");
static_assert(offsetof(C_AnimChar, m_managerHandles) == 0xB8,
              "AnimChar manager handles must be at 0xB8");
static_assert(offsetof(C_AnimChar, m_armorRuntimeData) == 0xD0,
              "AnimChar armor runtime data must be at 0xD0");

}  // namespace wh::entitymodule
