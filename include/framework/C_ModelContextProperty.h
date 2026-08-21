#pragma once
#include <cstdint>
#include "C_Signal.h"

namespace wh::shared {

template<class Ctx, class T>
class I_ReadonlyModelContextProperty {
public:
    virtual ~I_ReadonlyModelContextProperty() = default;
};

// Physical 0x20 form used by E_BlockModeContext in S_CombatActorState. Other
// context specializations can carry a different number of per-context bytes.
template<class Ctx, class T, int N>
class C_ModelContextProperty : public I_ReadonlyModelContextProperty<Ctx, T> {
public:
    wh::shared::C_Signal<T> m_signal;       // +0x08
    std::int32_t             m_ctxState;     // +0x18
    bool                     m_flag0;        // +0x1C
    bool                     m_subscribed;   // +0x1D
    std::uint8_t             _pad1E[2];      // +0x1E
};

}  // namespace wh::shared
