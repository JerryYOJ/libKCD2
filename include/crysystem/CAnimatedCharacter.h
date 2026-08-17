#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>
#include "../CryEngine/CryCommon/CryString.h"
#include "../CryEngine/CryCommon/Cry_Math.h"
#include "../Offsets/vtables/CGameObjectExtensionHelper.h"
#include "../Offsets/vtables/IAnimatedCharacter.h"
#include "../Offsets/vtables/IAnimationGraphStateListener.h"
#include "../Offsets/vtables/IGameObjectProfileManager.h"
#include "../framework/C_Signal.h"
#include "EWeaponRaisedPose.h"
#include "SAnimatedCharacterListenerSet.h"
#include "SAnimatedCharacterParams.h"
#include "SCharacterMoveRequest.h"
#include "SGroundAlignmentParams.h"
#include "SLandBobParams.h"
#include "SRagdollizeParams.h"

class CAnimationPlayerProxy;
class IActionController;
class IDebugHistoryManager;
struct IAnimationDatabase;
struct IAnimationGraphState;
struct IAnimationPoseAligner;
struct ICharacterInstance;
struct ISkeletonAnim;
struct ISkeletonPose;
struct SAnimationContext;
struct SExactPositioningTarget;
struct SViewParams;

class CAnimatedCharacter
    : public Offsets::CGameObjectExtensionHelper<
          CAnimatedCharacter,
          Offsets::IAnimatedCharacter,
          64>
    , public Offsets::IAnimationGraphStateListener {
public:
    inline static constexpr auto RTTI = Offsets::RTTI_CAnimatedCharacter;

    CAnimatedCharacter();
    ~CAnimatedCharacter() override; // [0]
    void ProcessEvent(SEntityEvent& event) override; // [1]
    bool _vf2() override; // [2]
    int GetEventPriority(int eventId) override; // [3]
    void _vf4() override; // [4]
    Offsets::IEntity* GetEntity() override; // [5]
    void GetMemoryUsage(ICrySizer* sizer) const override; // [6]
    bool Init(Offsets::IGameObject* gameObject) override; // [7]
    void PostInit(Offsets::IGameObject* gameObject) override; // [8]
    void InitClient(int channelId) override; // [9]
    void PostInitClient(int channelId) override; // [10]
    bool ReloadExtension(Offsets::IGameObject* gameObject,
                         const SEntitySpawnParams& params) override; // [11]
    void PostReloadExtension(Offsets::IGameObject* gameObject,
                             const SEntitySpawnParams& params) override; // [12]
    bool GetEntityPoolSignature(TSerialize signature) override; // [13]
    void Release() override; // [14]
    void FullSerialize(TSerialize serializer) override; // [15]
    bool NetSerialize(TSerialize serializer,
                      EEntityAspects aspect,
                      std::uint8_t profile,
                      int flags) override; // [16]
    bool _vf17() override; // [17]
    NetworkAspectType GetNetSerializeAspects() override; // [18]
    void PostSerialize() override; // [19]
    void SerializeSpawnInfo(TSerialize serializer) override; // [20]
    ISerializableInfoPtr GetSpawnInfo() override; // [21]
    void Update(SEntityUpdateContext& context, int updateSlot) override; // [22]
    void HandleEvent(const SGameObjectEvent& event) override; // [23]
    void SetChannelId(std::uint16_t id) override; // [24]
    void SetAuthority(bool authoritative) override; // [25]
    const void* GetRMIBase() const override; // [26]
    void PostUpdate(float frameTime) override; // [27]
    void PostRemoteSpawn() override; // [28]

    IAnimationGraphState* GetAnimationGraphState() override; // [29]
    void PushForcedState(const char* state) override; // [30]
    void ClearForcedStates() override; // [31]
    void ChangeGraph(const char* graph, int layer) override; // [32]
    void ResetState() override; // [33]
    void ResetInertiaCache() override; // [34]
    bool IsRagdollCreationQueued() const override; // [35]
    void PrepareForUpdate() override; // [36]
    IActionController* GetActionController() override; // [37]
    const IActionController* GetActionControllerConst() const override; // [38]
    void SetShadowCharacterSlot(int id) override; // [39]
    void SetAnimationPlayerProxy(CAnimationPlayerProxy* proxy,
                                 int layer) override; // [40]
    CAnimationPlayerProxy* GetAnimationPlayerProxy(int layer) override; // [41]
    void UpdateCharacterPtrs() override; // [42]
    void AddMovement(const SCharacterMoveRequest& request) override; // [43]
    void SetEntityRotation(const Quat& rotation) override; // [44]
    const SPredictedCharacterStates&
        GetOverriddenMotionParameters() const override; // [45]
    void SetOverriddenMotionParameters(
        const SPredictedCharacterStates& parameters) override; // [46]
    void SetMotionParameter(EMotionParamID id,
                            float value,
                            std::uint8_t characterMask) override; // [47]
    void UseAnimationMovementForEntity(bool xy,
                                       bool z,
                                       bool rotation) override; // [48]
    const QuatT& GetAnimLocation() const override; // [49]
    float GetEntitySpeedHorizontal() const override; // [50]
    float GetEntitySpeed() const override; // [51]
    const Vec2& GetEntityMovementDirHorizontal() const override; // [52]
    const Vec2& GetEntityVelocityHorizontal() const override; // [53]
    const Vec2& GetEntityAccelerationHorizontal() const override; // [54]
    float GetEntityTangentialAcceleration() const override; // [55]
    const Vec3& GetExpectedEntMovement() const override; // [56]
    const Vec3& GetAnimationDerivedExpectedMovement() const override; // [57]
    float GetAngularSpeedHorizontal() const override; // [58]
    const SAnimatedCharacterParams& GetParams() override; // [59]
    void SetParams(const SAnimatedCharacterParams& params) override; // [60]
    SGroundAlignmentParams& GetGroundAlignmentParams() override; // [61]
    void SetDoMotionParams(bool enabled) override; // [62]
    int GetCurrentStance() override; // [63]
    bool InStanceTransition() override; // [64]
    void RequestStance(int stanceId, const char* name) override; // [65]
    float FilterView(SViewParams& viewParams) const override; // [66]
    EColliderMode GetPhysicalColliderMode() const override; // [67]
    void ForceRefreshPhysicalColliderMode() override; // [68]
    void RequestPhysicalColliderMode(EColliderMode mode,
                                     EColliderModeLayer layer,
                                     const char* tag = nullptr) override; // [69]
    void SetCharacterCollisionFlags(unsigned int flags) override; // [70]
    void SetMovementControlMethodsForSlot(
        EMCMSlot slot,
        EMovementControlMethod horizontal,
        EMovementControlMethod vertical,
        const char* tag = nullptr) override; // [71]
    void SetMovementControlMethods(
        EMovementControlMethod horizontal,
        EMovementControlMethod vertical) override; // [72]
    void EnableRigidCollider(float radius) override; // [73]
    void DisableRigidCollider() override; // [74]
    EMovementControlMethod GetMCMH() const override; // [75]
    EMovementControlMethod GetMCMV() const override; // [76]
    const char* GetMovementControlMethodName(
        EMovementControlMethod method) const override; // [77]
    void ConnectMovementControlMethodChanged(
        const Offsets::SMovementControlMethodChangedDelegate& delegate) override; // [78]
    void DisconnectMovementControlMethodChanged(
        const Offsets::SMovementControlMethodChangedDelegate& delegate) override; // [79]
    void EnableLandBob(const SLandBobParams& params) override; // [80]
    void DisableLandBob() override; // [81]
    void SetFacialAlertnessLevel(int alertness) override; // [82]
    int GetFacialAlertnessLevel() override; // [83]
    void AllowLookIk(bool allow, int layer = -1) override; // [84]
    bool IsLookIkAllowed() const override; // [85]
    void AllowAimIk(bool allow) override; // [86]
    bool IsAimIkAllowed() const override; // [87]
    void TriggerRecoil(float duration,
                       float kinematicImpact,
                       float kickIn = 0.8f,
                       EAnimatedCharacterArms arms = eACA_BothArms) override; // [88]
    void SetWeaponRaisedPose(EWeaponRaisedPose pose) override; // [89]
    void SetNoMovementOverride(bool external) override; // [90]
    float GetSlopeDegreeMoveDir() const override; // [91]
    float GetSlopeDegree() const override; // [92]
    void SetInGrabbedState(bool enabled) override; // [93]
    void ForceMovement(const QuatT& relativeMovement) override; // [94]
    void ForceOverrideRotation(const Quat& worldRotation) override; // [95]
    void SetFakeLeaningScale(const Vec2& scale) override; // [96]
    IAnimationPoseAligner* GetAnimationPoseAligner() const override; // [97]
    void GetAnimationMovementUsage(bool& xy,
                                   bool& z,
                                   bool& rotation,
                                   bool& speed) const override; // [98]
    const QuatT& GetPreviousAnimLocation() const override; // [99]
    const Quat& GetRequestedRotation() const override; // [100]
    void SetUseAnimationMovementSpeed(bool enabled) override; // [101]
    void SetForceInertiaParameters(bool enabled) override; // [102]
    const QuatT& GetForcedMovement(bool& valid) const override; // [103]
    const Vec3& GetActualRelativeEntityMovement() const override; // [104]
    void AddRequestedColliderOptions(std::uint16_t options) override; // [105]
    void ClearRequestedColliderOptions(std::uint16_t options) override; // [106]
    std::uint16_t GetAppliedColliderOptions() const override; // [107]
    bool IsAnimationProcessingActive() const override; // [108]
    void SetAnimationProcessingOverride(bool enabled) override; // [109]
    void EnableUpdateSlotOptimization(bool enabled) override; // [110]
    void RefreshExactPositioningTarget() override; // [111]
    std::uint32_t _vf112() override; // [112], name/arguments OPEN
    void AddListener(Offsets::IAnimatedCharacterListener* listener) override; // [113]
    void RemoveListener(Offsets::IAnimatedCharacterListener* listener) override; // [114]

    void SetOutput(const char* output, const char* value) override; // listener [1]
    void QueryComplete(TAnimationGraphQueryID queryId,
                       bool succeeded) override; // listener [2]
    void DestroyedState(IAnimationGraphState* state) override; // listener [3]

    wh::shared::C_Signal<EMCMSlot,
                         EMovementControlMethod,
                         EMovementControlMethod> m_mcmChanged; // +0x048
    SAnimatedCharacterListenerSet m_listeners; // +0x058
    IActionController* m_pActionController; // +0x080, owning
    SAnimationContext* m_pAnimationContext; // +0x088, owning
    const IAnimationDatabase* m_pChar1PDatabase; // +0x090, borrowed
    const IAnimationDatabase* m_pChar3PDatabase; // +0x098, borrowed
    const IAnimationDatabase* m_pAudioDatabase; // +0x0A0, borrowed
    bool m_scopeCacheDirty; // +0x0A8
    std::uint8_t _pad0A9[7]; // +0x0A9
    CryStringT<char> m_unknownString; // +0x0B0, semantics OPEN
    IAnimationGraphState* m_pAnimationGraphState; // +0x0B8, owning/refcounted
    CAnimationPlayerProxy* m_animationPlayerProxies[3]; // +0x0C0, borrowed
    SAnimatedCharacterParams m_params; // +0x0D8
    float m_inertiaCache[3]; // +0x0F8
    bool m_useAnimationXY; // +0x104
    bool m_useAnimationZ; // +0x105
    bool m_useAnimationRotation; // +0x106
    bool m_useAnimationSpeed; // +0x107
    std::int32_t m_facialAlertness; // +0x108
    std::int32_t m_currentStance; // +0x10C
    std::int32_t m_pendingStance; // +0x110
    TAnimationGraphQueryID m_stanceQueryId; // +0x114
    std::uint32_t m_lookIkDisableMask; // +0x118
    std::uint8_t m_aimIkFlags; // +0x11C
    std::uint8_t _pad11D[3]; // +0x11D
    std::uint32_t m_frameState120; // +0x120
    std::uint32_t m_frameState124; // +0x124
    std::uint32_t m_frameState128; // +0x128
    std::uint32_t m_frameState12C; // +0x12C
    std::uint32_t m_frameState130; // +0x130
    std::uint32_t m_frameState134; // +0x134
    std::uint32_t m_previousProcessedFrame; // +0x138
    std::int32_t m_shadowCharacterSlot; // +0x13C
    bool m_shadowCharacterEnabled; // +0x140
    bool m_unknown141; // +0x141
    std::uint8_t _pad142[2]; // +0x142
    EWeaponRaisedPose m_weaponRaisedPose; // +0x144
    SCharacterMoveRequest m_moveRequest; // +0x148
    std::uint8_t m_movementState194; // +0x194
    std::uint8_t m_physicsState195; // +0x195
    std::uint8_t _pad196[2]; // +0x196
    std::int64_t m_timerTick; // +0x198
    double m_currentFrameTime; // +0x1A0
    double m_previousFrameTime; // +0x1A8
    double m_secondaryFrameTime; // +0x1B0
    bool m_forcedMovementValid; // +0x1B8
    std::uint8_t _pad1B9[3]; // +0x1B9
    QuatT m_forcedMovement; // +0x1BC
    bool m_forcedRotationValid; // +0x1D8
    std::uint8_t _pad1D9[3]; // +0x1D9
    Quat m_forcedWorldRotation; // +0x1DC
    QuatT m_animLocation; // +0x1EC
    QuatT m_previousAnimLocation; // +0x208
    Vec3 m_expectedEntityMovement; // +0x224
    QuatT m_relativeEntityMovement; // +0x230
    QuatT m_generatedPhysicalTransform; // +0x24C
    QuatT m_generatedUpdateTransform; // +0x268
    Vec2 m_fakeLeaningHistoryA[32]; // +0x284
    Vec2 m_fakeLeaningHistoryB[32]; // +0x384
    std::uint32_t _pad484; // +0x484
    std::uint64_t m_fakeLeaningTimestamps[32]; // +0x488
    std::uint32_t m_fakeLeaningRingIndex; // +0x588
    Vec3 m_filteredVelocity; // +0x58C
    std::uint32_t m_unknown598; // +0x598
    Vec3 m_filteredFakeLeaningAxis; // +0x59C
    Vec2 m_fakeLeaningScale; // +0x5A8
    bool m_doMotionParams; // +0x5B0
    std::uint8_t m_unknown5B1; // +0x5B1
    std::uint8_t m_unknown5B2; // +0x5B2
    std::uint8_t _pad5B3; // +0x5B3
    EMovementControlMethod m_horizontalMcm[5]; // +0x5B4
    EMovementControlMethod m_verticalMcm[5]; // +0x5C8
    std::uint32_t _pad5DC; // +0x5DC
    const char* m_mcmTags[5]; // +0x5E0, borrowed
    const char* m_mergedMcmTags[2]; // +0x608, borrowed
    float m_mcmTimers[2]; // +0x618
    const char* m_colliderTags[7]; // +0x620, borrowed
    EColliderMode m_colliderRequests[7]; // +0x658
    EColliderMode m_currentColliderMode; // +0x674
    std::uint16_t m_unknown678; // +0x678
    std::uint16_t _pad67A; // +0x67A
    Quat m_requestedRotation; // +0x67C
    Vec3 m_requestedVelocity; // +0x68C
    std::int32_t m_physicalMovementType; // +0x698
    std::int32_t m_physicalMovementMode; // +0x69C
    bool m_requestIsSwimming; // +0x6A0
    bool m_updateSlotSuspended; // +0x6A1
    bool m_physicsUpdateState; // +0x6A2
    std::uint8_t _pad6A3; // +0x6A3
    float m_unknown6A4; // +0x6A4
    Vec2 m_horizontalVelocity; // +0x6A8
    Vec2 m_horizontalDirection; // +0x6B0
    Vec2 m_horizontalAcceleration; // +0x6B8
    float m_tangentialAcceleration; // +0x6C0
    float m_entitySpeed; // +0x6C4
    float m_entitySpeedHorizontal; // +0x6C8
    std::uint32_t _pad6CC; // +0x6CC
    const SExactPositioningTarget* m_pExactPositioningTarget; // +0x6D0, borrowed
    ICharacterInstance* m_pCharacter; // +0x6D8, borrowed
    ISkeletonAnim* m_pSkeletonAnim; // +0x6E0, borrowed
    ISkeletonPose* m_pSkeletonPose; // +0x6E8, borrowed
    ICharacterInstance* m_pShadowCharacter; // +0x6F0, borrowed
    ISkeletonAnim* m_pShadowSkeletonAnim; // +0x6F8, borrowed
    ISkeletonPose* m_pShadowSkeletonPose; // +0x700, borrowed
    bool m_noMovementOverride; // +0x708
    bool m_unknown709; // +0x709
    std::uint8_t _pad70A[2]; // +0x70A
    float m_smoothedJumping; // +0x70C
    float m_smoothedJumpingVelocity; // +0x710
    float m_slopeMoveDir; // +0x714
    float m_slopeMoveDirVelocity; // +0x718
    float m_lateralSlope; // +0x71C
    float m_lateralSlopeVelocity; // +0x720
    float m_unknown724; // +0x724
    float m_groundSlope; // +0x728
    float m_groundSlopeVelocity; // +0x72C
    std::uint64_t m_unknown730; // +0x730
    SLandBobParams m_landBobParams; // +0x738
    std::byte m_landBobRuntime[0x10]; // +0x744, internals OPEN
    SGroundAlignmentParams m_groundAlignmentParams; // +0x754
    std::byte m_groundAlignmentRuntime[0x28]; // +0x75C, internals OPEN
    QuatT m_animationDerivedExpectedMovement; // +0x784
    bool m_forceRefreshCollider; // +0x7A0
    bool m_ragdollCreationQueued; // +0x7A1
    std::uint8_t _pad7A2[2]; // +0x7A2
    SRagdollizeParams m_ragdollParams; // +0x7A4
    std::uint32_t m_ragdollState; // +0x7B0
    bool m_blendFromRagdollQueued; // +0x7B4
    std::uint8_t _pad7B5[3]; // +0x7B5
    bool m_unknown7B8; // +0x7B8
    std::uint8_t _pad7B9[3]; // +0x7B9
    float m_unknown7BC; // +0x7BC
    float m_cachedPhysicalMovementWeight; // +0x7C0
    std::uint8_t m_cachedPhysicalMovementMode; // +0x7C4
    std::uint8_t _pad7C5[3]; // +0x7C5
    std::int32_t m_movementSmoothingFrameId; // +0x7C8
    std::uint32_t m_unknown7CC; // +0x7CC
    Vec3 m_movementSmoothingStages[4]; // +0x7D0
    void* m_pSpecialColliderHandle; // +0x800, service-owned; type OPEN
    void* m_pRigidColliderHandle; // +0x808, service-owned; type OPEN
    std::uint32_t m_characterCollisionFlags; // +0x810
    std::uint32_t _pad814; // +0x814
    IDebugHistoryManager* m_pDebugHistoryManager; // +0x818, owning/refcounted
    std::shared_ptr<IAnimationPoseAligner> m_poseAligner; // +0x820
    std::uint32_t m_unknown830; // +0x830
    bool m_grabbed; // +0x834
    bool m_useMannequinAgState; // +0x835, spelling inferred
    bool m_postInitComplete; // +0x836
    bool m_carriedForcedMovement; // +0x837
    bool m_forceInertiaParameters; // +0x838
    std::uint8_t _pad839[3]; // +0x839
    std::uint32_t m_frameState83C; // +0x83C
    std::uint32_t m_frameState840; // +0x840
    std::uint32_t m_frameState844; // +0x844
    bool m_updateSlotOptimizationEnabled; // +0x848
    bool m_animationProcessingState; // +0x849
    bool m_animationProcessingOverride; // +0x84A
    std::uint8_t _pad84B; // +0x84B
    std::uint16_t m_appliedColliderOptions; // +0x84C
    std::uint16_t m_requestedColliderOptions; // +0x84E
    Offsets::IGameObjectProfileManager* m_pProfileManager; // +0x850, borrowed/subscribed
};
static_assert(sizeof(CAnimatedCharacter) == 0x858,
              "CAnimatedCharacter must be 0x858");
