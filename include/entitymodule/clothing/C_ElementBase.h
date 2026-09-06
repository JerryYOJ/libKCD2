#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "../../CryEngine/CryCommon/CryString.h"

namespace wh::entitymodule::clothing {

class C_ElementBase {
public:
    virtual ~C_ElementBase() = 0;                                      // [0]
    virtual std::uint32_t GetElementType() const = 0;                   // [1]
    virtual CryStringT<char> GetAttachmentName() const = 0; // [2]
    virtual void ApplyToAttachment(IAttachment* target) const = 0; // [3]
    virtual bool IsComplete() const = 0; // [4]
    virtual CryStringT<char> GetMissingAttributes() const = 0; // [5]
    virtual std::int32_t GetEquipmentPartId() const = 0;                // [6]
    virtual const S_EquipmentPart* GetEquipmentPartRecord() const = 0; // [7]
    virtual std::int32_t GetBodyLayerId() const = 0;                    // [8]
    virtual const CryStringT<char>& GetModel() const = 0;               // [9]
    virtual const CryStringT<char>& GetMaterial() const = 0;            // [10]
    virtual CryStringT<char> GetJointName() const = 0; // [11]
    virtual bool IsFinalLayer() const = 0;                              // [12]
    virtual bool KeepBodyLayer() const = 0;                             // [13]
    virtual bool TryGetEquipmentPartLayerOrder(std::uint32_t* equipmentPartId, std::uint32_t* layerOrder) const = 0; // [14]
    virtual bool unk_15() const = 0;                                   // [15]
    virtual void SetAttachmentNamePrefix(const CryStringT<char>& value) = 0; // [16]
    virtual bool HasModelAsset() const = 0; // [17]
    virtual bool HasMaterialAsset() const = 0; // [18]
    virtual bool IsDummyModel() const = 0; // [19]
    virtual std::vector<CryStringT<char>> GetAssetPaths() const = 0; // [20]
    virtual void MergeFrom(const C_ElementBase* source) = 0; // [21]
    virtual bool IsEquivalentTo(const C_ElementBase* other) const = 0; // [22]
    virtual bool CanMergeWith(const C_ElementBase* other) const = 0; // [23]
    virtual bool MatchesEquipmentPart(std::int32_t equipmentPartId) const = 0; // [24]
};

static_assert(sizeof(C_ElementBase) == 0x08,
              "C_ElementBase size mismatch");

} // namespace wh::entitymodule::clothing
