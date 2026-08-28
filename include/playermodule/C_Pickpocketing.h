#pragma once
#include <cstddef>
#include <cstdint>

#include <boost/optional.hpp>

#include "../framework/S_ResourceHandle.h"
#include "../framework/T_TimeoutTimer.h"
#include "C_Minigame.h"
#include "I_UIPickpocketing.h"

namespace wh::rpgmodule { struct T_GameWorldTimePolicy; }

namespace wh::playermodule {

class C_Pickpocketing : public C_Minigame {
public:
    C_Pickpocketing(entitymodule::C_Actor* playerActor);
    E_MinigameType::Type GetMinigameType() const override;  // [0] 0x181A8AD10
    bool unk_01() const override;                            // [1] 0x182EA7F84
    void unk_02(std::uint32_t entityId) override;           // [2] 0x182EA9C68
    ~C_Pickpocketing() override;                            // [5] 0x182EB2614
    bool IsFinished() const override;                       // [7] 0x182EACAE8
    RTTR_ENABLE(C_Minigame) // [15..17]
    void Update(float deltaTime) override;                  // [19] 0x182EB3B34
    void Reset() override;                                  // [21] 0x182EAFAF4
    std::uint8_t unk_32() override;                         // [32] 0x181A78ED0
    void SelfDestruct() override;                           // [33] 0x182EAA1D0
    bool unk_39() override;                                 // [39] false

    wh::framework::S_ResourceHandle m_resource;             // +0x68
    std::uint32_t m_state;                                  // +0x78, 0..4; 4 finished
    std::uint32_t m_unknown7C;
    std::uint32_t m_unknown80;
    float m_progress;                                       // +0x84
    float m_progressRate;                                   // +0x88, ctor 1.0
    float m_phaseThreshold;                                 // +0x8C
    float m_progressMaximum;                                // +0x90
    std::uint32_t m_unknown94;
    wh::framework::T_TimeoutTimer<
        wh::rpgmodule::T_GameWorldTimePolicy> m_timerA;     // +0x98
    wh::framework::T_TimeoutTimer<
        wh::rpgmodule::T_GameWorldTimePolicy> m_timerB;     // +0xC0
    void* m_uiState;                                        // +0xE8, exact type unresolved
    I_UIPickpocketing* m_ui;                                // +0xF0
};

static_assert(sizeof(C_Pickpocketing) == 0xF8,
              "C_Pickpocketing size mismatch");
static_assert(offsetof(C_Pickpocketing, m_resource) == 0x68,
              "C_Pickpocketing resource offset mismatch");
static_assert(offsetof(C_Pickpocketing, m_state) == 0x78,
              "C_Pickpocketing state offset mismatch");
static_assert(offsetof(C_Pickpocketing, m_timerA) == 0x98,
              "C_Pickpocketing timer A offset mismatch");
static_assert(offsetof(C_Pickpocketing, m_timerB) == 0xC0,
              "C_Pickpocketing timer B offset mismatch");
static_assert(offsetof(C_Pickpocketing, m_ui) == 0xF0,
              "C_Pickpocketing UI offset mismatch");

} // namespace wh::playermodule
