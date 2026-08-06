#pragma once
#include <cstdint>
#include "S_Tracker.h"
#include "E_QuestProgress.h"
#include "../conceptmodule/C_AutoTriggerable.h"
#include "../conceptmodule/C_TemplatedNode.h"
#include "../conceptmodule/C_PortRef.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../framework/C_LocalizedString.h"
#include "../framework/S_ResourceHandle.h"

// -----------------------------------------------
// wh::questmodule::C_Objective -- quest objective node (KCD2 1.5.6, kd7u).
// modeled sizeof 0x110 [alloc UNPROVEN].
// -----------------------------------------------
// Own vtable 0x183A73BB8; ctor sub_180ACF804 (base chain sub_180ACF8AC:
// C_AutoTriggerable<C_TemplatedNode> -> C_TemplatedNode -> C_Node -> C_SharedResource;
// all four confirmed by the rttr _smart_ptr converters at 0x184C80620..0x184C836F0).
// CHEAT: the tracker port at +0x98 carries the objective's S_Tracker payload.
// CHEAT: m_name @+0xD8 is the objective's INTERNAL graph-node name (quest XML
// <Objective Name="...">), used as the registry key by
// C_UIQuestLog::AddObjectiveCompassMarkers (sub_180DC5F24). It is NOT localizable.
// The DISPLAY name is m_locText @+0xE0 = the <LocalizedName StringName="..."> loc
// key (rows in text_ui_quest.xml) -- prepare it with C_LocalizedString::Standardize,
// then resolve it through C_LocalizedString::Localize
// (runtime-verified 2026-07-10: using m_name shows the raw node name).
//
// === STATE LOOKUP (2026-08-07, dump-verified) ===
// GetStateEntry (0x181F38AC0) does NOT read a member directly: it builds a string key
// from m_port58's resolved value, then binary-searches m_vecF0 for it.  ON A MISS it
// returns the process-wide fallback entry &unk_1855E1450, whose state field reads 3 --
// i.e. E_QuestProgress::Failed.  Also consumed by C_UIQuestLog::AddQuestCompassMarkers
// and ::GetObjectiveMarkerTargets, so it is the module's central objective-state
// accessor, not a one-off.
//
// === WHY A STANDALONE C_Objective CRASHES ON ANY Set* PULSE ===
// Proven from a full dump (AV 0xC0000005 at 0x1804FD21F, rdx=0x10, thread 19016):
//   1. pulse -> C_Node::Execute -> OnTriggered [vtable slot 33] (0x180DC3BDC)
//   2. GetState() misses m_vecF0 (empty on a node we built ourselves) -> fallback
//      entry -> state == 3 (Failed), which is exactly the value that gates the
//      "objective failed" notification branch
//   3. that branch calls sub_180DC3DE8, which zero-inits its out-param and asks
//      sub_180C24A34 for the node's OWNER via the {slot,generation} handle at
//      C_Node+0x1C, resolved against the registry at
//      S_GameContext+0x120 -> +0x18 -> +0x10 (sub_180698748, which checks BOTH the
//      slot and the generation byte).  A factory-built node parented to a synthetic
//      module has no valid handle, so the lookup returns null and the out-param stays 0
//   4. CryStringT copy-ctor (0x1804FD208) then does `mov rcx,[rdx]` with rdx = 0+0x10
// So the node assumes "state Failed => I have an owner and localized text to announce".
// Both assumptions hold only inside a deserialized quest graph.  Not guardable from
// outside without synthesising quest state; LuaUtils simply does not expose this node.

namespace wh::questmodule {

class C_Objective : public conceptmodule::C_AutoTriggerable<conceptmodule::C_TemplatedNode> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Objective;

    // [33] 0x180DC3BDC -- runs on any input pulse (SetProgress/SetTracker both land
    // here). Compares the two port refs, dispatches m_signal48, and on state 3 raises
    // the failed-objective notification described above.
    virtual void OnTriggered(void* execContext);

    // 0x181F38AC0 -- key from m_port58 -> binary search m_vecF0 -> entry; returns the
    // shared fallback &unk_1855E1450 (state 3) when the key is absent. Never null.
    void* GetStateEntry();
    // 0x180DC3E88 -- *(uint32*)(GetStateEntry() + 8).
    // E_QuestProgress domain is LIKELY (matches S_QuestStateChangedData::m_newState and
    // the value dispatched to m_signal48), not certified from the field's own type.
    E_QuestProgress GetState();

    // +0x48  Dispatched by sub_180DC3B1C(&this, state, this, payload) on state change:
    //        *m_signal48 is an array of {void* receiver, fn(receiver,state,objective,
    //        payload)} pairs at 0x10 stride, with uint16 re-entrancy counters in the
    //        trailing bytes. That is a MULTICAST SIGNAL, which does not match the
    //        S_ResourceHandle type IDA has applied here -- [type CONFLICT, signal use
    //        is the verified one].
    framework::S_ResourceHandle m_signal48;
    conceptmodule::C_PortRef m_port58;                       // +0x58  untyped port ref (sub_1806B2890); its lazy cache
                                                             //        (m_resolved @+0x88, m_cachedPort @+0x90) is filled on
                                                             //        first resolve, not by the ctor (dtor sub_1806B30CC).
                                                             //        Its resolved value is the m_vecF0 lookup key.
    conceptmodule::C_TypedPortRef<S_Tracker> m_trackerPort;  // +0x98  objective tracker port
    CryStringT<char> m_name;                                 // +0xD8  objective name shown on map/compass markers
                                                             //        (VERIFIED: read as the marker name by sub_180DC5F24
                                                             //        and the map quest-marker builder; stored into
                                                             //        C_UIQuestLog's questId->{name,marks} registry).
                                                             //        ctor: interned empty string (sub_1804FD80C()+3).
    framework::C_LocalizedString m_locText;                  // +0xE0  localized objective text (ctor sub_1803D28B4);
                                                             //        distinct from m_name [exact consumer UNVERIFIED --
                                                             //        likely the quest-log body/description]
    // +0xF0..+0x108 -- flat sorted map, binary-searched by sub_181F3B470 (lower_bound
    // sub_181F36470 + a strcmp tail). Element stride 0x18: key CryStringT<char> @+0x00,
    // and the value BOTH readers take is at @+0x08 (sub_181F38AC0 0x181F38B8F and
    // sub_180DC3BDC 0x180DC3CBE) -- an earlier note here put the value at +0x10, which
    // no reader matches; the third qword is [UNRESOLVED].
    void*    m_vecF0Begin;                                   // +0xF0  begin
    uint64_t m_vecF0Size;                                    // +0xF8  element count (dtor loop sub_181F317D0, stride 0x18)
    uint64_t m_vecF0Cap;                                     // +0x100 capacity (dtor frees begin via sub_181AB5160 if !=0)
    uint8_t  m_flag108;                                      // +0x108 ctor 0
    uint8_t  _pad109[3];                                     // +0x109
    int32_t  m_param10C;                                     // +0x10C ctor -1 [role UNVERIFIED]
};
static_assert(sizeof(C_Objective) == 0x110, "modeled extent (ctor field extent; alloc UNPROVEN)");
static_assert(offsetof(C_Objective, m_trackerPort) == 0x98, "tracker port at +0x98");
static_assert(offsetof(C_Objective, m_vecF0Begin) == 0xF0, "state map begin at +0xF0");

}  // namespace wh::questmodule
