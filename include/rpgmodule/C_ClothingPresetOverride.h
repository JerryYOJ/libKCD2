#pragma once
#include <cstddef>
#include "../entitymodule/S_ClothingPresetGUID.h"
#include "C_SoulPresetOverride.h"

namespace wh::rpgmodule {

class C_ClothingPresetOverride : public C_SoulPresetOverride {
public:
    C_ClothingPresetOverride();
    ~C_ClothingPresetOverride() override;                        // [0]
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
        wh::entitymodule::S_ClothingPresetGUID> m_clothingPreset; // +0x120
};

static_assert(sizeof(C_ClothingPresetOverride) == 0x160,
              "C_ClothingPresetOverride size mismatch");
static_assert(offsetof(C_ClothingPresetOverride, m_clothingPreset) == 0x120,
              "C_ClothingPresetOverride preset offset mismatch");

} // namespace wh::rpgmodule
