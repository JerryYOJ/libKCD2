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

namespace wh::questmodule {

class C_Objective : public conceptmodule::C_AutoTriggerable<conceptmodule::C_TemplatedNode> {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Objective;
    framework::S_ResourceHandle m_ref48;                     // +0x48  (&unk_1856691B8) [target UNVERIFIED]
    conceptmodule::C_PortRef m_port58;                       // +0x58  untyped port (sub_1806B2890)
    uint64_t m_unk90;                                        // +0x90  not written by ctor (typed-port
                                                             //        tail slot candidate)
    conceptmodule::C_TypedPortRef<S_Tracker> m_trackerPort;  // +0x98  objective tracker port
    CryStringT<char> m_strD8;                                // +0xD8  [role UNVERIFIED]
    framework::C_LocalizedString m_locE0;                    // +0xE0  [role UNVERIFIED]
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
