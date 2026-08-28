#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "../rttr/rttr_enable.h"

namespace wh::entitymodule {

struct S_InventoryPresetGenerationContext;                // Synthetic name; 0x118 generation state.
struct S_ItemInstanceData;

class C_PresetItemBase {
public:
    virtual ~C_PresetItemBase();                          // [0] 0x182A1DFA0
    virtual void GenerateItems(
        S_InventoryPresetGenerationContext& context,
        std::vector<S_ItemInstanceData>& items,
        std::uint32_t amount) = 0;                        // [1] purecall 0x181D93E5D
    virtual bool IsValid();                               // [2] 0x182A1FD04
    virtual std::uint32_t GetAmount() const;              // [3] 0x181A72470
    RTTR_ENABLE()                                         // [4..6], vtable 0x183EB4E60

    float m_weight;                                       // +0x08 RTTR "Weight"
    float m_combatLevel;                                  // +0x0C RTTR "CombatLevel"
    CryStringT<char> m_name;                              // +0x10 RTTR "Name"
};

static_assert(offsetof(C_PresetItemBase, m_weight) == 0x08,
              "C_PresetItemBase::m_weight offset mismatch");
static_assert(offsetof(C_PresetItemBase, m_name) == 0x10,
              "C_PresetItemBase::m_name offset mismatch");
static_assert(sizeof(C_PresetItemBase) == 0x18,
              "C_PresetItemBase size mismatch");

}  // namespace wh::entitymodule
