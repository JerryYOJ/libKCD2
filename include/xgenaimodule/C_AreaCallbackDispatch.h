#pragma once
#include <cstdint>
#include "I_SmartAreasManagerListener.h"

// -----------------------------------------------
// wh::xgenaimodule::C_AreaCallbackDispatch : I_SmartAreasManagerListener --
// area event -> callback dispatcher SINGLETON at qword_185496108 (KCD2
// WHGame.dll 1.5.6, kd7u).  sizeof 0xA0 (create inside sub_180F80358:
// operator new(160) -> ctor sub_180F80414).
// -----------------------------------------------
// RTTI TD rva 0x4FE8D48, COL 0x45BB618.  Vtable rva 0x400F148 (4 slots:
// [0]nullsub, [1]OnSmartAreaRemoved-slot = sub_180D9B370 (forwards
// sub_18070A68C(this, msg+392)), [2]nullsub, [3] deleting dtor sub_18341F800
// -- appended own virtual dtor).  C_AreaLabelManager registers itself here
// via thunk sub_18070A630.

namespace wh::xgenaimodule {

class C_AreaCallbackDispatch : public I_SmartAreasManagerListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_AreaCallbackDispatch;
    void _vf0() override;                          // [0] nullsub
    void OnSmartAreaRemoved(void* area) override;  // [1] sub_180D9B370
    void _vf2() override;                          // [2] nullsub
    virtual ~C_AreaCallbackDispatch();             // [3] deleting dtor sub_18341F800 (appended)

    void*    m_pRecord;         // +0x08  &unk_1856681E0 (static record) [U type]
    int16_t  m_handleA;         // +0x10  ctor: -1 [U role]
    int16_t  m_handleB;         // +0x12  ctor: -1 [U role]
    uint8_t  _pad14[4];         // +0x14
    uint8_t  _zero18[0x30];     // +0x18..+0x48  zeroed [U roles]
    float    m_scale48;         // +0x48  ctor: 1.0f [U role]
    uint8_t  _pad4C[4];         // +0x4C
    void*    m_bucketHead50;    // +0x50  hash bucket-list head (32-byte node)
    uint8_t  _unk58[8];         // +0x58  [U]
    uint8_t  m_callbacks60[0x40]; // +0x60..+0xA0  hash container (sub_1803B5774; +0x78=7, +0x80=8) [U exact type]
};
static_assert(sizeof(C_AreaCallbackDispatch) == 0xA0, "must be 0xA0 (new 160 at sub_180F80358)");

}  // namespace wh::xgenaimodule
