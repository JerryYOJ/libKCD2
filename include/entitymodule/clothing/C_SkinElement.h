#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>
#include <optional>
#include <vector>

#include "../../framework/TinyOptional.h"
#include "../../rttr/rttr_enable.h"
#include "C_ElementBase.h"

namespace wh::entitymodule::clothing {

class C_SkinElement : public C_ElementBase {
public:
    ~C_SkinElement() override;                                          // [0] 0x1810DD108
    std::uint32_t GetElementType() const override;                       // [1] 0x181A72480
    CryStringT<char> unk_02() const override;                            // [2] 0x1809735B4
    void unk_03(void* target) const override;                            // [3] 0x1803B6E80
    bool unk_04() const override;                                       // [4] 0x18097354C
    CryStringT<char> unk_05() const override;                            // [5] 0x18295E5C0
    std::int32_t GetEquipmentPartId() const override;                    // [6] 0x181A72970
    const void* unk_07() const override;                                 // [7] 0x1809735F4
    std::int32_t GetBodyLayerId() const override;                        // [8] 0x1803BFF1C
    const CryStringT<char>& GetModel() const override;                   // [9] 0x1809735A0
    const CryStringT<char>& GetMaterial() const override;                // [10] 0x18097358C
    CryStringT<char> unk_11() const override;                            // [11] 0x181437814
    bool IsFinalLayer() const override;                                  // [12] 0x1809734EC
    bool KeepBodyLayer() const override;                                 // [13] 0x1809734D4
    bool unk_14(std::uint32_t* equipmentPartId,
                std::uint32_t* bodyLayerId) const override;              // [14] 0x180E11ED8
    bool unk_15() const override;                                       // [15] 0x180838AE0
    void unk_16(const CryStringT<char>& value) override;                 // [16] 0x1803B6E80
    bool unk_17() const override;                                       // [17] 0x180973628
    bool unk_18() const override;                                       // [18] 0x180973658
    bool unk_19() const override;                                       // [19] 0x180973688
    std::vector<CryStringT<char>> unk_20() const override;               // [20] 0x18295E22C
    void unk_21(const C_ElementBase* source) override;                   // [21] 0x181239CA0
    bool unk_22(const C_ElementBase* other) const override;              // [22] 0x18119BC90
    bool unk_23(const C_ElementBase* other) const override;              // [23] 0x1810D743C
    bool unk_24(std::int32_t equipmentPartId) const override;            // [24] 0x1810D7494
    RTTR_ENABLE(C_ElementBase)                                           // [25..27], vtable 0x183AC1810

    const CryStringT<char>& GetEquipmentPart() const;                    // 0x1809735D8
    void SetEquipmentPart(const CryStringT<char>& equipmentPart);        // 0x18074CCF0

    std::uint32_t m_equipmentPartId;                                    // +0x08 accessor-backed "EquipmentPart"
    tiny::optional<int, std::numeric_limits<int>::min()> m_bodyLayerId; // +0x0C RTTR "BodyLayerId"
    tiny::optional<bool> m_isFinalLayer;                                // +0x10 RTTR "IsFinalLayer"
    tiny::optional<bool> m_keepBodyLayer;                               // +0x11 RTTR "KeepBodyLayer"
    std::uint8_t m_padding12[6];                                        // +0x12
    std::optional<CryStringT<char>> m_model;                             // +0x18 RTTR "Model"
    std::optional<CryStringT<char>> m_material;                          // +0x28 RTTR "Material"
};

static_assert(offsetof(C_SkinElement, m_equipmentPartId) == 0x08,
              "C_SkinElement::m_equipmentPartId offset mismatch");
static_assert(offsetof(C_SkinElement, m_bodyLayerId) == 0x0C,
              "C_SkinElement::m_bodyLayerId offset mismatch");
static_assert(offsetof(C_SkinElement, m_model) == 0x18,
              "C_SkinElement::m_model offset mismatch");
static_assert(offsetof(C_SkinElement, m_material) == 0x28,
              "C_SkinElement::m_material offset mismatch");
static_assert(sizeof(C_SkinElement) == 0x38,
              "C_SkinElement size mismatch");

} // namespace wh::entitymodule::clothing
