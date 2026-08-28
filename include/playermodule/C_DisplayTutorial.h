#pragma once
#include <cstddef>
#include "../conceptmodule/C_Node.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "S_TutorialName.h"

namespace wh::playermodule {

class C_DisplayTutorial : public wh::conceptmodule::C_Node {
public:
    C_DisplayTutorial();
    ~C_DisplayTutorial() override;                              // [0] 0x1814480A8
    RTTR_ENABLE(wh::conceptmodule::C_Node) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                            // [27] 0x182DE0284
    void OnExecute(
        wh::conceptmodule::S_NodeExecuteContext const& context) override; // [33] 0x180A179AC

    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_show;                  // +0x40
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_hide;                  // +0x80
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_reset;                 // +0xC0
    wh::conceptmodule::C_TypedPortRef<S_TutorialName> m_tutorial; // +0x100
};

static_assert(sizeof(C_DisplayTutorial) == 0x140,
              "C_DisplayTutorial size mismatch");
static_assert(offsetof(C_DisplayTutorial, m_show) == 0x40,
              "C_DisplayTutorial show offset mismatch");
static_assert(offsetof(C_DisplayTutorial, m_tutorial) == 0x100,
              "C_DisplayTutorial tutorial offset mismatch");

} // namespace wh::playermodule
