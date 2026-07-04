#pragma once

// -----------------------------------------------
// wh::xgenaimodule::BehaviorTree::Expressions::C_ExpressionRef -- reference to a
// behavior-tree expression (KCD2 WHGame.dll 1.5.6, kd7u).  sizeof 0x10: vptr +
// one payload pointer.  Modeled from its embedded use in C_Variable @+0x30
// (ctor sub_1805B810C stores &C_ExpressionRef::vftable @+0x30 and 0 @+0x38).
// -----------------------------------------------
// RTTI mangled .?AVC_ExpressionRef@Expressions@BehaviorTree@xgenaimodule@wh@@.
// Own vtable slot roles NOT enumerated (out of G4B scope) -- only the dtor slot is
// modeled [U slot count/roles].

namespace wh::xgenaimodule::BehaviorTree::Expressions {

class C_ExpressionRef {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ExpressionRef;
    virtual ~C_ExpressionRef();   // [0] [U -- vtable not enumerated]

    void* m_expression;           // +0x08  expression payload ptr (0 at construction) [U pointee type]
};
static_assert(sizeof(C_ExpressionRef) == 0x10, "C_ExpressionRef must be 0x10 (vptr + ptr)");

}  // namespace wh::xgenaimodule::BehaviorTree::Expressions
