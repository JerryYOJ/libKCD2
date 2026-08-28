#pragma once
#include <cstddef>
#include <cstdint>
#include "../../CryEngine/CryCommon/CryString.h"
#include "../../entitymodule/E_OutfittingMode.h"
#include "C_ElementInitializerBase.h"

namespace wh::xgenaimodule::scheduler {

class C_ElementInitializerChangeEquipment : public C_ElementInitializerBase {
public:
    ~C_ElementInitializerChangeEquipment() override;
    void unk_01() override;
    void unk_02() override;
    void unk_03() override;
    RTTR_ENABLE(C_ElementInitializerBase)
    bool m_isInInstantPreSearch;                          // +0x18 RTTR "IsInInstantPreSearch"
    std::uint8_t _pad19[7];                               // +0x19
    CryStringT<char> m_filterName;                        // +0x20 RTTR "FilterName"
    wh::entitymodule::E_OutfittingMode::Type m_outfittingMode; // +0x28 RTTR "OutfittingMode"
    std::uint8_t _pad29[7];                               // +0x29
};

static_assert(offsetof(C_ElementInitializerChangeEquipment, m_filterName) == 0x20,
              "C_ElementInitializerChangeEquipment::m_filterName offset mismatch");
static_assert(offsetof(C_ElementInitializerChangeEquipment, m_outfittingMode) == 0x28,
              "C_ElementInitializerChangeEquipment::m_outfittingMode offset mismatch");
static_assert(sizeof(C_ElementInitializerChangeEquipment) == 0x30,
              "C_ElementInitializerChangeEquipment size mismatch");

}  // namespace wh::xgenaimodule::scheduler
