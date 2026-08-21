#pragma once
#include <cstddef>
#include <cstdint>
#include "../CryEngine/CryCommon/CryString.h"
#include "S_PlayerItemClass.h"

// -----------------------------------------------
// wh::entitymodule::S_DivisibleItemClass -- stackable item classes (KCD2 1.5.6).
// sizeof 0xC8.  E_ItemType::Divisible (23).
// -----------------------------------------------
// Vtable 0x183A4E878, ctor sub_180753830, copy-ctor sub_180D28E40, Clone alloc 0xC8.
// RTTR registrar sub_180132300 ("wh::entitymodule::DivisibleItem").

namespace wh::entitymodule {

class S_DivisibleItemClass : public S_PlayerItemClass {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_S_DivisibleItemClass;

    bool             m_isDivisible;              // +0xB0  RTTR "IsDivisible"  ctor 0
    std::uint8_t     _padB1[7];                  // +0xB1
    CryStringT<char> m_containerModel;           // +0xB8  RTTR "ContainerModel"
    CryStringT<char> m_containerMaterial;        // +0xC0  RTTR "ContainerMaterial"
};
static_assert(sizeof(S_DivisibleItemClass) == 0xC8, "S_DivisibleItemClass must be 0xC8");
static_assert(offsetof(S_DivisibleItemClass, m_isDivisible) == 0xB0);
static_assert(offsetof(S_DivisibleItemClass, m_containerModel) == 0xB8);

}  // namespace wh::entitymodule
