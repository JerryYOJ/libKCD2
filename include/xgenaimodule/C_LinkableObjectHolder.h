#pragma once
#include <cstddef>
#include "I_LinkableObjectHolder.h"

namespace wh::xgenaimodule {

class C_LinkableObjectHolder : public I_LinkableObjectHolder {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_LinkableObjectHolder;
    ~C_LinkableObjectHolder() override;                                  // [0] 0x18096D57C, trivial
    void SetTargetGuid(framework::WUID targetGuid) override;              // [1] 0x181A72900
    C_DynamicLinkableObject* _vf2() override;                             // [2] 0x180947210
    C_DynamicLinkableObject* _vf3() override;                             // [3] 0x180947210
    void Create(Offsets::IEntity* entity, bool withOwnership) override;   // [4] 0x18096E2B4
    void Destroy() override;                                             // [5] 0x18096D63C
    void _vf6() override;                                                // [6] nullsub_1

    C_DynamicLinkableObject* m_pObject; // +0x08, owned through explicit Destroy
    framework::WUID m_targetGuid;       // +0x10, raw requested/restored WUID seed
};
static_assert(sizeof(C_LinkableObjectHolder) == 0x18,
              "C_LinkableObjectHolder must be 0x18");
static_assert(offsetof(C_LinkableObjectHolder, m_pObject) == 0x08,
              "linkable object pointer must be at 0x08");
static_assert(offsetof(C_LinkableObjectHolder, m_targetGuid) == 0x10,
              "target WUID seed must be at 0x10");

}  // namespace wh::xgenaimodule
