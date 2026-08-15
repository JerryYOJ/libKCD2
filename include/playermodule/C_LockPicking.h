#pragma once
#include <cstddef>
#include <cstdint>
#include "C_Minigame.h"
#include "C_LockPickingView.h"
#include "E_LockPickingState.h"
#include "I_LockPickingAction.h"
#include "S_MinigameHandleSlot.h"

struct IActionController;

// -----------------------------------------------
// wh::playermodule::C_LockPicking -- live lockpicking minigame session
// (KCD2 WHGame.dll 1.5.6, kd7u). sizeof 0x1A8.
// -----------------------------------------------
// RTTI .?AVC_LockPicking@playermodule@wh@@ (TD 0x184DF9D80).
// Bases: C_Minigame { I_Minigame @+0x00, I_MinigameCamera @+0x08,
// IActionListener @+0x10 } then IExactPositioningListener @+0x68.
// Factory sub_1809F0234 type 5 alloc 0x1A8 -> ctor sub_18168D640.
// Primary vtable 0x183F6F8B0 (47 slots).

namespace wh::playermodule {

class I_ExactPositioningListener {
public:
    virtual ~I_ExactPositioningListener() = default;
    virtual void ExactPositioningQueryComplete(uint32_t queryID, bool succeeded) = 0;
    virtual void ExactPositioningNotifyFinishPoint(const Vec3& pt) = 0;
};
static_assert(sizeof(I_ExactPositioningListener) == 0x08,
              "IExactPositioningListener is a vptr-only 3-slot interface");

class C_LockPicking : public C_Minigame, public I_ExactPositioningListener {
public:
    E_MinigameType::Type GetMinigameType() const override;  // [0] 0x181A78ED0 -> 5
    void unk_02() override;                                 // [2] 0x182E8835C pick-break
    void Destroy() override;                                // [4] 0x180899D48
    ~C_LockPicking() override;                              // [5] 0x180899EA4
    bool IsFinished() const override;                       // [7] 0x181783FA8 m_state == Finished
    bool Begin() override;                                  // [18] 0x1819B532C
    void Update(float deltaTime) override;                  // [19] 0x18089A940
    void Reset() override;                                  // [21] 0x18168DC6C
    void RequestExit() override;                            // [46] 0x1827C0EBC

    void ExactPositioningQueryComplete(uint32_t queryID,
                                       bool succeeded) override; // 0x18121F13C
    void ExactPositioningNotifyFinishPoint(const Vec3& pt) override; // 0x1803B6E80

    bool Start(uint32_t entityId);                          // 0x1808986A4
    void CommitResult(bool success, bool skipLeave,
                      void* rpgScratch);                    // 0x180899568

    S_MinigameHandleSlot          m_slot70;                 // +0x70
    void*                         m_pActionMapSink;         // +0x80  sub_18079A6E8 tree
    E_LockPickingState::Type      m_state;                  // +0x88
    uint8_t                       _pad89[3];                // +0x89
    int32_t                       m_lockKind;               // +0x8C  action factory tag
    float                         m_sweetSpot;              // +0x90
    float                         m_startAngle;             // +0x94
    float                         m_endAngle;               // +0x98  ctor 358.0f
    float                         m_angle;                  // +0x9C
    float                         m_turning;                // +0xA0
    float                         m_cursorDistance;         // +0xA4
    float                         m_relDistance;            // +0xA8
    float                         m_lockpickHealth;         // +0xAC  ctor 100.0f
    float                         m_lockpickHealthMax;      // +0xB0  reset 100.0f
    float                         m_unkB4;                  // +0xB4
    float                         m_playTime;               // +0xB8
    float                         m_inPlace;                // +0xBC  0 or 1
    uint8_t                       _cursorBlock[0x70];       // +0xC0..+0x12F [OPEN]
    C_LockPickingView*            m_pView;                  // +0x130
    float                         m_inputDeltaX;            // +0x138
    float                         m_inputDeltaY;            // +0x13C
    float                         m_inputDeltaZ;            // +0x140
    uint8_t                       _pad144[4];               // +0x144
    IActionController*            m_pActionController;      // +0x148
    I_LockPickingAction*          m_pAction150;             // +0x150
    I_LockPickingAction*          m_pAction158;             // +0x158
    I_LockPickingAction*          m_pAction160;             // +0x160
    I_LockPickingAction*          m_pAction168;             // +0x168
    I_LockPickingAction*          m_pLeaveAction;           // +0x170
    uint8_t                       _pad178[0xC];             // +0x178
    float                         m_successHold;            // +0x184  0.5f on SuccessHold
    int32_t                       m_unk188;                 // +0x188
    uint8_t                       _pad18C[4];               // +0x18C
    void*                         m_pForceFeedback;         // +0x190
    uint32_t                      m_soundId198;             // +0x198
    uint32_t                      m_soundId19C;             // +0x19C
    uint32_t                      m_pendingSoundId;         // +0x1A0
    int32_t                       m_breakCount;             // +0x1A4
};
static_assert(sizeof(C_LockPicking) == 0x1A8,
              "C_LockPicking must match the type-5 factory allocation");
static_assert(offsetof(C_LockPicking, m_state) == 0x88,
              "lockpicking state byte must be at +0x88");
static_assert(offsetof(C_LockPicking, m_angle) == 0x9C,
              "current lock angle must be at +0x9C");
static_assert(offsetof(C_LockPicking, m_pView) == 0x130,
              "Flash view must be at +0x130");
static_assert(offsetof(C_LockPicking, m_pLeaveAction) == 0x170,
              "leave action must be at +0x170");
static_assert(offsetof(C_LockPicking, m_successHold) == 0x184,
              "success-hold timer must be at +0x184");

}  // namespace wh::playermodule
