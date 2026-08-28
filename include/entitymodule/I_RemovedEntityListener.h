#pragma once
#include <cstddef>
#include "../crysystem/IEntitySystemSink.h"

namespace wh::entitymodule {

class I_RemovedEntityListener : public ::IEntitySystemSink {
public:
    bool OnBeforeSpawn(SEntitySpawnParams& params) override;             // [1] 0x18041A6A0 returns true
    void OnSpawn(IEntity* entity, SEntitySpawnParams& params) override;   // [2] 0x1803B6E80
    bool OnRemove(IEntity* entity) override = 0;                         // [3] leaf-specific
    void OnReused(IEntity* entity, SEntitySpawnParams& params) override;  // [4] 0x1803B6E80
    void OnEvent(IEntity* entity, SEntityEvent& event) override;          // [5] 0x1803B6E80
    void GetMemoryUsage(ICrySizer* sizer) const override;                 // [6] 0x1803B6E80
    const char* GetName() const override = 0;                             // [7] leaf-specific
};

static_assert(sizeof(I_RemovedEntityListener) == 0x08,
              "I_RemovedEntityListener size mismatch");

} // namespace wh::entitymodule
