#pragma once

#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryString.h"
#include "C_ActorParamAction.h"
#include "C_ItemHolder.h"
#include "I_ActorAction.h"
#include "I_ActorActionCarry.h"
#include "S_CarryItemActionParams.h"

namespace wh::entitymodule {

using C_ActorActionCarryItemBase =
    C_ActorParamAction<S_CarryItemActionParams, I_ActorAction>;

class C_ActorActionCarryItem
    : public C_ActorActionCarryItemBase,
      public C_ItemHolder,
      public I_ActorActionCarry {
public:
    explicit C_ActorActionCarryItem(C_ActionActor& actor);               // 0x181391884
    ~C_ActorActionCarryItem() override;                                  // [0] 0x18180B748
    bool _vf8(const _smart_ptr<wh::framework::I_Action>& other) const override; // [8] 0x181380004
    std::int32_t GetActionTypeId() const override;                       // [14] 0x181A7DF40 returns 29
    const char* GetActionName() const override;                          // [18] 0x18287BAB8
    RTTR_ENABLE(C_ActorActionCarryItemBase, C_ItemHolder, I_ActorActionCarry) // [23..25], vtable 0x183B6F448
    std::int32_t GetStaticTypeId() const override;                       // [26] 0x181A72600
    void GetDebugLabel(CryStringT<char>* output) override;               // [30] 0x18287B614
    void GetTagRange(void* output) override;                             // [31] 0x181978788
    void GetDefaultAnimBlock(void* output) override;                     // [34] 0x1815791E4
    void SetObjectFlagsAndAdvance(char flag0, char flag1) override;      // [35] 0x1808569D4
    void Serialize(void* archive) override;                              // [36] 0x18287CB54
    bool OnStart() override;                                             // [38] 0x181083478
    void OnStop() override;                                              // [39] 0x181083644
    std::int64_t OnTick() override;                                      // [41] 0x18091030C; live Tick path supplies dt in xmm1
    void GetNameString(void* output) const override;                     // [45] 0x18287D668

    E_ItemHolderType GetHolderType() const override;                     // +0x80 [1] 0x181A78EC0 returns 6
    void _vf3(const ItemVisitor& visitor) override;                      // +0x80 [3] 0x18287A9A0
    void _vf9(C_Item* item, E_ItemHolderChangeFlags flags,
              std::uint32_t amount) override;                            // +0x80 [9] 0x1810838F4
    void _vf10(C_Item* item, E_ItemHolderChangeFlags flags,
               std::uint32_t amount) override;                           // +0x80 [10] 0x1819CBC20

    void unk_0() override;                                               // +0x88 [0] 0x181A82520 sets m_carryFlag

    std::uint8_t m_mode;                                                 // +0x90 observed 0, 1, 3
    std::uint8_t m_padding91[7];                                         // +0x91
    std::uint64_t m_unknown98;                                           // +0x98 ctor 0
    std::uint32_t m_attachCrc;                                           // +0xA0 case-insensitive CRC of "Attach"
    std::uint32_t m_detachCrc;                                           // +0xA4 case-insensitive CRC of "Detach"
    std::uint64_t m_unknownA8;                                           // +0xA8 ctor 0
    std::uint8_t m_unknownB0[0x10];                                      // +0xB0 ctor 0
    std::uint32_t m_unknownC0;                                           // +0xC0 ctor 0
    std::uint8_t m_paddingC4[4];                                         // +0xC4
    std::uint64_t m_unknownC8;                                           // +0xC8 ctor 0; OnStop tears down
    float m_timer;                                                       // +0xD0 decremented by OnTick when m_mode == 3
    bool m_carryFlag;                                                    // +0xD4 I_ActorActionCarry::unk_0
    std::uint8_t m_paddingD5[3];                                         // +0xD5
};

static_assert(offsetof(C_ActorActionCarryItemBase, m_params) == 0x50,
              "carry-item params offset mismatch");
static_assert(offsetof(C_ActorActionCarryItem, m_mode) == 0x90,
              "C_ActorActionCarryItem::m_mode offset mismatch");
static_assert(offsetof(C_ActorActionCarryItem, m_attachCrc) == 0xA0,
              "C_ActorActionCarryItem::m_attachCrc offset mismatch");
static_assert(offsetof(C_ActorActionCarryItem, m_detachCrc) == 0xA4,
              "C_ActorActionCarryItem::m_detachCrc offset mismatch");
static_assert(offsetof(C_ActorActionCarryItem, m_timer) == 0xD0,
              "C_ActorActionCarryItem::m_timer offset mismatch");
static_assert(offsetof(C_ActorActionCarryItem, m_carryFlag) == 0xD4,
              "C_ActorActionCarryItem::m_carryFlag offset mismatch");
static_assert(sizeof(C_ActorActionCarryItem) == 0xD8,
              "C_ActorActionCarryItem size mismatch");

} // namespace wh::entitymodule
