#pragma once

#include <cstddef>
#include <cstdint>

#include "C_LightCommonEditorProperties.h"
#include "I_GameObjectLight.h"
#include "I_TagPoint.h"

namespace wh::entitymodule {

class C_TagPoint
    : public I_TagPoint,
      public I_GameObjectLight,
      public C_LightCommonEditorProperties {
public:
    Offsets::IEntity* GetTagPointEntity() override;         // Primary [0] 0x18072DD20
    RTTR_ENABLE(I_TagPoint)                                  // Primary [1..3], vtable 0x183A2DB28

    ~C_TagPoint() override;                                 // Light secondary [0] thunk 0x182139D84
    void ProcessEvent(SEntityEvent& event) override;        // Light secondary [1] 0x181146FA0
    void _vf11() override;                                  // Light secondary [11] 0x18124267C
    void _vf13(std::uint64_t* value) override;              // Light secondary [13] 0x1804579F8
    void _vf17() override;                                  // Light secondary [17] 0x180457A04
    void GetRuntimeTypeToken(std::uint64_t* output) const override; // Shared [19]/editor [4]
    void* QueryInterfaceMutable(const void* type) override; // Shared [20]/editor [5]
    const void* QueryInterfaceConst(const void* type) const override; // Shared [21]/editor [6]
};

static_assert(sizeof(C_TagPoint) == 0x68,
              "C_TagPoint size mismatch");

}  // namespace wh::entitymodule
