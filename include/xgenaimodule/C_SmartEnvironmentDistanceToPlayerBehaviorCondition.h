#pragma once
#include <cstdint>
#include "C_AbstractSmartEnvironemntBehaviorCondition.h"

// -----------------------------------------------
// wh::xgenaimodule::C_SmartEnvironmentDistanceToPlayerBehaviorCondition :
// C_AbstractSmartEnvironemntBehaviorCondition -- distance-to-player SE
// condition (KCD2 WHGame.dll 1.5.6, kd7u).  Size ~0x18 (factory enum 8 ->
// sub_1832D6224, new 24 -- but the enum->class mapping is by ctor-address
// proximity, UNVERIFIED [U]) -- NO static_assert.
// -----------------------------------------------
// Vtable rva 0x3FEBAB8 (13 slots; per-slot bodies not dumped [U]).  Own
// members beyond the 0x10 base NOT itemized [U].

namespace wh::xgenaimodule {

class C_SmartEnvironmentDistanceToPlayerBehaviorCondition : public C_AbstractSmartEnvironemntBehaviorCondition {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_SmartEnvironmentDistanceToPlayerBehaviorCondition;
    void _vf1() override;  void _vf2() override;  void _vf3() override;
    void _vf4() override;  void _vf5() override;  void _vf6() override;
    void _vf7() override;  void _vf8() override;  void _vf9() override;
    void _vf10() override; void _vf11() override;   // [1..11] impls [U roles]

    uint8_t _unk10[8];   // +0x10  [U -- alloc suggests 0x18 total but mapping unverified]
};
// size UNVERIFIED (enum->class mapping by proximity) -- no static_assert.

}  // namespace wh::xgenaimodule
