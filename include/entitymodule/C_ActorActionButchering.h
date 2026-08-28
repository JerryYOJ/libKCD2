#pragma once

#include <cstddef>
#include <cstdint>

#include "../CryEngine/CryCommon/CryString.h"
#include "../guimodule/C_BasicFader.h"
#include "C_ActorParamAction.h"
#include "I_ActorAction.h"
#include "S_ButcheringActionParams.h"

namespace wh::animationmodule {
class C_CallbackAction;
}

namespace wh::entitymodule {

using C_ActorActionButcheringBase =
    C_ActorParamAction<S_ButcheringActionParams, I_ActorAction>;

class C_ActorActionButchering : public C_ActorActionButcheringBase {
public:
    explicit C_ActorActionButchering(C_ActionActor& actor);              // 0x182893B18
    ~C_ActorActionButchering() override;                                 // [0] 0x18289517C
    std::int32_t GetActionTypeId() const override;                       // [14] 0x181A82B70 returns 56
    const char* GetActionName() const override;                          // [18] 0x18287BAD0
    RTTR_ENABLE(C_ActorActionButcheringBase)                             // [23..25], vtable 0x184709690
    void GetDebugLabel(CryStringT<char>* output) override;               // [30] 0x18287B68C
    void GetTagRange(void* output) override;                             // [31] 0x18289A480
    void GetDefaultAnimBlock(void* output) override;                     // [34] 0x18289A990
    bool OnStart() override;                                             // [38] 0x182896E34
    void OnStop() override;                                              // [39] 0x182898BE8
    std::int64_t OnTick() override;                                      // [41] 0x1828A0DA0; live Tick path supplies dt in xmm1
    void GetNameString(void* output) const override;                     // [45] 0x18287D668

    std::uint32_t m_faderCrc;                                            // +0x70 case-insensitive CRC of "Fader"
    bool m_unknown74;                                                    // +0x74 ctor 0; OnStop reads
    std::uint8_t m_padding75[3];                                         // +0x75
    wh::animationmodule::C_CallbackAction* m_callbackAction;             // +0x78 owning; released by sub_1804B2F14
    wh::guimodule::C_BasicFader<wh::guimodule::C_FaderController>* m_fader; // +0x80 owning; deleting dtor 0x18194B6E0
    float m_faderTimer;                                                  // +0x88 decremented by OnTick
    std::uint8_t m_padding8C[4];                                         // +0x8C
};

static_assert(offsetof(C_ActorActionButcheringBase, m_params) == 0x50,
              "butchering params offset mismatch");
static_assert(offsetof(C_ActorActionButchering, m_faderCrc) == 0x70,
              "C_ActorActionButchering::m_faderCrc offset mismatch");
static_assert(offsetof(C_ActorActionButchering, m_unknown74) == 0x74,
              "C_ActorActionButchering::m_unknown74 offset mismatch");
static_assert(offsetof(C_ActorActionButchering, m_callbackAction) == 0x78,
              "C_ActorActionButchering::m_callbackAction offset mismatch");
static_assert(offsetof(C_ActorActionButchering, m_fader) == 0x80,
              "C_ActorActionButchering::m_fader offset mismatch");
static_assert(offsetof(C_ActorActionButchering, m_faderTimer) == 0x88,
              "C_ActorActionButchering::m_faderTimer offset mismatch");
static_assert(sizeof(C_ActorActionButchering) == 0x90,
              "C_ActorActionButchering size mismatch");

} // namespace wh::entitymodule
