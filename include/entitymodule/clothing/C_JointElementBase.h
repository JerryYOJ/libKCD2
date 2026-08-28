#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <vector>

#include "../../rttr/rttr_enable.h"
#include "C_ElementBase.h"

namespace wh::entitymodule::clothing {

class C_JointElementBase : public C_ElementBase {
public:
    C_JointElementBase();                                               // 0x1810E3308
    ~C_JointElementBase() override;                                     // [0] 0x18295C4C8
    std::uint32_t GetElementType() const override = 0;                   // [1] purecall
    CryStringT<char> unk_02() const override;                            // [2] 0x180975210
    void unk_03(void* target) const override = 0;                        // [3] purecall
    bool unk_04() const override = 0;                                   // [4] purecall
    CryStringT<char> unk_05() const override = 0;                        // [5] purecall
    std::int32_t GetEquipmentPartId() const override;                    // [6] 0x181A72600
    const void* unk_07() const override;                                 // [7] 0x18066CD10
    std::int32_t GetBodyLayerId() const override;                        // [8] 0x181A72600
    const CryStringT<char>& GetModel() const override;                   // [9] 0x181A85B10
    const CryStringT<char>& GetMaterial() const override;                // [10] 0x18119BBE0
    CryStringT<char> unk_11() const override;                            // [11] 0x180975454
    bool IsFinalLayer() const override;                                  // [12] 0x180838AE0
    bool KeepBodyLayer() const override;                                 // [13] 0x180838AE0
    bool unk_14(std::uint32_t* equipmentPartId,
                std::uint32_t* bodyLayerId) const override;              // [14] 0x180838AE0
    bool unk_15() const override;                                       // [15] 0x18041A6A0
    void unk_16(const CryStringT<char>& value) override;                 // [16] 0x18068E2B8
    bool unk_17() const override;                                       // [17] 0x180838AE0
    bool unk_18() const override;                                       // [18] 0x180838AE0
    bool unk_19() const override;                                       // [19] 0x180838AE0
    std::vector<CryStringT<char>> unk_20() const override;               // [20] 0x18295E22C
    void unk_21(const C_ElementBase* source) override;                   // [21] 0x18074D2C4
    bool unk_22(const C_ElementBase* other) const override;              // [22] 0x18295CFE0
    bool unk_23(const C_ElementBase* other) const override;              // [23] 0x180838AE0
    bool unk_24(std::int32_t equipmentPartId) const override;            // [24] 0x180838AE0
    RTTR_ENABLE(C_ElementBase)                                           // [25..27], vtable 0x183B08FE8

    CryStringT<char> GetAttachmentName() const;                          // 0x182138834

    CryStringT<char> m_name;                                            // +0x08 RTTR "Name"
    std::optional<CryStringT<char>> m_joint;                             // +0x10 RTTR "RowJoint" / "Joint"
    CryStringT<char> m_attachmentNamePrefix;                             // +0x20, writer slot [16]
};

static_assert(offsetof(C_JointElementBase, m_name) == 0x08,
              "C_JointElementBase::m_name offset mismatch");
static_assert(offsetof(C_JointElementBase, m_joint) == 0x10,
              "C_JointElementBase::m_joint offset mismatch");
static_assert(offsetof(C_JointElementBase, m_attachmentNamePrefix) == 0x20,
              "C_JointElementBase::m_attachmentNamePrefix offset mismatch");
static_assert(sizeof(C_JointElementBase) == 0x28,
              "C_JointElementBase size mismatch");

} // namespace wh::entitymodule::clothing
