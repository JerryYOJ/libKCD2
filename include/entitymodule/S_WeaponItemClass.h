#pragma once

#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "S_WeaponEquipItemClass.h"

namespace wh::entitymodule {

class S_WeaponItemClass : public S_WeaponEquipItemClass {
public:
    std::uint8_t m_unknownE8[8];                                         // +0xE8
    int32_t m_class;                                                     // +0xF0 RTTR "Class"
    int32_t m_subClass;                                                  // +0xF4 RTTR "SubClass"
    CryGUID m_brokenItemClassId;                                         // +0xF8 RTTR "BrokenItemClassId"
    std::uint8_t m_unknown108[8];                                        // +0x108
    float m_defense;                                                     // +0x110 RTTR "Defense"
    int32_t m_maxStatus;                                                 // +0x114 RTTR "MaxStatus"
    std::uint32_t m_strReq;                                              // +0x118 RTTR "StrReq"
    std::uint32_t m_agiReq;                                              // +0x11C RTTR "AgiReq"
    bool m_isBreakable;                                                  // +0x120 RTTR "IsBreakable"
    std::uint8_t m_padding121[7];                                        // +0x121
    CryStringT<char> m_holsterModel;                                     // +0x128 RTTR "HolsterModel"
    CryStringT<char> m_holsterMaterial;                                  // +0x130 RTTR "HolsterMaterial"
};

static_assert(offsetof(S_WeaponItemClass, m_class) == 0xF0,
              "S_WeaponItemClass::m_class offset mismatch");
static_assert(offsetof(S_WeaponItemClass, m_brokenItemClassId) == 0xF8,
              "S_WeaponItemClass::m_brokenItemClassId offset mismatch");
static_assert(offsetof(S_WeaponItemClass, m_defense) == 0x110,
              "S_WeaponItemClass::m_defense offset mismatch");
static_assert(offsetof(S_WeaponItemClass, m_holsterModel) == 0x128,
              "S_WeaponItemClass::m_holsterModel offset mismatch");
static_assert(offsetof(S_WeaponItemClass, m_holsterMaterial) == 0x130,
              "S_WeaponItemClass::m_holsterMaterial offset mismatch");
static_assert(sizeof(S_WeaponItemClass) == 0x138,
              "S_WeaponItemClass size mismatch");

} // namespace wh::entitymodule
