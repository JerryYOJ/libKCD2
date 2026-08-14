#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "C_Minigame.h"
#include "../animationmodule/C_CallbackAction.h"
#include "../guimodule/C_BasicFader.h"
#include "../guimodule/C_FaderController.h"
#include "../CryEngine/CryCommon/CryExtension/CryGUID.h"

// -----------------------------------------------
// wh::playermodule::C_HerbGathering -- live herb-gathering minigame session
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0xA0.
// -----------------------------------------------
// RTTI .?AVC_HerbGathering@playermodule@wh@@. Factory sub_1809F0234 allocates
// 0xA0 for E_MinigameType::HerbGathering and calls ctor sub_182E7FDD8. The
// C_Minigame base occupies +0x00..+0x67; herb-owned state begins at +0x68.

namespace wh::playermodule {

class C_HerbGathering : public C_Minigame {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_HerbGathering;

    E_MinigameType::Type GetMinigameType() const override; // [0] sub_181A78EA0 -> 4
    ~C_HerbGathering() override;                            // [5] sub_182E98B20
    bool IsFinished() const override;                       // [7] sub_182E8E2EC, state == 4
    bool Begin() override;                                  // [18] sub_182E8C324
    void Update(float deltaTime) override;                  // [19] sub_182E99C14
    void Reset() override;                                  // [21] nullsub_1
    void SelfDestruct() override;                           // [33] sub_182E167F0
    uint8_t unk_45() const override;                        // [45] sub_181A74A40 -> 2

    void Start(uint32_t pickableAreaEntityId);              // sub_182E97270

    int32_t m_state;                                        // +0x68  1 start, 2 fade/action, 3 award wait, 4 finished
    float   m_gatheringDuration;                            // +0x6C  wh_pl_HerbGatheringLength snapshot
    CryGUID m_itemGuid;                                     // +0x70  Lua GuidItemPicked snapshot
    int32_t m_amount;                                       // +0x80  Lua Amount snapshot
    float   m_elapsedTime;                                  // +0x84
    _smart_ptr<animationmodule::C_CallbackAction> m_pGatherAction; // +0x88
    std::unique_ptr<guimodule::C_BasicFader<guimodule::C_FaderController>> m_pFader; // +0x90
    int32_t m_consumedInstanceCount;                        // +0x98  C_RespawnManager slot [2] result
    uint32_t _pad9C;                                        // +0x9C
};
static_assert(sizeof(C_HerbGathering) == 0xA0,
              "C_HerbGathering must match the type-4 factory allocation");
static_assert(offsetof(C_HerbGathering, m_state) == 0x68,
              "herb-owned state must begin at +0x68");
static_assert(offsetof(C_HerbGathering, m_itemGuid) == 0x70,
              "snapshotted item GUID must be at +0x70");
static_assert(offsetof(C_HerbGathering, m_pGatherAction) == 0x88,
              "gather action must be at +0x88");
static_assert(offsetof(C_HerbGathering, m_consumedInstanceCount) == 0x98,
              "consumed-instance count must be at +0x98");

}  // namespace wh::playermodule
