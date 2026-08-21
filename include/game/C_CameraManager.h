#pragma once
#include <cstdint>
#include <cstddef>
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../Offsets/vtables/ISystem.h"   // Offsets::ISystemEventListener (CSystem secondary-base block)
#include "../framework/C_Signal.h"
#include "../framework/CScreenEffects.h"
#include "../crysystem/SViewParams.h"
#include "C_Camera.h"
#include "C_CameraFirstPerson.h"
#include "C_CameraThirdPerson.h"
#include "C_CameraDebug.h"
#include "C_CameraDialog.h"
#include "C_CameraMinigame.h"
#include "C_CameraBoneAnimated.h"
#include "C_CameraCombatDelegate.h"
#include "C_CameraUI.h"
#include "C_CameraRider.h"

// -----------------------------------------------
// wh::game::C_CameraManager -- per-game camera-mode owner (KCD2 WHGame.dll
// Steam 1.5.6, sjw7).  sizeof 0x4D0.  Vtable 0x18408E560 (ISystemEventListener
// + 1 extra).  RTTI .?AVC_CameraManager@game@wh@@ TD 0x18504d9c8.  Alloc
// 1232 in C_Game::Init 0x1806034B4; ctor 0x180896DC8.  Lives at
// S_GameContext+0x38.  SelectActive 0x1809E58CC writes m_pActive.
// -----------------------------------------------

namespace wh::game {

class C_CameraManager : public Offsets::ISystemEventListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_CameraManager;

    void _vf0() override;                                               // [0]  0x1839BAE38 scalar-deleting dtor (base slot 0 is _vf0, not a dtor)
    void OnSystemEventAnyThread(uint32_t, uint64_t, uint64_t) override; // [1]  nullsub
    void OnSystemEvent(uint32_t event, uint64_t, uint64_t) override;    // [2]  0x1808971C4  event 0x1012 -> WantsDof refresh
    virtual int unk_3(int32_t* flag);                                   // [3]  0x1807EEDCC  extra WH slot; writes m_unk39; no code xrefs

    wh::shared::C_Signal<C_Camera*> m_onActiveChanged;            // +0x08  SelectActive emit
    wh::shared::C_Signal<>          m_signal18;                   // +0x18  args UNVERIFIED
    C_Camera*     m_pBlendSource;                                 // +0x28  ctor = &m_thirdPerson
    C_Camera*     m_pActive;                                      // +0x30  ctor = &m_firstPerson; SelectActive writer
    uint8_t       m_blendFromThirdPerson;                         // +0x38  ApplyView composes m_pBlendSource when set
    uint8_t       m_unk39;                                        // +0x39  written by unk_3
    uint8_t       m_justActivated;                                // +0x3A  SelectActive=1; ApplyView copies to SViewParams then clears
    uint8_t       m_bypassCompose;                                // +0x3B  cutscene/trackview path
    SViewParams   m_viewCacheA;                                   // +0x3C
    SViewParams   m_viewCacheB;                                   // +0x110
    uint32_t      _pad1E4;                                        // +0x1E4
    C_CameraFirstPerson     m_firstPerson;                        // +0x1E8
    C_CameraThirdPerson     m_thirdPerson;                        // +0x208
    C_CameraDebug           m_debug;                              // +0x230
    C_CameraDialog          m_dialog;                             // +0x318
    C_CameraMinigame        m_minigame;                           // +0x338
    C_CameraBoneAnimated    m_boneAnimated;                       // +0x350
    C_CameraCombatDelegate  m_combat;                             // +0x370
    C_CameraUI              m_ui;                                 // +0x390
    C_CameraRider           m_rider;                              // +0x3C0
    float         m_fovBlendTimeLeft;                             // +0x3F8  FocusCamera deactivate writes this
    float         m_posBlendTimeLeft;                             // +0x3FC
    float         m_unk400;                                       // +0x400  ctor 0; unread by blend helper
    float         m_rotBlendTimeLeft;                             // +0x404
    Quat          m_rotBlendFrom;                                 // +0x408
    Vec3          m_posBlendFrom;                                 // +0x418
    float         m_posBlendDuration;                             // +0x424
    uint8_t       _unk428[0x38];                                  // +0x428  dtor 0x1803E23C0; no ctor vptr
    void*         m_pPosBlendHelper;                              // +0x460
    float         m_nearPlaneOverride;                            // +0x468
    float         m_fovBlendTarget;                               // +0x46C  FocusCamera deactivate writes 0
    uint8_t       m_dofEnable;                                    // +0x470  ctor 1
    uint8_t       _pad471[7];                                     // +0x471
    wh::framework::CScreenEffects m_screenEffects;                // +0x478
};
static_assert(sizeof(C_CameraManager) == 0x4D0, "C_CameraManager must be 0x4D0");
static_assert(offsetof(C_CameraManager, m_pActive) == 0x30);
static_assert(offsetof(C_CameraManager, m_firstPerson) == 0x1E8);
static_assert(offsetof(C_CameraManager, m_rider) == 0x3C0);
static_assert(offsetof(C_CameraManager, m_fovBlendTimeLeft) == 0x3F8);
static_assert(offsetof(C_CameraManager, m_screenEffects) == 0x478);

}  // namespace wh::game
