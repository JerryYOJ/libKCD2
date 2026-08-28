#pragma once

#include <cstddef>
#include <cstdint>

#include "C_FastForwardHandlingAction.h"
#include "I_QueueableAction.h"

namespace wh::xgenaimodule::NPCState {

class C_AnimActionBase : public C_FastForwardHandlingAction,
                         public I_QueueableAction {
public:
    ~C_AnimActionBase() override;
    void unk_0() override;                                                   // +0xC8 [0]
    RTTR_ENABLE(C_FastForwardHandlingAction)                                 // [24..26], vtable 0x183A2E418
    virtual void unk_39();
    virtual void unk_40();
    virtual void unk_41();
    virtual void unk_42();
    virtual void unk_43();
    virtual void unk_44();
    virtual void unk_45();
    virtual void unk_46();
    virtual void unk_47();
    virtual void unk_48();
    virtual void unk_49();
    virtual void unk_50();
    virtual void unk_51();
    virtual void unk_52();
    virtual void unk_53();
    virtual void unk_54();
    virtual void unk_55();
    virtual void unk_56();
    virtual void unk_57();
    virtual void unk_58();
    virtual void unk_59();
    virtual void unk_60();
    virtual void unk_61();
    virtual void unk_62();
    virtual void unk_63();
    virtual void unk_64();
    virtual void unk_65();
    virtual void unk_66();
    virtual void unk_67();

    std::uint8_t m_unknownD0[0xD0];                                          // +0xD0
};

static_assert(sizeof(C_AnimActionBase) == 0x1A0,
              "C_AnimActionBase size mismatch");

} // namespace wh::xgenaimodule::NPCState
