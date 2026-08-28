#pragma once
#include <cstddef>
#include "C_SharedResource.h"
#include "rttr/rttr_enable.h"
#include "rttr/type.h"
#include "rttr/variant.h"

namespace wh::conceptmodule {

class I_LinkAssetResolver {
public:
    virtual ~I_LinkAssetResolver();
    virtual rttr::variant ResolveAssets(
        rttr::type type,
        _smart_ptr<C_SharedResource> resource) = 0; // [1]
    RTTR_ENABLE() // [2..4]
};

static_assert(sizeof(I_LinkAssetResolver) == 0x08,
              "I_LinkAssetResolver size mismatch");

}  // namespace wh::conceptmodule
