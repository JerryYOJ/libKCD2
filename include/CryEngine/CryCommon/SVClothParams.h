#pragma once
#include <cstddef>
#include <cstdint>
#include "CCryName.h"
#include "CryString.h"
#include "EAttachmentBlendControlJointAxisToUse.h"
#include "E_ClothCollisionMode.h"

struct SVClothParams {
    SVClothParams();
    ~SVClothParams();

    float forceSkinningTranslateThreshold;                    // +0x00
    float disableSimulationTimeRange;                         // +0x04
    float timeStep;                                           // +0x08
    std::int32_t timeStepsMax;                                // +0x0C
    std::int32_t numIterations;                               // +0x10
    std::int32_t collideEveryNthStep;                         // +0x14
    float gravityFactor;                                      // +0x18
    float airResistance;                                      // +0x1C
    float stretchStiffness;                                   // +0x20
    float shearStiffness;                                     // +0x24
    float bendStiffness;                                      // +0x28
    float bendStiffnessByTrianglesAngle;                      // +0x2C
    float pullStiffness;                                      // +0x30
    float friction;                                          // +0x34
    float rigidDamping;                                       // +0x38
    float springDamping;                                      // +0x3C
    float collisionDampingTangential;                         // +0x40
    float nndcAllowedExtension;                               // +0x44
    float nndcMaximumShiftFactor;                             // +0x48
    float nndcShiftCollisionFactor;                           // +0x4C
    std::int32_t resetDampingRange;                           // +0x50
    float resetDampingFactor;                                 // +0x54
    float maxAnimDistance;                                    // +0x58
    float filterLaplace;                                      // +0x5C
    CryStringT<char> m_unknownString60;                        // +0x60, role OPEN
    CryStringT<char> simBinding;                              // +0x68
    CryStringT<char> m_unknownString70;                        // +0x70, role OPEN
    CCryName blendControlJointName;                            // +0x78
    std::uint16_t m_unknown80;                                // +0x80, initialized to 0xFFFF
    std::uint16_t m_padding82;                                // +0x82
    EAttachmentBlendControlJointAxisToUse blendControlAxis;   // +0x84
    E_ClothCollisionMode::Type collisionMode;                  // +0x88
    bool proxyNames;                                          // +0x89
    bool checkAnimationRewind;                                // +0x8A
    bool useNearestNeighborDistanceConstraints;               // +0x8B
    bool springDampingPerSubstep;                              // +0x8C
    std::uint8_t m_padding8D[3];                              // +0x8D
};

static_assert(offsetof(SVClothParams, forceSkinningTranslateThreshold) == 0x00,
              "SVClothParams force-skinning threshold offset mismatch");
static_assert(offsetof(SVClothParams, airResistance) == 0x1C,
              "SVClothParams air-resistance offset mismatch");
static_assert(offsetof(SVClothParams, m_unknownString60) == 0x60,
              "SVClothParams first string offset mismatch");
static_assert(offsetof(SVClothParams, simBinding) == 0x68,
              "SVClothParams sim-binding offset mismatch");
static_assert(offsetof(SVClothParams, blendControlJointName) == 0x78,
              "SVClothParams blend-control joint offset mismatch");
static_assert(offsetof(SVClothParams, blendControlAxis) == 0x84,
              "SVClothParams blend-control axis offset mismatch");
static_assert(offsetof(SVClothParams, collisionMode) == 0x88,
              "SVClothParams collision-mode offset mismatch");
static_assert(offsetof(SVClothParams, springDampingPerSubstep) == 0x8C,
              "SVClothParams spring-damping flag offset mismatch");
static_assert(sizeof(SVClothParams) == 0x90,
              "SVClothParams size mismatch");