static_assert(offsetof(CAnimatedCharacter, m_mcmChanged) == 0x48,
              "animated-character MCM signal must be at 0x48");
static_assert(offsetof(CAnimatedCharacter, m_pActionController) == 0x80,
              "animated-character action controller must be at 0x80");
static_assert(offsetof(CAnimatedCharacter, m_params) == 0xD8,
              "animated-character params must be at 0xD8");
static_assert(offsetof(CAnimatedCharacter, m_moveRequest) == 0x148,
              "animated-character move request must be at 0x148");
static_assert(offsetof(CAnimatedCharacter, m_horizontalMcm) == 0x5B4,
              "animated-character horizontal MCM stack must be at 0x5B4");
static_assert(offsetof(CAnimatedCharacter, m_pExactPositioningTarget) == 0x6D0,
              "animated-character exact-positioning target must be at 0x6D0");
static_assert(offsetof(CAnimatedCharacter, m_ragdollParams) == 0x7A4,
              "animated-character ragdoll params must be at 0x7A4");
static_assert(offsetof(CAnimatedCharacter, m_poseAligner) == 0x820,
              "animated-character pose aligner must be at 0x820");
static_assert(offsetof(CAnimatedCharacter, m_appliedColliderOptions) == 0x84C,
              "animated-character applied collider options must be at 0x84C");
static_assert(offsetof(CAnimatedCharacter, m_pProfileManager) == 0x850,
              "animated-character profile manager must be at 0x850");
