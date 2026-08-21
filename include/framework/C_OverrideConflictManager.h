#pragma once
#include <cstdint>
#include <cstddef>

// -----------------------------------------------
// wh::framework::C_OverrideConflictManager<K, V> -- KCD2 WHGame.dll.  sizeof 0x18.
// -----------------------------------------------
// Template override/conflict manager. ctor sub_181064EC0 (horse-usage):
// vtable +0x00, +0x08 = 0x68 intrusive tree node (3 self-ptrs + WORD 0x101), +0x10 = 0.
// 3 slots: [0] dtor [1] OcmVf1 [2] OcmVf2. Instantiations: C_HorseUsageManager,
// C_SmartBehaviorStateManager, C_AreaLabelManager.

namespace wh::framework {

template<typename K, typename V = K>
class C_OverrideConflictManager {
public:
    virtual ~C_OverrideConflictManager() = default;  // [0]
    virtual void OcmVf1() = 0;                       // [1]
    virtual void OcmVf2() = 0;                       // [2]
    void* m_pTree;     // +0x08
    void* m_unk10;     // +0x10
};
static_assert(sizeof(C_OverrideConflictManager<void*>) == 0x18, "conflict-manager prefix");

}  // namespace wh::framework
