#pragma once
#include <cstddef>
#include <cstdint>

#include <boost/optional.hpp>

#include "../framework/I_Action.h"
#include "../framework/S_ResourceHandle.h"
#include "C_Minigame.h"
#include "I_BlacksmithActionListener.h"
#include "I_BlacksmithingActions.h"
#include "S_BlacksmithingModelState.h"
#include "S_BlacksmithingProcessState.h"
#include "S_BlacksmithingStrokeState.h"
#include "S_BlacksmithingTrackingState.h"
#include "S_BlacksmithingWorkpieceState.h"

namespace wh::playermodule {

class C_Blacksmithing
    : public C_Minigame,
      public I_BlacksmithingActions,
      public I_BlacksmithActionListener {
public:
    C_Blacksmithing(entitymodule::C_Actor* playerActor);
    E_MinigameType::Type GetMinigameType() const override; // primary [0] 12
    ~C_Blacksmithing() override;                           // primary [5] 0x180B684B8
    void DestroySession() override;                        // primary [6] 0x182E59578
    bool IsFinished() const override;                      // primary [7] states 21/22
    boost::optional<std::uint8_t> unk_13() override;       // primary [13] engaged value 17
    RTTR_ENABLE(C_Minigame) // primary [15..17]
    void Update(float deltaTime) override;                 // primary [19] 0x180857D90
    void Reset() override;                                 // primary [21] null

    void TransitionToAnvil() override;                     // actions [0] state 6
    void TransitionToForge() override;                     // actions [1] state 5
    void TransitionToHardening() override;                 // actions [2] state 7
    void SetForgeInspection(bool enabled) override;        // actions [3]
    void unk_04(bool enabled) override;                    // actions [4]
    void unk_05(void* value) override;                     // actions [5]
    void FlipWorkpiece() override;                         // actions [6]
    void StartStroke() override;                           // actions [7] state 14
    void FinishStroke() override;                          // actions [8] state 16
    void unk_09(std::int32_t* index) override;             // actions [9]
    void SetBlacksmithActionMap(
        CryStringT<char> const& context) override;         // actions [10]
    void TransitionToHardeningAlternate() override;        // actions [11] state 7
    S_BlacksmithingModelState* GetModelState() override;   // actions [12]

    void OnBlacksmithActionEvent(
        _smart_ptr<wh::framework::I_Action> action,
        std::uint8_t event) override;                      // listener [0]
    void OnBlacksmithEvent(std::uint8_t event) override;   // listener [1]
    void ResetBlacksmithActions() override;                // listener [2]

    wh::framework::S_ResourceHandle m_resourceA;           // +0x78
    wh::framework::S_ResourceHandle m_resourceB;           // +0x88
    S_BlacksmithingModelState* m_modelState;               // +0x98, owned 0x300
    void* m_unknownA0;                                     // +0xA0, owned polymorphic
    S_BlacksmithingProcessState* m_processState;           // +0xA8, owned 0xE8
    S_BlacksmithingStrokeState* m_strokeState;             // +0xB0, owned 0x80
    S_BlacksmithingTrackingState* m_trackingState;         // +0xB8, owned 0x30
    S_BlacksmithingWorkpieceState* m_workpieceState;       // +0xC0, owned 0x40
    _smart_ptr<wh::framework::I_Action> m_actionA;         // +0xC8
    _smart_ptr<wh::framework::I_Action> m_actionB;         // +0xD0
    std::uint64_t m_unknownD8;                             // +0xD8
    std::int64_t m_finishDeadline;                         // +0xE0, ctor -100000
    bool m_stopForgeInspectionPending;                     // +0xE8
    bool m_unknownE9;                                      // +0xE9, ctor true
    bool m_unknownEA;                                      // +0xEA
    std::uint8_t m_paddingEB[5];
};

static_assert(sizeof(C_Blacksmithing) == 0xF0,
              "C_Blacksmithing size mismatch");
static_assert(offsetof(C_Blacksmithing, m_resourceA) == 0x78,
              "C_Blacksmithing resource A offset mismatch");
static_assert(offsetof(C_Blacksmithing, m_modelState) == 0x98,
              "C_Blacksmithing model state offset mismatch");
static_assert(offsetof(C_Blacksmithing, m_processState) == 0xA8,
              "C_Blacksmithing process state offset mismatch");
static_assert(offsetof(C_Blacksmithing, m_actionA) == 0xC8,
              "C_Blacksmithing action A offset mismatch");
static_assert(offsetof(C_Blacksmithing, m_finishDeadline) == 0xE0,
              "C_Blacksmithing finish deadline offset mismatch");
static_assert(offsetof(C_Blacksmithing, m_stopForgeInspectionPending) == 0xE8,
              "C_Blacksmithing pending inspection offset mismatch");

} // namespace wh::playermodule
