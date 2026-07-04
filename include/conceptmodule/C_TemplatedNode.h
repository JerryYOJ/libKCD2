#pragma once
#include <cstdint>
#include "C_Node.h"

// -----------------------------------------------
// wh::conceptmodule::C_TemplatedNode -- template-instantiated node base (KCD2 1.5.6, kd7u).
// -----------------------------------------------
// Base of questmodule::C_Objective (chain: C_AutoTriggerable<C_TemplatedNode> ->
// C_TemplatedNode -> C_Node -> C_SharedResource). Ctor sub_1806B2340: C_Node ctor
// (sub_1806B2744), own vftable, +0x40 = sub_180C0CDA4() -- a thread-safe magic-static global
// (qword_18549D930).  sizeof 0x48 (PROVEN: C_Objective places its first own member at +0x48).

namespace wh::conceptmodule {

class C_TemplatedNode : public C_Node {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_TemplatedNode;
    uint64_t m_unk40;   // +0x40  magic-static global qword_18549D930 via sub_180C0CDA4
                        //        [role UNVERIFIED -- default template/schema handle candidate]
};
static_assert(sizeof(C_TemplatedNode) == 0x48, "C_TemplatedNode must be 0x48 (C_Objective first member)");

}  // namespace wh::conceptmodule
