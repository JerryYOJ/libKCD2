#pragma once
#include <cstdint>
#include <functional>
#include "E_ItemHolderChangeFlags.h"
#include "E_ItemHolderType.h"
#include "../framework/WUID.h"
#include "../rttr/rttr_enable.h"

// -----------------------------------------------
// wh::entitymodule::C_ItemHolder -- KCD2 WHGame.dll 1.5.6 (kd7u).
// -----------------------------------------------
// Vptr-only abstract item-container interface. Retail vtable 0x183A2DD68 has
// 24 slots; the RTTR_ENABLE trio occupies slots 21..23.

namespace wh::entitymodule {

class C_Item;
struct S_ItemClass;

class C_ItemHolder {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_ItemHolder;
    using ItemVisitor = std::function<void(C_Item&)>;

    virtual ~C_ItemHolder() = default; // [0] 0x182878EF4
    virtual E_ItemHolderType GetHolderType() const = 0; // [1] PURE
    virtual void _vf2(const ItemVisitor& visitor); // [2] 0x181E96D10, forwards to [3]
    virtual void _vf3(const ItemVisitor& visitor) = 0; // [3] PURE
    virtual void* _vf4(); // [4] 0x18066CD10, pointer-type role OPEN
    virtual void* _vf5(); // [5] 0x18066CD10, pointer-type role OPEN
    virtual bool _vf6() const; // [6] 0x180838AE0, role OPEN
    virtual const framework::WUID& GetWuid() const; // [7] 0x181A8A550
    virtual void _vf8(C_Item* item, E_ItemHolderChangeFlags flags,
                      std::uint32_t amount); // [8] nullsub_1
    virtual void _vf9(C_Item* item, E_ItemHolderChangeFlags flags,
                      std::uint32_t amount) = 0; // [9] PURE
    virtual void _vf10(C_Item* item, E_ItemHolderChangeFlags flags,
                       std::uint32_t amount) = 0; // [10] PURE
    virtual void _vf11(C_Item* item, E_ItemHolderChangeFlags flags,
                       std::uint32_t amount); // [11] nullsub_1
    virtual void _vf12(S_ItemClass* itemClass, E_ItemHolderChangeFlags flags,
                       std::uint32_t amount,
                       framework::WUID itemWuid); // [12] nullsub_1
    virtual bool _vf13(E_ItemHolderChangeFlags flags,
                       S_ItemClass* itemClass,
                       std::uint32_t amount) const; // [13] 0x18041A6A0
    virtual bool _vf14() const; // [14] 0x180838AE0, role OPEN
    virtual bool _vf15() const; // [15] 0x180838AE0, role OPEN
    virtual bool _vf16() const; // [16] 0x180838AE0, role OPEN
    virtual void _vf17(C_Item* consumedItem,
                       C_Item* survivingItem); // [17] nullsub_1, pre-merge replacement
    virtual void _vf18(C_Item* survivingItem,
                       framework::WUID consumedItemWuid,
                       std::uint32_t consumedAmount); // [18] nullsub_1, post-merge summary
    virtual void _vf19(C_Item* sourceItem,
                       C_Item* splitItem); // [19] nullsub_1, split item added
    virtual void _vf20(C_Item* item,
                       std::int32_t amountDelta,
                       std::uint32_t changeMask); // [20] nullsub_1, item changed

    RTTR_ENABLE() // [21..23]
};
static_assert(sizeof(C_ItemHolder) == 0x08,
              "C_ItemHolder must be vptr-only");

}  // namespace wh::entitymodule
