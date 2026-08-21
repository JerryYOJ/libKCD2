#pragma once
#include <cstdint>
#include <cstddef>
#include <vector>
#include "../CryEngine/CryCommon/CryString.h"
#include "I_ChatFollowManager.h"
#include "I_ChatFollowFocus.h"
#include "../game/I_EntitySideEffectCallback.h"
#include "../framework/I_SourceMonitorListener.h"

// -----------------------------------------------
// wh::entitymodule::C_ChatFollowManager -- KCD2 WHGame.dll.  sizeof 0x78.
// -----------------------------------------------
// RTTI : I_ChatFollowManager @0, I_EntitySideEffectCallback @8,
//        I_SourceMonitorListener @16.
// Factory/ctor sub_180BC7050 (alloc 0x78). C_Player+0xCE8.
// Zero-stick drive is C_ActorActionFollow (0x18287A510), not this class.

namespace wh::entitymodule {

class C_Player;
class I_ChatFollowFocus;

class C_ChatFollowManager
    : public I_ChatFollowManager
    , public wh::game::I_EntitySideEffectCallback
    , public wh::framework::I_SourceMonitorListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ChatFollowManager;
    C_Player*           m_pOwner;            // +0x18
    I_ChatFollowFocus*  m_pFocus;            // +0x20  Start/StopFollow
    I_ChatFollowFocus*  m_pFollowLock;       // +0x28  copy of focus when bit1
    std::vector<int32_t> m_sideEffectTypes;  // +0x30  entity vt+0x430 ints
    int32_t             m_followIndex;       // +0x48  -1 empty; indexes player+0xCF0
    uint32_t            _pad4C;              // +0x4C
    uint64_t            m_hintHead;          // +0x50  dtor sub_1803D2880
    CryStringT<char>    m_hint;              // +0x58
    uint8_t             m_hasHint;           // +0x60
    uint8_t             _pad61[7];           // +0x61
    uint8_t             m_followFlags;       // +0x68  bits 0-1; bit1 = hard follow
    uint8_t             _pad69[7];           // +0x69
    int64_t             m_cooldown;          // +0x70  CTimeValue; ctor -100000
};
static_assert(sizeof(C_ChatFollowManager) == 0x78, "C_ChatFollowManager must be 0x78");
static_assert(offsetof(C_ChatFollowManager, m_pOwner) == 0x18, "owner");
static_assert(offsetof(C_ChatFollowManager, m_followIndex) == 0x48, "index");
static_assert(offsetof(C_ChatFollowManager, m_cooldown) == 0x70, "cooldown");

}  // namespace wh::entitymodule
