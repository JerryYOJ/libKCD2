#pragma once
#include <cstdint>
#include <unordered_set>
#include <vector>
#include "C_Effect.h"
#include "C_TypedArrayPortRef.h"
#include "../CryEngine/CryCommon/CryString.h"

// -----------------------------------------------
// wh::conceptmodule::C_ExternalPartialActivationEffect<T> -- reversible effect
// base over a reflected array of external targets (KCD2 WHGame.dll Steam 1.5.6).
// Observed specializations are sizeof 0xC8 and add three pure slots [46..48].
// -----------------------------------------------

namespace wh::conceptmodule {

template <typename T>
class C_ExternalPartialActivationEffect : public C_Effect {
public:
    ~C_ExternalPartialActivationEffect() override;            // [0]
    RTTR_ENABLE(C_Effect)                                     // [5..7]
    void OnLifecycleEvent(std::int32_t event) override;       // [34] 0x1805187E8
    void OnEffectActivate() override;                         // [43] 0x18051860C

    virtual void ApplyToTarget(T* target,
                               CryStringT<char> const& key,
                               bool initialApplication) = 0;   // [46]
    virtual void RemoveFromTarget(T* target,
                                  CryStringT<char> const& key) = 0; // [47]
    virtual std::unordered_set<T*> GetAppliedTargets() const = 0;   // [48]

    C_TypedArrayPortRef<std::vector<T*>> m_targets;           // +0x88
};

}  // namespace wh::conceptmodule
