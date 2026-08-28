#pragma once

#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryString.h"
#include "C_ActorAction.h"
#include "I_ActorAction.h"

namespace wh::entitymodule {

using C_ActorActionJumpBase =
    C_ActorAction<I_ActorAction, wh::framework::C_Action<I_ActorAction>>;

class C_ActorActionJump : public C_ActorActionJumpBase {
public:
    explicit C_ActorActionJump(C_ActionActor& actor);                    // 0x1812C0420
    ~C_ActorActionJump() override;                                       // [0] 0x1812C030C
    bool _vf8(const _smart_ptr<wh::framework::I_Action>& other) const override; // [8] 0x18137FEAC
    void _vf9() override;                                                // [9] 0x1819A95FC; body reads a begin/end pointer in rdx
    std::int32_t GetActionTypeId() const override;                       // [14] 0x181A74270 returns 9
    const char* GetActionName() const override;                          // [18] 0x18287BA80
    RTTR_ENABLE(C_ActorActionJumpBase)                                   // [23..25], vtable 0x183B51B90
    void GetTagRange(void* output) override;                             // [31] 0x1819ADFA8
    bool OnStart() override;                                             // [38] 0x180CF7F98
    void OnStop() override;                                              // [39] 0x180CF8DF8
    void GetNameString(void* output) const override;                     // [45] 0x18287D668

    std::uint8_t m_jumpState[0x60];                                      // +0x68 ctor 0x1812C04D8
    bool m_blockLandInterrupt;                                           // +0xC8 vf8: false only if clear and other type is land
    std::uint8_t m_paddingC9[7];                                         // +0xC9
    _smart_ptr<wh::framework::I_Action> m_landAction;                    // +0xD0 vf9 copies the land peer
};

static_assert(offsetof(C_ActorActionJump, m_jumpState) == 0x68,
              "C_ActorActionJump::m_jumpState offset mismatch");
static_assert(offsetof(C_ActorActionJump, m_blockLandInterrupt) == 0xC8,
              "C_ActorActionJump::m_blockLandInterrupt offset mismatch");
static_assert(offsetof(C_ActorActionJump, m_landAction) == 0xD0,
              "C_ActorActionJump::m_landAction offset mismatch");
static_assert(sizeof(C_ActorActionJump) == 0xD8,
              "C_ActorActionJump size mismatch");

} // namespace wh::entitymodule
