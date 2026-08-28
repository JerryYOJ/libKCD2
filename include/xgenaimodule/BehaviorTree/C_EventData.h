#pragma once

#include <cstddef>

#include "C_Node.h"
#include "C_NodeWrapper.h"
#include "S_EventDataContext.h"

namespace wh::xgenaimodule::BehaviorTree {

using C_EventDataBase = C_NodeWrapperGeneratedAttributes<
    class C_EventData, C_Node, S_EventDataContext>;

class C_EventData : public C_EventDataBase {
public:
    ~C_EventData() override;
    RTTR_ENABLE(C_EventDataBase)                                             // [5..7], vtable 0x183AC9DA0
};

static_assert(sizeof(C_EventData) == 0x30,
              "C_EventData size mismatch");

} // namespace wh::xgenaimodule::BehaviorTree
