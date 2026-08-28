#pragma once
#include <cstddef>
#include <cstdint>
#include "CryArray.h"
#include "CCryName.h"
#include "Cry_Math.h"
#include "EAttachmentBlendControlJointAxisToUse.h"

// -----------------------------------------------
// SimulationParams -- CryEngine attachment simulation parameters
// (KCD2 WHGame.dll Steam 1.5.6). sizeof 0x80.
// -----------------------------------------------
// Layout is reconciled from KCD2 RTTR member pointers, ProxyNames accessor
// disassembly, constructor size, and the public CryEngine IAttachment.h source.

struct SimulationParams {
    enum ClampType : std::int32_t {
        DISABLED                   = 0,
        PENDULUM_CONE              = 1,
        PENDULUM_HINGE_PLANE       = 2,
        PENDULUM_HALF_CONE         = 3,
        SPRING_ELLIPSOID           = 4,
        TRANSLATIONAL_PROJECTION   = 5,
    };

    CCryName m_dirTransJoint;                              // +0x00 RTTR "DirTransJoint"
    DynArray<CCryName> m_proxyNames;                       // +0x08 accessor-proven
    CCryName m_dissolveRefA;                               // +0x10 RTTR "DissolveRefA"
    std::int32_t m_projectionType;                         // +0x18 RTTR "ProjectionType"
    EAttachmentBlendControlJointAxisToUse m_blendControlAxis; // +0x1C RTTR "BlendControlAxis"
    float m_maxAngle;                                      // +0x20 RTTR "MaxAngle"
    float m_radius;                                        // +0x24 RTTR "Radius"
    Vec2 m_sphereScale;                                    // +0x28 RTTR "SphereScale"
    Vec2 m_diskRotation;                                   // +0x30 RTTR "DiskRotation"
    float m_mass;                                          // +0x38 RTTR "Mass"
    float m_gravity;                                       // +0x3C RTTR "Gravity"
    float m_damping;                                       // +0x40 RTTR "Damping"
    float m_stiffness;                                     // +0x44 RTTR "Stiffness"
    Vec3 m_pivotOffset;                                    // +0x48 RTTR "PivotOffset"
    Vec3 m_simulationAxis;                                 // +0x54 RTTR "SimulationAxis"
    Vec3 m_stiffnessTarget;                                // +0x60 RTTR "StiffnessTarget"
    Vec2 m_capsule;                                        // +0x6C RTTR "Capsule"
    ClampType m_clampType;                                 // +0x74 RTTR "ClampType"
    bool m_lodA;                                           // +0x78 RTTR "LodA"
    bool m_lodB;                                           // +0x79 RTTR "LodB"
    bool m_activateSimulation;                             // +0x7A RTTR "ActivateSimulation"
    bool m_redirect;                                       // +0x7B RTTR "Redirect"
    std::uint8_t m_simFPS;                                 // +0x7C RTTR "SimFPS"
    std::uint8_t _pad7D[3];                               // +0x7D
};

static_assert(sizeof(SimulationParams::ClampType) == 4,
              "SimulationParams::ClampType size mismatch");
static_assert(offsetof(SimulationParams, m_proxyNames) == 0x08,
              "SimulationParams::m_proxyNames offset mismatch");
static_assert(offsetof(SimulationParams, m_blendControlAxis) == 0x1C,
              "SimulationParams::m_blendControlAxis offset mismatch");
static_assert(offsetof(SimulationParams, m_clampType) == 0x74,
              "SimulationParams::m_clampType offset mismatch");
static_assert(offsetof(SimulationParams, m_simFPS) == 0x7C,
              "SimulationParams::m_simFPS offset mismatch");
static_assert(sizeof(SimulationParams) == 0x80,
              "SimulationParams size mismatch");
