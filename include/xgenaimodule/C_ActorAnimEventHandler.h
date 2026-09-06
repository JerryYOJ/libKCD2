#pragma once
#include <cstdint>

// -----------------------------------------------
// wh::xgenaimodule::C_ActorAnimEventHandler -- anim-event handler owned by
// C_AnimActionBase (+0x110 shared_ptr) and handed to requests (slot 49).
// (KCD2 WHGame.dll Steam 1.5.6). vtable 0x183A2CF18 (3 slots); TD 0x184F6E820.
// -----------------------------------------------
// Allocated by 0x18039BDB8 via std::_Ref_count_obj2 (vt 0x183A2CF38).
// sizeof not certified (>= 0x41); no static_assert on purpose.

namespace wh::xgenaimodule {

class C_ActorAnimEventHandler {
public:
    virtual ~C_ActorAnimEventHandler();   // [0]
    virtual void unk_01() {}              // [1]
    virtual void unk_02() {}              // [2]

    std::uint8_t _pad08[0x38];            // +0x08 pending writer tracing
    bool m_active;                        // +0x40 tested by C_AnimActionBase slots 2/64
};

}  // namespace wh::xgenaimodule
