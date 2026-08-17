#pragma once
#include <cstddef>
#include <cstdint>
#include "IGameObjectExtension.h"
#include "IAnimatedCharacterListener.h"
#include "../../CryEngine/CryCommon/Cry_Math.h"
#include "../../crysystem/EMotionParamID.h"
#include "../../framework/C_Signal.h"
#include "../../crysystem/EAnimatedCharacterArms.h"
#include "../../crysystem/EColliderMode.h"
#include "../../crysystem/EColliderModeLayer.h"
#include "../../crysystem/EMCMSlot.h"
#include "../../crysystem/EMovementControlMethod.h"
#include "../../crysystem/EWeaponRaisedPose.h"
#include "../../crysystem/SAnimatedCharacterParams.h"
#include "../../crysystem/SCharacterMoveRequest.h"
#include "../../crysystem/SGroundAlignmentParams.h"
#include "../../crysystem/SLandBobParams.h"
#include "../../crysystem/SPredictedCharacterStates.h"

class CAnimationPlayerProxy;
class IActionController;
struct IAnimationGraphState;
struct IAnimationPoseAligner;
struct SViewParams;

namespace Offsets {

using SMovementControlMethodChangedDelegate =
    wh::shared::S_Delegate<EMCMSlot,
                           EMovementControlMethod,
                           EMovementControlMethod>;

// Current KCD2 IAnimatedCharacter tail. The historical GetAnimationGraph(int)
// slot is absent; slots [35..36] and [96..114] are current additions.
class IAnimatedCharacter : public IGameObjectExtension {
public:
    virtual IAnimationGraphState* GetAnimationGraphState() = 0; // [29]
    virtual void PushForcedState(const char* state) = 0; // [30]
    virtual void ClearForcedStates() = 0; // [31]
    virtual void ChangeGraph(const char* graph, int layer) = 0; // [32]
    virtual void ResetState() = 0; // [33]
    virtual void ResetInertiaCache() = 0; // [34]
    virtual bool IsRagdollCreationQueued() const = 0; // [35], name reconstructed
    virtual void PrepareForUpdate() = 0; // [36], name reconstructed
    virtual IActionController* GetActionController() = 0; // [37]
    virtual const IActionController* GetActionControllerConst() const = 0; // [38], de-overloaded
    virtual void SetShadowCharacterSlot(int id) = 0; // [39]
    virtual void SetAnimationPlayerProxy(CAnimationPlayerProxy* proxy,
                                         int layer) = 0; // [40]
    virtual CAnimationPlayerProxy* GetAnimationPlayerProxy(int layer) = 0; // [41]
    virtual void UpdateCharacterPtrs() = 0; // [42]
    virtual void AddMovement(const SCharacterMoveRequest& request) = 0; // [43]
    virtual void SetEntityRotation(const Quat& rotation) = 0; // [44]
    virtual const SPredictedCharacterStates&
        GetOverriddenMotionParameters() const = 0; // [45]
    virtual void SetOverriddenMotionParameters(
        const SPredictedCharacterStates& parameters) = 0; // [46]
    virtual void SetMotionParameter(EMotionParamID id,
                                    float value,
                                    std::uint8_t characterMask) = 0; // [47]
    virtual void UseAnimationMovementForEntity(bool xy,
                                               bool z,
                                               bool rotation) = 0; // [48]
    virtual const QuatT& GetAnimLocation() const = 0; // [49]
    virtual float GetEntitySpeedHorizontal() const = 0; // [50]
    virtual float GetEntitySpeed() const = 0; // [51]
    virtual const Vec2& GetEntityMovementDirHorizontal() const = 0; // [52]
    virtual const Vec2& GetEntityVelocityHorizontal() const = 0; // [53]
    virtual const Vec2& GetEntityAccelerationHorizontal() const = 0; // [54]
    virtual float GetEntityTangentialAcceleration() const = 0; // [55]
    virtual const Vec3& GetExpectedEntMovement() const = 0; // [56]
    virtual const Vec3& GetAnimationDerivedExpectedMovement() const = 0; // [57]
    virtual float GetAngularSpeedHorizontal() const = 0; // [58]
    virtual const SAnimatedCharacterParams& GetParams() = 0; // [59]
    virtual void SetParams(const SAnimatedCharacterParams& params) = 0; // [60]
    virtual SGroundAlignmentParams& GetGroundAlignmentParams() = 0; // [61]
    virtual void SetDoMotionParams(bool enabled) = 0; // [62]
    virtual int GetCurrentStance() = 0; // [63]
    virtual bool InStanceTransition() = 0; // [64]
    virtual void RequestStance(int stanceId, const char* name) = 0; // [65]
    virtual float FilterView(SViewParams& viewParams) const = 0; // [66]
    virtual EColliderMode GetPhysicalColliderMode() const = 0; // [67]
    virtual void ForceRefreshPhysicalColliderMode() = 0; // [68]
    virtual void RequestPhysicalColliderMode(EColliderMode mode,
                                             EColliderModeLayer layer,
                                             const char* tag = nullptr) = 0; // [69]
    virtual void SetCharacterCollisionFlags(unsigned int flags) = 0; // [70]
    virtual void SetMovementControlMethodsForSlot(
        EMCMSlot slot,
        EMovementControlMethod horizontal,
        EMovementControlMethod vertical,
        const char* tag = nullptr) = 0; // [71], de-overloaded
    virtual void SetMovementControlMethods(
        EMovementControlMethod horizontal,
        EMovementControlMethod vertical) = 0; // [72]
    virtual void EnableRigidCollider(float radius) = 0; // [73]
    virtual void DisableRigidCollider() = 0; // [74]
    virtual EMovementControlMethod GetMCMH() const = 0; // [75]
    virtual EMovementControlMethod GetMCMV() const = 0; // [76]
    virtual const char* GetMovementControlMethodName(
        EMovementControlMethod method) const = 0; // [77], name reconstructed
    virtual void ConnectMovementControlMethodChanged(
        const SMovementControlMethodChangedDelegate& delegate) = 0; // [78]
    virtual void DisconnectMovementControlMethodChanged(
        const SMovementControlMethodChangedDelegate& delegate) = 0; // [79]
    virtual void EnableLandBob(const SLandBobParams& params) = 0; // [80]
    virtual void DisableLandBob() = 0; // [81]
    virtual void SetFacialAlertnessLevel(int alertness) = 0; // [82]
    virtual int GetFacialAlertnessLevel() = 0; // [83]
    virtual void AllowLookIk(bool allow, int layer = -1) = 0; // [84]
    virtual bool IsLookIkAllowed() const = 0; // [85]
    virtual void AllowAimIk(bool allow) = 0; // [86]
    virtual bool IsAimIkAllowed() const = 0; // [87]
    virtual void TriggerRecoil(
        float duration,
        float kinematicImpact,
        float kickIn = 0.8f,
        EAnimatedCharacterArms arms = eACA_BothArms) = 0; // [88]
    virtual void SetWeaponRaisedPose(EWeaponRaisedPose pose) = 0; // [89]
    virtual void SetNoMovementOverride(bool external) = 0; // [90]
    virtual float GetSlopeDegreeMoveDir() const = 0; // [91]
    virtual float GetSlopeDegree() const = 0; // [92]
    virtual void SetInGrabbedState(bool enabled) = 0; // [93]
    virtual void ForceMovement(const QuatT& relativeMovement) = 0; // [94]
    virtual void ForceOverrideRotation(const Quat& worldRotation) = 0; // [95]
    virtual void SetFakeLeaningScale(const Vec2& scale) = 0; // [96]
    virtual IAnimationPoseAligner* GetAnimationPoseAligner() const = 0; // [97]
    virtual void GetAnimationMovementUsage(bool& xy,
                                           bool& z,
                                           bool& rotation,
                                           bool& speed) const = 0; // [98]
    virtual const QuatT& GetPreviousAnimLocation() const = 0; // [99]
    virtual const Quat& GetRequestedRotation() const = 0; // [100]
    virtual void SetUseAnimationMovementSpeed(bool enabled) = 0; // [101]
    virtual void SetForceInertiaParameters(bool enabled) = 0; // [102]
    virtual const QuatT& GetForcedMovement(bool& valid) const = 0; // [103]
    virtual const Vec3& GetActualRelativeEntityMovement() const = 0; // [104]
    virtual void AddRequestedColliderOptions(std::uint16_t options) = 0; // [105]
    virtual void ClearRequestedColliderOptions(std::uint16_t options) = 0; // [106]
    virtual std::uint16_t GetAppliedColliderOptions() const = 0; // [107]
    virtual bool IsAnimationProcessingActive() const = 0; // [108]
    virtual void SetAnimationProcessingOverride(bool enabled) = 0; // [109]
    virtual void EnableUpdateSlotOptimization(bool enabled) = 0; // [110]
    virtual void RefreshExactPositioningTarget() = 0; // [111]
    virtual std::uint32_t _vf112() = 0; // [112], name/arguments OPEN
    virtual void AddListener(IAnimatedCharacterListener* listener) = 0; // [113]
    virtual void RemoveListener(IAnimatedCharacterListener* listener) = 0; // [114]
};
static_assert(sizeof(IAnimatedCharacter) == 0x40,
              "IAnimatedCharacter must preserve the 0x40 extension prefix");

}  // namespace Offsets
