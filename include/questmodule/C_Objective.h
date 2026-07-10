#pragma once
#include <cstdint>
#include "S_Tracker.h"
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
// C_AutoTriggerable<C_TemplatedNode> -> C_TemplatedNode -> C_Node -> C_SharedResource).
// CHEAT: the tracker port at +0x98 carries the objective's S_Tracker payload.
// CHEAT: m_name @+0xD8 is the objective's INTERNAL graph-node name (quest XML
// <Objective Name="...">), used as the registry key by
// C_UIQuestLog::AddObjectiveCompassMarkers (sub_180DC5F24). It is NOT localizable.
// The DISPLAY name is m_locText @+0xE0 = the <LocalizedName StringName="..."> loc
// key (rows in text_ui_quest.xml) -- resolve it via C_LocalizedString::Resolve
// (runtime-verified 2026-07-10: resolving m_name shows the raw node name).

namespace wh::questmodule {

class C_Objective : public conceptmodule::C_AutoTriggerable<conceptmodule::C_TemplatedNode> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Objective;
    framework::S_ResourceHandle m_ref48;                     // +0x48  (&unk_1856691B8) [target UNVERIFIED]
    conceptmodule::C_PortRef m_port58;                       // +0x58  untyped port (sub_1806B2890)
    uint64_t m_unk90;                                        // +0x90  not written by ctor (typed-port
                                                             //        tail slot candidate)
    conceptmodule::C_TypedPortRef<S_Tracker> m_trackerPort;  // +0x98  objective tracker port
    CryStringT<char> m_name;                                 // +0xD8  objective name shown on map/compass markers
                                                             //        (VERIFIED: read as the marker name by sub_180DC5F24
                                                             //        and the map quest-marker builder; stored into
                                                             //        C_UIQuestLog's questId->{name,marks} registry).
                                                             //        ctor: interned empty string (sub_1804FD80C()+3).
    framework::C_LocalizedString m_locText;                  // +0xE0  localized objective text (ctor sub_1803D28B4);
                                                             //        distinct from m_name [exact consumer UNVERIFIED --
                                                             //        likely the quest-log body/description]
    uint64_t m_unkF0;                                        // +0xF0  ctor 0
    uint64_t m_unkF8;                                        // +0xF8  ctor 0
    uint64_t m_unk100;                                       // +0x100 ctor 0
    uint8_t  m_flag108;                                      // +0x108 ctor 0
    uint8_t  _pad109[3];                                     // +0x109
    int32_t  m_param10C;                                     // +0x10C ctor -1 [role UNVERIFIED]
};
static_assert(sizeof(C_Objective) == 0x110, "modeled extent (ctor field extent; alloc UNPROVEN)");
static_assert(offsetof(C_Objective, m_trackerPort) == 0x98, "tracker port at +0x98");

}  // namespace wh::questmodule
