#pragma once

// -----------------------------------------------
// wh::framework::I_EEFunction -- expression-engine function interface (KCD2 1.5.6, kd7u).
// -----------------------------------------------
// Implementations are registered into the expression-function manager (e.g.
// C_EnvironmentModule::Init sub_180E3C398 creates C_FunctionIsRaining via sub_1819B78A4 and
// registers it through module+0x60 -> manager+0x430). 8-slot contract derived from the
// dialogmodule EE-function vtables (the 5 data::C_Function* nodes, vtables 0x183E6CED8..
// 0x183E6D008, + C_DialogFunctionExpression 0x183A518F8 -- all exactly 8 slots):
//   [0] dtor  [1] GetName -> const char* ("Port"/"Enum"/"SequenceUsed"/...)
//   [2] HasArg -> int(1|0)  [3] GetArgType -> arg-descriptor ptr | 0
//   [4] Evaluate(ctx) -> result (bool for the named intrinsics; float for expressions)
//   [5] ref-counter release  [6] stub (return 0)  [7] GetDescription
// Names coined from the dialog impl bodies; signatures loosely typed [arg types UNVERIFIED].

namespace wh::framework {

class I_EEFunction {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_EEFunction;
    virtual ~I_EEFunction();                  // [0]
    virtual const char* GetName();            // [1] function name in expressions
    virtual int HasArg();                     // [2] 1 if the function takes an argument
    virtual const void* GetArgType();         // [3] arg-descriptor ptr or nullptr
    virtual bool Evaluate(void* ctx);         // [4] evaluate against the EE context
    virtual void Release();                   // [5] ref-counter release
    virtual int64_t _vf6();                   // [6] stub (return 0) [role UNVERIFIED]
    virtual const char* GetDescription();     // [7]
};
static_assert(sizeof(I_EEFunction) == 0x08, "I_EEFunction is a vptr-only interface");

}  // namespace wh::framework
