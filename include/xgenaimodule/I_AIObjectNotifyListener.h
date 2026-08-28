#pragma once
#include <cstddef>
#include <cstdint>

// -----------------------------------------------
// wh::xgenaimodule::I_AIObjectNotifyListener -- AI-object notify facet
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x08. Not RTTR-scoped.
// -----------------------------------------------
// Secondary action vtables (e.g. 0x183A2E070) have a single function slot and
// no virtual destructor. I_Element privately inherits this at mdisp=0 and
// overrides slot 0 (0x1811E95A0). Argument width is one qword; the source
// type is not encoded.

namespace wh::xgenaimodule {

class I_AIObjectNotifyListener {
public:
    virtual void unk_00(std::uint64_t arg) = 0;           // [0] 0x18183727C on actions
};

static_assert(sizeof(I_AIObjectNotifyListener) == 0x08,
              "I_AIObjectNotifyListener size mismatch");

}  // namespace wh::xgenaimodule
