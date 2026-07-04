#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::framework::C_OverrideConflictManager<K, V> -- override/conflict tracking
// template (KCD2 WHGame.dll 1.5.6, kd7u).  sizeof 0x18 per instantiation.
// -----------------------------------------------
// Layout proven at C_AreaLabelManager (instantiation
// <S_AreaLabelHandle, E_AddRemove::Type>, new 24, ctor sub_180CC1AA8: base ctor
// sets C_OverrideConflictManager<>::vftable, then the derived vptr): +0x08 =
// head of a 104-byte intrusive tree/list node (sub_181AB55C0(104), sentinel
// self-refs, WORD@24 = 0x0101), +0x10 = count 0.  Same shape at
// C_SmartBehaviorStateManager (<S_BehaviorHandle, E_SmartBehaviorState::Type>).
// 3-slot vtable: [0] deleting dtor, [1]/[2] the override apply/revert hooks --
// which is apply vs revert NOT decompiled [U].  Template => no RTTI constant
// (gen_rtti skips templates).

namespace wh::framework {

template <class K, class V>
class C_OverrideConflictManager {
public:
    virtual ~C_OverrideConflictManager();   // [0] deleting dtor (instantiation-specific)
    virtual void OcmVf1();                  // [1] apply-override hook? [U role]
    virtual void OcmVf2();                  // [2] revert-override hook? [U role]

    void*    m_pEntries;   // +0x08  head of 104-byte intrusive tree/list (sentinel self-linked)
    uint64_t m_count;      // +0x10  entry count (ctor: 0)
};
static_assert(sizeof(C_OverrideConflictManager<int, int>) == 0x18,
              "C_OverrideConflictManager instantiations must be 0x18");

}  // namespace wh::framework
