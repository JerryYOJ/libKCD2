#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "../conceptmodule/C_Effect.h"
#include "../CryEngine/CryCommon/CryString.h"

namespace wh::rpgmodule {

class C_PauseWorldTime : public wh::conceptmodule::C_Effect {
public:
    struct S_PauseHandle {
        CryStringT<char> m_name;                                 // +0x00
        std::int32_t m_registryKind;                             // +0x08
        std::uint8_t m_padding0C[4];                            // +0x0C
    };

    C_PauseWorldTime();
    ~C_PauseWorldTime() override;                               // [0]
    RTTR_ENABLE(wh::conceptmodule::C_Effect) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27]
    void OnEffectActivate() override;                           // [43]
    void OnEffectDeactivate() override;                         // [44]

    std::unique_ptr<S_PauseHandle> m_pauseHandle;                // +0x88
};

static_assert(sizeof(C_PauseWorldTime::S_PauseHandle) == 0x10,
              "C_PauseWorldTime pause handle size mismatch");
static_assert(sizeof(C_PauseWorldTime) == 0x90,
              "C_PauseWorldTime size mismatch");
static_assert(offsetof(C_PauseWorldTime, m_pauseHandle) == 0x88,
              "C_PauseWorldTime pause handle offset mismatch");

} // namespace wh::rpgmodule
