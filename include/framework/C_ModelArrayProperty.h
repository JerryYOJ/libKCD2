#pragma once
#include <cstdint>
#include "C_Signal.h"
#include "ModelPropertyTraits.h"
#include "../combatmodule/CombatModelTraits.h"

namespace wh::shared {

template<class T, class IndexEnum, int N, class SigArr, class Trace>
class I_ReadonlyModelArrayProperty {
public:
    virtual ~I_ReadonlyModelArrayProperty() = default;
};

template<class T, class IndexEnum, int N,
         class Def    = traits::C_StandardDefaultValueTrait<T>,
         class SigArr = wh::combatmodule::traits::C_CombatSignalArrayTrait<T, IndexEnum>,
         class Trace  = wh::combatmodule::traits::C_CombatModelNoTrace,
         class Own    = wh::combatmodule::traits::C_CombatActorModelOwnership>
class C_ModelArrayProperty : public I_ReadonlyModelArrayProperty<T, IndexEnum, N, SigArr, Trace> {
public:
    T                                m_values[N];       // +0x08
    T                                m_default;
    typename Own::OwnerPtr           m_pOwner;
    typename SigArr::ElementSignal   m_signalElement;
    typename SigArr::AggregateSignal m_signalAggregate;
    std::uint8_t                     _tail[8];
};

}  // namespace wh::shared
