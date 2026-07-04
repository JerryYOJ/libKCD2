#pragma once
#include <cstdint>
#include "I_StealthWatcher.h"

// -----------------------------------------------
// wh::xgenaimodule::C_StealthWatcher : XGenPublic::I_StealthWatcher -- the
// trespass/stealth-context watcher singleton (KCD2 WHGame.dll 1.5.6, kd7u).
// sizeof 0x30 (create-site proven: alloc 48 in the lazy-init getter sub_180F667DC
// -> qword_185493928).
// -----------------------------------------------
// RTTI TD rva 0x4F5B598; vtable 0x183AE0A28, 3 slots.  Registers via
// sub_180F668CC(sub_1832AE82C()).
// [2] sub_180F668C0 -> sub_180460B88(this, *(this+0x20)) = the trespass check:
// for each object in the +0x20 list, GetOwnership tags "private" / "personal" /
// "prohibited"; returns private && (personal || prohibited).

namespace wh::xgenaimodule {

class C_StealthWatcher : public XGenPublic::I_StealthWatcher {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_StealthWatcher;
    ~C_StealthWatcher() override;   // [0] deleting dtor sub_1832EE0C8
    void _vf1() override;           // [1] sub_181A71D30 [U role]
    void _vf2() override;           // [2] sub_180F668C0 -- trespass/stealth-context check (see banner) [U exact signature]

    uint64_t m_unk08;   // +0x08  ctor: 0 [U role]
    uint64_t m_unk10;   // +0x10  ctor: 0 [U role]
    uint64_t m_unk18;   // +0x18  ctor: 0 [U role]
    uint64_t m_unk20;   // +0x20  ctor: 0; the watched-object list consumed by the trespass check [U exact type]
    uint64_t m_unk28;   // +0x28  ctor: 0 [U role]
};
static_assert(sizeof(C_StealthWatcher) == 0x30, "C_StealthWatcher must be 0x30 (48)");

}  // namespace wh::xgenaimodule
