#pragma once
#include <cstddef>
#include <cstdint>
#include "C_LockBase.h"

namespace wh::entitymodule {

class C_AnimDoor : public C_LockBase {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_AnimDoor;

    ~C_AnimDoor() override;                                         // [0] 0x180965190
    void GetMemoryUsage(ICrySizer* sizer) const override;           // [6] 0x1829E1254
    bool Init(Offsets::IGameObject* gameObject) override;           // [7] 0x18133E8F0
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override; // [11] 0x1827D22E8
    bool GetEntityPoolSignature(TSerialize signature) override;    // [13] 0x1829E101C
    void Release() override;                                       // [14] 0x180965160
    const char* GetExtensionName() const override;                  // [29] returns AnimDoor
    bool CanUnlockWithItemClass(const CryGUID& itemClassId) const override; // [30]

    RTTR_ENABLE() // [31..33]

    wh::shared::C_Signal<> m_signal70; // +0x70, template payload/role OPEN
    wh::shared::C_Signal<> m_signal80; // +0x80, template payload/role OPEN
    wh::shared::C_Signal<> m_signal90; // +0x90, template payload/role OPEN
    wh::shared::C_Signal<> m_signalA0; // +0xA0, template payload/role OPEN
    std::uint32_t m_stateB0;           // +0xB0, role OPEN
    std::uint8_t m_flagB4;             // +0xB4, role OPEN
    std::int32_t m_gateCountB8;        // +0xB8, signed nesting gate; name reconstructed
};
static_assert(sizeof(C_AnimDoor) == 0xC0, "C_AnimDoor must be 0xC0");
static_assert(offsetof(C_AnimDoor, m_signal70) == 0x70,
              "first AnimDoor signal must be at 0x70");
static_assert(offsetof(C_AnimDoor, m_stateB0) == 0xB0,
              "AnimDoor state dword must be at 0xB0");
static_assert(offsetof(C_AnimDoor, m_gateCountB8) == 0xB8,
              "AnimDoor gate counter must be at 0xB8");

}  // namespace wh::entitymodule
