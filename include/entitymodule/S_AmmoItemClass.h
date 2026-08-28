#pragma once

#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"
#include "../CryEngine/CryCommon/CryString.h"
#include "S_TypedItemClass.h"
#include "S_WeaponEquipItemClass.h"

namespace wh::entitymodule {

class S_AmmoItemClass
    : public S_WeaponEquipItemClass,
      public S_TypedItemClass {
public:
    std::uint8_t m_unknownF8[0xC];                                       // +0xF8
    float m_powerMod;                                                    // +0x104 RTTR "PowerMod"
    float m_rpgWeight;                                                   // +0x108 RTTR "RpgWeight"
    CryStringT<char> m_inquiverModel;                                    // +0x110 RTTR "InquiverModel"
    CryStringT<char> m_inquiverMaterial;                                 // +0x118 RTTR "InquiverMaterial"
    CryStringT<char> m_longModel;                                        // +0x120 RTTR "LongModel"
    CryStringT<char> m_shortModel;                                       // +0x128 RTTR "ShortModel"
    CryGUID m_brokenItemClassId;                                         // +0x130 RTTR "BrokenItemClassId"
};

static_assert(offsetof(S_AmmoItemClass, m_powerMod) == 0x104,
              "S_AmmoItemClass::m_powerMod offset mismatch");
static_assert(offsetof(S_AmmoItemClass, m_rpgWeight) == 0x108,
              "S_AmmoItemClass::m_rpgWeight offset mismatch");
static_assert(offsetof(S_AmmoItemClass, m_longModel) == 0x120,
              "S_AmmoItemClass::m_longModel offset mismatch");
static_assert(offsetof(S_AmmoItemClass, m_brokenItemClassId) == 0x130,
              "S_AmmoItemClass::m_brokenItemClassId offset mismatch");
static_assert(sizeof(S_AmmoItemClass) == 0x140,
              "S_AmmoItemClass size mismatch");

} // namespace wh::entitymodule
