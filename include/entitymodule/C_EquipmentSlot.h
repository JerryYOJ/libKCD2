#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {

class C_EquipmentSlot {
public:
    C_EquipmentSlot();
    virtual ~C_EquipmentSlot(); // [0] 0x1829FD64C
    RTTR_ENABLE() // [1..3]

    CryStringT<char> GetArmorTypes() const;               // 0x1829FF7F8
    void SetArmorTypes(CryStringT<char> armorTypes);       // 0x180D64F50

    CryStringT<char> m_name;                              // +0x08 RTTR "Name"
    CryStringT<char> m_uiSlot;                            // +0x10 RTTR "UISlot"
    std::int32_t m_id;                                    // +0x18 RTTR "Id"
    std::int32_t m_bodyLayerTypeId;                       // +0x1C
    std::uint32_t m_equipmentPartId;                      // +0x20
    std::int32_t m_uiBodyPartId;                          // +0x24
    std::int32_t m_uiSlotSubType;                         // +0x28
    std::uint32_t m_padding2C;
    std::vector<std::int32_t> m_armorTypeIds;             // +0x30 accessor-backed
    CryStringT<char> m_requiresEmptySlot;                 // +0x48
    CryStringT<char> m_requiresFilledSlot;                // +0x50
    void* m_unknown58;                                    // +0x58, borrowed
    void* m_unknown60;                                    // +0x60, borrowed
    std::vector<void*> m_unknown68;                       // +0x68
};

static_assert(offsetof(C_EquipmentSlot, m_armorTypeIds) == 0x30,
              "C_EquipmentSlot::m_armorTypeIds offset mismatch");
static_assert(offsetof(C_EquipmentSlot, m_requiresEmptySlot) == 0x48,
              "C_EquipmentSlot::m_requiresEmptySlot offset mismatch");
static_assert(offsetof(C_EquipmentSlot, m_unknown68) == 0x68,
              "C_EquipmentSlot::m_unknown68 offset mismatch");
static_assert(sizeof(C_EquipmentSlot) == 0x80,
              "C_EquipmentSlot size mismatch");

} // namespace wh::entitymodule
