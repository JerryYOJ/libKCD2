#pragma once

#include <cstddef>
#include <cstdint>

#include "C_ActorParamAction.h"
#include "I_ActorAction.h"
#include "S_InteractiveSceneActionParams.h"

namespace wh::entitymodule {

using C_ActorActionInteractiveSceneBase =
    C_ActorParamAction<S_InteractiveSceneActionParams, I_ActorAction>;

class C_ActorActionInteractiveScene : public C_ActorActionInteractiveSceneBase {
public:
    C_ActorActionInteractiveScene(
        C_ActionActor& actor,
        const S_InteractiveSceneActionParams& params);                   // 0x1812C07DC
    ~C_ActorActionInteractiveScene() override;                           // [0] 0x181865F38
    bool _vf8(const _smart_ptr<wh::framework::I_Action>& other) const override; // [8] 0x18137FED4
    std::int32_t GetActionTypeId() const override;                       // [14] 0x181A7D5B0
    const char* GetActionName() const override;                          // [18] 0x18287BAD0
    RTTR_ENABLE(C_ActorActionInteractiveSceneBase)                       // [23..25], vtable 0x183B52138
    void GetDebugLabel(CryStringT<char>* output) override;               // [30] 0x18287B68C
    void GetTagRange(void* output) override;                             // [31] 0x18173AB54
    void GetDefaultAnimBlock(void* output) override;                     // [34] 0x181755FAC
    void SetObjectFlagsAndAdvance(char flag0, char flag1) override;      // [35] 0x1819C0B08
    bool OnStart() override;                                             // [38] 0x180F48A4C
    void OnStop() override;                                              // [39] 0x180F48AA4
    void GetNameString(void* output) const override;                     // [45] 0x18287D808
};

static_assert(offsetof(C_ActorActionInteractiveSceneBase, m_params) == 0x50,
              "interactive-scene params offset mismatch");
static_assert(sizeof(C_ActorActionInteractiveScene) == 0x70,
              "C_ActorActionInteractiveScene size mismatch");

} // namespace wh::entitymodule
