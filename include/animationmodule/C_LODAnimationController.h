#pragma once
#include <cstddef>
#include <cstdint>
#include <functional>
#include "I_AnimationControllerTestable.h"
#include "I_LODAnimationController.h"
#include "S_LODAnimationControllerData.h"

namespace wh::animationmodule {

class C_LODAnimationController
    : public I_LODAnimationController,
      public I_AnimationControllerTestable {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_C_LODAnimationController;

    Offsets::IEntity* GetEntity() override;                             // primary [0] 0x180685D74
    Offsets::IActor* GetActorById(EntityId entityId) override;          // primary [1] 0x180AA70B4
    Offsets::IActor* GetOwnerActor() override;                          // primary [2] 0x1827D211C
    IAnimatedCharacter* GetAnimatedCharacter() override;               // primary [3] 0x180685CAC
    IAnimatedCharacter* GetCachedAnimatedCharacter() override;         // primary [4] 0x181A7F940
    ICharacterInstance* GetCharacterById(EntityId entityId) override;  // primary [5] 0x180AA7254
    ICharacterInstance* GetCharacter() override;                       // primary [6] 0x180ADD7B0
    ISkeletonAnim* GetSkeletonAnimById(EntityId entityId) override;    // primary [7] 0x180AA72A4
    ISkeletonAnim* GetSkeletonAnim() override;                         // primary [8] 0x180ADD778
    IActionController* GetActionController() override;                 // primary [9] 0x18083D2CC
    S_LODAnimationControllerData* GetData10() override;                // primary [10] 0x181A72EB0
    const S_LODAnimationControllerData* GetData11() const override;    // primary [11] 0x181A72EB0
    bool IsEnabled() const override;                                   // primary [12], secondary [0]
    bool IsPaused() const override;                                    // primary [13] 0x18083D0A4
    void InvokeGuarded(const std::function<void()>& callback) override; // primary [14] 0x181E5A980
    void ApplyDeferredEnableUpdate() override;                         // primary [15] 0x181E5AC70
    float _vf16(IScope* scope, std::uint32_t layer,
                std::int32_t animationIndex) override;                 // primary [16] 0x180AA7670
    float _vf17(const CAnimation* animation) override;                 // primary [17] 0x180AA7714
    float _vf18(IScope* scope) override;                               // primary [18] 0x180AA7308
    void _vf19(S_LODScope* lodScope, IScope* scope) override;          // primary [19] 0x1804AE2A0
    void SuppressRootMotion() override;                                // primary [20] 0x1813CB480
    bool _vf21() const override;                                       // primary [21] false stub
    void _vf22() override;                                             // primary [22] nullsub

    void EnumerateAnimations(
        std::function<void(std::int32_t, const char*)> callback) override; // secondary [1] 0x1827D2574
    bool _vf2() const override;                                        // secondary [2] false stub

    bool m_hasActionController;        // +0x10, source name reconstructed
    bool m_scopeRefreshPending;        // +0x11, source name reconstructed
    bool m_actionListenerRegistered;   // +0x12, source name reconstructed
    bool m_inGuardedCallback;          // +0x13, source name reconstructed
    bool m_deferredEnableUpdate;        // +0x14, source name reconstructed
    bool m_hasAnimationEvents;         // +0x15, source name reconstructed
    std::uint8_t _pad16[2];            // +0x16
    S_LODAnimationControllerData m_data; // +0x18
};
static_assert(sizeof(C_LODAnimationController) == 0x108,
              "C_LODAnimationController must be 0x108");
static_assert(offsetof(C_LODAnimationController, m_data) == 0x18,
              "LOD animation-controller data must be at 0x18");

}  // namespace wh::animationmodule
