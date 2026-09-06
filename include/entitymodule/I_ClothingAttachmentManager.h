#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../CryEngine/CryCommon/CryString.h"
#include "../rttr/rttr_enable.h"

#include <map>
#include <vector>
#include <array>
#include <functional>
#include <memory>

// [INFERRED] structural stand-in for boost::dynamic_bitset<uint32_t> (0x20:
// 0x18 block-vector prefix + size_t bit count; assign 0x181337680, block copy
// 0x1804F1040 proves 32-bit blocks). boost dynamic_bitset is not vendored.
struct AttachmentMask {
    std::vector<std::uint32_t> m_blocks;   // +0x00
    std::size_t                m_numBits;  // +0x18
};
static_assert(sizeof(AttachmentMask) == 0x20, "AttachmentMask size mismatch");
using AttachmentMaskMap = std::map<CryStringT<char>, AttachmentMask>;

struct ICharacterInstance;
struct SEntityEvent;

namespace wh::entitymodule::clothing {
class C_BloodMask;
class C_ClothingHidingGroup;
class C_ElementBase;
struct S_BloodMaskName;
}

namespace wh::entitymodule {

using BloodMaskArray = std::array<std::shared_ptr<clothing::C_BloodMask>, 6>;
using ElementPredicate = std::function<bool(const std::shared_ptr<clothing::C_ElementBase>&)>;

class I_ClothingAttachmentOwner;

class I_ClothingAttachmentManager {
public:
    virtual ~I_ClothingAttachmentManager();                              // [0] 0x1829174A0
    virtual void OnPrePhysicsUpdate() = 0; // [1]
    virtual void* GetClothingConfig() const = 0;                         // [2]
    virtual void unk_03() = 0; // [3]
    virtual void SetHandsExcluded(bool excluded) = 0; // [4]
    virtual bool HasEquippedHeadFaceComponent() const = 0; // [5]
    virtual ICharacterInstance* GetCharacterInstance() const = 0; // [6] owner slot 2 -> CEntity+0x328(0)
    virtual Offsets::IEntity* GetEntity() const = 0;                     // [7] 0x180638480 mov rax,[rcx+10h]
    virtual const char* GetOwnerName() const = 0;                        // [8]
    virtual I_ClothingAttachmentOwner* GetOwner() const = 0;             // [9]
    virtual void SetEnabled(bool enabled) = 0; // [10]
    virtual bool IsResetPending() const = 0; // [11]
    virtual std::uint32_t GetBloodMaskSeed() const = 0; // [12]
    virtual void CopyStateFrom(const I_ClothingAttachmentManager* source) = 0; // [13]
    virtual bool IsReady() const = 0; // [14]
    virtual bool IsAttachmentLodReady() const = 0; // [15]
    virtual bool IsAttachmentLodActive() const = 0; // [16]
    virtual void ProcessEvent(SEntityEvent& event) = 0;                  // [17]
    virtual void OverrideBloodZoneMask(std::uint32_t zoneIdx, const clothing::S_BloodMaskName& mask) = 0; // [18]
    virtual void ApplyBloodMaskOverride(const clothing::S_BloodMaskName& mask) = 0; // [19]
    virtual void ResetBloodMaskOverride(const clothing::S_BloodMaskName& mask) = 0; // [20]
    virtual std::uint32_t GetLoadedAttachmentCount() const = 0;          // [21]
    virtual bool Initialize() = 0; // [22]
    virtual void unk_23() = 0; // [23]
    virtual void RebuildAttachments() = 0; // [24]
    virtual bool AddItem(C_Item* item) = 0; // [25]
    virtual bool RemoveItem(C_Item* item) = 0; // [26]
    virtual void ClearItems() = 0; // [27]
    virtual void ReloadComponentData() = 0; // [28]
    virtual void ReloadBloodMasks() = 0; // [29]
    virtual void SetHidingGroupActive(const std::shared_ptr<clothing::C_ClothingHidingGroup>& group, bool active) = 0; // [30]
    virtual void SetAttachmentMask(const CryStringT<char>& attachmentName, const AttachmentMask& mask) = 0; // [31]
    virtual const AttachmentMaskMap& GetAttachmentMasks() const = 0; // [32]
    virtual const BloodMaskArray& GetBloodMasks() const = 0; // [33]
    virtual std::vector<clothing::C_ElementBase*> CollectElements(std::uint32_t equipmentPartId, ElementPredicate predicate) const = 0; // [34] 0x180F1EF94 sret
    RTTR_ENABLE()                                                        // [35..37], vtable 0x183E8B9A8
};

static_assert(sizeof(I_ClothingAttachmentManager) == 0x08,
              "I_ClothingAttachmentManager size mismatch");

} // namespace wh::entitymodule
