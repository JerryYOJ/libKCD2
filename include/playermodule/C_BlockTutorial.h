#pragma once
#include <cstddef>
#include "../conceptmodule/C_Effect.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "S_TutorialName.h"

namespace wh::playermodule {

class C_BlockTutorial : public wh::conceptmodule::C_Effect {
public:
    C_BlockTutorial();
    ~C_BlockTutorial() override;                                // [0] 0x18173FD34
    RTTR_ENABLE(wh::conceptmodule::C_Effect) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // [27] 0x182DDFF44
    void OnEffectActivate() override;                           // [43] 0x180A17914
    void OnEffectDeactivate() override;                         // [44] 0x180A17548

    wh::conceptmodule::C_TypedPortRef<S_TutorialName> m_tutorial; // +0x88
};

static_assert(sizeof(C_BlockTutorial) == 0xC8,
              "C_BlockTutorial size mismatch");
static_assert(offsetof(C_BlockTutorial, m_tutorial) == 0x88,
              "C_BlockTutorial tutorial offset mismatch");

} // namespace wh::playermodule
