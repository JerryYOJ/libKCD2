#pragma once
#include <cstddef>
#include <cstdint>
#include "../framework/WUID.h"
#include "C_CachedPuppet.h"

namespace Offsets {
struct IEntity;
}

namespace wh::entitymodule {
class C_Actor;
}

namespace wh::xgenaimodule {

// Entity-backed puppet used by ordinary dynamic linkables and as the data-bearing
// base of the SmartObject-side C_SOPuppet leaf.
class C_AIPuppet : public C_CachedPuppet {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_AIPuppet;
    ~C_AIPuppet() override;                 // [0] 0x18047B120
    void _vf1() override;                   // [1] 0x180479B40
    void* _vf2() override;                  // [2] 0x180602360, returns m_pEntity
    void* _vf3() override;                  // [3] 0x180602360, returns m_pEntity
    void _vf4() override;                   // [4] 0x181A749E0
    void UpdateCachedTransform() override;  // [5] 0x180647EA4
    void _vf6() override;                   // [6] 0x180761604
    void _vf7() override;                   // [7] 0x180D44DC8
    void _vf8() override;                   // [8] 0x183450898
    void _vf9() override;                   // [9] 0x18041B838
    void _vf10() override;                  // [10] 0x1803E5410
    void _vf11() override;                  // [11] 0x1803E3B40
    void _vf12() override;                  // [12] 0x180813048
    void _vf13() override;                  // [13] 0x18081351C
    void _vf14() override;                  // [14] 0x18087780C
    void _vf15() override;                  // [15] 0x180732A14
    void _vf16() override;                  // [16] 0x1807E7A94
    void _vf17() override;                  // [17] 0x18081362C
    void _vf18() override;                  // [18] 0x180953E58
    void _vf19() override;                  // [19] 0x183451C70
    void _vf20() override;                  // [20] 0x1807FE0FC
    void* _vf21() override;                 // [21] 0x181A8B5A0

    Vec3 m_worldPosition;               // +0x08
    Vec3 m_forwardDirection;            // +0x14
    CryStringT<char> m_name;             // +0x20, exact role OPEN
    std::uint32_t m_transformFrame;      // +0x28, compared with the global frame stamp
    bool m_staticTransform;              // +0x2C, SmartObject path receives !bMovingSmartObject
    std::uint8_t _pad2D[3];              // +0x2D
    framework::WUID m_wuid;              // +0x30
    Offsets::IEntity* m_pEntity;         // +0x38, borrowed
    entitymodule::C_Actor* m_pActor;     // +0x40, borrowed cache
};
static_assert(sizeof(C_AIPuppet) == 0x48, "C_AIPuppet must be 0x48");
static_assert(offsetof(C_AIPuppet, m_worldPosition) == 0x08,
              "cached world position must be at 0x08");
static_assert(offsetof(C_AIPuppet, m_wuid) == 0x30,
              "puppet WUID must be at 0x30");
static_assert(offsetof(C_AIPuppet, m_pEntity) == 0x38,
              "borrowed entity must be at 0x38");

}  // namespace wh::xgenaimodule
