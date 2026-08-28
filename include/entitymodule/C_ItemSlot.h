#pragma once

#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryString.h"
#include "../framework/I_ScheduleUpdatable.h"
#include "../framework/WUID.h"
#include "C_ItemHolder.h"
#include "C_LightCommonEditorProperties.h"
#include "I_GameObjectLight.h"
#include "S_ItemClassGUID.h"

namespace wh::entitymodule {

class C_Item;

class C_ItemSlot
    : public C_ItemHolder,
      public I_GameObjectLight,
      public C_LightCommonEditorProperties,
      public wh::framework::I_ScheduleUpdatable {
public:
    C_ItemSlot();                                                        // 0x1803A6744
    ~C_ItemSlot() override;                                              // [0] 0x1803A57A0 / deleting 0x1803A514C
    E_ItemHolderType GetHolderType() const override;                     // [1] 0x18041A6A0 returns ItemSlot
    void _vf2(const ItemVisitor& visitor) override;                      // [2] 0x182A69528
    void _vf3(const ItemVisitor& visitor) override;                      // [3] 0x182A695D4
    const framework::WUID& GetWuid() const override;                     // [7] 0x18161F13C
    void _vf8(C_Item* item, E_ItemHolderChangeFlags flags,
              std::uint32_t amount) override;                            // [8] 0x180F8FC84
    void _vf9(C_Item* item, E_ItemHolderChangeFlags flags,
              std::uint32_t amount) override;                            // [9] 0x1812B6890
    void _vf10(C_Item* item, E_ItemHolderChangeFlags flags,
               std::uint32_t amount) override;                           // [10] 0x1813E74C0
    RTTR_ENABLE(C_ItemHolder)                                            // [21..23], vtable 0x183A2DE30
    virtual void* unk_24();                                              // [24] 0x18066CD10
    virtual void unk_25();                                               // [25] 0x181F0F810
    virtual void unk_26();                                               // [26] 0x181F0EC70
    virtual S_ItemClassGUID GetItemClass() const;                        // [27] 0x181F0EC00 copies +0x70
    virtual void unk_28();                                               // [28] 0x181F0DA40
    virtual void unk_29();                                               // [29] 0x1808CCFA8
    virtual void unk_30();                                               // [30] 0x1815663C8
    virtual void unk_31();                                               // [31] 0x1809F1948
    virtual void unk_32();                                               // [32] 0x1803C314C
    virtual void unk_33();                                               // [33] 0x1803C38F4
    virtual void unk_34();                                               // [34] 0x182A6A37C
    virtual void unk_35();                                               // [35] 0x181F0F910
    virtual std::int32_t unk_36();                                       // [36] 0x181A74280 returns 7
    virtual std::int32_t unk_37();                                       // [37] 0x181A74280 returns 7

    void ScheduleUpdate(std::int32_t value) override;                    // +0x68 [0] 0x1808F3018

    bool HasItem() const;                                                // 0x1809E5498 RTTR "HasItem"/"IsItemInSlot"

    S_ItemClassGUID m_itemClass;                                         // +0x70 slot 27 / RTTR GetItemClass
    CryStringT<char> m_string80;                                         // +0x80 ctor empty
    CryStringT<char> m_string88;                                         // +0x88 ctor empty
    std::uint64_t m_unknown90;                                           // +0x90 ScheduleUpdate gate
    C_Item* m_item;                                                      // +0x98 HasItem
    std::uint8_t m_unknownA0[0x10];                                      // +0xA0 ctor 0
    std::uint64_t m_unknownB0;                                           // +0xB0
    std::uint32_t m_unknownB8;                                           // +0xB8 ctor 0xFFFFFFFF
    std::uint32_t m_unknownBC;                                           // +0xBC ctor 0x70007
    std::uint8_t m_unknownC0;                                            // +0xC0 ctor 1
    std::uint8_t m_flagsC1;                                              // +0xC1
    std::uint16_t m_unknownC2;                                           // +0xC2 ctor 0
    std::uint8_t m_unknownC4[0x10];                                      // +0xC4
    std::uint32_t m_unknownD4;                                           // +0xD4 ctor 0xFFFFFFFF
    std::uint64_t m_unknownD8;                                           // +0xD8 ctor 0xFFFFFFFFFFFFFFFF
};

static_assert(offsetof(C_ItemSlot, m_itemClass) == 0x70,
              "C_ItemSlot::m_itemClass offset mismatch");
static_assert(offsetof(C_ItemSlot, m_string80) == 0x80,
              "C_ItemSlot::m_string80 offset mismatch");
static_assert(offsetof(C_ItemSlot, m_item) == 0x98,
              "C_ItemSlot::m_item offset mismatch");
static_assert(offsetof(C_ItemSlot, m_unknownD8) == 0xD8,
              "C_ItemSlot::m_unknownD8 offset mismatch");
static_assert(sizeof(C_ItemSlot) == 0xE0,
              "C_ItemSlot size mismatch");

} // namespace wh::entitymodule
