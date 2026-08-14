#pragma once
#include "C_LockBase.h"

namespace wh::entitymodule {

class C_LockpickableEntity : public C_LockBase {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_LockpickableEntity;

    ~C_LockpickableEntity() override;                                // [0] 0x1819BF094
    void GetMemoryUsage(ICrySizer* sizer) const override;            // [6] 0x1824AA0F8
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override; // [11] 0x1827D22E8
    bool GetEntityPoolSignature(TSerialize signature) override;     // [13] 0x182A89B6C
    void Release() override;                                        // [14] 0x1803A5684
    const char* GetExtensionName() const override;                   // [29] returns Lockpickable

    RTTR_ENABLE() // [31..33]
};
static_assert(sizeof(C_LockpickableEntity) == 0x70,
              "C_LockpickableEntity must be 0x70");

}  // namespace wh::entitymodule
