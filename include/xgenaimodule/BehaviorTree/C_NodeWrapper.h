#pragma once

#include <cstddef>

#include "../../rttr/rttr_enable.h"

namespace wh::xgenaimodule::BehaviorTree {

template <typename TDerived, typename TBase, typename TContext>
class C_NodeWrapper : public TBase {
public:
    ~C_NodeWrapper() override;
    RTTR_ENABLE(TBase)
};

template <typename TDerived, typename TBase, typename TContext>
class C_NodeWrapperGeneratedAttributes : public TBase {
public:
    ~C_NodeWrapperGeneratedAttributes() override;
    RTTR_ENABLE(TBase)
};

} // namespace wh::xgenaimodule::BehaviorTree
