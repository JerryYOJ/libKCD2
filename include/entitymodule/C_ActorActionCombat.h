#pragma once

#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryString.h"
#include "C_ActorParamAction.h"
#include "I_ActorAction.h"
#include "I_RiderAnimCombiner.h"
#include "S_CombatActionParams.h"

namespace wh::entitymodule {

using C_ActorActionCombatBase =
    C_ActorParamAction<S_CombatActionParams, I_ActorAction>;

class C_ActorActionCombat
    : public C_ActorActionCombatBase,
      public I_RiderAnimCombiner {
public:
    explicit C_ActorActionCombat(C_ActionActor& actor);                  // factory 0x1812EE288 / body 0x1812EE354
    ~C_ActorActionCombat() override;                                     // [0] 0x1812EE144
    bool _vf8(const _smart_ptr<wh::framework::I_Action>& other) const override; // [8] 0x18137FDA8
    void _vf9() override;                                                // [9] 0x1816D52CC; body reads a begin/end pointer in rdx
    std::int32_t GetActionTypeId() const override;                       // [14] 0x181A74D00 returns 12
    const char* GetActionName() const override;                          // [18] 0x18287BAAC
    RTTR_ENABLE(C_ActorActionCombatBase, I_RiderAnimCombiner)            // [23..25], vtable 0x183B56BE0
    std::int32_t GetStaticTypeId() const override;                       // [26] 0x181A823C0
    void GetDebugLabel(CryStringT<char>* output) override;               // [30] 0x18287B5D8
    void GetTagRange(void* output) override;                             // [31] 0x18180DE5C
    bool StopAndRelease(void* smartPtr) override;                        // [32] 0x182879120
    void GetDefaultAnimBlock(void* output) override;                     // [34] 0x181394398
    void SetObjectFlagsAndAdvance(char flag0, char flag1) override;      // [35] 0x18194B504
    void _vfOwn0() override;                                             // [37] 0x1819BB680 SetPriority(m_params.m_highPriority ? 2 : 1)
    bool OnStart() override;                                             // [38] 0x180C59ED8
    void OnStop() override;                                              // [39] 0x1810ED604
    std::int64_t OnTick() override;                                      // [41] 0x180738590
    void GetNameString(void* output) const override;                     // [45] 0x18287D668

    bool unk_0(bool flag, void* context) override;                       // +0x78 [0] 0x18287BAE8

    bool m_flag80;                                                       // +0x80 OnStop reads
    bool m_flag81;                                                       // +0x81 vf8 returns for one peer type
    bool m_flag82;                                                       // +0x82 vf8 returns for another peer type
    std::uint8_t m_padding83[5];                                         // +0x83
};

static_assert(offsetof(C_ActorActionCombatBase, m_params) == 0x50,
              "combat params offset mismatch");
static_assert(offsetof(C_ActorActionCombat, m_flag80) == 0x80,
              "C_ActorActionCombat::m_flag80 offset mismatch");
static_assert(offsetof(C_ActorActionCombat, m_flag81) == 0x81,
              "C_ActorActionCombat::m_flag81 offset mismatch");
static_assert(offsetof(C_ActorActionCombat, m_flag82) == 0x82,
              "C_ActorActionCombat::m_flag82 offset mismatch");
static_assert(sizeof(C_ActorActionCombat) == 0x88,
              "C_ActorActionCombat size mismatch");

} // namespace wh::entitymodule
