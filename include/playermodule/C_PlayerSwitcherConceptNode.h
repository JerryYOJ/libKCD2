#pragma once
#include <cstddef>
#include <cstdint>
#include "../conceptmodule/C_Node.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "I_PlayerManagerListener.h"
#include "S_PlayerId.h"

namespace wh::playermodule {

class C_PlayerSwitcherConceptNode
    : public wh::conceptmodule::C_Node,
      public I_PlayerManagerListener {
public:
    C_PlayerSwitcherConceptNode();
    ~C_PlayerSwitcherConceptNode() override;                    // primary [0] 0x1815D5830
    RTTR_ENABLE(wh::conceptmodule::C_Node) // primary [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                             // primary [27] 0x182EAD9B0
    void OnExecute(
        wh::conceptmodule::S_NodeExecuteContext const& context) override; // primary [33] 0x182EA9B64

    void OnPlayerSwitchFinished(bool successful) override;     // secondary [0] 0x182EAEEEC
    void Unk01() override;                                      // secondary [1] nullsub_1

    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_exec;                   // +0x48
    wh::conceptmodule::C_TypedPortRef<S_PlayerId> m_playerId;   // +0x88
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onFinished;             // +0xC8
    bool m_switchInProgress;                                    // +0x108
    std::uint8_t m_padding109[7];                              // +0x109
};

static_assert(sizeof(C_PlayerSwitcherConceptNode) == 0x110,
              "C_PlayerSwitcherConceptNode size mismatch");
static_assert(offsetof(C_PlayerSwitcherConceptNode, m_exec) == 0x48,
              "C_PlayerSwitcherConceptNode exec offset mismatch");
static_assert(offsetof(C_PlayerSwitcherConceptNode, m_onFinished) == 0xC8,
              "C_PlayerSwitcherConceptNode finished offset mismatch");
static_assert(offsetof(C_PlayerSwitcherConceptNode, m_switchInProgress) == 0x108,
              "C_PlayerSwitcherConceptNode state offset mismatch");

} // namespace wh::playermodule
