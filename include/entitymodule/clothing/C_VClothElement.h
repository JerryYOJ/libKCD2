#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>
#include <optional>
#include <vector>

#include "../../CryEngine/CryCommon/EAttachmentBlendControlJointAxisToUse.h"
#include "../../CryEngine/CryCommon/E_ClothCollisionMode.h"
#include "../../framework/TinyOptional.h"
#include "C_SkinElement.h"

namespace wh::entitymodule::clothing {

class C_VClothElement : public C_SkinElement {
public:
    C_VClothElement();                                                   // 0x180E71D8C
    ~C_VClothElement() override;                                         // [0] 0x18295C580
    std::uint32_t GetElementType() const override;                       // [1] 0x181A724F0
    void unk_03(void* target) const override;                            // [3] 0x180CBD9C0
    bool unk_04() const override;                                       // [4] 0x1813C2BD8
    CryStringT<char> unk_05() const override;                            // [5] 0x18295E63C
    bool unk_17() const override;                                       // [17] 0x1813D3DB0
    std::vector<CryStringT<char>> unk_20() const override;               // [20] 0x18295E2B8
    void unk_21(const C_ElementBase* source) override;                   // [21] 0x181239828
    bool unk_22(const C_ElementBase* other) const override;              // [22] 0x18119BA30
    RTTR_ENABLE(C_SkinElement)                                           // [25..27], vtable 0x183AC1920

    std::optional<CryStringT<char>> m_simBinding;                        // +0x38 RTTR "SimBinding"
    tiny::optional<bool> m_forceSkinning;                               // +0x48 RTTR "ForceSkinning"
    std::uint8_t m_padding49[3];                                        // +0x49
    tiny::optional<float> m_forceSkinningTranslateThreshold;            // +0x4C RTTR "ForceSkinningTranslateThreshold"
    tiny::optional<bool> m_checkAnimationRewind;                        // +0x50 RTTR "CheckAnimationRewind"
    std::uint8_t m_padding51[3];                                        // +0x51
    tiny::optional<float> m_disableSimulationTimeRange;                 // +0x54 RTTR "DisableSimulationTimeRange"
    tiny::optional<float> m_timeStep;                                   // +0x58 RTTR "TimeStep"
    tiny::optional<int, std::numeric_limits<int>::min()> m_timeStepMax; // +0x5C RTTR "TimeStepMax"
    tiny::optional<int, std::numeric_limits<int>::min()> m_numIterations; // +0x60 RTTR "NumIterations"
    tiny::optional<int, std::numeric_limits<int>::min()> m_collideEveryNthStep; // +0x64 RTTR "CollideEveryNthStep"
    std::optional<E_ClothCollisionMode::Type> m_collisionMode;           // +0x68 RTTR "CollisionMode"
    std::uint8_t m_padding6A[2];                                        // +0x6A
    tiny::optional<float> m_gravityFactor;                              // +0x6C RTTR "GravityFactor"
    tiny::optional<float> m_airResistance;                              // +0x70 RTTR "AirResistance"
    tiny::optional<float> m_stretchStiffness;                           // +0x74 RTTR "StretchStiffness"
    tiny::optional<float> m_shearStiffness;                             // +0x78 RTTR "ShearStiffness"
    tiny::optional<float> m_bendStiffness;                              // +0x7C RTTR "BendStiffness"
    tiny::optional<float> m_bendStiffnessByTrianglesAngle;              // +0x80 RTTR "BendStiffnessByTrianglesAngle"
    tiny::optional<float> m_pullStiffness;                              // +0x84 RTTR "PullStiffness"
    tiny::optional<float> m_friction;                                   // +0x88 RTTR "Friction"
    tiny::optional<float> m_rigidDamping;                               // +0x8C RTTR "RigidDamping"
    tiny::optional<float> m_springDamping;                              // +0x90 RTTR "SpringDamping"
    tiny::optional<bool> m_springDampingPerSubstep;                     // +0x94 RTTR "SpringDampingPerSubstep"
    std::uint8_t m_padding95[3];                                        // +0x95
    tiny::optional<float> m_collisionDampingTangential;                 // +0x98 RTTR "CollisionDampingTangential"
    tiny::optional<bool> m_nearestNeighborDistanceConstraints;          // +0x9C RTTR "NearestNeighborDistanceConstraints"
    std::uint8_t m_padding9D[3];                                        // +0x9D
    tiny::optional<float> m_nndcMaximumShiftFactor;                     // +0xA0 RTTR "NndcMaximumShiftFactor"
    tiny::optional<float> m_nndcShiftCollisionFactor;                   // +0xA4 RTTR "NndcShiftCollisionFactor"
    tiny::optional<float> m_nndcAllowedExtension;                       // +0xA8 RTTR "NndcAllowedExtension"
    tiny::optional<float> m_maxAnimDistance;                            // +0xAC RTTR "MaxAnimDistance"
    tiny::optional<float> m_filterLaplace;                              // +0xB0 RTTR "FilterLaplace"
    tiny::optional<int, std::numeric_limits<int>::min()> m_resetDampingRange; // +0xB4 RTTR "ResetDampingRange"
    tiny::optional<float> m_resetDampingFactor;                         // +0xB8 RTTR "ResetDampingFactor"
    std::uint8_t m_paddingBC[4];                                        // +0xBC
    std::optional<CryStringT<char>> m_blendControlJointName;            // +0xC0 RTTR "BlendControlJointName"
    std::optional<EAttachmentBlendControlJointAxisToUse> m_blendControlAxis; // +0xD0 RTTR "BlendControlAxis"
};

static_assert(offsetof(C_VClothElement, m_simBinding) == 0x38,
              "C_VClothElement::m_simBinding offset mismatch");
static_assert(offsetof(C_VClothElement, m_collisionMode) == 0x68,
              "C_VClothElement::m_collisionMode offset mismatch");
static_assert(offsetof(C_VClothElement, m_nearestNeighborDistanceConstraints) == 0x9C,
              "C_VClothElement::m_nearestNeighborDistanceConstraints offset mismatch");
static_assert(offsetof(C_VClothElement, m_blendControlJointName) == 0xC0,
              "C_VClothElement::m_blendControlJointName offset mismatch");
static_assert(offsetof(C_VClothElement, m_blendControlAxis) == 0xD0,
              "C_VClothElement::m_blendControlAxis offset mismatch");
static_assert(sizeof(C_VClothElement) == 0xD8,
              "C_VClothElement size mismatch");

} // namespace wh::entitymodule::clothing
