#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "C_FastForwardHandlingAction.h"
#include "I_QueueableAction.h"
#include "I_Element.h"
#include "S_SmartAreaFragmentRef.h"
#include "S_AnimEventContext.h"
#include "S_AnimItemAttachmentRecord.h"
#include "../C_SpawnedItemsHolder.h"
#include "../C_ActorAnimEventHandler.h"
#include "../../entitymodule/C_ActorAnimsExpansion.h"
#include "../../entitymodule/S_ActorAnimActionDataInstance.h"
#include "../../entitymodule/S_ActionRequest.h"
#include "../../entitymodule/S_ActorAnimRequest.h"

struct AnimEventInstance;   // CryEngine/CryCommon/CryCharAnimationParams.h (PCH)

namespace wh::xgenaimodule::NPCState {

class C_AnimActionBase : public C_FastForwardHandlingAction,
                         public I_QueueableAction {
public:
    ~C_AnimActionBase() override;
    void unk_0() override;                                                   // +0xC8 [0]
    RTTR_ENABLE(C_FastForwardHandlingAction)                                 // [24..26], vtable 0x183A2E418
    virtual bool Begin() = 0;
    virtual bool ResolveMovementTarget(QuatT& target, bool& outFlagA, bool& outFlagB);
    virtual bool RequiresMovement() const = 0;
    virtual bool HasValidRuntimeData() const = 0;
    virtual CryStringT<char> GetQueueName() const;
    virtual S_SmartAreaFragmentRef GetSmartAreaFragmentRef() const;          // [44] 0x1816E94F0 default {0xFFFF,null}
    virtual std::shared_ptr<wh::entitymodule::S_ActorAnimRequest> CreateAnimRequest(wh::entitymodule::C_ActorAnimsExpansion* animsExpansion) = 0; // [45]
    virtual wh::entitymodule::S_ActorAnimActionDataInstance GetAnimActionData(wh::entitymodule::C_ActorAnimsExpansion* animsExpansion, std::shared_ptr<wh::entitymodule::S_ActorAnimRequest> request); // [46] 0x18039EFE8
    virtual std::int32_t* GetAnimEventCategory(std::int32_t* outCategory);   // [47] 0x181AA6BF0 base writes 1
    virtual bool AcceptsAnimRequest(wh::entitymodule::S_ActionRequest* request) const; // [48] 0x18039B6FC
    virtual void AttachAnimEventHandler(std::shared_ptr<wh::xgenaimodule::C_ActorAnimEventHandler> handler, wh::entitymodule::S_ActionRequest* request); // [49] 0x18039B714
    virtual bool ProvidesSpawnedItemsHolder() const;                         // [50] true stub
    virtual void OnAnimationEvent(const AnimEventInstance& event);           // [51]
    virtual void OnNamedAnimEvent(const CryStringT<char>& eventName);        // [52]
    virtual void OnMovementFinished(bool succeeded);                         // [53]
    virtual bool UsesOrientedMovementTarget() const;                         // [54]
    virtual float GetGenericStoppingDistance() const;                        // [55]
    virtual bool ContinueAfterMovementFailure() const;                       // [56]
    virtual bool CanResumeBlockedMovement() const;                           // [57]
    virtual bool CanWaitForFragment() const;                                 // [58]
    virtual bool ShouldReplanMovement(const Vec3& currentPosition) const;    // [59]
    virtual void InitializeRuntimeData();
    virtual void HandleInvalidRuntimeData();
    virtual bool AcceptsElement(const I_Element* element) const;
    virtual bool TryStartDeferredTransition(const S_AnimEventContext& context);
    virtual bool HandleAnimEventContext(const S_AnimEventContext& context);
    virtual void ApplyAnimEventContext(const S_AnimEventContext& context);
    virtual void DispatchAnimEvents(const S_AnimEventContext& context, float maxTime, void* eventContext);
    virtual bool BlocksSubsequentMovement() const;

    bool m_movementRequestActive;                                            // +0xD0  set 0x1809F8FF4 after movement-callback register
    bool m_animCompletionCallbackActive;                                     // +0xD1  set 0x18039C47D after completion-callback register
    bool m_cancelMovementRequest;                                            // +0xD2  set 0x1815B0641; callback 0x1809F8D04 aborts on it
    std::uint8_t _padD3;                                                     // +0xD3
    Vec3 m_lastReplanPosition;                                               // +0xD4  actor position snapshot at movement start / replan
    QuatT m_requestedTransform;                                              // +0xE0  resolved movement target (ctor writes identity)
    std::uint8_t _padFC[4];                                                  // +0xFC
    CryStringT<char> m_queueName;                                            // +0x100 slot-43 result, interned
    std::uint8_t m_queueIndex;                                               // +0x108 queue insertion index
    bool m_isQueued;                                                         // +0x109
    std::uint8_t _pad10A[6];                                                 // +0x10A
    std::shared_ptr<C_ActorAnimEventHandler> m_animEventHandler;             // +0x110 producer 0x18039BC4B (vt 0x183A2CF18)
    bool m_forcePostMovementContinuation;                                    // +0x120
    std::uint8_t _pad121[7];                                                 // +0x121
    C_SpawnedItemsHolder m_spawnedItemsHolder;                               // +0x128 ctor 0x1803A7D28 (vt 0x183A2D998)
    std::vector<S_AnimItemAttachmentRecord> m_itemAttachmentRecords;         // +0x168 stride 0x24; drained via 0x18186472C
    S_AnimEventContext m_pendingAnimEventContext;                            // +0x180
    bool m_hasPendingAnimEventContext;                                       // +0x190
    bool m_fragmentReservationActive;                                        // +0x191 reserve 0x18086FB64 / release 0x18086FAE0
    bool m_waitForResumeCondition;                                           // +0x192
    bool m_restoreActorModePending;                                          // +0x193
    bool m_waitingForFragmentAvailability;                                   // +0x194
    bool m_interrupted;                                                      // +0x195 slot 29 0x1815B0599
    std::uint8_t _pad196[2];                                                 // +0x196
    std::int32_t m_lastRendererFrameId;                                      // +0x198 init -1; renderer vfunc+0x600 frame id
    std::uint8_t _pad19C[4];                                                 // +0x19C
};

static_assert(offsetof(C_AnimActionBase, m_movementRequestActive) == 0xD0,
              "C_AnimActionBase::m_movementRequestActive offset mismatch");
static_assert(offsetof(C_AnimActionBase, m_queueName) == 0x100,
              "C_AnimActionBase::m_queueName offset mismatch");
static_assert(offsetof(C_AnimActionBase, m_animEventHandler) == 0x110,
              "C_AnimActionBase::m_animEventHandler offset mismatch");
static_assert(offsetof(C_AnimActionBase, m_spawnedItemsHolder) == 0x128,
              "C_AnimActionBase::m_spawnedItemsHolder offset mismatch");
static_assert(offsetof(C_AnimActionBase, m_itemAttachmentRecords) == 0x168,
              "C_AnimActionBase::m_itemAttachmentRecords offset mismatch");
static_assert(offsetof(C_AnimActionBase, m_pendingAnimEventContext) == 0x180,
              "C_AnimActionBase::m_pendingAnimEventContext offset mismatch");
static_assert(offsetof(C_AnimActionBase, m_lastRendererFrameId) == 0x198,
              "C_AnimActionBase::m_lastRendererFrameId offset mismatch");
static_assert(sizeof(C_AnimActionBase) == 0x1A0,
              "C_AnimActionBase size mismatch");

} // namespace wh::xgenaimodule::NPCState
