#pragma once
#include <cstddef>
#include <unordered_set>
#include <vector>
#include "../conceptmodule/C_ExternalPartialActivationEffect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "I_Soul.h"

namespace wh::rpgmodule {

class C_SoulPresetOverride
    : public wh::conceptmodule::C_ExternalPartialActivationEffect<I_Soul> {
public:
    C_SoulPresetOverride();
    ~C_SoulPresetOverride() override;                           // [0]
    RTTR_ENABLE(wh::conceptmodule::C_ExternalPartialActivationEffect<I_Soul>) // [5..7]
    void OnEffectDeactivate() override;                         // [44]
    void ApplyToTarget(I_Soul* soul,
                       const CryStringT<char>& key,
                       bool initialApplication) override;       // [46]
    void RemoveFromTarget(I_Soul* soul,
                          const CryStringT<char>& key) override; // [47]
    std::unordered_set<I_Soul*> GetAppliedTargets() const override; // [48]
    virtual bool ApplyPreset(I_Soul* soul,
                             const CryStringT<char>& key,
                             bool initialApplication) = 0;       // [49]
    virtual void RemovePreset(I_Soul* soul,
                              const CryStringT<char>& key) = 0;  // [50]

    std::vector<I_Soul*> m_appliedSouls;                        // +0xC8
    wh::conceptmodule::C_TypedPortRef<bool> m_priorityEquip;     // +0xE0
};

static_assert(sizeof(C_SoulPresetOverride) == 0x120,
              "C_SoulPresetOverride size mismatch");
static_assert(offsetof(C_SoulPresetOverride, m_appliedSouls) == 0xC8,
              "C_SoulPresetOverride applied-souls offset mismatch");
static_assert(offsetof(C_SoulPresetOverride, m_priorityEquip) == 0xE0,
              "C_SoulPresetOverride priority offset mismatch");

} // namespace wh::rpgmodule
