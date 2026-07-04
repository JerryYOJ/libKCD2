#pragma once
#include "../entitymodule/I_WorldInventoryListener.h"

// -----------------------------------------------
// wh::xgenaimodule::C_PerceptionItemListener : entitymodule::
// I_WorldInventoryListener -- feeds world-inventory item changes into the
// perception system (KCD2 WHGame.dll 1.5.6, kd7u).  sizeof NOT proven -> no size
// assert [U].
// -----------------------------------------------
// RTTI TD rva 0x4F4CD00; vtable 0x183FE6C40, 3 slots: [0] sub_1819DBEF4,
// [1] sub_181850510, [2] sub_1832AE9A4.  Registered in C_WorldInventory's
// C_Listeners<I_WorldInventoryListener,4> @+0x178.

namespace wh::xgenaimodule {

class C_PerceptionItemListener : public entitymodule::I_WorldInventoryListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_PerceptionItemListener;
    void _vf0() override;   // [0] sub_1819DBEF4 [U role; dtor placement unverified]
    void _vf1() override;   // [1] sub_181850510 [U role]
    void _vf2() override;   // [2] sub_1832AE9A4 [U role]
};
// members + sizeof unresolved -> no static_assert [U]

}  // namespace wh::xgenaimodule
