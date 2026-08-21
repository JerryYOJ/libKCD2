#pragma once
#include <cstdint>
#include <cstddef>
#include <vector>
#include "../framework/C_Signal.h"
#include "I_ActionActor.h"
#include "C_ActorObject.h"

// -----------------------------------------------
// wh::entitymodule::C_ActionActor -- KCD2 WHGame.dll.  sizeof 0x80.
// -----------------------------------------------
// RTTI : I_ActionActor. Ctor sub_1810E80F8(this, C_Actor*). GetActor = +0x28.

namespace wh::entitymodule {

class C_Actor;

class C_ActionActor : public I_ActionActor {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ActionActor;
    C_Actor* GetActor() const override { return m_pActor; }
    void*    GetOwnerSubsystem() const override { return m_pOwnerSubsystem; }
    void     vf08() override {}
    void     vf20() override {}
    void     vf28() override {}
    void     vf30() override {}
    void     vf38() override {}
    void     vf40() override {}
    void     vf48() override {}
    void     vf50() override {}
    void     vf58() override {}
    void     vf60() override {}
    void     vf68() override {}
    void     vf70() override {}
    void     vf78() override {}
    void     vf80() override {}
    void     vf88() override {}
    void     vf90() override {}
    void     vf98() override {}
    void     vfA0() override {}

    wh::shared::C_Signal<>     m_sig08;            // +0x08
    wh::shared::C_Signal<>     m_sig18;            // +0x18
    C_Actor*                   m_pActor;           // +0x28
    void*                      m_pSpec;            // +0x30  C_ActionActorSpec* 0x10
    void*                      m_pTreeHead;        // +0x38  0x68 node
    uint64_t                   m_q40;              // +0x40
    void*                      m_pOwnerSubsystem;  // +0x48
    void*                      m_pActionFactory;   // +0x50
    uint64_t                   m_q58;              // +0x58
    std::vector<C_ActorObject*> m_objects;         // +0x60
    uint8_t                    m_flag78;           // +0x78  ctor 1
    uint8_t                    m_b79;              // +0x79  ctor word split
    uint8_t                    m_b7A;              // +0x7A
    uint8_t                    _pad7B[5];          // +0x7B
};
static_assert(sizeof(C_ActionActor) == 0x80, "C_ActionActor must be 0x80");
static_assert(offsetof(C_ActionActor, m_pActor) == 0x28, "actor");
static_assert(offsetof(C_ActionActor, m_objects) == 0x60, "objects");

}  // namespace wh::entitymodule
