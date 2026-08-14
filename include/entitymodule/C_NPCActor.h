#pragma once
#include <cstddef>
#include <cstdint>
#include "C_Human.h"
#include "S_StashValueWatcher.h"

namespace wh::entitymodule {

class C_NPCActor : public C_Human {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_NPCActor;

    ~C_NPCActor() override;                                      // [0] 0x1804CEC6C
    void ProcessEvent(SEntityEvent& event) override;             // [1] 0x1804A8D80
    bool Init(Offsets::IGameObject* gameObject) override;        // [7] 0x1808D25D0
    void FullSerialize(TSerialize serializer) override;         // [15] 0x182AA30EC
    const char* GetActorClassName() override;                    // [83] 0x180BFD8E0
    int GetActorClass() override;                                // [84] 0x181A74270, returns 9
    void _vf151() override;                                      // [151] 0x1808AB460, forwarding thunk
    void _vf238(std::uint32_t openerEntityId) override;          // [238] 0x18194BE44
    int _vf243() override;                                       // [243] 0x18192F774, robbed-value query
    void _vf244() override;                                      // [244] 0x181A8B5E0, reset watcher
    void _vf245(std::int32_t amount) override;                   // [245] 0x182AA1A74, subtract/clamp
    void _vf246(std::int32_t amount) override;                   // [246] 0x182AA9BDC, add/timestamp
    void _vf270() override;                                      // [270] 0x180BFD7F8
    void _vf272(bool enabled) override;                          // [272] 0x18044CA98
    void _vf273() override;                                      // [273] 0x1804CA27C
    void _vf274() override;                                      // [274] 0x181744DAC

    S_StashValueWatcher m_valueWatcher;                          // +0xA60
};

static_assert(sizeof(C_NPCActor) == 0xA78,
              "C_NPCActor must be 0xA78");
static_assert(offsetof(C_NPCActor, m_valueWatcher) == 0xA60,
              "NPC robbed-value watcher must be at 0xA60");

}  // namespace wh::entitymodule
