#pragma once

#include <cstddef>

#include "C_NodeWrapper.h"
#include "C_SemiFixedComposite.h"
#include "S_CallDecoratorContext.h"

namespace wh::xgenaimodule::BehaviorTree {

using C_CallDecoratorBase = C_NodeWrapperGeneratedAttributes<
    class C_CallDecorator, C_SemiFixedComposite, S_CallDecoratorContext>;

class C_CallDecorator : public C_CallDecoratorBase {
public:
    ~C_CallDecorator() override;
    RTTR_ENABLE(C_CallDecoratorBase)                                         // [5..7], vtable 0x183AA9290
};

static_assert(sizeof(C_CallDecorator) == 0x48,
              "C_CallDecorator size mismatch");

} // namespace wh::xgenaimodule::BehaviorTree
