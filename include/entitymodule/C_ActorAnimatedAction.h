#pragma once

#include <cstdint>

#include "C_ActorParamAction.h"

namespace wh::entitymodule {

template <typename TParams, typename TIface>
class C_ActorAnimatedAction : public C_ActorParamAction<TParams, TIface> {
public:
    virtual bool unk_47();                                               // [47] default true 0x18041A6A0
    virtual void unk_48();                                               // [48] nullsub
    virtual void unk_49();                                               // [49] nullsub
    virtual void unk_50();                                               // [50] if unk_47 then anim helper
    virtual void unk_51();                                               // [51] AdvanceActionSlot(this, 2)
    virtual void unk_52();                                               // [52] nullsub
    virtual void unk_53();                                               // [53] same family as unk_51

    std::uint64_t m_animationToken;                                      // +sizeof(C_ActorParamAction) ctor 0
    bool m_advanced;                                                     // +0x08 latched by unk_51/unk_53
    bool m_blocked;                                                      // +0x09 inhibits unk_51/unk_53
    std::uint8_t m_padding0A[6];                                         // +0x0A
};

} // namespace wh::entitymodule
