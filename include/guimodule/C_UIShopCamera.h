#pragma once
#include <cstddef>
#include <cstdint>
#include "C_UIBase.h"
#include "C_UILightsManager.h"
#include "framework/C_Signal.h"
#include "framework/I_UICamera.h"
#include "CryEngine/CryCommon/Cry_Math.h"

namespace wh::guimodule {

class C_UIShop;

class C_UIShopCamera : public C_UIBase,
                       public wh::framework::I_UICamera {
public:
    explicit C_UIShopCamera(C_UIShop* owner);                     // 0x18146D304
    ~C_UIShopCamera() override;                                   // primary [0] 0x182BA5BCC

    void Update() override;                                       // [4] 0x180568444
    void _vf1() override;                                         // I_UICamera [1] 0x181630B60
    void _vf2() override;                                         // I_UICamera [2] 0x1815A1020

    wh::shared::C_Signal<> m_changed;                             // +0x18
    Vec3 m_vectors28[8];                                          // +0x28, roles unverified
    C_UILightsManager m_lights;                                   // +0x88
    Vec3 m_vectorsC8[3];                                          // +0xC8, roles unverified
    std::uint32_t m_unknownEC;                                    // +0xEC
    std::uint8_t m_runtimeTimer[0x30];                            // +0xF0
    C_UIShop* m_owner;                                            // +0x120
};

static_assert(offsetof(C_UIShopCamera, m_lights) == 0x88,
              "C_UIShopCamera::m_lights offset mismatch");
static_assert(sizeof(C_UIShopCamera) == 0x128,
              "C_UIShopCamera size mismatch");

}  // namespace wh::guimodule
