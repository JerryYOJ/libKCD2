#pragma once

namespace wh::entitymodule {

class I_ProjectileAreaDetectionListener {
public:
    virtual void OnProjectileDetected() = 0; // [0] behavior-derived; C_ProjectileInAreaTrigger 0x1829A9ED4
};

static_assert(sizeof(I_ProjectileAreaDetectionListener) == 0x08,
              "I_ProjectileAreaDetectionListener size mismatch");

} // namespace wh::entitymodule
