#pragma once
#include <cstddef>
#include "../entitymodule/S_WeaponPresetGUID.h"
#include "C_SoulPresetOverride.h"

namespace wh::rpgmodule {

class C_WeaponPresetOverride : public C_SoulPresetOverride {
public:
    C_WeaponPresetOverride();
    ~C_WeaponPresetOverride() override;                          // [0]
    RTTR_ENABLE(C_SoulPresetOverride) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                              // [27]
    bool ApplyPreset(I_Soul* soul,
                     const CryStringT<char>& key,
                     bool initialApplication) override;          // [49]
    void RemovePreset(I_Soul* soul,
                      const CryStringT<char>& key) override;      // [50]

    wh::conceptmodule::C_TypedPortRef<
        wh::entitymodule::S_WeaponPresetGUID> m_weaponPreset;     // +0x120
};

static_assert(sizeof(C_WeaponPresetOverride) == 0x160,
              "C_WeaponPresetOverride size mismatch");
static_assert(offsetof(C_WeaponPresetOverride, m_weaponPreset) == 0x120,
              "C_WeaponPresetOverride preset offset mismatch");

} // namespace wh::rpgmodule
