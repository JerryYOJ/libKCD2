#pragma once
#include <cstddef>
#include <memory>
#include <vector>
#include "../conceptmodule/C_Node.h"
#include "../conceptmodule/C_TypedPortRef.h"
#include "../conceptmodule/S_Trigger.h"
#include "I_Reward.h"

namespace wh::rpgmodule {

class C_AddReward : public wh::conceptmodule::C_Node {
public:
    C_AddReward();
    ~C_AddReward() override;                                    // [0]
    RTTR_ENABLE(wh::conceptmodule::C_Node) // [5..7]
    void EnumerateNodeVariants(
        wh::conceptmodule::definition::NodeDefinitionSink sink,
        bool allVariants) override;                              // [27]
    void OnExecute(
        const wh::conceptmodule::S_NodeExecuteContext& context) override; // [33]

    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_addReward;               // +0x40
    wh::conceptmodule::C_TypedPortRef<
        wh::conceptmodule::S_Trigger> m_onAdded;                 // +0x80
    std::vector<std::shared_ptr<I_Reward>> m_rewards;            // +0xC0
};

static_assert(sizeof(C_AddReward) == 0xD8,
              "C_AddReward size mismatch");
static_assert(offsetof(C_AddReward, m_addReward) == 0x40,
              "C_AddReward input offset mismatch");
static_assert(offsetof(C_AddReward, m_onAdded) == 0x80,
              "C_AddReward output offset mismatch");
static_assert(offsetof(C_AddReward, m_rewards) == 0xC0,
              "C_AddReward rewards offset mismatch");

} // namespace wh::rpgmodule
