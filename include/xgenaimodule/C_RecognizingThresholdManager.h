#pragma once
#include <cstdint>
#include "../game/I_EntitySideEffectCallback.h"

// -----------------------------------------------
// wh::xgenaimodule::C_RecognizingThresholdManager : game::I_EntitySideEffectCallback
// -- per-entity recognition-threshold overrides, embedded at +0x198 of
// C_PerceptionManager (KCD2 WHGame.dll 1.5.6, kd7u).  sizeof 0x90 (ctor-proven:
// spans PM+0x198..+0x228).
// -----------------------------------------------
// RTTI TD rva 0x4EDD760; vtable 0x183FD06C0, 2 slots: [0] sub_1808ACF2C,
// [1] sub_1808AC6F4.  Slot [1] (entity side-effect) reads the global
// wh_ai_perception_recognizing_threshold (PerceptionManager+0xD0) and drops
// per-entity entries that match it.
// Hash container evidence (init sub_1803B5774, cap 0x10): mask 7 @+0x50, bucket
// count 8 @+0x58 => hashmap<entityId, per-entity recognition threshold>; a
// parallel vector sits @+0x40 -- interior layout not fully resolved [U].

namespace wh::xgenaimodule {

class C_RecognizingThresholdManager : public game::I_EntitySideEffectCallback {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_RecognizingThresholdManager;
    ~C_RecognizingThresholdManager() override;           // [0] sub_1808ACF2C [U slot order vs [1]]
    void OnEntitySideEffect(void* sideEffect) override;  // [1] sub_1808AC6F4 -- drops per-entity thresholds matching PM+0xD0

    uint8_t  _unk08[0x18];        // +0x08..+0x1F [U roles]
    float    m_thresholdScale;    // +0x20  ctor: 1.0f -- per-manager threshold scale [V]
    uint8_t  _pad24[4];           // +0x24
    uint64_t m_listHead[2];       // +0x28  intrusive circular-list head (32B nodes)
    uint8_t  m_entityThresholds[0x58];  // +0x38..+0x8F  hashmap<entityId, threshold> (init sub_1803B5774; mask 7 @+0x50, buckets 8 @+0x58) + vector @+0x40 [U interior]
};
static_assert(sizeof(C_RecognizingThresholdManager) == 0x90, "C_RecognizingThresholdManager must be 0x90 (PM+0x198..+0x228)");

}  // namespace wh::xgenaimodule
