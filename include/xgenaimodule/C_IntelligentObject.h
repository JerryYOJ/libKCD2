#pragma once
#include <cstdint>
#include <vector>
#include "C_MessageCapableObject.h"
#include "S_IntelligentObjectEntry.h"

// -----------------------------------------------
// wh::xgenaimodule::C_IntelligentObject : C_MessageCapableObject -- intelligent spine
// level (KCD2 WHGame.dll 1.5.6, kd7u).  sizeof 0xA8 (own members +0x60..+0xA7 proven
// by ctor; G2_supplement §3.5).
// -----------------------------------------------
// RTTI TD rva 0x4EFD9C8; primary vtable 0x183A6C230, 27 slots (implements [19], adds
// [20..26]); I_RWLocked subobject vtable @+0x20 = 0x183A6C210. Real ctor
// sub_180A2BC4C(this, const WUID* wuid, I_AIPuppet* puppet): copies the inherited
// root WUID to +0x98 and registers this capability view in qword_1854930D0.
// OnMessage ([19], sub_18070DBD0) delegates acceptance to the installed brain at
// +0x70; absent/refusing brains reject the message with dispatcher result 3.

namespace wh::xgenaimodule {

class C_AIBrain;

class C_IntelligentObject : public C_MessageCapableObject {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_IntelligentObject;
    ~C_IntelligentObject() override;                       // [0]  deleting dtor sub_1832086F0
    uint32_t GetTypeMask() override;                       // [1]  sub_181AA3690
    int64_t OnMessage(void* msg) override;                 // [19] sub_18070DBD0 -- delegates to m_pBrain->CanReceiveMessages()
    virtual void _vf20();                                  // [20] sub_18071174C [U role]
    virtual void SetBrain(C_AIBrain* brain);               // [21] sub_180A2AD4C -- detach old, store, attach new
    virtual void _vf22();                                  // [22] sub_180A2A858 [U role]
    virtual void _vf23();                                  // [23] sub_1807FAC88 [U role]
    virtual void _vf24();                                  // [24] nullsub_1
    virtual void _vf25();                                  // [25] sub_183209730 [U role]
    virtual void _vf26();                                  // [26] sub_180A2C3E0 [U role]

    void*           m_staticDefault;   // +0x60  DynArray<T> head (CryEngine SmallDynStorage, single ptr; empty = &unk_185665430; blk hdr {cap@-8,cnt@-4}); elem 0x10 {obj* @0, callback/vtbl* @8}; teardown sub_1804CDAE8 / walk sub_180875DF8 [elem T U]
    int16_t         m_word68;          // +0x68  ctor: -1 [U role]
    int16_t         m_word6A;          // +0x6A  ctor: -1 [U role]
    uint8_t         _pad6C[4];         // +0x6C
    C_AIBrain*      m_pBrain;          // +0x70  currently installed brain; destructor deletes current pointer
    void*           m_typeToken;       // +0x78  intrusive _smart_ptr<T> to an RTTR type descriptor [pointee class OPEN]
    std::vector<S_IntelligentObjectEntry> m_entries; // +0x80
    framework::WUID m_intelligentWuid; // +0x98  copy of the inherited root WUID used by this manager view
    bool            m_flagA0;          // +0xA0  ctor: 0 [U role]
    bool            m_flagA1;          // +0xA1  ctor: 0 [U role]
    uint8_t         _padA2[6];         // +0xA2
};
static_assert(sizeof(C_IntelligentObject) == 0xA8, "C_IntelligentObject must be 0xA8");

}  // namespace wh::xgenaimodule
