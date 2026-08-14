#pragma once
#include <cstddef>
#include <cstdint>
#include "I_Minigame.h"
#include "I_MinigameCamera.h"
#include "../Offsets/vtables/IActionListener.h"
#include "../framework/I_Action.h"

// -----------------------------------------------
// wh::playermodule::C_Minigame -- shared minigame-session base
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x68.
// -----------------------------------------------
// RTTI hierarchy: I_Minigame @+0x00, I_MinigameCamera @+0x08,
// IActionListener @+0x10. Constructor sub_1809F0F30 writes every base vptr and
// initializes the complete +0x18..+0x67 data region; destructor sub_1809F0E60.

namespace Offsets { struct IGameObject; }
namespace wh::entitymodule { class C_Actor; }

namespace wh::playermodule {

class C_Minigame : public I_Minigame,
                   public I_MinigameCamera,
                   public Offsets::IActionListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_Minigame;

    bool unk_01() const override;                         // [1] default false
    void unk_02() override;                              // [2] nullsub
    bool unk_03() const override;                        // [3] default true
    void Destroy() override;                             // [4] forwards to destructor
    ~C_Minigame() override;                              // [5] sub_1809F0E60
    void DestroySession() override;                      // [6] forwards to destructor
    void unk_08() override;                              // [8]
    void unk_09() override;                              // [9]
    uint32_t GetPlayerId() const override;               // [10]
    void unk_11() override;                              // [11]
    void unk_12() override;                              // [12]
    void unk_13() override;                              // [13]
    void unk_14() override;                              // [14]
    void unk_15() override;                              // [15]
    void* unk_16() override;                             // [16]
    void unk_17() override;                              // [17]
    bool Begin() override;                               // [18] sub_18061885C
    void unk_20() override;                              // [20] nullsub
    uint32_t GetUserId() const override;                 // [22]
    void unk_23() override;                              // [23]
    void unk_24() override;                              // [24]
    void unk_25() override;                              // [25]
    void unk_26() override;                              // [26]
    void unk_27() override;                              // [27]
    void unk_28() override;                              // [28]
    void unk_29() override;                              // [29]
    void unk_30() override;                              // [30]
    void unk_31() override;                              // [31]
    void unk_32() override;                              // [32]
    void SelfDestruct() override;                        // [33] base nullsub
    void SetActionMapContext(CryStringT<char> context) override; // [34] sub_18085A3EC
    void UpdateExitHint() override;                      // [35] sub_1809F1E1C
    void unk_36() override;                              // [36]
    void unk_37() override;                              // [37]
    void unk_38() override;                              // [38]
    void unk_39() override;                              // [39]
    void unk_40() override;                              // [40]
    void unk_41() override;                              // [41]
    void unk_42() override;                              // [42]
    void unk_43() override;                              // [43]
    void unk_44() override;                              // [44]
    uint8_t unk_45() const override;                     // [45] default true
    void RequestExit() override;                         // [46]

    // I_MinigameCamera secondary vtable @ +0x08. Distinct names prevent the
    // unrelated I_Minigame [1..3] methods from becoming accidental overrides.
    bool  camera_unk_00() const override;                // camera [0] default false
    bool  camera_unk_01() const override;                // camera [1] default false
    void  camera_unk_02() override;                      // camera [2] nullsub
    bool  camera_unk_03() const override;                // camera [3] default false
    float camera_unk_04() const override;                // camera [4] default 1.0f
    bool  camera_unk_05() const override;                // camera [5] default true

    void OnAction(const Offsets::SActionId& action, int activationMode, float value) override;
    void AfterAction() override;

    entitymodule::C_Actor*       m_pPlayerActor;          // +0x18  session owner
    Offsets::IGameObject*        m_pPlayerGameObject;     // +0x20  actor virtual [221]
    uint32_t                     m_targetEntityId;        // +0x28  Start target/proxy EntityId
    bool                         m_started;               // +0x2C
    uint8_t                      _pad2D[3];               // +0x2D
    CryStringT<char>             m_currentContext;       // +0x30  active action-map context
    _smart_ptr<framework::I_Action> m_pAction;            // +0x38  active framework action
    uint64_t                     m_handle40;              // +0x40  shared sentinel-backed handle [role OPEN]
    uint64_t                     m_handle48;              // +0x48  shared sentinel-backed handle [role OPEN]
    bool                         m_cameraActive;          // +0x50
    uint8_t                      _pad51[7];               // +0x51
    void*                        m_pInputRegistration;     // +0x58  owned registration block [type OPEN]
    bool                         m_flag60;                // +0x60
    bool                         m_listenerRegistered;    // +0x61  cleared by destructor
    uint8_t                      _pad62[6];               // +0x62
};
static_assert(sizeof(C_Minigame) == 0x68,
              "C_Minigame must match constructor sub_1809F0F30");
static_assert(offsetof(C_Minigame, m_pPlayerActor) == 0x18,
              "C_Minigame data must begin at +0x18");
static_assert(offsetof(C_Minigame, m_currentContext) == 0x30,
              "action-map context must be at +0x30");
static_assert(offsetof(C_Minigame, m_pAction) == 0x38,
              "active action must be at +0x38");
static_assert(offsetof(C_Minigame, m_pInputRegistration) == 0x58,
              "input registration must be at +0x58");

}  // namespace wh::playermodule
