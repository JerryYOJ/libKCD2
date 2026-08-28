#pragma once

#include <cstddef>
#include <cstdint>

#include "C_Decorator.h"
#include "C_NodeWrapper.h"
#include "I_CallbackEventConsumer.h"
#include "S_CallbackEventCatchContext.h"

namespace wh::xgenaimodule::BehaviorTree {

using C_CallbackEventCatchBase = C_NodeWrapperGeneratedAttributes<
    class C_CallbackEventCatch, C_Decorator, S_CallbackEventCatchContext>;

class C_CallbackEventCatch : public C_CallbackEventCatchBase,
                             public I_CallbackEventConsumer {
public:
    ~C_CallbackEventCatch() override;
    RTTR_ENABLE(C_CallbackEventCatchBase)                                    // [5..7], vtable 0x183AA8518

    std::uint8_t m_unknown38[8];                                             // +0x38
};

static_assert(sizeof(C_CallbackEventCatch) == 0x40,
              "C_CallbackEventCatch size mismatch");

} // namespace wh::xgenaimodule::BehaviorTree
