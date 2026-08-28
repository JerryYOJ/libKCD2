#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "C_ItemHealthProvider.h"
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::entitymodule::C_InventoryPreset : C_ItemHealthProvider
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x50, vtable 0x183A4F808.
// -----------------------------------------------
// Direct base and zero adjustment are MSVC/RTTR reconciled. Vtable is exactly
// [0] destructor + [1..3] own RTTR trio. All added fields have direct RTTR offsets.

namespace wh::entitymodule {

class C_PresetItemBase;

class C_InventoryPreset : public C_ItemHealthProvider {
public:
    struct E_GeneratorMode {
        enum Type : std::uint8_t {
            All            = 0,
            OneChild       = 1,
            AmountCount    = 2,
            AmountFraction = 3,
        };
    };

    ~C_InventoryPreset() override;                    // [0] 0x182A1DE40
    RTTR_ENABLE(C_ItemHealthProvider)                 // [1..3], get_type 0x181A6D06C

    CryStringT<char> m_name;                          // +0x20 RTTR "Name"
    std::vector<C_PresetItemBase*> m_presetItems;     // +0x28 RTTR "PresetItems"
    E_GeneratorMode::Type m_mode;                     // +0x40 RTTR "Mode"
    std::uint8_t _pad41[3];                          // +0x41
    float m_modeValue;                                // +0x44 RTTR "ModeValue"
    float m_modeValueVariation;                       // +0x48 RTTR "ModeValueVariation"
    std::uint8_t _pad4C[4];                          // +0x4C
};

static_assert(sizeof(C_InventoryPreset::E_GeneratorMode::Type) == 1,
              "C_InventoryPreset::E_GeneratorMode::Type size mismatch");
static_assert(offsetof(C_InventoryPreset, m_name) == 0x20,
              "C_InventoryPreset::m_name offset mismatch");
static_assert(offsetof(C_InventoryPreset, m_mode) == 0x40,
              "C_InventoryPreset::m_mode offset mismatch");
static_assert(sizeof(C_InventoryPreset) == 0x50,
              "C_InventoryPreset size mismatch");

}  // namespace wh::entitymodule
