#pragma once
#include "../framework/WUID.h"

namespace Offsets {
struct IEntity;
}

namespace wh::xgenaimodule {

class C_DynamicLinkableObject;

// The concrete seven-slot ABI is exact. The interface/concrete declaration split and
// original method spellings are not emitted independently by the binary.
class I_LinkableObjectHolder {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_I_LinkableObjectHolder;
    virtual ~I_LinkableObjectHolder() = default;                         // [0]
    virtual void SetTargetGuid(framework::WUID targetGuid) = 0;          // [1] raw seed writer
    virtual C_DynamicLinkableObject* _vf2() = 0;                         // [2] returns m_pObject
    virtual C_DynamicLinkableObject* _vf3() = 0;                         // [3] returns m_pObject
    virtual void Create(Offsets::IEntity* entity, bool withOwnership) = 0; // [4]
    virtual void Destroy() = 0;                                         // [5]
    virtual void _vf6() = 0;                                            // [6] no-op, role OPEN
};
static_assert(sizeof(I_LinkableObjectHolder) == 0x08,
              "I_LinkableObjectHolder must be 0x08");

}  // namespace wh::xgenaimodule
