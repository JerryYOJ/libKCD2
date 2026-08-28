#pragma once
#include <cstddef>
#include "C_SharedResource.h"
#include "rttr/rttr_enable.h"

namespace wh::conceptmodule {

class I_ConceptScopeHelper {
public:
    virtual ~I_ConceptScopeHelper();
    virtual void AddScope(_smart_ptr<C_SharedResource> resource) = 0;       // [1]
    virtual void* ResolveScope(_smart_ptr<C_SharedResource> resource) = 0; // [2]
    virtual bool HasScope(_smart_ptr<C_SharedResource> resource) = 0;      // [3]
    virtual bool IsScopeActive(
        _smart_ptr<C_SharedResource> const& resource) = 0;                 // [4]
    RTTR_ENABLE() // [5..7]
};

static_assert(sizeof(I_ConceptScopeHelper) == 0x08,
              "I_ConceptScopeHelper size mismatch");

}  // namespace wh::conceptmodule
