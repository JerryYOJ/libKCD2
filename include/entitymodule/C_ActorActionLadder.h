#pragma once

#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryString.h"
#include "C_ActorAnimatedAction.h"
#include "I_ActorAction.h"
#include "S_LadderActionParams.h"

namespace wh::entitymodule {

using C_ActorActionLadderBase =
    C_ActorAnimatedAction<S_LadderActionParams, I_ActorAction>;

class C_ActorActionLadder : public C_ActorActionLadderBase {
public:
    explicit C_ActorActionLadder(C_ActionActor& actor);                  // 0x180F49F4C
    ~C_ActorActionLadder() override;                                     // [0] 0x180F49930
    std::int32_t GetActionTypeId() const override;                       // [14] 0x181A7DF60 returns 34
    const char* GetActionName() const override;                          // [18] 0x18287BAD0
    RTTR_ENABLE(C_ActorActionLadderBase)                                 // [23..25], vtable 0x183ADABD8
    void GetDebugLabel(CryStringT<char>* output) override;               // [30] 0x18287B68C
    void GetTagRange(void* output) override;                             // [31] 0x1819CB4A4
    void GetDefaultAnimBlock(void* output) override;                     // [34] 0x1817907F8
    void SetObjectFlagsAndAdvance(char flag0, char flag1) override;      // [35] 0x1819C0B08
    void Serialize(void* archive) override;                              // [36] 0x18287CBA4
    bool OnStart() override;                                             // [38] 0x180F49D5C
    void OnStop() override;                                              // [39] 0x18040A87C
    std::int64_t OnTick() override;                                      // [41] 0x181626EAC
    void GetNameString(void* output) const override;                     // [45] 0x18287D808
    void unk_50() override;                                              // [50] 0x18287C238
    void unk_51() override;                                              // [51] 0x181846890
    void unk_53() override;                                              // [53] 0x181846890

    std::uint8_t m_ladderRuntime[0x74];                                  // +0x80 ctor 0x180F49FA8; unaligned path state
    float m_fraction;                                                    // +0xF4 ctor dword 0xBF800000
};

static_assert(offsetof(C_ActorActionLadderBase, m_params) == 0x50,
              "ladder params offset mismatch");
static_assert(offsetof(C_ActorActionLadderBase, m_animationToken) == 0x70,
              "ladder animated token offset mismatch");
static_assert(offsetof(C_ActorActionLadder, m_ladderRuntime) == 0x80,
              "C_ActorActionLadder::m_ladderRuntime offset mismatch");
static_assert(offsetof(C_ActorActionLadder, m_fraction) == 0xF4,
              "C_ActorActionLadder::m_fraction offset mismatch");
static_assert(sizeof(C_ActorActionLadder) == 0xF8,
              "C_ActorActionLadder size mismatch");

} // namespace wh::entitymodule
