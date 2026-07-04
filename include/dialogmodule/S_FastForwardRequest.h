#pragma once

// -----------------------------------------------
// wh::dialogmodule::data::S_FastForwardRequest -- dialog fast-forward (SKIP) message
// (KCD2 1.5.6, kd7u).  sizeof 0x08.
// -----------------------------------------------
// RTTI TD 0x184B6F270; vtable 0x183E70390 (5 slots); ctor sub_18284C258. Polymorphic
// event object pushed into the dialog message queue: skips the CURRENT line. Senders
// live in the 0x18285026x..0x182855510 cluster. Derived: S_FastForwardRequestForAll
// (whole conversation), S_FastForwardRequestForRole (one role).
// CHEAT: the programmatic dialog-skip hook, complementing the wh_dlg_AutoSkip /
// wh_dlg_SkipCooldown ICVars cached on C_DialogInstance +0x370/+0x378.

namespace wh::dialogmodule::data {

struct S_FastForwardRequest {
    inline static constexpr auto RTTI = Offsets::RTTI_S_FastForwardRequest;
    virtual ~S_FastForwardRequest();   // [0]
    virtual int GetType();             // [1] message type id [signature UNVERIFIED]
    virtual void ClonePayload();       // [2] [signature UNVERIFIED]
    virtual void _vf3();               // [3] [role UNVERIFIED]
    virtual void* Clone();             // [4] [signature UNVERIFIED]
};
static_assert(sizeof(S_FastForwardRequest) == 0x08, "S_FastForwardRequest is vptr-only");

}  // namespace wh::dialogmodule::data
