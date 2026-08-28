#pragma once
#include <cstddef>
#include <cstdint>

#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "C_RandomEventBase.h"

namespace wh::playermodule {

class C_ManualRandomEvent : public C_RandomEventBase {
public:
    C_ManualRandomEvent();
    ~C_ManualRandomEvent() override;                        // [0] 0x181533260
    RTTR_ENABLE(C_RandomEventBase) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                         // [27] 0x182EAD8D8
    void OnExecute(
        wh::conceptmodule::S_NodeExecuteContext const& context) override; // [33] 0x182EA9AD4
    std::uint8_t GetModuleKind() const override;            // [44] false

    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_spawn;              // +0x1F0 RTTR "Spawn"
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_despawn;            // +0x230 RTTR "Despawn"
};

static_assert(sizeof(C_ManualRandomEvent) == 0x270,
              "C_ManualRandomEvent size mismatch");
static_assert(offsetof(C_ManualRandomEvent, m_spawn) == 0x1F0,
              "C_ManualRandomEvent spawn offset mismatch");
static_assert(offsetof(C_ManualRandomEvent, m_despawn) == 0x230,
              "C_ManualRandomEvent despawn offset mismatch");

} // namespace wh::playermodule
