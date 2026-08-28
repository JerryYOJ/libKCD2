#pragma once
#include "C_NPCProperty.h"

// -----------------------------------------------
// wh::xgenaimodule::activitysystem::C_NPCWatch : C_NPCProperty
// (KCD2 WHGame.dll 1.5.6). sizeof 0x50. 6 slots (0 new; overrides Bind/Unbind/ToDbgStr).
// -----------------------------------------------
// RTTI .?AVC_NPCWatch@activitysystem@xgenaimodule@wh@@
// vtable 0x183A82180, COL 0x1840DE1A0 offset 0, CHD 4 bases (single inheritance).
// ctor 0x180BCA630, deleting dtor 0x1832F80F0.
//
// A C_NPCProperty specialization that, once bound to a live I_NPC, additionally subscribes to
// that NPC's actor-event stream and re-emits single-byte codes on its own extra signal (+0x40) --
// used by Alarm/Hunt to detect e.g. "watch target invalidated" / "prey stopped" transitions
// without polling. Bind/Unbind (inherited slots [4]/[5]) install/remove that subscription;
// ToDbgStr additionally prints the watched NPC's debug name when bound.

namespace wh::xgenaimodule::activitysystem {

class C_NPCWatch : public C_NPCProperty {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_NPCWatch;

    const char* ToDbgStr() const override;  // [2] 0x1832F9BA4  "<empty>" or the watched NPC's debug name
    void Bind() override;                    // [4] 0x1832F83F8  subscribe to the watched NPC's actor-event stream, re-emit onto m_actorEventSignal
    void Unbind() override;                  // [5] 0x1832F8494  unsubscribe

    wh::shared::C_Signal<uint8_t> m_actorEventSignal;  // +0x40  single-byte actor-event re-emit; sentinel 0x18566C060
};
static_assert(sizeof(C_NPCWatch) == 0x50, "C_NPCWatch must be 0x50");
static_assert(offsetof(C_NPCWatch, m_actorEventSignal) == 0x40, "m_actorEventSignal at +0x40");

// The byte codes re-emitted on m_actorEventSignal (observed 0x15/0x16 in C_HuntDogObjective) are
// forwarded verbatim from the watched NPC's own actor-event hook -- their source enum is
// UNVERIFIED at this layer; document per-consumer where the values are actually branched on.

}  // namespace wh::xgenaimodule::activitysystem
