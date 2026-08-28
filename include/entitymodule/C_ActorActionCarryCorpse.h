#pragma once

#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryString.h"
#include "C_ActorAnimatedAction.h"
#include "I_ActorAction.h"
#include "I_ActorActionCarry.h"
#include "S_CarryCorpseActionParams.h"

namespace wh::entitymodule {

using C_ActorActionCarryCorpseBase =
    C_ActorAnimatedAction<S_CarryCorpseActionParams, I_ActorAction>;

class C_ActorActionCarryCorpse
    : public C_ActorActionCarryCorpseBase,
      public I_ActorActionCarry {
public:
    explicit C_ActorActionCarryCorpse(C_ActionActor& actor);             // 0x182878520
    ~C_ActorActionCarryCorpse() override;                                // [0] 0x182878E2C
    bool _vf8(const _smart_ptr<wh::framework::I_Action>& other) const override; // [8] 0x18287902C
    std::int32_t GetActionTypeId() const override;                       // [14] 0x181A7F5B0 returns 35
    const char* GetActionName() const override;                          // [18] 0x18287BAAC
    RTTR_ENABLE(C_ActorActionCarryCorpseBase, I_ActorActionCarry)        // [23..25], vtable 0x184700B78
    void GetDebugLabel(CryStringT<char>* output) override;               // [30] 0x18287B5D8
    void GetTagRange(void* output) override;                             // [31] 0x18287B22C
    void GetDefaultAnimBlock(void* output) override;                     // [34] 0x18287B33C
    void SetObjectFlagsAndAdvance(char flag0, char flag1) override;      // [35] 0x18194B504
    void Serialize(void* archive) override;                              // [36] 0x18287CB24
    bool OnStart() override;                                             // [38] 0x182879F54
    void OnStop() override;                                              // [39] 0x18287A370
    void GetNameString(void* output) const override;                     // [45] 0x18287D808
    void unk_50() override;                                              // [50] 0x18287C214
    void unk_51() override;                                              // [51] 0x18287C264
    void unk_53() override;                                              // [53] 0x18287C264

    void unk_0() override;                                               // +0x88 [0] 0x18287CA38
};

static_assert(offsetof(C_ActorActionCarryCorpseBase, m_params) == 0x50,
              "carry-corpse params offset mismatch");
static_assert(offsetof(C_ActorActionCarryCorpseBase, m_animationToken) == 0x78,
              "carry-corpse animated token offset mismatch");
static_assert(offsetof(C_ActorActionCarryCorpseBase, m_advanced) == 0x80,
              "carry-corpse m_advanced offset mismatch");
static_assert(offsetof(C_ActorActionCarryCorpseBase, m_blocked) == 0x81,
              "carry-corpse m_blocked offset mismatch");
static_assert(sizeof(C_ActorActionCarryCorpse) == 0x90,
              "C_ActorActionCarryCorpse size mismatch");

} // namespace wh::entitymodule
